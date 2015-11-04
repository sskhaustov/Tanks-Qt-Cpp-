/****************************************************************************
** Meta object code from reading C++ file 'bullet.h'
**
** Created: Wed 2. Sep 21:17:01 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bullet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bullet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bullet[] = {

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
      13,    8,    7,    7, 0x05,
      35,   32,    7,    7, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Bullet[] = {
    "Bullet\0\0_pos\0popal_stena(Cell*)\0_t\0"
    "popal_tank(Tank*)\0"
};

void Bullet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Bullet *_t = static_cast<Bullet *>(_o);
        switch (_id) {
        case 0: _t->popal_stena((*reinterpret_cast< Cell*(*)>(_a[1]))); break;
        case 1: _t->popal_tank((*reinterpret_cast< Tank*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Bullet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Bullet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Bullet,
      qt_meta_data_Bullet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bullet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bullet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bullet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bullet))
        return static_cast<void*>(const_cast< Bullet*>(this));
    return QObject::qt_metacast(_clname);
}

int Bullet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Bullet::popal_stena(Cell * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Bullet::popal_tank(Tank * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_BulletTimer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   12,   12,   12, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_BulletTimer[] = {
    "BulletTimer\0\0_b,_p,_tmr\0"
    "takt(Bullet*,QGraphicsPixmapItem*,BulletTimer*)\0"
    "on_takt()\0"
};

void BulletTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BulletTimer *_t = static_cast<BulletTimer *>(_o);
        switch (_id) {
        case 0: _t->takt((*reinterpret_cast< Bullet*(*)>(_a[1])),(*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[2])),(*reinterpret_cast< BulletTimer*(*)>(_a[3]))); break;
        case 1: _t->on_takt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BulletTimer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BulletTimer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BulletTimer,
      qt_meta_data_BulletTimer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BulletTimer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BulletTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BulletTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BulletTimer))
        return static_cast<void*>(const_cast< BulletTimer*>(this));
    return QObject::qt_metacast(_clname);
}

int BulletTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BulletTimer::takt(Bullet * _t1, QGraphicsPixmapItem * _t2, BulletTimer * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
