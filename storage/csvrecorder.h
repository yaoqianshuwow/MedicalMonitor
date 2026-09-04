#pragma once

#include "../protocol/vitalsigns.h"

#include <QFile>
#include <QObject>
#include <QTextStream>

class CsvRecorder final : public QObject
{
    Q_OBJECT

public:
    explicit CsvRecorder(QObject *parent = nullptr);
    ~CsvRecorder() override;

    bool start(const QString &fileName, QString *errorMessage = nullptr);
    void stop();
    bool isRecording() const;
    QString fileName() const;
    qint64 rowCount() const;

public slots:
    void recordSample(qint64 timestampMs, double ecg1, double ecg2,
                      double spo2, double resp, const VitalSigns &signs);
    void recordSerialBytes(const QByteArray &bytes);

private:
    QFile m_file;
    QTextStream m_stream;
    qint64 m_rows = 0;
};
