/****************************************************************************
** Meta object code from reading C++ file 'bomber.h'
**
** Created: Wed 2. Sep 21:17:21 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bomber.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bomber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bomber[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Bomber[] = {
    "Bomber\0\0_b\0bomba(Bomb*)\0"
};

void Bomber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Bomber *_t = static_cast<Bomber *>(_o);
        switch (_id) {
        case 0: _t->bomba((*reinterpret_cast< Bomb*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Bomber::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Bomber::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Bomber,
      qt_meta_data_Bomber, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bomber::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bomber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bomber::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bomber))
        return static_cast<void*>(const_cast< Bomber*>(this));
    return QObject::qt_metacast(_clname);
}

int Bomber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Bomber::bomba(Bomb * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_Bomb[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    6,    5,    5, 0x05,
      33,   30,    5,    5, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Bomb[] = {
    "Bomb\0\0_pos\0popal_stena(Cell*)\0_t\0"
    "popal_tank(Tank*)\0"
};

void Bomb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Bomb *_t = static_cast<Bomb *>(_o);
        switch (_id) {
        case 0: _t->popal_stena((*reinterpret_cast< Cell*(*)>(_a[1]))); break;
        case 1: _t->popal_tank((*reinterpret_cast< Tank*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Bomb::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Bomb::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Bomb,
      qt_meta_data_Bomb, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bomb::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bomb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bomb::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bomb))
        return static_cast<void*>(const_cast< Bomb*>(this));
    return QObject::qt_metacast(_clname);
}

int Bomb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Bomb::popal_stena(Cell * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Bomb::popal_tank(Tank * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
