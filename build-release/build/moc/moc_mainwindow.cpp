/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[70];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 15), // "updateWaveforms"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 13), // "QList<double>"
QT_MOC_LITERAL(42, 4), // "ecg1"
QT_MOC_LITERAL(47, 4), // "ecg2"
QT_MOC_LITERAL(52, 4), // "spo2"
QT_MOC_LITERAL(57, 4), // "resp"
QT_MOC_LITERAL(62, 16), // "updateVitalSigns"
QT_MOC_LITERAL(79, 10), // "VitalSigns"
QT_MOC_LITERAL(90, 5), // "signs"
QT_MOC_LITERAL(96, 16), // "showSerialDialog"
QT_MOC_LITERAL(113, 14), // "openSerialPort"
QT_MOC_LITERAL(128, 4), // "name"
QT_MOC_LITERAL(133, 8), // "baudRate"
QT_MOC_LITERAL(142, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(164, 8), // "dataBits"
QT_MOC_LITERAL(173, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(193, 6), // "parity"
QT_MOC_LITERAL(200, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(222, 8), // "stopBits"
QT_MOC_LITERAL(231, 15), // "closeSerialPort"
QT_MOC_LITERAL(247, 13), // "useSimulation"
QT_MOC_LITERAL(261, 14), // "readSerialData"
QT_MOC_LITERAL(276, 23), // "showBloodPressureDialog"
QT_MOC_LITERAL(300, 19), // "updateBloodPressure"
QT_MOC_LITERAL(320, 8), // "systolic"
QT_MOC_LITERAL(329, 9), // "diastolic"
QT_MOC_LITERAL(339, 4), // "mean"
QT_MOC_LITERAL(344, 5), // "pulse"
QT_MOC_LITERAL(350, 18), // "updateCuffPressure"
QT_MOC_LITERAL(369, 8), // "pressure"
QT_MOC_LITERAL(378, 17), // "sendSerialCommand"
QT_MOC_LITERAL(396, 7), // "command"
QT_MOC_LITERAL(404, 15) // "toggleRecording"

    },
    "MainWindow\0updateWaveforms\0\0QList<double>\0"
    "ecg1\0ecg2\0spo2\0resp\0updateVitalSigns\0"
    "VitalSigns\0signs\0showSerialDialog\0"
    "openSerialPort\0name\0baudRate\0"
    "QSerialPort::DataBits\0dataBits\0"
    "QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0stopBits\0"
    "closeSerialPort\0useSimulation\0"
    "readSerialData\0showBloodPressureDialog\0"
    "updateBloodPressure\0systolic\0diastolic\0"
    "mean\0pulse\0updateCuffPressure\0pressure\0"
    "sendSerialCommand\0command\0toggleRecording"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   86,    2, 0x08,    1 /* Private */,
       8,    1,   95,    2, 0x08,    6 /* Private */,
      11,    0,   98,    2, 0x08,    8 /* Private */,
      12,    5,   99,    2, 0x08,    9 /* Private */,
      21,    0,  110,    2, 0x08,   15 /* Private */,
      22,    0,  111,    2, 0x08,   16 /* Private */,
      23,    0,  112,    2, 0x08,   17 /* Private */,
      24,    0,  113,    2, 0x08,   18 /* Private */,
      25,    4,  114,    2, 0x08,   19 /* Private */,
      30,    1,  123,    2, 0x08,   24 /* Private */,
      32,    1,  126,    2, 0x08,   26 /* Private */,
      34,    0,  129,    2, 0x08,   28 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 15, 0x80000000 | 17, 0x80000000 | 19,   13,   14,   16,   18,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   26,   27,   28,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::QByteArray,   33,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateWaveforms((*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[4]))); break;
        case 1: _t->updateVitalSigns((*reinterpret_cast< std::add_pointer_t<VitalSigns>>(_a[1]))); break;
        case 2: _t->showSerialDialog(); break;
        case 3: _t->openSerialPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint32>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::DataBits>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::Parity>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::StopBits>>(_a[5]))); break;
        case 4: _t->closeSerialPort(); break;
        case 5: _t->useSimulation(); break;
        case 6: _t->readSerialData(); break;
        case 7: _t->showBloodPressureDialog(); break;
        case 8: _t->updateBloodPressure((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 9: _t->updateCuffPressure((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->sendSerialCommand((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 11: _t->toggleRecording(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const VitalSigns &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<qint32, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::DataBits, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::Parity, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::StopBits, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
