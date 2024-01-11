/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/settingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsWindow_t {
    const uint offsetsAndSize[34];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SettingsWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SettingsWindow_t qt_meta_stringdata_SettingsWindow = {
    {
QT_MOC_LITERAL(0, 14), // "SettingsWindow"
QT_MOC_LITERAL(15, 12), // "colorChanged"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 5), // "color"
QT_MOC_LITERAL(35, 20), // "enabledNotifications"
QT_MOC_LITERAL(56, 7), // "enabled"
QT_MOC_LITERAL(64, 11), // "changeColor"
QT_MOC_LITERAL(76, 16), // "setNotifications"
QT_MOC_LITERAL(93, 13), // "notifications"
QT_MOC_LITERAL(107, 16), // "getNotifications"
QT_MOC_LITERAL(124, 22), // "updateNotificationIcon"
QT_MOC_LITERAL(147, 5), // "state"
QT_MOC_LITERAL(153, 21), // "getColorNameFromValue"
QT_MOC_LITERAL(175, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(197, 8), // "colorMap"
QT_MOC_LITERAL(206, 5), // "value"
QT_MOC_LITERAL(212, 4) // "save"

    },
    "SettingsWindow\0colorChanged\0\0color\0"
    "enabledNotifications\0enabled\0changeColor\0"
    "setNotifications\0notifications\0"
    "getNotifications\0updateNotificationIcon\0"
    "state\0getColorNameFromValue\0"
    "QMap<QString,QString>\0colorMap\0value\0"
    "save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   68,    2, 0x0a,    5 /* Public */,
       7,    1,   71,    2, 0x0a,    7 /* Public */,
       9,    0,   74,    2, 0x10a,    9 /* Public | MethodIsConst  */,
      10,    1,   75,    2, 0x0a,   10 /* Public */,
      12,    2,   78,    2, 0x08,   12 /* Private */,
      16,    0,   83,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::QString, 0x80000000 | 13, QMetaType::QString,   14,   15,
    QMetaType::Void,

       0        // eod
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->enabledNotifications((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->changeColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setNotifications((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: { bool _r = _t->getNotifications();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->updateNotificationIcon((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: { QString _r = _t->getColorNameFromValue((*reinterpret_cast< std::add_pointer_t<QMap<QString,QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->save(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingsWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::colorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SettingsWindow::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::enabledNotifications)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SettingsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SettingsWindow.offsetsAndSize,
    qt_meta_data_SettingsWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SettingsWindow_t
, QtPrivate::TypeAndForceComplete<SettingsWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<const QMap<QString,QString> &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SettingsWindow::colorChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SettingsWindow::enabledNotifications(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
