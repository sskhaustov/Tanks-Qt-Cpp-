/****************************************************************************
** Meta object code from reading C++ file 'mediator.h'
**
** Created: Wed 2. Sep 21:16:51 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mediator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mediator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      16,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   23,    9,    9, 0x09,
      46,   43,    9,    9, 0x09,
      97,    9,    9,    9, 0x09,
     119,    9,    9,    9, 0x09,
     140,    9,    9,    9, 0x09,
     154,    9,    9,    9, 0x09,
     163,    9,    9,    9, 0x09,
     176,  173,    9,    9, 0x09,
     196,   23,    9,    9, 0x09,
     219,    9,    9,    9, 0x09,
     229,    9,    9,    9, 0x09,
     242,   23,    9,    9, 0x09,
     260,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Mediator[] = {
    "Mediator\0\0win()\0lose()\0_b\0on_shot(Bullet*)\0"
    ",,\0on_tick(Bullet*,QGraphicsPixmapItem*,BulletTimer*)\0"
    "on_popal_stena(Cell*)\0on_popal_tank(Tank*)\0"
    "drive_tanks()\0on_win()\0on_lose()\0_t\0"
    "on_tank_kill(Tank*)\0on_found_bonus(Bonus*)\0"
    "respawn()\0bomber_fly()\0on_bombing(Bomb*)\0"
    "on_pushButton_clicked()\0"
};

void Mediator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Mediator *_t = static_cast<Mediator *>(_o);
        switch (_id) {
        case 0: _t->win(); break;
        case 1: _t->lose(); break;
        case 2: _t->on_shot((*reinterpret_cast< Bullet*(*)>(_a[1]))); break;
        case 3: _t->on_tick((*reinterpret_cast< Bullet*(*)>(_a[1])),(*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[2])),(*reinterpret_cast< BulletTimer*(*)>(_a[3]))); break;
        case 4: _t->on_popal_stena((*reinterpret_cast< Cell*(*)>(_a[1]))); break;
        case 5: _t->on_popal_tank((*reinterpret_cast< Tank*(*)>(_a[1]))); break;
        case 6: _t->drive_tanks(); break;
        case 7: _t->on_win(); break;
        case 8: _t->on_lose(); break;
        case 9: _t->on_tank_kill((*reinterpret_cast< Tank*(*)>(_a[1]))); break;
        case 10: _t->on_found_bonus((*reinterpret_cast< Bonus*(*)>(_a[1]))); break;
        case 11: _t->respawn(); break;
        case 12: _t->bomber_fly(); break;
        case 13: _t->on_bombing((*reinterpret_cast< Bomb*(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Mediator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Mediator::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Mediator,
      qt_meta_data_Mediator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mediator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mediator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mediator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mediator))
        return static_cast<void*>(const_cast< Mediator*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Mediator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Mediator::win()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Mediator::lose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
