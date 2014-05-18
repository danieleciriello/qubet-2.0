/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created: Tue Jan 10 10:44:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Menu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    6,    5,    5, 0x05,
      45,   30,    5,    5, 0x05,
      69,    6,    5,    5, 0x05,
      97,   89,    5,    5, 0x05,
     125,  120,    5,    5, 0x05,
     163,  155,    5,    5, 0x05,
     190,  181,    5,    5, 0x05,
     216,    5,    5,    5, 0x05,
     246,  235,    5,    5, 0x05,
     277,  266,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     312,  296,    5,    5, 0x08,
     358,  352,    5,    5, 0x08,
     386,  296,    5,    5, 0x08,
     425,  352,    5,    5, 0x08,
     453,  352,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Menu[] = {
    "Menu\0\0skinId\0playStory(GLint)\0"
    "skinId,levelId\0playArcade(GLint,GLint)\0"
    "playSurvivor(GLint)\0levelId\0"
    "showLevelEditor(GLint)\0mode\0"
    "setMouseMovementTracking(int)\0enabled\0"
    "enableAudio(bool)\0filename\0"
    "playAmbientMusic(QString)\0stopAmbientMusic()\0"
    "effectName\0playEffect(QString)\0"
    "skyboxName\0setSkybox(QString)\0"
    "event,listNames\0itemClicked(QMouseEvent*,QList<GLuint>)\0"
    "event\0mouseReleased(QMouseEvent*)\0"
    "mouseMoved(QMouseEvent*,QList<GLuint>)\0"
    "wheelScrolled(QWheelEvent*)\0"
    "keyPressed(QKeyEvent*)\0"
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Menu *_t = static_cast<Menu *>(_o);
        switch (_id) {
        case 0: _t->playStory((*reinterpret_cast< GLint(*)>(_a[1]))); break;
        case 1: _t->playArcade((*reinterpret_cast< GLint(*)>(_a[1])),(*reinterpret_cast< GLint(*)>(_a[2]))); break;
        case 2: _t->playSurvivor((*reinterpret_cast< GLint(*)>(_a[1]))); break;
        case 3: _t->showLevelEditor((*reinterpret_cast< GLint(*)>(_a[1]))); break;
        case 4: _t->setMouseMovementTracking((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->enableAudio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->playAmbientMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->stopAmbientMusic(); break;
        case 8: _t->playEffect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setSkybox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->itemClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 11: _t->mouseReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 12: _t->mouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 13: _t->wheelScrolled((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 14: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Menu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Menu::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Menu,
      qt_meta_data_Menu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Menu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Menu))
        return static_cast<void*>(const_cast< Menu*>(this));
    return QObject::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Menu::playStory(GLint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Menu::playArcade(GLint _t1, GLint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Menu::playSurvivor(GLint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Menu::showLevelEditor(GLint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Menu::setMouseMovementTracking(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Menu::enableAudio(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Menu::playAmbientMusic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Menu::stopAmbientMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Menu::playEffect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Menu::setSkybox(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
