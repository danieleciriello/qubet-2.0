/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created: Tue Jan 10 10:44:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Game[] = {

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
       6,    5,    5,    5, 0x05,
      18,    5,    5,    5, 0x05,
      42,   37,    5,    5, 0x05,
      78,   72,    5,    5, 0x05,
     115,  107,    5,    5, 0x05,
     142,  133,    5,    5, 0x05,
     168,    5,    5,    5, 0x05,
     198,  187,    5,    5, 0x05,
     229,  218,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     264,  248,    5,    5, 0x08,
     304,   72,    5,    5, 0x08,
     332,  248,    5,    5, 0x08,
     371,   72,    5,    5, 0x08,
     399,   72,    5,    5, 0x08,
     422,    5,    5,    5, 0x08,
     433,    5,    5,    5, 0x08,
     444,    5,    5,    5, 0x08,
     464,    5,    5,    5, 0x08,
     481,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Game[] = {
    "Game\0\0collision()\0gameClosedSignal()\0"
    "mode\0setMouseMovementTracking(int)\0"
    "event\0keyPressedSignal(QKeyEvent*)\0"
    "enabled\0enableAudio(bool)\0filename\0"
    "playAmbientMusic(QString)\0stopAmbientMusic()\0"
    "effectName\0playEffect(QString)\0"
    "skyboxName\0setSkybox(QString)\0"
    "event,listNames\0itemClicked(QMouseEvent*,QList<GLuint>)\0"
    "mouseReleased(QMouseEvent*)\0"
    "mouseMoved(QMouseEvent*,QList<GLuint>)\0"
    "wheelScrolled(QWheelEvent*)\0"
    "keyPressed(QKeyEvent*)\0collided()\0"
    "exploded()\0explosionFinished()\0"
    "levelCompleted()\0hideLevelName()\0"
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Game *_t = static_cast<Game *>(_o);
        switch (_id) {
        case 0: _t->collision(); break;
        case 1: _t->gameClosedSignal(); break;
        case 2: _t->setMouseMovementTracking((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->keyPressedSignal((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->enableAudio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->playAmbientMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->stopAmbientMusic(); break;
        case 7: _t->playEffect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setSkybox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->itemClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 10: _t->mouseReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 11: _t->mouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 12: _t->wheelScrolled((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 13: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 14: _t->collided(); break;
        case 15: _t->exploded(); break;
        case 16: _t->explosionFinished(); break;
        case 17: _t->levelCompleted(); break;
        case 18: _t->hideLevelName(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Game::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Game::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Game,
      qt_meta_data_Game, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Game::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game))
        return static_cast<void*>(const_cast< Game*>(this));
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Game::collision()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Game::gameClosedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Game::setMouseMovementTracking(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Game::keyPressedSignal(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Game::enableAudio(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Game::playAmbientMusic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Game::stopAmbientMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Game::playEffect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Game::setSkybox(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
