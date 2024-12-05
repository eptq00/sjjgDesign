#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maze.h"
#include "nestmaze.h"
#include "timecount.h"
#include "taskmaze.h"
#include "threedmaze.h"
#include "autopathdes.h"
#include "questionboxjudge.h"
#include "questionboxpoem.h"
#include "userlogin.h"
#include "userinfo.h"
#include "ranklist.h"

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
    void closeEvent(QCloseEvent *event);

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

    void on_mode21_triggered();

    void on_mode22_triggered();

    void on_action13_triggered();

    void on_action23_triggered();

    void on_action31_triggered();

    void showWindow();

    void taskTotalPlus();

    void taskRightPlus();

    void on_actionRanklist_triggered();

private:
    Ui::MainWindow *ui;
    QString expression;
    TimeCount* timeCNT;
    QTimer* timer;
    Maze* maze;
    nestMaze* nestmaze;
    taskMaze* taskmaze;
    threeDMaze* threedmaze;
    userInfo* user_my;
    bool lock = false;
    int mazeSize = -1;
    int mode = 1; //1-无尽普通 2-无尽嵌套 3-计时普通 4-计时内嵌 5-无尽立体 6-计时立体 7-任务普通
    autoPathDes* autoPathBox;
    questionBoxJudge* quesBoxJudge;
    questionBoxPoem* quesBoxPoem;
    userLogin* userLog;
    rankList* ranklist;
    void showMaze(Maze *maze);
    void showNestMaze();
    void showNestCell(nestMaze* nestmaze1);//显示小内嵌迷宫
    void initMaze();
    void initNestMaze();
    void initTaskMaze();
    void init3DMaze();
    void nextLevel(Maze *maze);
    void refresh();
    void largeNest(QImage orimage);
    void smallNest(QImage orimage);
    void findPath();
    void showDuanwei();
};
#endif // MAINWINDOW_H
