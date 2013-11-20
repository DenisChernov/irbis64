/****************************************************************************
** Meta object code from reading C++ file 'form_UserReRg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form_UserReRg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_UserReRg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_form_UserReRg_t {
    QByteArrayData data[18];
    char stringdata[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_form_UserReRg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_form_UserReRg_t qt_meta_stringdata_form_UserReRg = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 10),
QT_MOC_LITERAL(4, 41, 19),
QT_MOC_LITERAL(5, 61, 14),
QT_MOC_LITERAL(6, 76, 22),
QT_MOC_LITERAL(7, 99, 25),
QT_MOC_LITERAL(8, 125, 16),
QT_MOC_LITERAL(9, 142, 15),
QT_MOC_LITERAL(10, 158, 25),
QT_MOC_LITERAL(11, 184, 24),
QT_MOC_LITERAL(12, 209, 24),
QT_MOC_LITERAL(13, 234, 24),
QT_MOC_LITERAL(14, 259, 12),
QT_MOC_LITERAL(15, 272, 17),
QT_MOC_LITERAL(16, 290, 34),
QT_MOC_LITERAL(17, 325, 3)
    },
    "form_UserReRg\0slotSearchByID\0\0slotSearch\0"
    "slotShowContextMenu\0slotDeleteItem\0"
    "slotSendUpdatedRecords\0slot_DefenceFromDuplicate\0"
    "slot_DateChanged\0slot_fioChanged\0"
    "slot_DebugViewFrontRecord\0"
    "slot_DebugViewBackRecord\0"
    "slot_DebugViewNextRecord\0"
    "slot_DebugViewPrevRecord\0slot_timerGO\0"
    "slot_timerHideMsg\0slot_EnableDisableSearchingMethods\0"
    "txt\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_UserReRg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08,
       3,    0,   90,    2, 0x08,
       4,    1,   91,    2, 0x08,
       5,    0,   94,    2, 0x08,
       6,    0,   95,    2, 0x08,
       7,    1,   96,    2, 0x08,
       8,    1,   99,    2, 0x08,
       9,    1,  102,    2, 0x08,
      10,    0,  105,    2, 0x08,
      11,    0,  106,    2, 0x08,
      12,    0,  107,    2, 0x08,
      13,    0,  108,    2, 0x08,
      14,    0,  109,    2, 0x08,
      15,    0,  110,    2, 0x08,
      16,    1,  111,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void form_UserReRg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        form_UserReRg *_t = static_cast<form_UserReRg *>(_o);
        switch (_id) {
        case 0: _t->slotSearchByID(); break;
        case 1: _t->slotSearch(); break;
        case 2: _t->slotShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->slotDeleteItem(); break;
        case 4: _t->slotSendUpdatedRecords(); break;
        case 5: _t->slot_DefenceFromDuplicate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_DateChanged((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 7: _t->slot_fioChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slot_DebugViewFrontRecord(); break;
        case 9: _t->slot_DebugViewBackRecord(); break;
        case 10: _t->slot_DebugViewNextRecord(); break;
        case 11: _t->slot_DebugViewPrevRecord(); break;
        case 12: _t->slot_timerGO(); break;
        case 13: _t->slot_timerHideMsg(); break;
        case 14: _t->slot_EnableDisableSearchingMethods((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject form_UserReRg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_UserReRg.data,
      qt_meta_data_form_UserReRg,  qt_static_metacall, 0, 0}
};


const QMetaObject *form_UserReRg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_UserReRg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_UserReRg.stringdata))
        return static_cast<void*>(const_cast< form_UserReRg*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_UserReRg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
