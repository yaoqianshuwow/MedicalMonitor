#include "mainwindow.h"

#include "datasource/simulateddatasource.h"
#include "dialogs/bloodpressuredialog.h"
#include "dialogs/serialdialog.h"
#include "storage/csvrecorder.h"
#include "widgets/vitalcard.h"
#include "widgets/waveformwidget.h"

#include <QAction>
#include <QCloseEvent>
#include <QDateTime>
#include <QEvent>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QScrollArea>
#include <QSplitter>
#include <QStandardPaths>
#include <QStatusBar>
#include <QTimer>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_simulator(new SimulatedDataSource(this)),
      m_recorder(new CsvRecorder(this)),
      m_serial(new QSerialPort(this)),
      m_serialDialog(new SerialDialog(this)),
      m_bpDialog(new BloodPressureDialog(this)),
      m_clockTimer(new QTimer(this))
{
    buildInterface();
    buildMenus();
    applyTheme();

    connect(m_simulator, &SimulatedDataSource::waveformBatchReady,
            this, &MainWindow::updateWaveforms);
    connect(m_simulator, &SimulatedDataSource::vitalSignsReady,
            this, &MainWindow::updateVitalSigns);
    connect(m_simulator, &SimulatedDataSource::sampleForRecording,
            m_recorder, &CsvRecorder::recordSample);

    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
    connect(m_serial, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError error) {
        if (error == QSerialPort::NoError)
            return;
        statusBar()->showMessage(QStringLiteral("串口错误：%1").arg(m_serial->errorString()), 8000);
        if (error == QSerialPort::ResourceError)
            closeSerialPort();
    });

    connect(m_serialDialog, &SerialDialog::openPortRequested,
            this, &MainWindow::openSerialPort);
    connect(m_serialDialog, &SerialDialog::closePortRequested,
            this, &MainWindow::closeSerialPort);
    connect(m_serialDialog, &SerialDialog::simulationRequested,
            this, &MainWindow::useSimulation);

    connect(m_bpDialog, &BloodPressureDialog::cuffPressureChanged,
            this, &MainWindow::updateCuffPressure);
    connect(m_bpDialog, &BloodPressureDialog::measurementFinished,
            this, &MainWindow::updateBloodPressure);
    connect(m_bpDialog, &BloodPressureDialog::serialCommandRequested,
            this, &MainWindow::sendSerialCommand);

    connect(m_clockTimer, &QTimer::timeout, this, [this] {
        m_clockLabel->setText(QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd  HH:mm:ss")));
    });
    m_clockTimer->start(1000);
    m_clockLabel->setText(QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd  HH:mm:ss")));

    resize(1360, 850);
    setMinimumSize(1080, 700);
    setWindowTitle(QStringLiteral("MedicalMonitor — Qt 医用参数监护教学演示"));
    statusBar()->showMessage(QStringLiteral("模拟数据源运行中｜无需连接硬件"));
    updateVitalSigns(m_vitals);
    m_simulator->start();
}

MainWindow::~MainWindow()
{
    m_simulator->stop();
    stopRecording();
    if (m_serial->isOpen())
        m_serial->close();
}

void MainWindow::buildInterface()
{
    auto *central = new QWidget(this);
    auto *root = new QVBoxLayout(central);
    root->setContentsMargins(10, 8, 10, 8);
    root->setSpacing(8);

    auto *brand = new QLabel(QStringLiteral("MEDICAL MONITOR  /  教学演示"), central);
    brand->setObjectName(QStringLiteral("brandLabel"));
    m_sourceLabel = new QLabel(QStringLiteral("● SIM 模拟数据"), central);
    m_sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
    m_clockLabel = new QLabel(central);
    auto *header = new QHBoxLayout;
    header->addWidget(brand);
    header->addStretch();
    header->addWidget(m_sourceLabel);
    header->addSpacing(24);
    header->addWidget(m_clockLabel);
    root->addLayout(header);

    auto *notice = new QLabel(QStringLiteral("教学演示，所有数值均为模拟数据，不用于医疗诊断或临床决策。"), central);
    notice->setObjectName(QStringLiteral("noticeLabel"));
    notice->setAlignment(Qt::AlignCenter);
    root->addWidget(notice);

    m_ecg1Wave = new WaveformWidget(QStringLiteral("ECG1  I"), QColor("#55f59b"), -0.55, 1.25, central);
    m_ecg2Wave = new WaveformWidget(QStringLiteral("ECG2  II"), QColor("#74f1c2"), -0.55, 1.25, central);
    m_spo2Wave = new WaveformWidget(QStringLiteral("SpO₂  Pleth"), QColor("#54d8ff"), -0.05, 1.15, central);
    m_respWave = new WaveformWidget(QStringLiteral("RESP"), QColor("#ffe45e"), -1.2, 1.2, central);

    auto *wavePanel = new QWidget(central);
    wavePanel->setMinimumWidth(650);
    auto *waveLayout = new QVBoxLayout(wavePanel);
    waveLayout->setContentsMargins(0, 0, 0, 0);
    waveLayout->setSpacing(5);
    waveLayout->addWidget(m_ecg1Wave);
    waveLayout->addWidget(m_ecg2Wave);
    waveLayout->addWidget(m_spo2Wave);
    waveLayout->addWidget(m_respWave);

    m_hrCard = new VitalCard(QStringLiteral("心率 HR"), QStringLiteral("bpm"), QColor("#55f59b"), central);
    m_bpCard = new VitalCard(QStringLiteral("无创血压 NIBP"), QStringLiteral("mmHg"), QColor("#ffdf5d"), central);
    m_bpCard->setCursor(Qt::PointingHandCursor);
    m_bpCard->installEventFilter(this);
    m_spo2Card = new VitalCard(QStringLiteral("血氧 SpO₂"), QStringLiteral("%"), QColor("#54d8ff"), central);
    m_respCard = new VitalCard(QStringLiteral("呼吸 RESP"), QStringLiteral("rpm"), QColor("#ffe45e"), central);
    m_tempCard = new VitalCard(QStringLiteral("双路体温 TEMP"), QStringLiteral("℃"), QColor("#ff8eb4"), central);

    auto *cardPanel = new QWidget(central);
    cardPanel->setMinimumWidth(285);
    cardPanel->setMaximumWidth(360);
    auto *cardLayout = new QVBoxLayout(cardPanel);
    cardLayout->setContentsMargins(0, 0, 0, 0);
    cardLayout->setSpacing(5);
    cardLayout->addWidget(m_hrCard);
    cardLayout->addWidget(m_bpCard);
    cardLayout->addWidget(m_spo2Card);
    cardLayout->addWidget(m_respCard);
    cardLayout->addWidget(m_tempCard);
    cardLayout->addStretch();

    auto *splitter = new QSplitter(Qt::Horizontal, central);
    splitter->addWidget(wavePanel);
    splitter->addWidget(cardPanel);
    splitter->setStretchFactor(0, 5);
    splitter->setStretchFactor(1, 1);
    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);
    splitter->setSizes(QList<int> {1000, 310});
    root->addWidget(splitter, 1);
    setCentralWidget(central);
}

