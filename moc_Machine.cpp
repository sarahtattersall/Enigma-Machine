/****************************************************************************
** Meta object code from reading C++ file 'Machine.hpp'
**
** Created: Fri Dec 2 22:05:34 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Machine.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Machine.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Machine[] = {

 // content:
       5,       // revision
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

const QMetaObject Machine::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Machine,
      qt_meta_data_Machine, 0 }
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
        switch (_id) {
        case 0: load_rotor_files(); break;
        case 1: load_plug_file(); break;
        case 2: encrypt_text(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
