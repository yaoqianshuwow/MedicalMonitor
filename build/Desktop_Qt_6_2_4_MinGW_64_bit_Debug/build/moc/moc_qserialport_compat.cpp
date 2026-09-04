/****************************************************************************
** Meta object code from reading C++ file 'qserialport_compat.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../compat/serialport/qserialport_compat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qserialport_compat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSerialPort_t {
    const uint offsetsAndSize[68];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QSerialPort_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QSerialPort_t qt_meta_stringdata_QSerialPort = {
    {
QT_MOC_LITERAL(0, 11), // "QSerialPort"
QT_MOC_LITERAL(12, 13), // "errorOccurred"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(56, 5), // "error"
QT_MOC_LITERAL(62, 9), // "pollInput"
QT_MOC_LITERAL(72, 15), // "SerialPortError"
QT_MOC_LITERAL(88, 7), // "NoError"
QT_MOC_LITERAL(96, 19), // "DeviceNotFoundError"
QT_MOC_LITERAL(116, 15), // "PermissionError"
QT_MOC_LITERAL(132, 9), // "OpenError"
QT_MOC_LITERAL(142, 10), // "WriteError"
QT_MOC_LITERAL(153, 9), // "ReadError"
QT_MOC_LITERAL(163, 13), // "ResourceError"
QT_MOC_LITERAL(177, 12), // "UnknownError"
QT_MOC_LITERAL(190, 8), // "DataBits"
QT_MOC_LITERAL(199, 5), // "Data5"
QT_MOC_LITERAL(205, 5), // "Data6"
QT_MOC_LITERAL(211, 5), // "Data7"
QT_MOC_LITERAL(217, 5), // "Data8"
QT_MOC_LITERAL(223, 6), // "Parity"
QT_MOC_LITERAL(230, 8), // "NoParity"
QT_MOC_LITERAL(239, 10), // "EvenParity"
QT_MOC_LITERAL(250, 9), // "OddParity"
QT_MOC_LITERAL(260, 11), // "SpaceParity"
QT_MOC_LITERAL(272, 10), // "MarkParity"
QT_MOC_LITERAL(283, 8), // "StopBits"
QT_MOC_LITERAL(292, 7), // "OneStop"
QT_MOC_LITERAL(300, 14), // "OneAndHalfStop"
QT_MOC_LITERAL(315, 7), // "TwoStop"
QT_MOC_LITERAL(323, 11), // "FlowControl"
QT_MOC_LITERAL(335, 13), // "NoFlowControl"
QT_MOC_LITERAL(349, 15), // "HardwareControl"
QT_MOC_LITERAL(365, 15) // "SoftwareControl"

    },
    "QSerialPort\0errorOccurred\0\0"
    "QSerialPort::SerialPortError\0error\0"
    "pollInput\0SerialPortError\0NoError\0"
    "DeviceNotFoundError\0PermissionError\0"
    "OpenError\0WriteError\0ReadError\0"
    "ResourceError\0UnknownError\0DataBits\0"
    "Data5\0Data6\0Data7\0Data8\0Parity\0NoParity\0"
    "EvenParity\0OddParity\0SpaceParity\0"
    "MarkParity\0StopBits\0OneStop\0OneAndHalfStop\0"
    "TwoStop\0FlowControl\0NoFlowControl\0"
    "HardwareControl\0SoftwareControl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSerialPort[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       5,   30, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   29,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       6,    6, 0x0,    8,   55,
      15,   15, 0x0,    4,   71,
      20,   20, 0x0,    5,   79,
      26,   26, 0x0,    3,   89,
      30,   30, 0x0,    3,   95,

 // enum data: key, value
       7, uint(QSerialPort::NoError),
       8, uint(QSerialPort::DeviceNotFoundError),
       9, uint(QSerialPort::PermissionError),
      10, uint(QSerialPort::OpenError),
      11, uint(QSerialPort::WriteError),
      12, uint(QSerialPort::ReadError),
      13, uint(QSerialPort::ResourceError),
      14, uint(QSerialPort::UnknownError),
      16, uint(QSerialPort::Data5),
      17, uint(QSerialPort::Data6),
      18, uint(QSerialPort::Data7),
      19, uint(QSerialPort::Data8),
      21, uint(QSerialPort::NoParity),
      22, uint(QSerialPort::EvenParity),
      23, uint(QSerialPort::OddParity),
      24, uint(QSerialPort::SpaceParity),
      25, uint(QSerialPort::MarkParity),
      27, uint(QSerialPort::OneStop),
      28, uint(QSerialPort::OneAndHalfStop),
      29, uint(QSerialPort::TwoStop),
      31, uint(QSerialPort::NoFlowControl),
      32, uint(QSerialPort::HardwareControl),
      33, uint(QSerialPort::SoftwareControl),

       0        // eod
};

void QSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSerialPort *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        case 1: _t->pollInput(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSerialPort::*)(QSerialPort::SerialPortError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSerialPort::errorOccurred)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QSerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<QIODevice::staticMetaObject>(),
    qt_meta_stringdata_QSerialPort.offsetsAndSize,
    qt_meta_data_QSerialPort,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QSerialPort_t
, QtPrivate::TypeAndForceComplete<QSerialPort, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *QSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSerialPort.stringdata0))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int QSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QSerialPort::errorOccurred(QSerialPort::SerialPortError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
