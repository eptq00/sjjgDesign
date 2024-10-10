#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maze.h"
#include "nestmaze.h"

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
    void keyPressEvent(QKeyEvent *event);

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

    void on_mazeBegin_clicked();

    void on_actionHelp_triggered();

    void on_actionGame_triggered();

    void on_mode11_triggered();

    void on_mode12_triggered();

    void on_mazeAuto_clicked();

private:
    Ui::MainWindow *ui;
    QString expression;

    Maze* maze;
    nestMaze* nestmaze;
    int mazeSize = -1;
    int mode = 1;
    void showMaze(Maze *maze);
    void showNestMaze();
    void initMaze();
    void initNestMaze();
    void nextLevel(Maze *maze);
};
#endif // MAINWINDOW_H
