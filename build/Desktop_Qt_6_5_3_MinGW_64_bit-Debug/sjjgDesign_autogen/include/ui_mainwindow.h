/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "rescaleimg.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *mazeSizeBox;
    QLabel *mazeSizeLabel1;
    QLabel *mazeSizeLabel2;
    QLineEdit *mazeSizeLine;
    QGridLayout *numberBox_2;
    QPushButton *mazeSize8;
    QPushButton *mazeSize2;
    QPushButton *mazeSize7;
    QPushButton *mazeSize5;
    QPushButton *mazeSizeBack;
    QPushButton *mazeSize1;
    QPushButton *mazeSize6;
    QPushButton *mazeSize3;
    QPushButton *mazeSizeSure;
    QPushButton *mazeSize9;
    QPushButton *mazeSize4;
    QPushButton *mazeSize0;
    QLabel *mazeTipLabel1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    rescaleImg *mazeGraphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 151, 261));
        mazeSizeBox = new QVBoxLayout(verticalLayoutWidget_2);
        mazeSizeBox->setObjectName("mazeSizeBox");
        mazeSizeBox->setContentsMargins(0, 0, 0, 0);
        mazeSizeLabel1 = new QLabel(verticalLayoutWidget_2);
        mazeSizeLabel1->setObjectName("mazeSizeLabel1");

        mazeSizeBox->addWidget(mazeSizeLabel1);

        mazeSizeLabel2 = new QLabel(verticalLayoutWidget_2);
        mazeSizeLabel2->setObjectName("mazeSizeLabel2");

        mazeSizeBox->addWidget(mazeSizeLabel2);

        mazeSizeLine = new QLineEdit(verticalLayoutWidget_2);
        mazeSizeLine->setObjectName("mazeSizeLine");

        mazeSizeBox->addWidget(mazeSizeLine);

        numberBox_2 = new QGridLayout();
        numberBox_2->setObjectName("numberBox_2");
        mazeSize8 = new QPushButton(verticalLayoutWidget_2);
        mazeSize8->setObjectName("mazeSize8");

        numberBox_2->addWidget(mazeSize8, 3, 1, 1, 1);

        mazeSize2 = new QPushButton(verticalLayoutWidget_2);
        mazeSize2->setObjectName("mazeSize2");

        numberBox_2->addWidget(mazeSize2, 0, 1, 1, 1);

        mazeSize7 = new QPushButton(verticalLayoutWidget_2);
        mazeSize7->setObjectName("mazeSize7");

        numberBox_2->addWidget(mazeSize7, 3, 0, 1, 1);

        mazeSize5 = new QPushButton(verticalLayoutWidget_2);
        mazeSize5->setObjectName("mazeSize5");

        numberBox_2->addWidget(mazeSize5, 2, 1, 1, 1);

        mazeSizeBack = new QPushButton(verticalLayoutWidget_2);
        mazeSizeBack->setObjectName("mazeSizeBack");

        numberBox_2->addWidget(mazeSizeBack, 4, 0, 1, 1);

        mazeSize1 = new QPushButton(verticalLayoutWidget_2);
        mazeSize1->setObjectName("mazeSize1");

        numberBox_2->addWidget(mazeSize1, 0, 0, 1, 1);

        mazeSize6 = new QPushButton(verticalLayoutWidget_2);
        mazeSize6->setObjectName("mazeSize6");

        numberBox_2->addWidget(mazeSize6, 2, 2, 1, 1);

        mazeSize3 = new QPushButton(verticalLayoutWidget_2);
        mazeSize3->setObjectName("mazeSize3");

        numberBox_2->addWidget(mazeSize3, 0, 2, 1, 1);

        mazeSizeSure = new QPushButton(verticalLayoutWidget_2);
        mazeSizeSure->setObjectName("mazeSizeSure");

        numberBox_2->addWidget(mazeSizeSure, 4, 2, 1, 1);

        mazeSize9 = new QPushButton(verticalLayoutWidget_2);
        mazeSize9->setObjectName("mazeSize9");

        numberBox_2->addWidget(mazeSize9, 3, 2, 1, 1);

        mazeSize4 = new QPushButton(verticalLayoutWidget_2);
        mazeSize4->setObjectName("mazeSize4");

        numberBox_2->addWidget(mazeSize4, 2, 0, 1, 1);

        mazeSize0 = new QPushButton(verticalLayoutWidget_2);
        mazeSize0->setObjectName("mazeSize0");

        numberBox_2->addWidget(mazeSize0, 4, 1, 1, 1);


        mazeSizeBox->addLayout(numberBox_2);

        mazeTipLabel1 = new QLabel(verticalLayoutWidget_2);
        mazeTipLabel1->setObjectName("mazeTipLabel1");

        mazeSizeBox->addWidget(mazeTipLabel1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 280, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 320, 93, 28));
        mazeGraphicsView = new rescaleImg(centralwidget);
        mazeGraphicsView->setObjectName("mazeGraphicsView");
        mazeGraphicsView->setGeometry(QRect(150, 0, 651, 601));
        mazeGraphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mazeSizeLabel1->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\277\267\345\256\253\345\244\247\345\260\217\357\274\232", nullptr));
        mazeSizeLabel2->setText(QCoreApplication::translate("MainWindow", "\346\263\250\346\204\217\357\274\232\345\245\207\346\225\260\357\274\214\345\260\217\344\272\216xxx", nullptr));
        mazeSize8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        mazeSize2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        mazeSize7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        mazeSize5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        mazeSizeBack->setText(QCoreApplication::translate("MainWindow", "\342\254\205", nullptr));
        mazeSize1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        mazeSize6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        mazeSize3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        mazeSizeSure->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        mazeSize9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        mazeSize4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        mazeSize0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        mazeTipLabel1->setText(QCoreApplication::translate("MainWindow", "     \345\275\223\345\211\215\350\277\267\345\256\253\351\230\266\346\225\260\344\270\272\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\257\273\350\267\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
