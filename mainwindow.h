#pragma once

#include "protocol/vitalsigns.h"

#include <QMainWindow>
#include <QSerialPort>
#include <QVector>

class QAction;
class BloodPressureDialog;
class CsvRecorder;
class QLabel;
class QTimer;
class SerialDialog;
class SimulatedDataSource;
class VitalCard;
class WaveformWidget;

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void updateWaveforms(const QVector<double> &ecg1, const QVector<double> &ecg2,
                         const QVector<double> &spo2, const QVector<double> &resp);
    void updateVitalSigns(const VitalSigns &signs);
    void showSerialDialog();
    void openSerialPort(const QString &name, qint32 baudRate,
                        QSerialPort::DataBits dataBits, QSerialPort::Parity parity,
                        QSerialPort::StopBits stopBits);
    void closeSerialPort();
    void useSimulation();
    void readSerialData();
    void showBloodPressureDialog();
    void updateBloodPressure(int systolic, int diastolic, int mean, int pulse);
    void updateCuffPressure(int pressure);
    void sendSerialCommand(const QByteArray &command);
    void toggleRecording();

private:
    void buildInterface();
    void buildMenus();
    void applyTheme();
    void setDataSourceLabel(const QString &text, bool simulation);
    void stopRecording();

    WaveformWidget *m_ecg1Wave = nullptr;
    WaveformWidget *m_ecg2Wave = nullptr;
    WaveformWidget *m_spo2Wave = nullptr;
    WaveformWidget *m_respWave = nullptr;
    VitalCard *m_hrCard = nullptr;
    VitalCard *m_bpCard = nullptr;
    VitalCard *m_spo2Card = nullptr;
    VitalCard *m_respCard = nullptr;
    VitalCard *m_tempCard = nullptr;
    QLabel *m_sourceLabel = nullptr;
    QLabel *m_clockLabel = nullptr;
    QAction *m_recordAction = nullptr;

    SimulatedDataSource *m_simulator = nullptr;
    CsvRecorder *m_recorder = nullptr;
    QSerialPort *m_serial = nullptr;
    SerialDialog *m_serialDialog = nullptr;
    BloodPressureDialog *m_bpDialog = nullptr;
    QTimer *m_clockTimer = nullptr;
    VitalSigns m_vitals;
    bool m_simulationMode = true;
};
