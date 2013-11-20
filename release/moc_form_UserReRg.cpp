/****************************************************************************
** Meta object code from reading C++ file 'form_UserReRg.h'
**
** Created: Sat 6. Oct 18:52:58 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form_UserReRg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_UserReRg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_form_UserReRg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      32,   14,   14,   14, 0x08,
      45,   14,   14,   14, 0x08,
      73,   14,   14,   14, 0x08,
      90,   14,   14,   14, 0x08,
     115,   14,   14,   14, 0x08,
     146,   14,   14,   14, 0x08,
     170,   14,   14,   14, 0x08,
     195,   14,   14,   14, 0x08,
     223,   14,   14,   14, 0x08,
     250,   14,   14,   14, 0x08,
     277,   14,   14,   14, 0x08,
     304,   14,   14,   14, 0x08,
     323,  319,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_form_UserReRg[] = {
    "form_UserReRg\0\0slotSearchByID()\0"
    "slotSearch()\0slotShowContextMenu(QPoint)\0"
    "slotDeleteItem()\0slotSendUpdatedRecords()\0"
    "slot_DefenceFromDuplicate(int)\0"
    "slot_DateChanged(QDate)\0"
    "slot_fioChanged(QString)\0"
    "slot_DebugViewFrontRecord()\0"
    "slot_DebugViewBackRecord()\0"
    "slot_DebugViewNextRecord()\0"
    "slot_DebugViewPrevRecord()\0slot_timerGO()\0"
    "txt\0slot_EnableDisableSearchingMethods(QString)\0"
};

void form_UserReRg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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
        case 13: _t->slot_EnableDisableSearchingMethods((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData form_UserReRg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject form_UserReRg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_UserReRg,
      qt_meta_data_form_UserReRg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &form_UserReRg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *form_UserReRg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *form_UserReRg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_UserReRg))
        return static_cast<void*>(const_cast< form_UserReRg*>(this));
    return QDialog::qt_metacast(_clname);
}

int form_UserReRg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
