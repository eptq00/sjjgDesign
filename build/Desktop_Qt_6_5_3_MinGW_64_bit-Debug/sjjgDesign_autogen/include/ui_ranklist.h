/********************************************************************************
** Form generated from reading UI file 'ranklist.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKLIST_H
#define UI_RANKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rankList
{
public:
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QComboBox *comboBox;

    void setupUi(QWidget *rankList)
    {
        if (rankList->objectName().isEmpty())
            rankList->setObjectName("rankList");
        rankList->resize(319, 462);
        textBrowser = new QTextBrowser(rankList);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 60, 281, 391));
        verticalScrollBar = new QScrollBar(rankList);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(280, 60, 16, 391));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        comboBox = new QComboBox(rankList);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(110, 20, 83, 25));

        retranslateUi(rankList);

        QMetaObject::connectSlotsByName(rankList);
    } // setupUi

    void retranslateUi(QWidget *rankList)
    {
        rankList->setWindowTitle(QCoreApplication::translate("rankList", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("rankList", "\350\257\267\351\200\211\346\213\251", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("rankList", "\345\201\232\351\242\230\346\225\260", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("rankList", "\346\255\243\347\241\256\346\225\260", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("rankList", "\345\207\206\347\241\256\347\216\207", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("rankList", "\346\256\265\344\275\215", nullptr));

    } // retranslateUi

};

namespace Ui {
    class rankList: public Ui_rankList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKLIST_H
