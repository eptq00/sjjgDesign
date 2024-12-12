/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userLogin
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *duanwei;
    QPushButton *login;
    QPushButton *registerbutton;

    void setupUi(QWidget *userLogin)
    {
        if (userLogin->objectName().isEmpty())
            userLogin->setObjectName("userLogin");
        userLogin->resize(428, 312);
        label = new QLabel(userLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 130, 69, 19));
        label_2 = new QLabel(userLogin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 170, 69, 19));
        usernameEdit = new QLineEdit(userLogin);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(170, 130, 113, 25));
        passwordEdit = new QLineEdit(userLogin);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(170, 170, 113, 25));
        duanwei = new QLabel(userLogin);
        duanwei->setObjectName("duanwei");
        duanwei->setGeometry(QRect(80, 40, 261, 51));
        duanwei->setScaledContents(false);
        duanwei->setAlignment(Qt::AlignmentFlag::AlignCenter);
        login = new QPushButton(userLogin);
        login->setObjectName("login");
        login->setGeometry(QRect(90, 230, 93, 28));
        registerbutton = new QPushButton(userLogin);
        registerbutton->setObjectName("registerbutton");
        registerbutton->setGeometry(QRect(220, 230, 93, 28));

        retranslateUi(userLogin);

        QMetaObject::connectSlotsByName(userLogin);
    } // setupUi

    void retranslateUi(QWidget *userLogin)
    {
        userLogin->setWindowTitle(QCoreApplication::translate("userLogin", "Form", nullptr));
        label->setText(QCoreApplication::translate("userLogin", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("userLogin", "\345\257\206\347\240\201", nullptr));
        duanwei->setText(QString());
        login->setText(QCoreApplication::translate("userLogin", "\347\231\273\345\275\225", nullptr));
        registerbutton->setText(QCoreApplication::translate("userLogin", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userLogin: public Ui_userLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
