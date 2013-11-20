/****************************************************************************
** Meta object code from reading C++ file 'form_Information.h'
**
** Created: Sat 6. Oct 18:52:50 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form_Information.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_Information.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_form_Information[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      55,   17,   17,   17, 0x08,
      71,   17,   17,   17, 0x08,
      92,   17,   17,   17, 0x08,
     117,   17,   17,   17, 0x08,
     144,   17,   17,   17, 0x08,
     160,   17,   17,   17, 0x08,
     182,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_form_Information[] = {
    "form_Information\0\0"
    "slotGetInfosFromIrbis64ByParametrs()\0"
    "slotAddToList()\0slotRemoveFromList()\0"
    "slotSendInfosToIrbis64()\0"
    "slotFilialChanged(QString)\0slotRowFilled()\0"
    "slotTimer_FillTable()\0slotHideInfoStatus()\0"
};

void form_Information::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData form_Information::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject form_Information::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_Information,
      qt_meta_data_form_Information, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &form_Information::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *form_Information::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *form_Information::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_Information))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
