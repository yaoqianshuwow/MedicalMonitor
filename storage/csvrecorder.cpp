#include "csvrecorder.h"

#include <QDateTime>

CsvRecorder::CsvRecorder(QObject *parent)
    : QObject(parent)
{
}

CsvRecorder::~CsvRecorder()
{
    stop();
}

bool CsvRecorder::start(const QString &fileName, QString *errorMessage)
{
    stop();
    m_file.setFileName(fileName);
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        if (errorMessage)
            *errorMessage = m_file.errorString();
        return false;
    }
    m_stream.setDevice(&m_file);
    m_stream << "timestamp_iso,source,ecg1,ecg2,spo2_wave,resp_wave,heart_rate,"
                "systolic,diastolic,mean_pressure,pulse_rate,spo2,respiration_rate,"
                "temperature1,temperature2,cuff_pressure,raw_hex\n";
    m_stream.flush();
    m_rows = 0;
    return true;
}

void CsvRecorder::stop()
{
    if (m_file.isOpen()) {
        m_stream.flush();
        m_stream.setDevice(nullptr);
        m_file.close();
    }
}

bool CsvRecorder::isRecording() const { return m_file.isOpen(); }
QString CsvRecorder::fileName() const { return m_file.fileName(); }
qint64 CsvRecorder::rowCount() const { return m_rows; }

void CsvRecorder::recordSample(qint64 timestampMs, double ecg1, double ecg2,
                               double spo2, double resp, const VitalSigns &v)
{
    if (!m_file.isOpen())
        return;
    m_stream << QDateTime::fromMSecsSinceEpoch(timestampMs, Qt::UTC).toString(Qt::ISODateWithMs)
             << ",simulation," << QString::number(ecg1, 'f', 5)
             << ',' << QString::number(ecg2, 'f', 5)
             << ',' << QString::number(spo2, 'f', 5)
             << ',' << QString::number(resp, 'f', 5)
             << ',' << v.heartRate << ',' << v.systolic << ',' << v.diastolic
             << ',' << v.meanPressure << ',' << v.pulseRate << ',' << v.spo2
             << ',' << v.respirationRate << ',' << QString::number(v.temperature1, 'f', 1)
             << ',' << QString::number(v.temperature2, 'f', 1) << ',' << v.cuffPressure << ",\n";
    if (++m_rows % 50 == 0)
        m_stream.flush();
}

void CsvRecorder::recordSerialBytes(const QByteArray &bytes)
{
    if (!m_file.isOpen() || bytes.isEmpty())
        return;
    m_stream << QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs)
             << ",serial,,,,,,,,,,,,,,," << bytes.toHex(' ').toUpper() << '\n';
    ++m_rows;
    m_stream.flush();
}
