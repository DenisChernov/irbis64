/****************************************************************************
** Meta object code from reading C++ file 'form_UserRegistration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_UserRegistration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_UserRegistration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_UserRegistration_t {
    QByteArrayData data[11];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_form_UserRegistration_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_form_UserRegistration_t qt_meta_stringdata_form_UserRegistration = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 21),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 15),
QT_MOC_LITERAL(4, 61, 23),
QT_MOC_LITERAL(5, 85, 11),
QT_MOC_LITERAL(6, 97, 13),
QT_MOC_LITERAL(7, 111, 14),
QT_MOC_LITERAL(8, 126, 17),
QT_MOC_LITERAL(9, 144, 19),
QT_MOC_LITERAL(10, 164, 21)
    },
    "form_UserRegistration\0slotOnBirthYearChange\0"
    "\0slotOnFamChange\0slotOnAdditionalAddress\0"
    "slotRegUser\0slotClearForm\0slotKeyPressed\0"
    "slotStreetChanged\0slotCheckUserExists\0"
    "slotSetOVD_OUFMS_Year\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_UserRegistration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08,
       3,    1,   62,    2, 0x08,
       4,    0,   65,    2, 0x08,
       5,    0,   66,    2, 0x08,
       6,    0,   67,    2, 0x08,
       7,    0,   68,    2, 0x08,
       8,    1,   69,    2, 0x08,
       9,    1,   72,    2, 0x08,
      10,    1,   75,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void form_UserRegistration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_UserRegistration *_t = static_cast<form_UserRegistration *>(_o);
        switch (_id) {
        case 0: _t->slotOnBirthYearChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotOnFamChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotOnAdditionalAddress(); break;
        case 3: _t->slotRegUser(); break;
        case 4: _t->slotClearForm(); break;
        case 5: _t->slotKeyPressed(); break;
        case 6: _t->slotStreetChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotCheckUserExists((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slotSetOVD_OUFMS_Year((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject form_UserRegistration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_UserRegistration.data,
      qt_meta_data_form_UserRegistration,  qt_static_metacall, 0, 0}
};


const QMetaObject *form_UserRegistration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_UserRegistration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_UserRegistration.stringdata))
        return static_cast<void*>(const_cast< form_UserRegistration*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_UserRegistration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
