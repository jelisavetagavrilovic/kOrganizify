/****************************************************************************
** Meta object code from reading C++ file 'syncwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/syncwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'syncwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SyncWindow_t {
    const uint offsetsAndSize[28];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SyncWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SyncWindow_t qt_meta_stringdata_SyncWindow = {
    {
QT_MOC_LITERAL(0, 10), // "SyncWindow"
QT_MOC_LITERAL(11, 15), // "sendSyncRequest"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 8), // "username"
QT_MOC_LITERAL(37, 10), // "friendName"
QT_MOC_LITERAL(48, 10), // "eventTitle"
QT_MOC_LITERAL(59, 8), // "duration"
QT_MOC_LITERAL(68, 8), // "Calendar"
QT_MOC_LITERAL(77, 8), // "calendar"
QT_MOC_LITERAL(86, 13), // "onTextEntered"
QT_MOC_LITERAL(100, 6), // "m_text"
QT_MOC_LITERAL(107, 16), // "onNumberSelected"
QT_MOC_LITERAL(124, 7), // "m_index"
QT_MOC_LITERAL(132, 19) // "onSyncButtonClicked"

    },
    "SyncWindow\0sendSyncRequest\0\0username\0"
    "friendName\0eventTitle\0duration\0Calendar\0"
    "calendar\0onTextEntered\0m_text\0"
    "onNumberSelected\0m_index\0onSyncButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SyncWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   49,    2, 0x08,    7 /* Private */,
      11,    1,   52,    2, 0x08,    9 /* Private */,
      13,    0,   55,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, 0x80000000 | 7,    3,    4,    5,    6,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void SyncWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SyncWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendSyncRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<Calendar>>(_a[5]))); break;
        case 1: _t->onTextEntered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onNumberSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onSyncButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SyncWindow::*)(QString , QString , QString , int , Calendar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SyncWindow::sendSyncRequest)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SyncWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SyncWindow.offsetsAndSize,
    qt_meta_data_SyncWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SyncWindow_t
, QtPrivate::TypeAndForceComplete<SyncWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Calendar, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SyncWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SyncWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SyncWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SyncWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SyncWindow::sendSyncRequest(QString _t1, QString _t2, QString _t3, int _t4, Calendar _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
