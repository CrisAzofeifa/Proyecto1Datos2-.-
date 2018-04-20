/****************************************************************************
** Meta object code from reading C++ file 'ide_cfactorial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../forms/ide_cfactorial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ide_cfactorial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IDE_CFactorial_t {
    QByteArrayData data[24];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IDE_CFactorial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IDE_CFactorial_t qt_meta_stringdata_IDE_CFactorial = {
    {
QT_MOC_LITERAL(0, 0, 14), // "IDE_CFactorial"
QT_MOC_LITERAL(1, 15, 20), // "on_RunButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 22), // "on_ClearStdOut_clicked"
QT_MOC_LITERAL(4, 60, 22), // "on_ClearAppLog_clicked"
QT_MOC_LITERAL(5, 83, 21), // "on_StopButton_clicked"
QT_MOC_LITERAL(6, 105, 16), // "separarExpresion"
QT_MOC_LITERAL(7, 122, 6), // "string"
QT_MOC_LITERAL(8, 129, 4), // "code"
QT_MOC_LITERAL(9, 134, 5), // "nivel"
QT_MOC_LITERAL(10, 140, 21), // "on_StepButton_clicked"
QT_MOC_LITERAL(11, 162, 8), // "esNumero"
QT_MOC_LITERAL(12, 171, 5), // "valor"
QT_MOC_LITERAL(13, 177, 16), // "validarExpresion"
QT_MOC_LITERAL(14, 194, 9), // "Expresion"
QT_MOC_LITERAL(15, 204, 9), // "expresion"
QT_MOC_LITERAL(16, 214, 11), // "generarJson"
QT_MOC_LITERAL(17, 226, 4), // "tipo"
QT_MOC_LITERAL(18, 231, 6), // "nombre"
QT_MOC_LITERAL(19, 238, 7), // "tipoRef"
QT_MOC_LITERAL(20, 246, 20), // "dividirEnExpresiones"
QT_MOC_LITERAL(21, 267, 5), // "Texto"
QT_MOC_LITERAL(22, 273, 12), // "convertirInt"
QT_MOC_LITERAL(23, 286, 2) // "xi"

    },
    "IDE_CFactorial\0on_RunButton_clicked\0"
    "\0on_ClearStdOut_clicked\0on_ClearAppLog_clicked\0"
    "on_StopButton_clicked\0separarExpresion\0"
    "string\0code\0nivel\0on_StepButton_clicked\0"
    "esNumero\0valor\0validarExpresion\0"
    "Expresion\0expresion\0generarJson\0tipo\0"
    "nombre\0tipoRef\0dividirEnExpresiones\0"
    "Texto\0convertirInt\0xi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IDE_CFactorial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    2,   73,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      16,    4,   85,    2, 0x08 /* Private */,
      20,    1,   94,    2, 0x08 /* Private */,
      22,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 7,   12,
    QMetaType::Bool, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7,   17,   18,   12,   19,
    QMetaType::Void, 0x80000000 | 7,   21,
    0x80000000 | 7, QMetaType::Int,   23,

       0        // eod
};

void IDE_CFactorial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IDE_CFactorial *_t = static_cast<IDE_CFactorial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_RunButton_clicked(); break;
        case 1: _t->on_ClearStdOut_clicked(); break;
        case 2: _t->on_ClearAppLog_clicked(); break;
        case 3: _t->on_StopButton_clicked(); break;
        case 4: _t->separarExpresion((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_StepButton_clicked(); break;
        case 6: { bool _r = _t->esNumero((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->validarExpresion((*reinterpret_cast< Expresion(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->generarJson((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< string(*)>(_a[3])),(*reinterpret_cast< string(*)>(_a[4]))); break;
        case 9: _t->dividirEnExpresiones((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 10: { string _r = _t->convertirInt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject IDE_CFactorial::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_IDE_CFactorial.data,
      qt_meta_data_IDE_CFactorial,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IDE_CFactorial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IDE_CFactorial::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IDE_CFactorial.stringdata0))
        return static_cast<void*>(const_cast< IDE_CFactorial*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int IDE_CFactorial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
