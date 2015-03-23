/****************************************************************************
** Meta object code from reading C++ file 'hexEdit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modules/hexEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hexEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HexEditor[] = {

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
      15,   11,   10,   10, 0x0a,
      57,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HexEditor[] = {
    "HexEditor\0\0,,,\0analysis(char*,size_t,bool,QProgressBar*)\0"
    "clean()\0"
};

void HexEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HexEditor *_t = static_cast<HexEditor *>(_o);
        switch (_id) {
        case 0: _t->analysis((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QProgressBar*(*)>(_a[4]))); break;
        case 1: _t->clean(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HexEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HexEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HexEditor,
      qt_meta_data_HexEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HexEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HexEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HexEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HexEditor))
        return static_cast<void*>(const_cast< HexEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int HexEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
