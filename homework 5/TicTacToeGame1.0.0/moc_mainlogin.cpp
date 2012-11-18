/****************************************************************************
** Meta object code from reading C++ file 'mainlogin.h'
**
** Created: Mon Nov 5 23:06:56 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainlogin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainLogin[] = {

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
      11,   10,   10,   10, 0x08,
      30,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainLogin[] = {
    "MainLogin\0\0on_Login_clicked()\0"
    "on_Exit_clicked()\0"
};

void MainLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainLogin *_t = static_cast<MainLogin *>(_o);
        switch (_id) {
        case 0: _t->on_Login_clicked(); break;
        case 1: _t->on_Exit_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainLogin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainLogin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainLogin,
      qt_meta_data_MainLogin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainLogin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainLogin))
        return static_cast<void*>(const_cast< MainLogin*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