void MainWindow::buildMenus()
{
    auto *dataMenu = menuBar()->addMenu(QStringLiteral("数据源(&D)"));
    auto *serialAction = dataMenu->addAction(QStringLiteral("串口设置…"));
    auto *simulationAction = dataMenu->addAction(QStringLiteral("使用模拟数据"));
    connect(serialAction, &QAction::triggered, this, &MainWindow::showSerialDialog);
    connect(simulationAction, &QAction::triggered, this, &MainWindow::useSimulation);

    auto *measureMenu = menuBar()->addMenu(QStringLiteral("测量(&M)"));
    auto *bpAction = measureMenu->addAction(QStringLiteral("无创血压测量…"));
    connect(bpAction, &QAction::triggered, this, &MainWindow::showBloodPressureDialog);

    auto *storageMenu = menuBar()->addMenu(QStringLiteral("存储(&S)"));
    m_recordAction = storageMenu->addAction(QStringLiteral("开始 CSV 记录…"));
    connect(m_recordAction, &QAction::triggered, this, &MainWindow::toggleRecording);

    auto *helpMenu = menuBar()->addMenu(QStringLiteral("帮助(&H)"));
    auto *aboutAction = helpMenu->addAction(QStringLiteral("关于教学演示"));
    connect(aboutAction, &QAction::triggered, this, [this] {
        QMessageBox::about(this, QStringLiteral("关于 MedicalMonitor"),
            QStringLiteral("<h3>MedicalMonitor</h3>"
                           "<p>基于 Qt 6 Widgets 的医用参数监护教学项目。</p>"
                           "<p><b>教学演示，模拟数据不用于医疗诊断或临床决策。</b></p>"
                           "<p>演示内容：四路连续扫描波形、生命体征、NIBP 流程、串口设置与 CSV 保存。</p>"));
    });
    helpMenu->addSeparator();
    auto *exitAction = helpMenu->addAction(QStringLiteral("退出"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::applyTheme()
{
    setStyleSheet(QStringLiteral(R"(
        QMainWindow, QWidget { background:#081319; color:#d8e3e8; }
        QMenuBar { background:#0c1e27; padding:4px; }
        QMenuBar::item:selected, QMenu::item:selected { background:#19404d; }
        QMenu { background:#10252e; border:1px solid #31515c; }
        QMenu::item { padding:7px 28px; }
        #brandLabel { font-size:17px; font-weight:700; color:#e9f7fb; }
        #sourceLabel { color:#65f4a3; font-weight:600; }
        #noticeLabel { background:#3e3211; color:#ffe685; border:1px solid #766022;
                       border-radius:4px; padding:5px; }
        #vitalCard { background:#0c1d24; border:1px solid #24414b; border-radius:6px; }
        QPushButton { background:#183744; border:1px solid #386171; border-radius:4px;
                      padding:7px 13px; }
        QPushButton:hover { background:#235165; }
        QPushButton:disabled { color:#63757c; background:#12262e; }
        QComboBox { background:#102832; border:1px solid #385663; padding:5px; }
        QStatusBar { background:#0c1e27; color:#a9bbc2; }
        QSplitter::handle { background:#17313b; width:3px; }
    )"));
}

void MainWindow::updateWaveforms(const QVector<double> &ecg1, const QVector<double> &ecg2,
                                 const QVector<double> &spo2, const QVector<double> &resp)
{
    m_ecg1Wave->appendSamples(ecg1);
    m_ecg2Wave->appendSamples(ecg2);
    m_spo2Wave->appendSamples(spo2);
    m_respWave->appendSamples(resp);
}

void MainWindow::updateVitalSigns(const VitalSigns &signs)
{
    const int previousCuff = m_vitals.cuffPressure;
    m_vitals = signs;
    m_vitals.cuffPressure = previousCuff;
    m_hrCard->setValue(QString::number(m_vitals.heartRate));
    m_hrCard->setSecondaryText(QStringLiteral("导联：I / II 已连接"));
    m_bpCard->setValue(QStringLiteral("%1/%2").arg(m_vitals.systolic).arg(m_vitals.diastolic));
    m_bpCard->setSecondaryText(QStringLiteral("MAP %1　PR %2　点击菜单测量")
                               .arg(m_vitals.meanPressure).arg(m_vitals.pulseRate));
    m_spo2Card->setValue(QString::number(m_vitals.spo2));
    m_spo2Card->setSecondaryText(QStringLiteral("探头：已连接　PR %1").arg(m_vitals.pulseRate));
    m_respCard->setValue(QString::number(m_vitals.respirationRate));
    m_respCard->setSecondaryText(QStringLiteral("阻抗呼吸：正常"));
    m_tempCard->setValue(QStringLiteral("%1 / %2")
                         .arg(m_vitals.temperature1, 0, 'f', 1)
                         .arg(m_vitals.temperature2, 0, 'f', 1));
    m_tempCard->setSecondaryText(QStringLiteral("T1 / T2 探头已连接"));
}

void MainWindow::showSerialDialog()
{
    m_serialDialog->setPortOpen(m_serial->isOpen(),
        m_serial->isOpen() ? QStringLiteral("串口 %1 已打开").arg(m_serial->portName())
                           : QStringLiteral("当前：%1").arg(m_simulationMode ? QStringLiteral("模拟数据")
                                                                            : QStringLiteral("串口未打开")));
    m_serialDialog->show();
    m_serialDialog->raise();
    m_serialDialog->activateWindow();
}

void MainWindow::openSerialPort(const QString &name, qint32 baudRate,
                                QSerialPort::DataBits dataBits, QSerialPort::Parity parity,
                                QSerialPort::StopBits stopBits)
{
    if (m_serial->isOpen())
        m_serial->close();
    m_serial->setPortName(name);
    m_serial->setBaudRate(baudRate);
    m_serial->setDataBits(dataBits);
    m_serial->setParity(parity);
    m_serial->setStopBits(stopBits);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (!m_serial->open(QIODevice::ReadWrite)) {
        const QString message = QStringLiteral("打开 %1 失败：%2").arg(name, m_serial->errorString());
        m_serialDialog->setPortOpen(false, message);
        statusBar()->showMessage(message, 8000);
        return;
    }
    m_simulator->stop();
    m_simulationMode = false;
    setDataSourceLabel(QStringLiteral("● SERIAL %1 @ %2").arg(name).arg(baudRate), false);
    m_serialDialog->setPortOpen(true, QStringLiteral("串口 %1 已打开").arg(name));
    statusBar()->showMessage(QStringLiteral("真实串口数据源：%1 @ %2").arg(name).arg(baudRate));
}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    m_serialDialog->setPortOpen(false, QStringLiteral("串口已关闭"));
    if (!m_simulationMode)
        statusBar()->showMessage(QStringLiteral("串口已关闭；可从数据源菜单恢复模拟数据"));
}

void MainWindow::useSimulation()
{
    if (m_serial->isOpen())
        m_serial->close();
    m_simulationMode = true;
    m_simulator->start();
    m_serialDialog->setPortOpen(false, QStringLiteral("当前：模拟数据（串口已关闭）"));
    setDataSourceLabel(QStringLiteral("● SIM 模拟数据"), true);
    statusBar()->showMessage(QStringLiteral("模拟数据源运行中｜无需连接硬件"));
}

void MainWindow::readSerialData()
{
    const QByteArray bytes = m_serial->readAll();
    m_recorder->recordSerialBytes(bytes);
    statusBar()->showMessage(QStringLiteral("串口接收 %1 字节（原始数据可记录到 CSV）").arg(bytes.size()), 2500);
}

void MainWindow::showBloodPressureDialog()
{
    m_bpDialog->setSerialMode(!m_simulationMode, m_serial->isOpen());
    m_bpDialog->show();
    m_bpDialog->raise();
    m_bpDialog->activateWindow();
}

void MainWindow::updateBloodPressure(int systolic, int diastolic, int mean, int pulse)
{
    m_vitals.systolic = systolic;
    m_vitals.diastolic = diastolic;
    m_vitals.meanPressure = mean;
    m_vitals.pulseRate = pulse;
    m_bpCard->setValue(QStringLiteral("%1/%2").arg(systolic).arg(diastolic));
    m_bpCard->setSecondaryText(QStringLiteral("MAP %1　PR %2　测量完成").arg(mean).arg(pulse));
    statusBar()->showMessage(QStringLiteral("NIBP 测量完成：%1/%2 mmHg").arg(systolic).arg(diastolic), 6000);
}

void MainWindow::updateCuffPressure(int pressure)
{
    m_vitals.cuffPressure = pressure;
    if (pressure > 0)
        m_bpCard->setSecondaryText(QStringLiteral("测量中｜袖带压力 %1 mmHg").arg(pressure));
}

void MainWindow::sendSerialCommand(const QByteArray &command)
{
    if (!m_serial->isOpen()) {
        statusBar()->showMessage(QStringLiteral("命令未发送：串口未打开"), 5000);
        return;
    }
    const qint64 written = m_serial->write(command);
    statusBar()->showMessage(written >= 0 ? QStringLiteral("血压控制命令已发送")
                                          : QStringLiteral("血压控制命令发送失败"), 4000);
}

void MainWindow::toggleRecording()
{
    if (m_recorder->isRecording()) {
        const QString file = m_recorder->fileName();
        const qint64 rows = m_recorder->rowCount();
        stopRecording();
        statusBar()->showMessage(QStringLiteral("CSV 已保存：%1（%2 行）").arg(file).arg(rows), 8000);
        return;
    }

    const QString directory = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    const QString defaultName = directory + QStringLiteral("/medical-monitor-%1.csv")
        .arg(QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMdd-HHmmss")));
    const QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("保存采集数据"),
                                                          defaultName, QStringLiteral("CSV 文件 (*.csv)"));
    if (fileName.isEmpty())
        return;
    QString error;
    if (!m_recorder->start(fileName, &error)) {
        QMessageBox::critical(this, QStringLiteral("无法保存"), error);
        return;
    }
    m_recordAction->setText(QStringLiteral("停止 CSV 记录"));
    statusBar()->showMessage(QStringLiteral("正在记录 CSV：%1").arg(fileName));
}

void MainWindow::stopRecording()
{
    if (m_recorder->isRecording())
        m_recorder->stop();
    if (m_recordAction)
        m_recordAction->setText(QStringLiteral("开始 CSV 记录…"));
}

void MainWindow::setDataSourceLabel(const QString &text, bool simulation)
{
    m_sourceLabel->setText(text);
    m_sourceLabel->setStyleSheet(simulation ? QStringLiteral("color:#65f4a3;font-weight:600;")
                                            : QStringLiteral("color:#54d8ff;font-weight:600;"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_simulator->stop();
    m_clockTimer->stop();
    if (m_serial->isOpen())
        m_serial->close();
    stopRecording();
    QMainWindow::closeEvent(event);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_bpCard && event->type() == QEvent::MouseButtonRelease) {
        showBloodPressureDialog();
        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}
