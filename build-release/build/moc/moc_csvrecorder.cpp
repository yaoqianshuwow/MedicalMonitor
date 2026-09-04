/****************************************************************************
** Meta object code from reading C++ file 'csvrecorder.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../storage/csvrecorder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'csvrecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CsvRecorder_t {
    const uint offsetsAndSize[24];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CsvRecorder_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CsvRecorder_t qt_meta_stringdata_CsvRecorder = {
    {
QT_MOC_LITERAL(0, 11), // "CsvRecorder"
QT_MOC_LITERAL(12, 12), // "recordSample"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 11), // "timestampMs"
QT_MOC_LITERAL(38, 4), // "ecg1"
QT_MOC_LITERAL(43, 4), // "ecg2"
QT_MOC_LITERAL(48, 4), // "spo2"
QT_MOC_LITERAL(53, 4), // "resp"
QT_MOC_LITERAL(58, 10), // "VitalSigns"
QT_MOC_LITERAL(69, 5), // "signs"
QT_MOC_LITERAL(75, 17), // "recordSerialBytes"
QT_MOC_LITERAL(93, 5) // "bytes"

    },
    "CsvRecorder\0recordSample\0\0timestampMs\0"
    "ecg1\0ecg2\0spo2\0resp\0VitalSigns\0signs\0"
    "recordSerialBytes\0bytes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CsvRecorder[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    6,   26,    2, 0x0a,    1 /* Public */,
      10,    1,   39,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 8,    3,    4,    5,    6,    7,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,

       0        // eod
};

void CsvRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CsvRecorder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->recordSample((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<VitalSigns>>(_a[6]))); break;
        case 1: _t->recordSerialBytes((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CsvRecorder::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CsvRecorder.offsetsAndSize,
    qt_meta_data_CsvRecorder,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CsvRecorder_t
, QtPrivate::TypeAndForceComplete<CsvRecorder, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<const VitalSigns &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>


>,
    nullptr
} };


const QMetaObject *CsvRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CsvRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CsvRecorder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CsvRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
