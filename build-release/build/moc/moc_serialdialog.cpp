/****************************************************************************
** Meta object code from reading C++ file 'serialdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../dialogs/serialdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialDialog_t {
    const uint offsetsAndSize[30];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SerialDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SerialDialog_t qt_meta_stringdata_SerialDialog = {
    {
QT_MOC_LITERAL(0, 12), // "SerialDialog"
QT_MOC_LITERAL(13, 19), // "simulationRequested"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 17), // "openPortRequested"
QT_MOC_LITERAL(52, 8), // "portName"
QT_MOC_LITERAL(61, 8), // "baudRate"
QT_MOC_LITERAL(70, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(92, 8), // "dataBits"
QT_MOC_LITERAL(101, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(121, 6), // "parity"
QT_MOC_LITERAL(128, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(150, 8), // "stopBits"
QT_MOC_LITERAL(159, 18), // "closePortRequested"
QT_MOC_LITERAL(178, 12), // "refreshPorts"
QT_MOC_LITERAL(191, 13) // "requestToggle"

    },
    "SerialDialog\0simulationRequested\0\0"
    "openPortRequested\0portName\0baudRate\0"
    "QSerialPort::DataBits\0dataBits\0"
    "QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0stopBits\0"
    "closePortRequested\0refreshPorts\0"
    "requestToggle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    5,   45,    2, 0x06,    2 /* Public */,
      12,    0,   56,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,   57,    2, 0x08,    9 /* Private */,
      14,    0,   58,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    4,    5,    7,    9,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->simulationRequested(); break;
        case 1: _t->openPortRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint32>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::DataBits>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::Parity>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::StopBits>>(_a[5]))); break;
        case 2: _t->closePortRequested(); break;
        case 3: _t->refreshPorts(); break;
        case 4: _t->requestToggle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialDialog::simulationRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialDialog::*)(const QString & , qint32 , QSerialPort::DataBits , QSerialPort::Parity , QSerialPort::StopBits );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialDialog::openPortRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialDialog::closePortRequested)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SerialDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SerialDialog.offsetsAndSize,
    qt_meta_data_SerialDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SerialDialog_t
, QtPrivate::TypeAndForceComplete<SerialDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<qint32, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::DataBits, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::Parity, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::StopBits, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SerialDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SerialDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SerialDialog::simulationRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SerialDialog::openPortRequested(const QString & _t1, qint32 _t2, QSerialPort::DataBits _t3, QSerialPort::Parity _t4, QSerialPort::StopBits _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialDialog::closePortRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
