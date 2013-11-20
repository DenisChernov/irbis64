/****************************************************************************
** Meta object code from reading C++ file 'searchBook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "searchBook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchBook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_searchBook_t {
    QByteArrayData data[14];
    char stringdata[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_searchBook_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_searchBook_t qt_meta_stringdata_searchBook = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 18),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 24),
QT_MOC_LITERAL(4, 56, 6),
QT_MOC_LITERAL(5, 63, 21),
QT_MOC_LITERAL(6, 85, 3),
QT_MOC_LITERAL(7, 89, 16),
QT_MOC_LITERAL(8, 106, 16),
QT_MOC_LITERAL(9, 123, 16),
QT_MOC_LITERAL(10, 140, 19),
QT_MOC_LITERAL(11, 160, 16),
QT_MOC_LITERAL(12, 177, 20),
QT_MOC_LITERAL(13, 198, 21)
    },
    "searchBook\0slotFilterBookName\0\0"
    "slotChangeFilterBookName\0filter\0"
    "slotSetFilterOnFilial\0fil\0slotChangeSearch\0"
    "slotTableClicked\0slotShowFullInfo\0"
    "slotShowContextMenu\0slotViewHelpInfo\0"
    "slotInfoTimerTimeout\0slotCheckBDConnection\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_searchBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a,
       3,    1,   65,    2, 0x0a,
       5,    1,   68,    2, 0x0a,
       7,    0,   71,    2, 0x0a,
       8,    1,   72,    2, 0x0a,
       9,    0,   75,    2, 0x0a,
      10,    1,   76,    2, 0x08,
      11,    0,   79,    2, 0x08,
      12,    0,   80,    2, 0x08,
      13,    0,   81,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void searchBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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
        case 9: _t->slotCheckBDConnection(); break;
        default: ;
        }
    }
}

const QMetaObject searchBook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_searchBook.data,
      qt_meta_data_searchBook,  qt_static_metacall, 0, 0}
};


const QMetaObject *searchBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *searchBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_searchBook.stringdata))
        return static_cast<void*>(const_cast< searchBook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int searchBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
