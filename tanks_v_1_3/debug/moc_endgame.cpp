/****************************************************************************
** Meta object code from reading C++ file 'endgame.h'
**
** Created: Wed 2. Sep 21:17:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../endgame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'endgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EndGame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      37,    8,   33,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EndGame[] = {
    "EndGame\0\0on_pushButton_clicked()\0int\0"
    "return_res()\0"
};

void EndGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EndGame *_t = static_cast<EndGame *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: { int _r = _t->return_res();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EndGame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EndGame::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EndGame,
      qt_meta_data_EndGame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EndGame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EndGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EndGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EndGame))
        return static_cast<void*>(const_cast< EndGame*>(this));
    return QDialog::qt_metacast(_clname);
}

int EndGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
