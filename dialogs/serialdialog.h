#pragma once

#include <QDialog>
#include <QSerialPort>

class QComboBox;
class QLabel;
class QPushButton;

class SerialDialog final : public QDialog
{
    Q_OBJECT

public:
    explicit SerialDialog(QWidget *parent = nullptr);
    void setPortOpen(bool open, const QString &detail = QString());

signals:
    void simulationRequested();
    void openPortRequested(const QString &portName, qint32 baudRate,
                           QSerialPort::DataBits dataBits,
                           QSerialPort::Parity parity,
                           QSerialPort::StopBits stopBits);
    void closePortRequested();

private slots:
    void refreshPorts();
    void requestToggle();

private:
    QComboBox *m_portBox = nullptr;
    QComboBox *m_baudBox = nullptr;
    QComboBox *m_dataBitsBox = nullptr;
    QComboBox *m_parityBox = nullptr;
    QComboBox *m_stopBitsBox = nullptr;
    QLabel *m_stateLabel = nullptr;
    QPushButton *m_toggleButton = nullptr;
    bool m_isOpen = false;
};
