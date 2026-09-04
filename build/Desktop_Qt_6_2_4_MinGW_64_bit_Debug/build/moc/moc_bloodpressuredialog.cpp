/****************************************************************************
** Meta object code from reading C++ file 'bloodpressuredialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../dialogs/bloodpressuredialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bloodpressuredialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BloodPressureDialog_t {
    const uint offsetsAndSize[28];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BloodPressureDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BloodPressureDialog_t qt_meta_stringdata_BloodPressureDialog = {
    {
QT_MOC_LITERAL(0, 19), // "BloodPressureDialog"
QT_MOC_LITERAL(20, 19), // "cuffPressureChanged"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 8), // "pressure"
QT_MOC_LITERAL(50, 19), // "measurementFinished"
QT_MOC_LITERAL(70, 8), // "systolic"
QT_MOC_LITERAL(79, 9), // "diastolic"
QT_MOC_LITERAL(89, 12), // "meanPressure"
QT_MOC_LITERAL(102, 9), // "pulseRate"
QT_MOC_LITERAL(112, 22), // "serialCommandRequested"
QT_MOC_LITERAL(135, 7), // "command"
QT_MOC_LITERAL(143, 16), // "startMeasurement"
QT_MOC_LITERAL(160, 15), // "stopMeasurement"
QT_MOC_LITERAL(176, 17) // "advanceSimulation"

    },
    "BloodPressureDialog\0cuffPressureChanged\0"
    "\0pressure\0measurementFinished\0systolic\0"
    "diastolic\0meanPressure\0pulseRate\0"
    "serialCommandRequested\0command\0"
    "startMeasurement\0stopMeasurement\0"
    "advanceSimulation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BloodPressureDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    4,   53,    2, 0x06,    3 /* Public */,
       9,    1,   62,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   65,    2, 0x08,   10 /* Private */,
      12,    0,   66,    2, 0x08,   11 /* Private */,
      13,    0,   67,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QByteArray,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BloodPressureDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BloodPressureDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cuffPressureChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->measurementFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 2: _t->serialCommandRequested((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->startMeasurement(); break;
        case 4: _t->stopMeasurement(); break;
        case 5: _t->advanceSimulation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BloodPressureDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BloodPressureDialog::cuffPressureChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BloodPressureDialog::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BloodPressureDialog::measurementFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BloodPressureDialog::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BloodPressureDialog::serialCommandRequested)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject BloodPressureDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_BloodPressureDialog.offsetsAndSize,
    qt_meta_data_BloodPressureDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BloodPressureDialog_t
, QtPrivate::TypeAndForceComplete<BloodPressureDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BloodPressureDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BloodPressureDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BloodPressureDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BloodPressureDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BloodPressureDialog::cuffPressureChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BloodPressureDialog::measurementFinished(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BloodPressureDialog::serialCommandRequested(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
