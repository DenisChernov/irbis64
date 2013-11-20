/****************************************************************************
** Meta object code from reading C++ file 'form_DownloadBooks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_DownloadBooks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_DownloadBooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_DownloadBooks_t {
    QByteArrayData data[8];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_form_DownloadBooks_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_form_DownloadBooks_t qt_meta_stringdata_form_DownloadBooks = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 12),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 15),
QT_MOC_LITERAL(4, 49, 16),
QT_MOC_LITERAL(5, 66, 12),
QT_MOC_LITERAL(6, 79, 2),
QT_MOC_LITERAL(7, 82, 9)
    },
    "form_DownloadBooks\0slotGetBooks\0\0"
    "slotUploadBooks\0slotPrepareFiles\0"
    "slotChangeBD\0bd\0slotlogin\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_DownloadBooks[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08,
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    1,   42,    2, 0x08,
       7,    0,   45,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void form_DownloadBooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_DownloadBooks *_t = static_cast<form_DownloadBooks *>(_o);
        switch (_id) {
        case 0: _t->slotGetBooks(); break;
        case 1: _t->slotUploadBooks(); break;
        case 2: _t->slotPrepareFiles(); break;
        case 3: _t->slotChangeBD((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotlogin(); break;
        default: ;
        }
    }
}

const QMetaObject form_DownloadBooks::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_DownloadBooks.data,
      qt_meta_data_form_DownloadBooks,  qt_static_metacall, 0, 0}
};


const QMetaObject *form_DownloadBooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_DownloadBooks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_DownloadBooks.stringdata))
        return static_cast<void*>(const_cast< form_DownloadBooks*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_DownloadBooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
