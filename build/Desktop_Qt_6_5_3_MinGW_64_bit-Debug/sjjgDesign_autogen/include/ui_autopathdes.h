/********************************************************************************
** Form generated from reading UI file 'autopathdes.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOPATHDES_H
#define UI_AUTOPATHDES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_autoPathDes
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *rowEdit;
    QLineEdit *colEdit;
    QPushButton *sureButton;
    QPushButton *exitButton;

    void setupUi(QWidget *autoPathDes)
    {
        if (autoPathDes->objectName().isEmpty())
            autoPathDes->setObjectName("autoPathDes");
        autoPathDes->resize(326, 173);
        label = new QLabel(autoPathDes);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 30, 16, 19));
        label_2 = new QLabel(autoPathDes);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 70, 16, 19));
        label_3 = new QLabel(autoPathDes);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 30, 16, 19));
        label_4 = new QLabel(autoPathDes);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 70, 16, 19));
        rowEdit = new QLineEdit(autoPathDes);
        rowEdit->setObjectName("rowEdit");
        rowEdit->setGeometry(QRect(140, 30, 41, 25));
        colEdit = new QLineEdit(autoPathDes);
        colEdit->setObjectName("colEdit");
        colEdit->setGeometry(QRect(140, 70, 41, 25));
        sureButton = new QPushButton(autoPathDes);
        sureButton->setObjectName("sureButton");
        sureButton->setGeometry(QRect(90, 120, 51, 28));
        exitButton = new QPushButton(autoPathDes);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(170, 120, 51, 28));

        retranslateUi(autoPathDes);

        QMetaObject::connectSlotsByName(autoPathDes);
    } // setupUi

    void retranslateUi(QWidget *autoPathDes)
    {
        autoPathDes->setWindowTitle(QCoreApplication::translate("autoPathDes", "Form", nullptr));
        label->setText(QCoreApplication::translate("autoPathDes", "\347\254\254", nullptr));
        label_2->setText(QCoreApplication::translate("autoPathDes", "\347\254\254", nullptr));
        label_3->setText(QCoreApplication::translate("autoPathDes", "\350\241\214", nullptr));
        label_4->setText(QCoreApplication::translate("autoPathDes", "\345\210\227", nullptr));
        sureButton->setText(QCoreApplication::translate("autoPathDes", "\347\241\256\345\256\232", nullptr));
        exitButton->setText(QCoreApplication::translate("autoPathDes", "\345\210\260\347\273\210\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class autoPathDes: public Ui_autoPathDes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOPATHDES_H
