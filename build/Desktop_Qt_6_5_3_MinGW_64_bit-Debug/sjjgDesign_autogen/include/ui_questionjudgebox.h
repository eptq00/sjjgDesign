/********************************************************************************
** Form generated from reading UI file 'questionjudgebox.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONJUDGEBOX_H
#define UI_QUESTIONJUDGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_questionBox
{
public:
    QPushButton *trueButton;
    QPushButton *pushButton_2;
    QLabel *questionLabel;

    void setupUi(QWidget *questionBox)
    {
        if (questionBox->objectName().isEmpty())
            questionBox->setObjectName("questionBox");
        questionBox->resize(321, 182);
        trueButton = new QPushButton(questionBox);
        trueButton->setObjectName("trueButton");
        trueButton->setGeometry(QRect(50, 140, 93, 28));
        pushButton_2 = new QPushButton(questionBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 140, 93, 28));
        questionLabel = new QLabel(questionBox);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(50, 20, 221, 101));

        retranslateUi(questionBox);

        QMetaObject::connectSlotsByName(questionBox);
    } // setupUi

    void retranslateUi(QWidget *questionBox)
    {
        questionBox->setWindowTitle(QCoreApplication::translate("questionBox", "Form", nullptr));
        trueButton->setText(QCoreApplication::translate("questionBox", "\345\257\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("questionBox", "\351\224\231", nullptr));
        questionLabel->setText(QCoreApplication::translate("questionBox", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class questionBox: public Ui_questionBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONJUDGEBOX_H
