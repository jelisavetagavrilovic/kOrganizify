/****************************************************************************
** Meta object code from reading C++ file 'basiceventwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/basiceventwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basiceventwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BasicEventWindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BasicEventWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BasicEventWindow_t qt_meta_stringdata_BasicEventWindow = {
    {
QT_MOC_LITERAL(0, 16), // "BasicEventWindow"
QT_MOC_LITERAL(17, 22), // "previousCalendarSignal"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 9), // "Calendar*"
QT_MOC_LITERAL(51, 10), // "m_calendar"
QT_MOC_LITERAL(62, 18), // "nextCalendarSignal"
QT_MOC_LITERAL(81, 12), // "saveCalendar"
QT_MOC_LITERAL(94, 8), // "addEvent"
QT_MOC_LITERAL(103, 2), // "op"
QT_MOC_LITERAL(106, 11), // "removeEvent"
QT_MOC_LITERAL(118, 8), // "generate"
QT_MOC_LITERAL(127, 9), // "nextEvent"
QT_MOC_LITERAL(137, 13), // "previousEvent"
QT_MOC_LITERAL(151, 8), // "updateUi"
QT_MOC_LITERAL(160, 16), // "previousCalendar"
QT_MOC_LITERAL(177, 12) // "nextCalendar"

    },
    "BasicEventWindow\0previousCalendarSignal\0"
    "\0Calendar*\0m_calendar\0nextCalendarSignal\0"
    "saveCalendar\0addEvent\0op\0removeEvent\0"
    "generate\0nextEvent\0previousEvent\0"
    "updateUi\0previousCalendar\0nextCalendar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasicEventWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       5,    1,   83,    2, 0x06,    3 /* Public */,
       6,    1,   86,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   89,    2, 0x08,    7 /* Private */,
       9,    0,   92,    2, 0x08,    9 /* Private */,
      10,    0,   93,    2, 0x08,   10 /* Private */,
      11,    0,   94,    2, 0x08,   11 /* Private */,
      12,    0,   95,    2, 0x08,   12 /* Private */,
      13,    0,   96,    2, 0x08,   13 /* Private */,
      14,    0,   97,    2, 0x08,   14 /* Private */,
      15,    0,   98,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Bool, QMetaType::Char,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BasicEventWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BasicEventWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->previousCalendarSignal((*reinterpret_cast< std::add_pointer_t<Calendar*>>(_a[1]))); break;
        case 1: _t->nextCalendarSignal((*reinterpret_cast< std::add_pointer_t<Calendar*>>(_a[1]))); break;
        case 2: _t->saveCalendar((*reinterpret_cast< std::add_pointer_t<Calendar*>>(_a[1]))); break;
        case 3: { bool _r = _t->addEvent((*reinterpret_cast< std::add_pointer_t<char>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->removeEvent(); break;
        case 5: _t->generate(); break;
        case 6: _t->nextEvent(); break;
        case 7: _t->previousEvent(); break;
        case 8: _t->updateUi(); break;
        case 9: _t->previousCalendar(); break;
        case 10: _t->nextCalendar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BasicEventWindow::*)(Calendar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BasicEventWindow::previousCalendarSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BasicEventWindow::*)(Calendar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BasicEventWindow::nextCalendarSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BasicEventWindow::*)(Calendar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BasicEventWindow::saveCalendar)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject BasicEventWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_BasicEventWindow.offsetsAndSize,
    qt_meta_data_BasicEventWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BasicEventWindow_t
, QtPrivate::TypeAndForceComplete<BasicEventWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Calendar *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Calendar *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Calendar *, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const char, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BasicEventWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasicEventWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BasicEventWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BasicEventWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BasicEventWindow::previousCalendarSignal(Calendar * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BasicEventWindow::nextCalendarSignal(Calendar * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BasicEventWindow::saveCalendar(Calendar * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
