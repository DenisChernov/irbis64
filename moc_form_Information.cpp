/****************************************************************************
** Meta object code from reading C++ file 'form_Information.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_Information.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_Information.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_Information_t {
    QByteArrayData data[10];
    char stringdata[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_form_Information_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_form_Information_t qt_meta_stringdata_form_Information = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 34),
QT_MOC_LITERAL(2, 52, 0),
QT_MOC_LITERAL(3, 53, 13),
QT_MOC_LITERAL(4, 67, 18),
QT_MOC_LITERAL(5, 86, 22),
QT_MOC_LITERAL(6, 109, 17),
QT_MOC_LITERAL(7, 127, 13),
QT_MOC_LITERAL(8, 141, 19),
QT_MOC_LITERAL(9, 161, 18)
    },
    "form_Information\0slotGetInfosFromIrbis64ByParametrs\0"
    "\0slotAddToList\0slotRemoveFromList\0"
    "slotSendInfosToIrbis64\0slotFilialChanged\0"
    "slotRowFilled\0slotTimer_FillTable\0"
    "slotHideInfoStatus\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_Information[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    1,   58,    2, 0x08,
       7,    0,   61,    2, 0x08,
       8,    0,   62,    2, 0x08,
       9,    0,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void form_Information::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_Information *_t = static_cast<form_Information *>(_o);
        switch (_id) {
        case 0: _t->slotGetInfosFromIrbis64ByParametrs(); break;
        case 1: _t->slotAddToList(); break;
        case 2: _t->slotRemoveFromList(); break;
        case 3: _t->slotSendInfosToIrbis64(); break;
        case 4: _t->slotFilialChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotRowFilled(); break;
        case 6: _t->slotTimer_FillTable(); break;
        case 7: _t->slotHideInfoStatus(); break;
        default: ;
        }
    }
}

const QMetaObject form_Information::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_Information.data,
      qt_meta_data_form_Information,  qt_static_metacall, 0, 0}
};


const QMetaObject *form_Information::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_Information::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_Information.stringdata))
        return static_cast<void*>(const_cast< form_Information*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_Information::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
