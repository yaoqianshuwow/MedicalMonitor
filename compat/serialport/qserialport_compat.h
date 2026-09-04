#pragma once

#include <QByteArray>
#include <QIODevice>
#include <QList>
#include <QString>
#include <QTimer>

class QSerialPort final : public QIODevice
{
    Q_OBJECT

public:
    enum SerialPortError {
        NoError, DeviceNotFoundError, PermissionError, OpenError,
        WriteError, ReadError, ResourceError, UnknownError
    };
    Q_ENUM(SerialPortError)

    enum DataBits { Data5 = 5, Data6 = 6, Data7 = 7, Data8 = 8 };
    Q_ENUM(DataBits)
    enum Parity { NoParity = 0, EvenParity = 2, OddParity = 3, SpaceParity = 4, MarkParity = 5 };
    Q_ENUM(Parity)
    enum StopBits { OneStop = 1, OneAndHalfStop = 3, TwoStop = 2 };
    Q_ENUM(StopBits)
    enum FlowControl { NoFlowControl, HardwareControl, SoftwareControl };
    Q_ENUM(FlowControl)

    explicit QSerialPort(QObject *parent = nullptr);
    ~QSerialPort() override;

    void setPortName(const QString &name);
    QString portName() const;
    bool setBaudRate(qint32 baudRate);
    bool setDataBits(DataBits dataBits);
    bool setParity(Parity parity);
    bool setStopBits(StopBits stopBits);
    bool setFlowControl(FlowControl flowControl);

    bool open(OpenMode mode) override;
    void close() override;
    qint64 bytesAvailable() const override;
    bool isSequential() const override { return true; }
    SerialPortError error() const { return m_error; }

signals:
    void errorOccurred(QSerialPort::SerialPortError error);

protected:
    qint64 readData(char *data, qint64 maxSize) override;
    qint64 writeData(const char *data, qint64 maxSize) override;

private slots:
    void pollInput();

private:
    void setSerialError(SerialPortError error, const QString &message);

    QString m_portName;
    qint32 m_baudRate = 115200;
    DataBits m_dataBits = Data8;
    Parity m_parity = NoParity;
    StopBits m_stopBits = OneStop;
    FlowControl m_flowControl = NoFlowControl;
    SerialPortError m_error = NoError;
    QByteArray m_readBuffer;
    QTimer m_pollTimer;
    void *m_handle = nullptr;
};

class QSerialPortInfo
{
public:
    QSerialPortInfo() = default;
    explicit QSerialPortInfo(const QString &portName)
        : m_portName(portName) {}

    QString portName() const { return m_portName; }
    QString description() const { return m_description; }
    static QList<QSerialPortInfo> availablePorts();

private:
    QString m_portName;
    QString m_description = QStringLiteral("Windows serial port");
};
