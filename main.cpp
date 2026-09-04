#include "mainwindow.h"
#include "datasource/simulateddatasource.h"
#include "dialogs/bloodpressuredialog.h"
#include "storage/csvrecorder.h"

#include <QApplication>
#include <QDir>
#include <QFont>
#include <QMetaObject>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("MedicalMonitor"));
    QApplication::setOrganizationName(QStringLiteral("Qt Teaching Lab"));
    QApplication::setFont(QFont(QStringLiteral("Microsoft YaHei UI"), 10));

    // 自动化冒烟测试：验证模拟源、CSV 写入和完整 NIBP 流程，不显示窗口。
    if (app.arguments().contains(QStringLiteral("--smoke-test"))) {
        const int argumentIndex = app.arguments().indexOf(QStringLiteral("--smoke-test"));
        const QString csvPath = argumentIndex + 1 < app.arguments().size()
            ? app.arguments().at(argumentIndex + 1)
            : QDir::temp().filePath(QStringLiteral("medical-monitor-smoke.csv"));
        CsvRecorder recorder;
        SimulatedDataSource simulator;
        BloodPressureDialog bloodPressure;
        bool bloodPressureFinished = false;
        QString error;
        if (!recorder.start(csvPath, &error))
            return 2;
        QObject::connect(&simulator, &SimulatedDataSource::sampleForRecording,
                         &recorder, &CsvRecorder::recordSample);
        QObject::connect(&bloodPressure, &BloodPressureDialog::measurementFinished,
                         &app, [&](int systolic, int diastolic, int mean, int pulse) {
            bloodPressureFinished = systolic > diastolic && diastolic > 0
                                    && mean > diastolic && pulse > 0;
            app.quit();
        });
        simulator.start();
        QMetaObject::invokeMethod(&bloodPressure, "startMeasurement", Qt::QueuedConnection);
        QTimer::singleShot(15000, &app, &QCoreApplication::quit);
        app.exec();
        simulator.stop();
        const qint64 recordedRows = recorder.rowCount();
        recorder.stop();
        return bloodPressureFinished && recordedRows >= 100 ? 0 : 3;
    }

    MainWindow window;
    window.show();
    const int screenshotIndex = app.arguments().indexOf(QStringLiteral("--screenshot"));
    if (screenshotIndex >= 0 && screenshotIndex + 1 < app.arguments().size()) {
        const QString screenshotPath = app.arguments().at(screenshotIndex + 1);
        QTimer::singleShot(2500, &app, [&window, screenshotPath, &app] {
            window.grab().save(screenshotPath, "PNG");
            app.quit();
        });
    }
    return app.exec();
}
