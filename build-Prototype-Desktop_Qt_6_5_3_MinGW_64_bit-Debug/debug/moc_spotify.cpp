/****************************************************************************
** Meta object code from reading C++ file 'spotify.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Project/spotify.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spotify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSspotifyENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSspotifyENDCLASS = QtMocHelpers::stringData(
    "spotify",
    "updateDuration",
    "",
    "duration",
    "durationChanged",
    "positionChanged",
    "position",
    "on_play_button_clicked",
    "on_mute_button_clicked",
    "on_pushButton_clicked",
    "on_volumeSlider_valueChanged",
    "value",
    "on_musicTimer_valueChanged",
    "on_skip_ten_seconds_back_clicked",
    "on_skip_ten_seconds_foward_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSspotifyENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[8];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[16];
    char stringdata5[16];
    char stringdata6[9];
    char stringdata7[23];
    char stringdata8[23];
    char stringdata9[22];
    char stringdata10[29];
    char stringdata11[6];
    char stringdata12[27];
    char stringdata13[33];
    char stringdata14[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSspotifyENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSspotifyENDCLASS_t qt_meta_stringdata_CLASSspotifyENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "spotify"
        QT_MOC_LITERAL(8, 14),  // "updateDuration"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 8),  // "duration"
        QT_MOC_LITERAL(33, 15),  // "durationChanged"
        QT_MOC_LITERAL(49, 15),  // "positionChanged"
        QT_MOC_LITERAL(65, 8),  // "position"
        QT_MOC_LITERAL(74, 22),  // "on_play_button_clicked"
        QT_MOC_LITERAL(97, 22),  // "on_mute_button_clicked"
        QT_MOC_LITERAL(120, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(142, 28),  // "on_volumeSlider_valueChanged"
        QT_MOC_LITERAL(171, 5),  // "value"
        QT_MOC_LITERAL(177, 26),  // "on_musicTimer_valueChanged"
        QT_MOC_LITERAL(204, 32),  // "on_skip_ten_seconds_back_clicked"
        QT_MOC_LITERAL(237, 34)   // "on_skip_ten_seconds_foward_cl..."
    },
    "spotify",
    "updateDuration",
    "",
    "duration",
    "durationChanged",
    "positionChanged",
    "position",
    "on_play_button_clicked",
    "on_mute_button_clicked",
    "on_pushButton_clicked",
    "on_volumeSlider_valueChanged",
    "value",
    "on_musicTimer_valueChanged",
    "on_skip_ten_seconds_back_clicked",
    "on_skip_ten_seconds_foward_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSspotifyENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x08,    1 /* Private */,
       4,    1,   77,    2, 0x08,    3 /* Private */,
       5,    1,   80,    2, 0x08,    5 /* Private */,
       7,    0,   83,    2, 0x08,    7 /* Private */,
       8,    0,   84,    2, 0x08,    8 /* Private */,
       9,    0,   85,    2, 0x08,    9 /* Private */,
      10,    1,   86,    2, 0x08,   10 /* Private */,
      12,    1,   89,    2, 0x08,   12 /* Private */,
      13,    0,   92,    2, 0x08,   14 /* Private */,
      14,    0,   93,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject spotify::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSspotifyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSspotifyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSspotifyENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<spotify, std::true_type>,
        // method 'updateDuration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'positionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'on_play_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mute_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_volumeSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_musicTimer_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_skip_ten_seconds_back_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_skip_ten_seconds_foward_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void spotify::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<spotify *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateDuration((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 1: _t->durationChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 2: _t->positionChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 3: _t->on_play_button_clicked(); break;
        case 4: _t->on_mute_button_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_volumeSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_musicTimer_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_skip_ten_seconds_back_clicked(); break;
        case 9: _t->on_skip_ten_seconds_foward_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *spotify::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spotify::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSspotifyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int spotify::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
