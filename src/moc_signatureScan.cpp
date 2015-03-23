/****************************************************************************
** Meta object code from reading C++ file 'signatureScan.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modules/signatureScan.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signatureScan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SignatureScan[] = {

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
      19,   15,   14,   14, 0x0a,
      61,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SignatureScan[] = {
    "SignatureScan\0\0,,,\0"
    "analysis(char*,size_t,bool,QProgressBar*)\0"
    "clean()\0"
};

void SignatureScan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SignatureScan *_t = static_cast<SignatureScan *>(_o);
        switch (_id) {
        case 0: _t->analysis((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QProgressBar*(*)>(_a[4]))); break;
        case 1: _t->clean(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SignatureScan::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SignatureScan::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SignatureScan,
      qt_meta_data_SignatureScan, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SignatureScan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SignatureScan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SignatureScan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SignatureScan))
        return static_cast<void*>(const_cast< SignatureScan*>(this));
    return QWidget::qt_metacast(_clname);
}

int SignatureScan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
