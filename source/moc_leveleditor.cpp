/****************************************************************************
** Meta object code from reading C++ file 'leveleditor.h'
**
** Created: Tue Jan 10 10:44:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "leveleditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leveleditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LevelEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      40,   33,   12,   12, 0x05,
      74,   69,   12,   12, 0x05,
     112,  104,   12,   12, 0x05,
     139,  130,   12,   12, 0x05,
     165,   12,   12,   12, 0x05,
     195,  184,   12,   12, 0x05,
     226,  215,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     261,  245,   12,   12, 0x08,
     307,  301,   12,   12, 0x08,
     335,  245,   12,   12, 0x08,
     374,  301,   12,   12, 0x08,
     402,  301,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LevelEditor[] = {
    "LevelEditor\0\0levelEditorClosed()\0"
    "_level\0addLevelToLevelsList(Level*)\0"
    "mode\0setMouseMovementTracking(int)\0"
    "enabled\0enableAudio(bool)\0filename\0"
    "playAmbientMusic(QString)\0stopAmbientMusic()\0"
    "effectName\0playEffect(QString)\0"
    "skyboxName\0setSkybox(QString)\0"
    "event,listNames\0itemClicked(QMouseEvent*,QList<GLuint>)\0"
    "event\0mouseReleased(QMouseEvent*)\0"
    "mouseMoved(QMouseEvent*,QList<GLuint>)\0"
    "wheelScrolled(QWheelEvent*)\0"
    "keyPressed(QKeyEvent*)\0"
};

void LevelEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LevelEditor *_t = static_cast<LevelEditor *>(_o);
        switch (_id) {
        case 0: _t->levelEditorClosed(); break;
        case 1: _t->addLevelToLevelsList((*reinterpret_cast< Level*(*)>(_a[1]))); break;
        case 2: _t->setMouseMovementTracking((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->enableAudio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->playAmbientMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->stopAmbientMusic(); break;
        case 6: _t->playEffect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setSkybox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->itemClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 9: _t->mouseReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: _t->mouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QList<GLuint>(*)>(_a[2]))); break;
        case 11: _t->wheelScrolled((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 12: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LevelEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LevelEditor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LevelEditor,
      qt_meta_data_LevelEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LevelEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LevelEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LevelEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LevelEditor))
        return static_cast<void*>(const_cast< LevelEditor*>(this));
    return QObject::qt_metacast(_clname);
}

int LevelEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void LevelEditor::levelEditorClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LevelEditor::addLevelToLevelsList(Level * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LevelEditor::setMouseMovementTracking(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LevelEditor::enableAudio(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LevelEditor::playAmbientMusic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LevelEditor::stopAmbientMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void LevelEditor::playEffect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void LevelEditor::setSkybox(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
