/****************************************************************************
** Meta object code from reading C++ file 'manche.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../QT_Application2/manche.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manche.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Manche_t {
    const uint offsetsAndSize[18];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Manche_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Manche_t qt_meta_stringdata_Manche = {
    {
QT_MOC_LITERAL(0, 6), // "Manche"
QT_MOC_LITERAL(7, 13), // "relancer_menu"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 6), // "fermer"
QT_MOC_LITERAL(29, 14), // "afficher_effet"
QT_MOC_LITERAL(44, 15), // "acheter_reserve"
QT_MOC_LITERAL(60, 19), // "construire_monument"
QT_MOC_LITERAL(80, 18), // "eliminerCarteChere"
QT_MOC_LITERAL(99, 12) // "terminertour"

    },
    "Manche\0relancer_menu\0\0fermer\0"
    "afficher_effet\0acheter_reserve\0"
    "construire_monument\0eliminerCarteChere\0"
    "terminertour"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Manche[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Manche::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Manche *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->relancer_menu(); break;
        case 1: _t->fermer(); break;
        case 2: _t->afficher_effet(); break;
        case 3: _t->acheter_reserve(); break;
        case 4: _t->construire_monument(); break;
        case 5: _t->eliminerCarteChere(); break;
        case 6: _t->terminertour(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Manche::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manche::relancer_menu)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Manche::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Manche.offsetsAndSize,
    qt_meta_data_Manche,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Manche_t
, QtPrivate::TypeAndForceComplete<Manche, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Manche::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manche::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Manche.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Manche::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Manche::relancer_menu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
