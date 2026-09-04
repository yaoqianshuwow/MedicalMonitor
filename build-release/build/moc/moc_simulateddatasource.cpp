/****************************************************************************
** Meta object code from reading C++ file 'simulateddatasource.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../datasource/simulateddatasource.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulateddatasource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimulatedDataSource_t {
    const uint offsetsAndSize[28];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SimulatedDataSource_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SimulatedDataSource_t qt_meta_stringdata_SimulatedDataSource = {
    {
QT_MOC_LITERAL(0, 19), // "SimulatedDataSource"
QT_MOC_LITERAL(20, 18), // "waveformBatchReady"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 13), // "QList<double>"
QT_MOC_LITERAL(54, 4), // "ecg1"
QT_MOC_LITERAL(59, 4), // "ecg2"
QT_MOC_LITERAL(64, 4), // "spo2"
QT_MOC_LITERAL(69, 4), // "resp"
QT_MOC_LITERAL(74, 15), // "vitalSignsReady"
QT_MOC_LITERAL(90, 10), // "VitalSigns"
QT_MOC_LITERAL(101, 5), // "signs"
QT_MOC_LITERAL(107, 18), // "sampleForRecording"
QT_MOC_LITERAL(126, 11), // "timestampMs"
QT_MOC_LITERAL(138, 13) // "generateFrame"

    },
    "SimulatedDataSource\0waveformBatchReady\0"
    "\0QList<double>\0ecg1\0ecg2\0spo2\0resp\0"
    "vitalSignsReady\0VitalSigns\0signs\0"
    "sampleForRecording\0timestampMs\0"
    "generateFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulatedDataSource[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   38,    2, 0x06,    1 /* Public */,
       8,    1,   47,    2, 0x06,    6 /* Public */,
      11,    6,   50,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,   63,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::LongLong, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, 0x80000000 | 9,   12,    4,    5,    6,    7,   10,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SimulatedDataSource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SimulatedDataSource *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->waveformBatchReady((*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[4]))); break;
        case 1: _t->vitalSignsReady((*reinterpret_cast< std::add_pointer_t<VitalSigns>>(_a[1]))); break;
        case 2: _t->sampleForRecording((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<VitalSigns>>(_a[6]))); break;
        case 3: _t->generateFrame(); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SimulatedDataSource::*)(const QVector<double> & , const QVector<double> & , const QVector<double> & , const QVector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimulatedDataSource::waveformBatchReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SimulatedDataSource::*)(const VitalSigns & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimulatedDataSource::vitalSignsReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SimulatedDataSource::*)(qint64 , double , double , double , double , const VitalSigns & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimulatedDataSource::sampleForRecording)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SimulatedDataSource::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SimulatedDataSource.offsetsAndSize,
    qt_meta_data_SimulatedDataSource,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SimulatedDataSource_t
, QtPrivate::TypeAndForceComplete<SimulatedDataSource, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<double> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const VitalSigns &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<const VitalSigns &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SimulatedDataSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulatedDataSource::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimulatedDataSource.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SimulatedDataSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SimulatedDataSource::waveformBatchReady(const QVector<double> & _t1, const QVector<double> & _t2, const QVector<double> & _t3, const QVector<double> & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimulatedDataSource::vitalSignsReady(const VitalSigns & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SimulatedDataSource::sampleForRecording(qint64 _t1, double _t2, double _t3, double _t4, double _t5, const VitalSigns & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
