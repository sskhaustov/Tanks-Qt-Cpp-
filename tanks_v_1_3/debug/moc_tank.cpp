/****************************************************************************
** Meta object code from reading C++ file 'tank.h'
**
** Created: Wed 2. Sep 21:16:56 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tank.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tank.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tank[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    6,    5,    5, 0x05,
      26,   23,    5,    5, 0x05,
      38,    6,    5,    5, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Tank[] = {
    "Tank\0\0_b\0shot(Bullet*)\0_t\0kill(Tank*)\0"
    "found(Bonus*)\0"
};

void Tank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tank *_t = static_cast<Tank *>(_o);
        switch (_id) {
        case 0: _t->shot((*reinterpret_cast< Bullet*(*)>(_a[1]))); break;
        case 1: _t->kill((*reinterpret_cast< Tank*(*)>(_a[1]))); break;
        case 2: _t->found((*reinterpret_cast< Bonus*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tank::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tank::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tank,
      qt_meta_data_Tank, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tank::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tank::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tank))
        return static_cast<void*>(const_cast< Tank*>(this));
    return QObject::qt_metacast(_clname);
}

int Tank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Tank::shot(Bullet * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tank::kill(Tank * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tank::found(Bonus * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
