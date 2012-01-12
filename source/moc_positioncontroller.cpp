/****************************************************************************
** Meta object code from reading C++ file 'positioncontroller.h'
**
** Created: Tue Jan 10 10:44:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "positioncontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'positioncontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PositionController[] = {

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
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PositionController[] = {
    "PositionController\0\0collision()\0"
    "checkCollision()\0"
};

void PositionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PositionController *_t = static_cast<PositionController *>(_o);
        switch (_id) {
        case 0: _t->collision(); break;
        case 1: _t->checkCollision(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PositionController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PositionController::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PositionController,
      qt_meta_data_PositionController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PositionController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PositionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PositionController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PositionController))
        return static_cast<void*>(const_cast< PositionController*>(this));
    return QThread::qt_metacast(_clname);
}

int PositionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void PositionController::collision()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
