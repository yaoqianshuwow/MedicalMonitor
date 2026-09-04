#include "serialdialog.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSerialPortInfo>
#include <QVBoxLayout>

SerialDialog::SerialDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(QStringLiteral("串口与数据源设置"));
    setMinimumWidth(430);

    m_portBox = new QComboBox(this);
    auto *refreshButton = new QPushButton(QStringLiteral("刷新"), this);
    auto *portRow = new QHBoxLayout;
    portRow->addWidget(m_portBox, 1);
    portRow->addWidget(refreshButton);

    m_baudBox = new QComboBox(this);
    const QList<qint32> baudRates {9600, 19200, 38400, 57600, 115200, 230400};
    for (qint32 rate : baudRates)
        m_baudBox->addItem(QString::number(rate), rate);
    m_baudBox->setCurrentText(QStringLiteral("115200"));

    m_dataBitsBox = new QComboBox(this);
    m_dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    m_dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);

    m_parityBox = new QComboBox(this);
    m_parityBox->addItem(QStringLiteral("无校验"), QSerialPort::NoParity);
    m_parityBox->addItem(QStringLiteral("偶校验"), QSerialPort::EvenParity);
    m_parityBox->addItem(QStringLiteral("奇校验"), QSerialPort::OddParity);

    m_stopBitsBox = new QComboBox(this);
    m_stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    m_stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    auto *form = new QFormLayout;
    form->addRow(QStringLiteral("端口"), portRow);
    form->addRow(QStringLiteral("波特率"), m_baudBox);
    form->addRow(QStringLiteral("数据位"), m_dataBitsBox);
    form->addRow(QStringLiteral("校验位"), m_parityBox);
    form->addRow(QStringLiteral("停止位"), m_stopBitsBox);

    m_stateLabel = new QLabel(QStringLiteral("当前：模拟数据（串口未打开）"), this);
    m_stateLabel->setWordWrap(true);
    m_toggleButton = new QPushButton(QStringLiteral("打开串口"), this);
    auto *simulationButton = new QPushButton(QStringLiteral("切换到模拟数据"), this);
    auto *closeButton = new QPushButton(QStringLiteral("关闭"), this);

    auto *buttons = new QHBoxLayout;
    buttons->addWidget(simulationButton);
    buttons->addStretch();
    buttons->addWidget(m_toggleButton);
    buttons->addWidget(closeButton);

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(m_stateLabel);
    layout->addLayout(buttons);

    connect(refreshButton, &QPushButton::clicked, this, &SerialDialog::refreshPorts);
    connect(m_toggleButton, &QPushButton::clicked, this, &SerialDialog::requestToggle);
    connect(simulationButton, &QPushButton::clicked, this, [this] {
        emit simulationRequested();
    });
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    refreshPorts();
}

void SerialDialog::refreshPorts()
{
    const QString previous = m_portBox->currentData().toString();
    m_portBox->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        QString label = port.portName();
        if (!port.description().isEmpty())
            label += QStringLiteral(" — ") + port.description();
        m_portBox->addItem(label, port.portName());
    }
    const int previousIndex = m_portBox->findData(previous);
    if (previousIndex >= 0)
        m_portBox->setCurrentIndex(previousIndex);
    if (m_portBox->count() == 0)
        m_portBox->addItem(QStringLiteral("未发现串口"), QString());
}

void SerialDialog::requestToggle()
{
    if (m_isOpen) {
        emit closePortRequested();
        return;
    }
    const QString portName = m_portBox->currentData().toString();
    if (portName.isEmpty()) {
        m_stateLabel->setText(QStringLiteral("没有可打开的串口，请连接设备后刷新。"));
        return;
    }
    emit openPortRequested(portName, m_baudBox->currentData().toInt(),
                           static_cast<QSerialPort::DataBits>(m_dataBitsBox->currentData().toInt()),
                           static_cast<QSerialPort::Parity>(m_parityBox->currentData().toInt()),
                           static_cast<QSerialPort::StopBits>(m_stopBitsBox->currentData().toInt()));
}

void SerialDialog::setPortOpen(bool open, const QString &detail)
{
    m_isOpen = open;
    m_toggleButton->setText(open ? QStringLiteral("关闭串口") : QStringLiteral("打开串口"));
    m_stateLabel->setText(detail.isEmpty()
        ? (open ? QStringLiteral("串口已打开") : QStringLiteral("当前：模拟数据（串口未打开）"))
        : detail);
}
