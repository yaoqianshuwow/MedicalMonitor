#pragma once

#include <QDialog>
#include <QTimer>

class QLabel;
class QPushButton;

class BloodPressureDialog final : public QDialog
{
    Q_OBJECT

public:
    explicit BloodPressureDialog(QWidget *parent = nullptr);
    void setSerialMode(bool serialMode, bool portOpen);

signals:
    void cuffPressureChanged(int pressure);
    void measurementFinished(int systolic, int diastolic, int meanPressure, int pulseRate);
    void serialCommandRequested(const QByteArray &command);

private slots:
    void startMeasurement();
    void stopMeasurement();
    void advanceSimulation();

private:
    void resetUi(const QString &message);

    QLabel *m_pressureLabel = nullptr;
    QLabel *m_resultLabel = nullptr;
    QLabel *m_phaseLabel = nullptr;
    QPushButton *m_startButton = nullptr;
    QPushButton *m_stopButton = nullptr;
    QTimer m_timer;
    int m_pressure = 0;
    int m_phase = 0;
    bool m_serialMode = false;
    bool m_portOpen = false;
};
