/********************************************************************************
** Form generated from reading UI file 'questionbox.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONBOX_H
#define UI_QUESTIONBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_questionBox
{
public:

    void setupUi(QWidget *questionBox)
    {
        if (questionBox->objectName().isEmpty())
            questionBox->setObjectName("questionBox");
        questionBox->resize(400, 300);

        retranslateUi(questionBox);

        QMetaObject::connectSlotsByName(questionBox);
    } // setupUi

    void retranslateUi(QWidget *questionBox)
    {
        questionBox->setWindowTitle(QCoreApplication::translate("questionBox", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class questionBox: public Ui_questionBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONBOX_H
