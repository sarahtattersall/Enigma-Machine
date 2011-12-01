/****************************************************************************
** Meta object code from reading C++ file 'Machine.hpp'
**
** Created: Thu Dec 1 22:12:25 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Machine.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Machine.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Machine[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      28,    8,    8,    8, 0x0a,
      45,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Machine[] = {
    "Machine\0\0load_rotor_files()\0"
    "load_plug_file()\0encrypt_text()\0"
};

void Machine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Machine *_t = static_cast<Machine *>(_o);
        switch (_id) {
        case 0: _t->load_rotor_files(); break;
        case 1: _t->load_plug_file(); break;
        case 2: _t->encrypt_text(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Machine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Machine::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Machine,
      qt_meta_data_Machine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Machine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Machine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Machine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Machine))
        return static_cast<void*>(const_cast< Machine*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Machine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
