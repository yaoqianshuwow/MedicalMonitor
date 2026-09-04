#include "bloodpressuredialog.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRandomGenerator>
#include <QVBoxLayout>

BloodPressureDialog::BloodPressureDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(QStringLiteral("无创血压测量"));
    setMinimumWidth(430);

    auto *title = new QLabel(QStringLiteral("袖带压力"), this);
    m_pressureLabel = new QLabel(QStringLiteral("0 mmHg"), this);
    m_pressureLabel->setAlignment(Qt::AlignCenter);
    m_pressureLabel->setStyleSheet(QStringLiteral("font-size:42px;font-weight:700;color:#ffdf5d;"));
    m_phaseLabel = new QLabel(QStringLiteral("准备就绪（模拟模式）"), this);
    m_phaseLabel->setAlignment(Qt::AlignCenter);
    m_resultLabel = new QLabel(QStringLiteral("最近结果：120 / 78 mmHg　MAP 92　PR 72"), this);
    m_resultLabel->setAlignment(Qt::AlignCenter);

    m_startButton = new QPushButton(QStringLiteral("开始测量"), this);
    m_stopButton = new QPushButton(QStringLiteral("停止测量"), this);
    m_stopButton->setEnabled(false);
    auto *closeButton = new QPushButton(QStringLiteral("关闭"), this);
    auto *buttons = new QHBoxLayout;
    buttons->addWidget(m_startButton);
    buttons->addWidget(m_stopButton);
    buttons->addStretch();
    buttons->addWidget(closeButton);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(title, 0, Qt::AlignCenter);
    layout->addWidget(m_pressureLabel);
    layout->addWidget(m_phaseLabel);
    layout->addWidget(m_resultLabel);
    layout->addSpacing(12);
    layout->addLayout(buttons);

    m_timer.setInterval(100);
    connect(&m_timer, &QTimer::timeout, this, &BloodPressureDialog::advanceSimulation);
    connect(m_startButton, &QPushButton::clicked, this, &BloodPressureDialog::startMeasurement);
    connect(m_stopButton, &QPushButton::clicked, this, &BloodPressureDialog::stopMeasurement);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

void BloodPressureDialog::setSerialMode(bool serialMode, bool portOpen)
{
    m_serialMode = serialMode;
    m_portOpen = portOpen;
    if (serialMode)
        m_phaseLabel->setText(portOpen ? QStringLiteral("真实串口模式：设备命令已启用")
                                       : QStringLiteral("真实串口模式：请先打开串口"));
    else
        m_phaseLabel->setText(QStringLiteral("准备就绪（模拟模式）"));
}

void BloodPressureDialog::startMeasurement()
{
    if (m_serialMode) {
        if (!m_portOpen) {
            m_phaseLabel->setText(QStringLiteral("无法开始：串口未打开"));
            return;
        }
        emit serialCommandRequested(QByteArray::fromHex("140180"));
        m_phaseLabel->setText(QStringLiteral("启动命令已发送，等待设备数据…"));
        m_startButton->setEnabled(false);
        m_stopButton->setEnabled(true);
        return;
    }

    m_pressure = 0;
    m_phase = 1;
    m_startButton->setEnabled(false);
    m_stopButton->setEnabled(true);
    m_resultLabel->setText(QStringLiteral("测量中，请保持静止…"));
    m_timer.start();
}

void BloodPressureDialog::stopMeasurement()
{
    if (m_serialMode && m_portOpen)
        emit serialCommandRequested(QByteArray::fromHex("140181"));
    m_timer.stop();
    m_pressure = 0;
    emit cuffPressureChanged(0);
    resetUi(QStringLiteral("测量已停止"));
}

void BloodPressureDialog::advanceSimulation()
{
    if (m_phase == 1) {
        m_pressure += 5;
        m_phaseLabel->setText(QStringLiteral("袖带充气中…"));
        if (m_pressure >= 170)
            m_phase = 2;
    } else {
        m_pressure -= 2;
        m_phaseLabel->setText(QStringLiteral("缓慢放气并分析脉搏波…"));
        if (m_pressure <= 35) {
            m_timer.stop();
            m_pressure = 0;
            const int systolic = 118 + QRandomGenerator::global()->bounded(7);
            const int diastolic = 75 + QRandomGenerator::global()->bounded(7);
            const int mean = qRound((systolic + 2.0 * diastolic) / 3.0);
            const int pulse = 70 + QRandomGenerator::global()->bounded(7);
            m_resultLabel->setText(QStringLiteral("结果：%1 / %2 mmHg　MAP %3　PR %4")
                                   .arg(systolic).arg(diastolic).arg(mean).arg(pulse));
            emit cuffPressureChanged(0);
            emit measurementFinished(systolic, diastolic, mean, pulse);
            resetUi(QStringLiteral("测量完成"));
            return;
        }
    }
    m_pressureLabel->setText(QStringLiteral("%1 mmHg").arg(m_pressure));
    emit cuffPressureChanged(m_pressure);
}

void BloodPressureDialog::resetUi(const QString &message)
{
    m_pressureLabel->setText(QStringLiteral("0 mmHg"));
    m_phaseLabel->setText(message);
    m_startButton->setEnabled(true);
    m_stopButton->setEnabled(false);
    m_phase = 0;
}
