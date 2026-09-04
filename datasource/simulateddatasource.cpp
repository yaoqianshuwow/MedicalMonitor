#include "simulateddatasource.h"

#include <QDateTime>
#include <QRandomGenerator>
#include <QtMath>
#include <cmath>

SimulatedDataSource::SimulatedDataSource(QObject *parent)
    : QObject(parent)
{
    m_timer.setTimerType(Qt::PreciseTimer);
    m_timer.setInterval(20);
    connect(&m_timer, &QTimer::timeout, this, &SimulatedDataSource::generateFrame);
}

void SimulatedDataSource::start()
{
    if (!m_timer.isActive())
        m_timer.start();
}

void SimulatedDataSource::stop()
{
    m_timer.stop();
}

bool SimulatedDataSource::isRunning() const
{
    return m_timer.isActive();
}

double SimulatedDataSource::gaussian(double x, double center, double width)
{
    const double d = (x - center) / width;
    return qExp(-0.5 * d * d);
}

double SimulatedDataSource::ecgValue(double seconds, double phaseOffset, double amplitude) const
{
    const double beatPeriod = 60.0 / qMax(40, m_vitals.heartRate);
    double phase = std::fmod(seconds + phaseOffset, beatPeriod) / beatPeriod;
    if (phase < 0.0)
        phase += 1.0;

    const double p = 0.12 * gaussian(phase, 0.18, 0.035);
    const double q = -0.18 * gaussian(phase, 0.36, 0.012);
    const double r = 1.15 * gaussian(phase, 0.40, 0.010);
    const double s = -0.34 * gaussian(phase, 0.435, 0.014);
    const double t = 0.32 * gaussian(phase, 0.66, 0.065);
    const double wander = 0.025 * qSin(seconds * 2.0 * M_PI * 0.28);
    const double noise = (QRandomGenerator::global()->generateDouble() - 0.5) * 0.018;
    return amplitude * (p + q + r + s + t) + wander + noise;
}

double SimulatedDataSource::plethValue(double seconds) const
{
    const double period = 60.0 / qMax(40, m_vitals.pulseRate);
    const double phase = std::fmod(seconds, period) / period;
    const double primary = gaussian(phase, 0.16, 0.085);
    const double notch = -0.13 * gaussian(phase, 0.42, 0.035);
    const double reflected = 0.23 * gaussian(phase, 0.53, 0.09);
    return qBound(0.0, 0.10 + 0.86 * primary + notch + reflected, 1.15);
}

void SimulatedDataSource::generateFrame()
{
    QVector<double> ecg1;
    QVector<double> ecg2;
    QVector<double> spo2;
    QVector<double> resp;
    ecg1.reserve(5);
    ecg2.reserve(5);
    spo2.reserve(2);

    for (int i = 0; i < 5; ++i) {
        const double seconds = (m_sampleIndex + i) / 250.0;
        ecg1.append(ecgValue(seconds, 0.0, 1.0));
        ecg2.append(ecgValue(seconds, 0.018, 0.78));
    }
    for (int i = 0; i < 2; ++i) {
        const double seconds = (m_sampleIndex / 5.0 * 2.0 + i) / 100.0;
        spo2.append(plethValue(seconds));
    }
    if ((m_sampleIndex / 5) % 2 == 0) {
        const double seconds = m_sampleIndex / 250.0;
        resp.append(qSin(seconds * 2.0 * M_PI * m_vitals.respirationRate / 60.0));
    }

    m_sampleIndex += 5;
    const qint64 currentSecond = m_sampleIndex / 250;
    if (currentSecond != m_lastVitalsSecond) {
        m_lastVitalsSecond = currentSecond;
        const double time = currentSecond;
        // 各参数按独立周期刷新，避免把全部指标绑定为同一个“整包”节拍。
        m_vitals.heartRate = 72 + qRound(2.0 * qSin(time * 0.31));
        m_vitals.pulseRate = m_vitals.heartRate;
        if (currentSecond % 2 == 0)
            m_vitals.spo2 = qBound(95, 98 + qRound(qSin(time * 0.17)), 99);
        if (currentSecond % 3 == 0)
            m_vitals.respirationRate = 16 + qRound(qSin(time * 0.22));
        if (currentSecond % 5 == 0) {
            m_vitals.temperature1 = 36.7 + 0.12 * qSin(time * 0.05);
            m_vitals.temperature2 = 36.8 + 0.10 * qSin(time * 0.043 + 0.8);
        }
        emit vitalSignsReady(m_vitals);
    }

    emit waveformBatchReady(ecg1, ecg2, spo2, resp);
    emit sampleForRecording(QDateTime::currentMSecsSinceEpoch(), ecg1.constLast(), ecg2.constLast(),
                            spo2.constLast(), resp.isEmpty() ? 0.0 : resp.constLast(), m_vitals);
}
