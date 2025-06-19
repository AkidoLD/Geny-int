/****************************************************************************
** Meta object code from reading C++ file 'DashBord.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ui/MainWindow/BodyBox/DashBord.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DashBord.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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
struct qt_meta_stringdata_CLASSPasswordPackENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPasswordPackENDCLASS = QtMocHelpers::stringData(
    "PasswordPack",
    "display_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "generate_bt_clicked",
    "config_change"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPasswordPackENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[13];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[20];
    char stringdata6[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPasswordPackENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPasswordPackENDCLASS_t qt_meta_stringdata_CLASSPasswordPackENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "PasswordPack"
        QT_MOC_LITERAL(13, 18),  // "display_bt_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 10),  // "ConfigBox*"
        QT_MOC_LITERAL(44, 10),  // "ResultBox*"
        QT_MOC_LITERAL(55, 19),  // "generate_bt_clicked"
        QT_MOC_LITERAL(75, 13)   // "config_change"
    },
    "PasswordPack",
    "display_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "generate_bt_clicked",
    "config_change"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPasswordPackENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,
       5,    2,   37,    2, 0x06,    4 /* Public */,
       6,    1,   42,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject PasswordPack::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPasswordPackENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPasswordPackENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPasswordPackENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PasswordPack, std::true_type>,
        // method 'display_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'generate_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'config_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>
    >,
    nullptr
} };

void PasswordPack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PasswordPack *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->display_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 1: _t->generate_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 2: _t->config_change((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PasswordPack::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &PasswordPack::display_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PasswordPack::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &PasswordPack::generate_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PasswordPack::*)(ConfigBox * );
            if (_t _q_method = &PasswordPack::config_change; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *PasswordPack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PasswordPack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPasswordPackENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PasswordPack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PasswordPack::display_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PasswordPack::generate_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PasswordPack::config_change(ConfigBox * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUidPackENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUidPackENDCLASS = QtMocHelpers::stringData(
    "UidPack",
    "display_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "generate_bt_clicked",
    "config_change"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUidPackENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[8];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[20];
    char stringdata6[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUidPackENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUidPackENDCLASS_t qt_meta_stringdata_CLASSUidPackENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "UidPack"
        QT_MOC_LITERAL(8, 18),  // "display_bt_clicked"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 10),  // "ConfigBox*"
        QT_MOC_LITERAL(39, 10),  // "ResultBox*"
        QT_MOC_LITERAL(50, 19),  // "generate_bt_clicked"
        QT_MOC_LITERAL(70, 13)   // "config_change"
    },
    "UidPack",
    "display_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "generate_bt_clicked",
    "config_change"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUidPackENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,
       5,    2,   37,    2, 0x06,    4 /* Public */,
       6,    1,   42,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject UidPack::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSUidPackENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUidPackENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUidPackENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UidPack, std::true_type>,
        // method 'display_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'generate_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'config_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>
    >,
    nullptr
} };

void UidPack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UidPack *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->display_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 1: _t->generate_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 2: _t->config_change((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UidPack::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &UidPack::display_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UidPack::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &UidPack::generate_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UidPack::*)(ConfigBox * );
            if (_t _q_method = &UidPack::config_change; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *UidPack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UidPack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUidPackENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UidPack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UidPack::display_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UidPack::generate_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UidPack::config_change(ConfigBox * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPseudoPackENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPseudoPackENDCLASS = QtMocHelpers::stringData(
    "PseudoPack",
    "display_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "generate_bt_clicked",
    "config_change"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPseudoPackENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[20];
    char stringdata6[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPseudoPackENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPseudoPackENDCLASS_t qt_meta_stringdata_CLASSPseudoPackENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "PseudoPack"
        QT_MOC_LITERAL(11, 18),  // "display_bt_clicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 10),  // "ConfigBox*"
        QT_MOC_LITERAL(42, 10),  // "ResultBox*"
        QT_MOC_LITERAL(53, 19),  // "generate_bt_clicked"
        QT_MOC_LITERAL(73, 13)   // "config_change"
    },
    "PseudoPack",
    "display_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "generate_bt_clicked",
    "config_change"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPseudoPackENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,
       5,    2,   37,    2, 0x06,    4 /* Public */,
       6,    1,   42,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject PseudoPack::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPseudoPackENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPseudoPackENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPseudoPackENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PseudoPack, std::true_type>,
        // method 'display_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'generate_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'config_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>
    >,
    nullptr
} };

void PseudoPack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PseudoPack *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->display_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 1: _t->generate_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 2: _t->config_change((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PseudoPack::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &PseudoPack::display_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PseudoPack::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &PseudoPack::generate_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PseudoPack::*)(ConfigBox * );
            if (_t _q_method = &PseudoPack::config_change; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *PseudoPack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PseudoPack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPseudoPackENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PseudoPack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PseudoPack::display_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PseudoPack::generate_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PseudoPack::config_change(ConfigBox * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDashBordENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDashBordENDCLASS = QtMocHelpers::stringData(
    "DashBord",
    "generate_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "config_change",
    "on_display_bt_clicked",
    "on_generate_signal_emit",
    "on_change_config"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDashBordENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[14];
    char stringdata6[22];
    char stringdata7[24];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDashBordENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDashBordENDCLASS_t qt_meta_stringdata_CLASSDashBordENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "DashBord"
        QT_MOC_LITERAL(9, 19),  // "generate_bt_clicked"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 10),  // "ConfigBox*"
        QT_MOC_LITERAL(41, 10),  // "ResultBox*"
        QT_MOC_LITERAL(52, 13),  // "config_change"
        QT_MOC_LITERAL(66, 21),  // "on_display_bt_clicked"
        QT_MOC_LITERAL(88, 23),  // "on_generate_signal_emit"
        QT_MOC_LITERAL(112, 16)   // "on_change_config"
    },
    "DashBord",
    "generate_bt_clicked",
    "",
    "ConfigBox*",
    "ResultBox*",
    "config_change",
    "on_display_bt_clicked",
    "on_generate_signal_emit",
    "on_change_config"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDashBordENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,
       5,    1,   49,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   52,    2, 0x08,    6 /* Private */,
       7,    2,   57,    2, 0x08,    9 /* Private */,
       8,    1,   62,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject DashBord::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSDashBordENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDashBordENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDashBordENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DashBord, std::true_type>,
        // method 'generate_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'config_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        // method 'on_display_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'on_generate_signal_emit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResultBox *, std::false_type>,
        // method 'on_change_config'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ConfigBox *, std::false_type>
    >,
    nullptr
} };

void DashBord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DashBord *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->generate_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 1: _t->config_change((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1]))); break;
        case 2: _t->on_display_bt_clicked((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 3: _t->on_generate_signal_emit((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ResultBox*>>(_a[2]))); break;
        case 4: _t->on_change_config((*reinterpret_cast< std::add_pointer_t<ConfigBox*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ResultBox* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ConfigBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DashBord::*)(ConfigBox * , ResultBox * );
            if (_t _q_method = &DashBord::generate_bt_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DashBord::*)(ConfigBox * );
            if (_t _q_method = &DashBord::config_change; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *DashBord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashBord::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDashBordENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DashBord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DashBord::generate_bt_clicked(ConfigBox * _t1, ResultBox * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DashBord::config_change(ConfigBox * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
