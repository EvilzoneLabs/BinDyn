/****************************************************************************
** Meta object code from reading C++ file 'printableMap.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modules/printableMap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printableMap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrintableMap[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      32,   13,   13,   13, 0x0a,
      51,   13,   13,   13, 0x0a,
      74,   13,   13,   13, 0x0a,
      93,   13,   13,   13, 0x0a,
     113,  109,   13,   13, 0x0a,
     155,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PrintableMap[] = {
    "PrintableMap\0\0nullColorDialog()\0"
    "belowColorDialog()\0printableColorDialog()\0"
    "aboveColorDialog()\0ffColorDialog()\0"
    ",,,\0analysis(char*,size_t,bool,QProgressBar*)\0"
    "clean()\0"
};

void PrintableMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PrintableMap *_t = static_cast<PrintableMap *>(_o);
        switch (_id) {
        case 0: _t->nullColorDialog(); break;
        case 1: _t->belowColorDialog(); break;
        case 2: _t->printableColorDialog(); break;
        case 3: _t->aboveColorDialog(); break;
        case 4: _t->ffColorDialog(); break;
        case 5: _t->analysis((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QProgressBar*(*)>(_a[4]))); break;
        case 6: _t->clean(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PrintableMap::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PrintableMap::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PrintableMap,
      qt_meta_data_PrintableMap, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrintableMap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrintableMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrintableMap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintableMap))
        return static_cast<void*>(const_cast< PrintableMap*>(this));
    return QWidget::qt_metacast(_clname);
}

int PrintableMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
