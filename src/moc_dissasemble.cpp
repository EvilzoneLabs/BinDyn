/****************************************************************************
** Meta object code from reading C++ file 'dissasemble.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modules/dissasemble.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dissasemble.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dissasemble[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x0a,
      59,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dissasemble[] = {
    "Dissasemble\0\0,,,\0"
    "analysis(char*,size_t,bool,QProgressBar*)\0"
    "clean()\0"
};

void Dissasemble::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dissasemble *_t = static_cast<Dissasemble *>(_o);
        switch (_id) {
        case 0: _t->analysis((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QProgressBar*(*)>(_a[4]))); break;
        case 1: _t->clean(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dissasemble::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dissasemble::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Dissasemble,
      qt_meta_data_Dissasemble, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dissasemble::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dissasemble::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dissasemble::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dissasemble))
        return static_cast<void*>(const_cast< Dissasemble*>(this));
    return QWidget::qt_metacast(_clname);
}

int Dissasemble::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
