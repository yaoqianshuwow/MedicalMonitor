#pragma once

#include "../protocol/vitalsigns.h"

#include <QObject>
#include <QTimer>
#include <QVector>

class SimulatedDataSource final : public QObject
{
    Q_OBJECT

public:
    explicit SimulatedDataSource(QObject *parent = nullptr);
    void start();
    void stop();
    bool isRunning() const;

signals:
    void waveformBatchReady(const QVector<double> &ecg1,
                            const QVector<double> &ecg2,
                            const QVector<double> &spo2,
                            const QVector<double> &resp);
    void vitalSignsReady(const VitalSigns &signs);
    void sampleForRecording(qint64 timestampMs, double ecg1, double ecg2,
                            double spo2, double resp, const VitalSigns &signs);

private slots:
    void generateFrame();

private:
    static double gaussian(double x, double center, double width);
    double ecgValue(double seconds, double phaseOffset, double amplitude) const;
    double plethValue(double seconds) const;

    QTimer m_timer;
    VitalSigns m_vitals;
    qint64 m_sampleIndex = 0;
    qint64 m_lastVitalsSecond = -1;
};
