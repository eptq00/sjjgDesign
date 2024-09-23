#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mazeSize1_clicked();

    void on_mazeSize2_clicked();

    void on_mazeSize3_clicked();

    void on_mazeSize4_clicked();

    void on_mazeSize5_clicked();

    void on_mazeSize6_clicked();

    void on_mazeSize7_clicked();

    void on_mazeSize8_clicked();

    void on_mazeSize9_clicked();

    void on_mazeSize0_clicked();

    void on_mazeSizeSure_clicked();

    void on_mazeSizeBack_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString expression;
    int mazeSize = -1;
    void showMaze();
};
#endif // MAINWINDOW_H
