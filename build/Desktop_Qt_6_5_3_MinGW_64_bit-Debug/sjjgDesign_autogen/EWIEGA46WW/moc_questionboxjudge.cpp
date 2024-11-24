/****************************************************************************
** Meta object code from reading C++ file 'questionboxjudge.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../questionboxjudge.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'questionboxjudge.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS = QtMocHelpers::stringData(
    "questionBoxJudge",
    "problemTotalPlus",
    "",
    "problemRightPlus",
    "on_trueButton_clicked",
    "on_falseButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[17];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[22];
    char stringdata5[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS_t qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "questionBoxJudge"
        QT_MOC_LITERAL(17, 16),  // "problemTotalPlus"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 16),  // "problemRightPlus"
        QT_MOC_LITERAL(52, 21),  // "on_trueButton_clicked"
        QT_MOC_LITERAL(74, 22)   // "on_falseButton_clicked"
    },
    "questionBoxJudge",
    "problemTotalPlus",
    "",
    "problemRightPlus",
    "on_trueButton_clicked",
    "on_falseButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSquestionBoxJudgeENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    0,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject questionBoxJudge::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSquestionBoxJudgeENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<questionBoxJudge, std::true_type>,
        // method 'problemTotalPlus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'problemRightPlus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trueButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_falseButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void questionBoxJudge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<questionBoxJudge *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->problemTotalPlus(); break;
        case 1: _t->problemRightPlus(); break;
        case 2: _t->on_trueButton_clicked(); break;
        case 3: _t->on_falseButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (questionBoxJudge::*)();
            if (_t _q_method = &questionBoxJudge::problemTotalPlus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (questionBoxJudge::*)();
            if (_t _q_method = &questionBoxJudge::problemRightPlus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *questionBoxJudge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *questionBoxJudge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSquestionBoxJudgeENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int questionBoxJudge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void questionBoxJudge::problemTotalPlus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void questionBoxJudge::problemRightPlus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
