#include "qserialport_compat.h"

#include <QtGlobal>
#include <algorithm>
#include <cstring>
#include <iterator>

#ifdef Q_OS_WIN
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#endif

QSerialPort::QSerialPort(QObject *parent)
    : QIODevice(parent)
{
    m_pollTimer.setInterval(20);
    connect(&m_pollTimer, &QTimer::timeout, this, &QSerialPort::pollInput);
}

QSerialPort::~QSerialPort()
{
    close();
}

void QSerialPort::setPortName(const QString &name) { m_portName = name; }
QString QSerialPort::portName() const { return m_portName; }
bool QSerialPort::setBaudRate(qint32 value) { m_baudRate = value; return true; }
bool QSerialPort::setDataBits(DataBits value) { m_dataBits = value; return true; }
bool QSerialPort::setParity(Parity value) { m_parity = value; return true; }
bool QSerialPort::setStopBits(StopBits value) { m_stopBits = value; return true; }
bool QSerialPort::setFlowControl(FlowControl value) { m_flowControl = value; return true; }

bool QSerialPort::open(OpenMode mode)
{
#ifdef Q_OS_WIN
    if (m_portName.isEmpty()) {
        setSerialError(DeviceNotFoundError, QStringLiteral("未指定串口"));
        return false;
    }

    const QString devicePath = QStringLiteral("\\\\.\\") + m_portName;
    HANDLE handle = CreateFileW(reinterpret_cast<LPCWSTR>(devicePath.utf16()),
                                GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL, nullptr);
    if (handle == INVALID_HANDLE_VALUE) {
        setSerialError(OpenError, QStringLiteral("无法打开 %1（Windows 错误 %2）")
                       .arg(m_portName).arg(GetLastError()));
        return false;
    }

    DCB dcb {};
    dcb.DCBlength = sizeof(DCB);
    if (!GetCommState(handle, &dcb)) {
        CloseHandle(handle);
        setSerialError(OpenError, QStringLiteral("读取串口参数失败"));
        return false;
    }
    dcb.BaudRate = static_cast<DWORD>(m_baudRate);
    dcb.ByteSize = static_cast<BYTE>(m_dataBits);
    dcb.Parity = m_parity == EvenParity ? EVENPARITY
               : m_parity == OddParity ? ODDPARITY
               : m_parity == MarkParity ? MARKPARITY
               : m_parity == SpaceParity ? SPACEPARITY : NOPARITY;
    dcb.fParity = m_parity != NoParity;
    dcb.StopBits = m_stopBits == TwoStop ? TWOSTOPBITS
                 : m_stopBits == OneAndHalfStop ? ONE5STOPBITS : ONESTOPBIT;
    dcb.fOutxCtsFlow = m_flowControl == HardwareControl;
    dcb.fRtsControl = m_flowControl == HardwareControl ? RTS_CONTROL_HANDSHAKE : RTS_CONTROL_ENABLE;
    dcb.fOutX = dcb.fInX = m_flowControl == SoftwareControl;

    if (!SetCommState(handle, &dcb)) {
        CloseHandle(handle);
        setSerialError(OpenError, QStringLiteral("设置串口参数失败"));
        return false;
    }

    COMMTIMEOUTS timeouts {};
    timeouts.ReadIntervalTimeout = MAXDWORD;
    SetCommTimeouts(handle, &timeouts);
    SetupComm(handle, 8192, 8192);
    PurgeComm(handle, PURGE_RXCLEAR | PURGE_TXCLEAR);

    m_handle = handle;
    m_error = NoError;
    setErrorString(QString());
    QIODevice::open(mode);
    m_pollTimer.start();
    return true;
#else
    Q_UNUSED(mode)
    setSerialError(OpenError, QStringLiteral("内置串口兼容层仅支持 Windows"));
    return false;
#endif
}

void QSerialPort::close()
{
    m_pollTimer.stop();
#ifdef Q_OS_WIN
    if (m_handle) {
        CloseHandle(static_cast<HANDLE>(m_handle));
        m_handle = nullptr;
    }
#endif
    m_readBuffer.clear();
    QIODevice::close();
}

qint64 QSerialPort::bytesAvailable() const
{
    return m_readBuffer.size() + QIODevice::bytesAvailable();
}

qint64 QSerialPort::readData(char *data, qint64 maxSize)
{
    const qint64 count = qMin(maxSize, static_cast<qint64>(m_readBuffer.size()));
    if (count <= 0)
        return 0;
    std::memcpy(data, m_readBuffer.constData(), static_cast<size_t>(count));
    m_readBuffer.remove(0, static_cast<int>(count));
    return count;
}

qint64 QSerialPort::writeData(const char *data, qint64 maxSize)
{
#ifdef Q_OS_WIN
    if (!m_handle)
        return -1;
    DWORD written = 0;
    if (!WriteFile(static_cast<HANDLE>(m_handle), data, static_cast<DWORD>(maxSize), &written, nullptr)) {
        setSerialError(WriteError, QStringLiteral("串口写入失败（Windows 错误 %1）").arg(GetLastError()));
        return -1;
    }
    emit bytesWritten(written);
    return written;
#else
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
#endif
}

void QSerialPort::pollInput()
{
#ifdef Q_OS_WIN
    if (!m_handle)
        return;
    COMSTAT status {};
    DWORD errors = 0;
    if (!ClearCommError(static_cast<HANDLE>(m_handle), &errors, &status)) {
        setSerialError(ResourceError, QStringLiteral("串口连接已断开"));
        close();
        return;
    }
    if (status.cbInQue == 0)
        return;
    QByteArray bytes(static_cast<int>(qMin<DWORD>(status.cbInQue, 8192)), Qt::Uninitialized);
    DWORD read = 0;
    if (!ReadFile(static_cast<HANDLE>(m_handle), bytes.data(), static_cast<DWORD>(bytes.size()), &read, nullptr)) {
        setSerialError(ReadError, QStringLiteral("串口读取失败（Windows 错误 %1）").arg(GetLastError()));
        return;
    }
    if (read > 0) {
        bytes.resize(static_cast<int>(read));
        m_readBuffer.append(bytes);
        emit readyRead();
    }
#endif
}

void QSerialPort::setSerialError(SerialPortError error, const QString &message)
{
    m_error = error;
    setErrorString(message);
    emit errorOccurred(error);
}

QList<QSerialPortInfo> QSerialPortInfo::availablePorts()
{
    QList<QSerialPortInfo> ports;
#ifdef Q_OS_WIN
    wchar_t target[1024];
    for (int number = 1; number <= 256; ++number) {
        const QString name = QStringLiteral("COM%1").arg(number);
        if (QueryDosDeviceW(reinterpret_cast<LPCWSTR>(name.utf16()), target,
                            static_cast<DWORD>(std::size(target))) != 0)
            ports.append(QSerialPortInfo(name));
    }
#endif
    return ports;
}
