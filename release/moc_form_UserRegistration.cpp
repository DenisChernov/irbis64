/****************************************************************************
** Meta object code from reading C++ file 'form_UserRegistration.h'
**
** Created: Sat 6. Oct 18:52:55 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form_UserRegistration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_UserRegistration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_form_UserRegistration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      54,   22,   22,   22, 0x08,
      79,   22,   22,   22, 0x08,
     105,   22,   22,   22, 0x08,
     119,   22,   22,   22, 0x08,
     135,   22,   22,   22, 0x08,
     152,   22,   22,   22, 0x08,
     179,   22,   22,   22, 0x08,
     208,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_form_UserRegistration[] = {
    "form_UserRegistration\0\0"
    "slotOnBirthYearChange(QString)\0"
    "slotOnFamChange(QString)\0"
    "slotOnAdditionalAddress()\0slotRegUser()\0"
    "slotClearForm()\0slotKeyPressed()\0"
    "slotStreetChanged(QString)\0"
    "slotCheckUserExists(QString)\0"
    "slotSetOVD_OUFMS_Year(QString)\0"
};

void form_UserRegistration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData form_UserRegistration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject form_UserRegistration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_form_UserRegistration,
      qt_meta_data_form_UserRegistration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &form_UserRegistration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *form_UserRegistration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *form_UserRegistration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_UserRegistration))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
