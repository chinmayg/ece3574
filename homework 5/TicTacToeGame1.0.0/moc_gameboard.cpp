/****************************************************************************
** Meta object code from reading C++ file 'gameboard.h'
**
** Created: Mon Nov 5 23:07:00 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gameboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameBoard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      27,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      59,   10,   10,   10, 0x08,
      75,   10,   10,   10, 0x08,
      91,   10,   10,   10, 0x08,
     107,   10,   10,   10, 0x08,
     123,   10,   10,   10, 0x08,
     139,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameBoard[] = {
    "GameBoard\0\0on_TL_clicked()\0on_TC_clicked()\0"
    "on_TR_clicked()\0on_CL_clicked()\0"
    "on_CC_clicked()\0on_CR_clicked()\0"
    "on_BL_clicked()\0on_BC_clicked()\0"
    "on_BR_clicked()\0"
};

void GameBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameBoard *_t = static_cast<GameBoard *>(_o);
        switch (_id) {
        case 0: _t->on_TL_clicked(); break;
        case 1: _t->on_TC_clicked(); break;
        case 2: _t->on_TR_clicked(); break;
        case 3: _t->on_CL_clicked(); break;
        case 4: _t->on_CC_clicked(); break;
        case 5: _t->on_CR_clicked(); break;
        case 6: _t->on_BL_clicked(); break;
        case 7: _t->on_BC_clicked(); break;
        case 8: _t->on_BR_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GameBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameBoard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameBoard,
      qt_meta_data_GameBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameBoard))
        return static_cast<void*>(const_cast< GameBoard*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
