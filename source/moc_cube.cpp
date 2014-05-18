/****************************************************************************
** Meta object code from reading C++ file 'cube.h'
**
** Created: Tue Jan 10 10:44:22 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cube.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cube.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Cube[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      23,    5,    5,    5, 0x05,
      33,    5,    5,    5, 0x05,
      53,    5,    5,    5, 0x05,
      80,   69,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,    5,    5,    5, 0x08,
     117,  111,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Cube[] = {
    "Cube\0\0levelCompleted()\0suicide()\0"
    "explosionFinished()\0hideLevelName()\0"
    "effectName\0playEffect(QString)\0"
    "collided()\0event\0keyPressed(QKeyEvent*)\0"
};

void Cube::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Cube *_t = static_cast<Cube *>(_o);
        switch (_id) {
        case 0: _t->levelCompleted(); break;
        case 1: _t->suicide(); break;
        case 2: _t->explosionFinished(); break;
        case 3: _t->hideLevelName(); break;
        case 4: _t->playEffect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->collided(); break;
        case 6: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Cube::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Cube::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cube,
      qt_meta_data_Cube, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Cube::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Cube::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Cube::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cube))
        return static_cast<void*>(const_cast< Cube*>(this));
    return QObject::qt_metacast(_clname);
}

int Cube::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Cube::levelCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Cube::suicide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Cube::explosionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Cube::hideLevelName()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Cube::playEffect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
