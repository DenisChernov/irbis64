/****************************************************************************
** Meta object code from reading C++ file 'searchBook.h'
**
** Created: Thu 11. Oct 13:50:32 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../searchBook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchBook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_searchBook[] = {

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
      12,   11,   11,   11, 0x0a,
      40,   33,   11,   11, 0x0a,
      78,   74,   11,   11, 0x0a,
     109,   11,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     158,   11,   11,   11, 0x0a,
     177,   11,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_searchBook[] = {
    "searchBook\0\0slotFilterBookName()\0"
    "filter\0slotChangeFilterBookName(QString)\0"
    "fil\0slotSetFilterOnFilial(QString)\0"
    "slotChangeSearch()\0slotTableClicked(QModelIndex)\0"
    "slotShowFullInfo()\0slotShowContextMenu(QPoint)\0"
    "slotViewHelpInfo()\0slotInfoTimerTimeout()\0"
};

void searchBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        searchBook *_t = static_cast<searchBook *>(_o);
        switch (_id) {
        case 0: _t->slotFilterBookName(); break;
        case 1: _t->slotChangeFilterBookName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotSetFilterOnFilial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotChangeSearch(); break;
        case 4: _t->slotTableClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->slotShowFullInfo(); break;
        case 6: _t->slotShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->slotViewHelpInfo(); break;
        case 8: _t->slotInfoTimerTimeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData searchBook::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject searchBook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_searchBook,
      qt_meta_data_searchBook, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &searchBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *searchBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *searchBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_searchBook))
        return static_cast<void*>(const_cast< searchBook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int searchBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
