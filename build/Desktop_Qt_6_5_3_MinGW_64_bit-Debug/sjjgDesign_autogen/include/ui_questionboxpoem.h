/********************************************************************************
** Form generated from reading UI file 'questionboxpoem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONBOXPOEM_H
#define UI_QUESTIONBOXPOEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_questionBoxPoem
{
public:
    QLabel *questionLabel;
    QLineEdit *answerEdit;
    QPushButton *sureButton;

    void setupUi(QWidget *questionBoxPoem)
    {
        if (questionBoxPoem->objectName().isEmpty())
            questionBoxPoem->setObjectName("questionBoxPoem");
        questionBoxPoem->resize(341, 172);
        questionLabel = new QLabel(questionBoxPoem);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(90, 40, 161, 21));
        answerEdit = new QLineEdit(questionBoxPoem);
        answerEdit->setObjectName("answerEdit");
        answerEdit->setGeometry(QRect(90, 80, 161, 25));
        sureButton = new QPushButton(questionBoxPoem);
        sureButton->setObjectName("sureButton");
        sureButton->setGeometry(QRect(120, 130, 93, 28));

        retranslateUi(questionBoxPoem);

        QMetaObject::connectSlotsByName(questionBoxPoem);
    } // setupUi

    void retranslateUi(QWidget *questionBoxPoem)
    {
        questionBoxPoem->setWindowTitle(QCoreApplication::translate("questionBoxPoem", "Form", nullptr));
        questionLabel->setText(QString());
        sureButton->setText(QCoreApplication::translate("questionBoxPoem", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class questionBoxPoem: public Ui_questionBoxPoem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONBOXPOEM_H
