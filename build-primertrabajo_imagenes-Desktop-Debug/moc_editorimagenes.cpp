/****************************************************************************
** Meta object code from reading C++ file 'editorimagenes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../primertrabajo_imagenes/editorimagenes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editorimagenes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditorImagenes_t {
    QByteArrayData data[10];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditorImagenes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditorImagenes_t qt_meta_stringdata_EditorImagenes = {
    {
QT_MOC_LITERAL(0, 0, 14), // "EditorImagenes"
QT_MOC_LITERAL(1, 15, 23), // "on_select_image_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 35), // "on_btn_difuminado_aleatorio_c..."
QT_MOC_LITERAL(4, 76, 38), // "on_btn_transformacion_bilinel..."
QT_MOC_LITERAL(5, 115, 20), // "on_btn_sobel_clicked"
QT_MOC_LITERAL(6, 136, 29), // "on_btn_filtro_mediana_clicked"
QT_MOC_LITERAL(7, 166, 38), // "on_btn_ecualizacion_histogram..."
QT_MOC_LITERAL(8, 205, 18), // "on_btn_fft_clicked"
QT_MOC_LITERAL(9, 224, 21) // "on_btn_rgbHSI_clicked"

    },
    "EditorImagenes\0on_select_image_clicked\0"
    "\0on_btn_difuminado_aleatorio_clicked\0"
    "on_btn_transformacion_bilinela_clicked\0"
    "on_btn_sobel_clicked\0on_btn_filtro_mediana_clicked\0"
    "on_btn_ecualizacion_histograma_clicked\0"
    "on_btn_fft_clicked\0on_btn_rgbHSI_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditorImagenes[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditorImagenes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditorImagenes *_t = static_cast<EditorImagenes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_select_image_clicked(); break;
        case 1: _t->on_btn_difuminado_aleatorio_clicked(); break;
        case 2: _t->on_btn_transformacion_bilinela_clicked(); break;
        case 3: _t->on_btn_sobel_clicked(); break;
        case 4: _t->on_btn_filtro_mediana_clicked(); break;
        case 5: _t->on_btn_ecualizacion_histograma_clicked(); break;
        case 6: _t->on_btn_fft_clicked(); break;
        case 7: _t->on_btn_rgbHSI_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EditorImagenes::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EditorImagenes.data,
      qt_meta_data_EditorImagenes,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditorImagenes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditorImagenes::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditorImagenes.stringdata0))
        return static_cast<void*>(const_cast< EditorImagenes*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EditorImagenes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
