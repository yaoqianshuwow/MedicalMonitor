QT += core gui widgets

CONFIG += c++17
TEMPLATE = app
TARGET = MedicalMonitor

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    widgets/waveformwidget.cpp \
    widgets/vitalcard.cpp \
    datasource/simulateddatasource.cpp \
    dialogs/serialdialog.cpp \
    dialogs/bloodpressuredialog.cpp \
    storage/csvrecorder.cpp

HEADERS += \
    mainwindow.h \
    widgets/waveformwidget.h \
    widgets/vitalcard.h \
    datasource/simulateddatasource.h \
    dialogs/serialdialog.h \
    dialogs/bloodpressuredialog.h \
    storage/csvrecorder.h \
    protocol/vitalsigns.h

# 标准完整 Kit 使用 qmake 参数 CONFIG+=use_qt_serialport，即会启用：QT += serialport
# 当前离线 Qt 6.2.4 Kit 未安装该可选模块，默认使用工程内的 Win32 兼容层。
contains(CONFIG, use_qt_serialport):QT += serialport
contains(CONFIG, use_qt_serialport):DEFINES += MEDICALMONITOR_HAS_QT_SERIALPORT
!contains(CONFIG, use_qt_serialport):message("Using bundled Win32 serial compatibility layer")
!contains(CONFIG, use_qt_serialport):INCLUDEPATH += $$PWD/compat/serialport
!contains(CONFIG, use_qt_serialport):SOURCES += compat/serialport/qserialport_compat.cpp
!contains(CONFIG, use_qt_serialport):HEADERS += \
    compat/serialport/QSerialPort \
    compat/serialport/QSerialPortInfo \
    compat/serialport/qserialport_compat.h
!contains(CONFIG, use_qt_serialport):win32:LIBS += -ladvapi32

win32:RC_ICONS =

DESTDIR = bin
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui
