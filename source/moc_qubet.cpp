/****************************************************************************
** Meta object code from reading C++ file 'qubet.h'
**
** Created: Tue Jan 10 11:25:04 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qubet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qubet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qubet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,    7,    6,    6, 0x05,
      69,   63,    6,    6, 0x05,
      97,    7,    6,    6, 0x05,
     136,   63,    6,    6, 0x05,
     164,   63,    6,    6, 0x05,
     195,  187,    6,    6, 0x05,
     222,  213,    6,    6, 0x05,
     248,    6,    6,    6, 0x05,
     278,  267,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     298,    6,    6,    6, 0x08,
     312,  305,    6,    6, 0x08,
     344,  329,    6,    6, 0x08,
     368,  305,    6,    6, 0x08,
     388,    6,    6,    6, 0x08,
     410,  401,    6,    6, 0x08,
     440,  433,    6,    6, 0x08,
     469,    6,    6,    6, 0x08,
     494,  489,    6,    6, 0x08,
     535,  524,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Qubet[] = {
    "Qubet\0\0event,listNames\0"
    "itemClicked(QMouseEvent*,QList<GLuint>)\0"
    "event\0mouseReleased(QMouseEvent*)\0"
    "mouseMoved(QMouseEvent*,QList<GLuint>)\0"
    "wheelScrolled(QWheelEvent*)\0"
    "keyPressed(QKeyEvent*)\0enabled\0"
    "enableAudio(bool)\0filename\0"
    "playAmbientMusic(QString)\0stopAmbientMusic()\0"
    "effectName\0playEffect(QString)\0draw()\0"
    "skinId\0playStory(GLint)\0skinId,levelId\0"
    "playArcade(GLint,GLint)\0playSurvivor(GLint)\0"
    "gameClosed()\0_levelId\0showLevelEditor(GLint)\0"
    "_level\0addLevelToLevelsList(Level*)\0"
    "levelEditorClosed()\0mode\0"
    "setMouseMovementTracking(int)\0skyboxName\0"
    "setSkybox(QString)\0"
};

void Qubet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Qubet *_t = static_cast<Qubet *>(_o);
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 1: _t->mouseReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 3: _t->wheelScrolled((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 4: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->enableAudio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->playAmbientMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->stopAmbientMusic(); break;
        case 8: _t->playEffect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->draw(); break;
        case 10: _t->playStory((*reinterpret_cast< GLint(*)>(_a[1]))); break;
        case 11: _t->playArcade((*reinterpret_cast< GLint(*)>(_a[1])),(*reinterpret_cast< GLint(*)>(_a[2]))); break;
        case 12: _t->playSurvivor((*reinterpret_cast< GLint(*)>(_a[1]))); break;
        case 13: _t->gameClosed(); break;
        case 14: _t->showLevelEditor((*reinterpret_cast< GLint(*)>(_a[1]))); break;
        case 15: _t->addLevelToLevelsList((*reinterpret_cast< Level*(*)>(_a[1]))); break;
        case 16: _t->levelEditorClosed(); break;
        case 17: _t->setMouseMovementTracking((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->setSkybox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Qubet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Qubet::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Qubet,
      qt_meta_data_Qubet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qubet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qubet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qubet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qubet))
        return static_cast<void*>(const_cast< Qubet*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Qubet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Qubet::itemClicked(QMouseEvent * _t1, QList<GLuint> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Qubet::mouseReleased(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Qubet::mouseMoved(QMouseEvent * _t1, QList<GLuint> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Qubet::wheelScrolled(QWheelEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Qubet::keyPressed(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Qubet::enableAudio(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Qubet::playAmbientMusic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Qubet::stopAmbientMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Qubet::playEffect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE