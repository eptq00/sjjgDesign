/********************************************************************************
** Form generated from reading UI file 'questionboxjudge.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONBOXJUDGE_H
#define UI_QUESTIONBOXJUDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_questionBoxJudge
{
public:
    QLabel *questionLabel;
    QPushButton *trueButton;
    QPushButton *falseButton;

    void setupUi(QWidget *questionBoxJudge)
    {
        if (questionBoxJudge->objectName().isEmpty())
            questionBoxJudge->setObjectName("questionBoxJudge");
        questionBoxJudge->resize(312, 188);
        questionLabel = new QLabel(questionBoxJudge);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(58, 30, 201, 61));
        questionLabel->setWordWrap(true);
        trueButton = new QPushButton(questionBoxJudge);
        trueButton->setObjectName("trueButton");
        trueButton->setGeometry(QRect(50, 130, 93, 28));
        falseButton = new QPushButton(questionBoxJudge);
        falseButton->setObjectName("falseButton");
        falseButton->setGeometry(QRect(170, 130, 93, 28));

        retranslateUi(questionBoxJudge);

        QMetaObject::connectSlotsByName(questionBoxJudge);
    } // setupUi

    void retranslateUi(QWidget *questionBoxJudge)
    {
        questionBoxJudge->setWindowTitle(QCoreApplication::translate("questionBoxJudge", "Form", nullptr));
        questionLabel->setText(QString());
        trueButton->setText(QCoreApplication::translate("questionBoxJudge", "\345\257\271", nullptr));
        falseButton->setText(QCoreApplication::translate("questionBoxJudge", "\351\224\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class questionBoxJudge: public Ui_questionBoxJudge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONBOXJUDGE_H
