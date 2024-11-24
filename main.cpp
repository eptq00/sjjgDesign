#include "mainwindow.h"
#include "userlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("迷宫游戏");
    return a.exec();
}
