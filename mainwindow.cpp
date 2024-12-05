 #include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "maze.h"
#include "nestmaze.h"
#include "taskmaze.h"
#include "questionboxjudge.h"
#include "questionboxpoem.h"
#include "autopathdes.h"
#include "userlogin.h"
#include "taskpos.h"
#include <QVector>
#include <QTime>
#include <QCoreApplication>
#include <QtGlobal>
#include <QTimer>

// 在ui上放置mainwindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    userLog = new userLogin();
    userLog->show();
    connect(userLog,&userLogin::userIsLogin,this,&MainWindow::showWindow);
    ui->setupUi(this);
    quesBoxJudge = new questionBoxJudge();
    quesBoxPoem = new questionBoxPoem();
    connect(quesBoxJudge, &questionBoxJudge::problemTotalPlus, this, &MainWindow::taskTotalPlus);
    connect(quesBoxJudge, &questionBoxJudge::problemRightPlus, this, &MainWindow::taskRightPlus);
    connect(quesBoxPoem, &questionBoxPoem::problemTotalPlus, this, &MainWindow::taskTotalPlus);
    connect(quesBoxPoem, &questionBoxPoem::problemRightPlus, this, &MainWindow::taskRightPlus);
}

void MainWindow::showWindow(){
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 按下‘1’按键，expression后添1，在textline输出，下同
void MainWindow::on_mazeSize1_clicked()
{
    expression.append("1");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize2_clicked()
{
    expression.append("2");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize3_clicked()
{
    expression.append("3");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize4_clicked()
{
    expression.append("4");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize5_clicked()
{
    expression.append("5");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize6_clicked()
{
    expression.append("6");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize7_clicked()
{
    expression.append("7");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize8_clicked()
{
    expression.append("8");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize9_clicked()
{
    expression.append("9");
    ui->mazeSizeLine->setText(expression);
}


void MainWindow::on_mazeSize0_clicked()
{
    // 不等于空时才能添加0，第一个数不能为0
    if(expression != ""){
        expression.append("0");
        ui->mazeSizeLine->setText(expression);
    }
    else{
        expression = "";
    }

}

// ‘确定’按键逻辑
void MainWindow::on_mazeSizeSure_clicked()
{
    mazeSize=ui->mazeSizeLine->text().toInt();    // 将expression转化为int型
    if ( mazeSize >= 300 ){         // 不大于100的输入，可修改迷宫阶数大小最大值
        ui->mazeSizeLine->setText("Error input! Try again!");
        expression = "";
        mazeSize = -1;
    }
    else if ( mazeSize < 2){        // 不小于2的输入
        ui->mazeSizeLine->setText("Error input! Try again!");
        mazeSize = -1;
    }
    else if(mazeSize%2==0){
        ui->mazeSizeLine->setText("Error input! Try again!");
        expression = "";
        mazeSize = -1;
    }
    else {                          // 将expression置空，为下次输入准备
        ui->mazeSizeLine->setText("");
        ui->mazeTipLabel1->setText("     当前迷宫阶数为:"+expression);
        expression = "";
    }
}

// 退格
void MainWindow::on_mazeSizeBack_clicked()
{
    expression.erase(expression.end()-1);
    ui->mazeSizeLine->setText(expression);
}

// 初始化迷宫，
void MainWindow::initMaze(){
    maze = new Maze();  // 创建对象
    maze->setMazeLevel(this->mazeSize); // 设置阶数
    maze->createMaze(); // 调用函数创建迷宫矩阵 0，1表示
    showMaze(maze);
}

void MainWindow::initNestMaze(){
    nestmaze = new nestMaze();
    nestmaze->setMazeLevel(this->mazeSize);
    nestmaze->createMaze();
    nestmaze->createNestMaze();
    nestmaze->nestCoordinate();
    showMaze(nestmaze);
}

void MainWindow::initTaskMaze(){
    taskmaze = new taskMaze();
    taskmaze->setMazeLevel(this->mazeSize);
    taskmaze->createMaze();
    taskmaze->setTask();
    showMaze(taskmaze);
}

void MainWindow::init3DMaze(){
    threedmaze = new threeDMaze();
    threedmaze->setMazeLevel(this->mazeSize);
    threedmaze->setLayer(this->mazeSize/7);
    threedmaze->base();
    threedmaze->create3DMaze();
    threedmaze->setTransfer();
    showMaze(threedmaze);
}

// QGraphicsView上打印迷宫图片
void MainWindow::showMaze(Maze* maze1){
    QGraphicsScene *scene = new QGraphicsScene;
    QImage orimage, scaledImage;
    orimage = maze1->mazeMap(); // 生成迷宫图片


    // 调整大小
    if(ui->mazeGraphicsView->width() > ui->mazeGraphicsView->height())
        scaledImage = orimage.scaled(ui->mazeGraphicsView->height(), ui->mazeGraphicsView->height());
    else
        scaledImage = orimage.scaled(ui->mazeGraphicsView->width(), ui->mazeGraphicsView->width());

    scene->addPixmap(QPixmap::fromImage(scaledImage));
    ui->mazeGraphicsView->setScene(scene);
    ui->mazeGraphicsView->show();
}

void MainWindow::showNestCell(nestMaze* nestmaze1){
    QGraphicsScene *scene = new QGraphicsScene;
    QImage orimage, scaledImage;
    orimage = nestmaze1->getNestCell(); // 生成迷宫图片

    // 调整大小
    if(ui->mazeGraphicsView->width() > ui->mazeGraphicsView->height())
        scaledImage = orimage.scaled(ui->mazeGraphicsView->height(), ui->mazeGraphicsView->height());
    else
        scaledImage = orimage.scaled(ui->mazeGraphicsView->width(), ui->mazeGraphicsView->width());

    scene->addPixmap(QPixmap::fromImage(scaledImage));
    ui->mazeGraphicsView->setScene(scene);
    ui->mazeGraphicsView->show();
}

void MainWindow::on_mazeBegin_clicked()
{
    user_my = new userInfo(userLog->usercurrent);
    this->showDuanwei();
    lock = false;
    if(mazeSize!=-1){
        if(this->mode == 1 || this->mode == 3){
            this->initMaze();
            if(this->mode == 3){
                //添加开始计时逻辑
                timer = new QTimer(this);
                timer->setInterval(100);

                timeCNT->timeStart();

                connect(timer, &QTimer::timeout, this, &MainWindow::refresh);
                timer->start();  // 启动计时器
            }
        }
        else if(this->mode == 2 || this->mode == 4){
            this->initNestMaze();
            if(this->mode == 4){
                //添加开始计时逻辑
                timer = new QTimer(this);
                timer->setInterval(100);
                timeCNT->timeStart();

                connect(timer, &QTimer::timeout, this, &MainWindow::refresh);
                timer->start();  // 启动计时器
            }
        }
        else if(this->mode == 5 || this->mode == 6){
            this->init3DMaze();
            if(this->mode == 6){
                //添加开始计时逻辑
                timer = new QTimer(this);
                timer->setInterval(100);
                timeCNT->timeStart();

                connect(timer, &QTimer::timeout, this, &MainWindow::refresh);
                timer->start();  // 启动计时器
            }
        }
        else if(this->mode == 7){
            this->initTaskMaze();
        }
    }
}

void MainWindow::refresh(){
    if(this->mode == 3 || this->mode == 4){
        QString time = timeCNT->refreshTime();
        this->ui->TimeCNT->setText("<font color='red'>"+time+"</font>");
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    userLog->saveUserFile();
    event->accept();  // 接受关闭事件
}

// 键盘事件监控函数
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(!lock){
        if(this->mode == 1 || this->mode == 3){
            switch (event->key()) { // 捕获键盘事件按下的键
            // W键逻辑-向上移动
            case Qt::Key_W:
                // 如果角色上面为路，改变矩阵当前位置为1（路），上方为2（人），下同
                if(maze->map[maze->my_x-1][maze->my_y] == 1 || maze->map[maze->my_x-1][maze->my_y] == 4){
                    maze->map[maze->my_x][maze->my_y]=1;
                    maze->map[maze->my_x-1][maze->my_y]=2;
                    maze->my_x=maze->my_x-1;
                }
                break;
            case Qt::Key_A:
                if(maze->map[maze->my_x][maze->my_y-1] == 1 || maze->map[maze->my_x][maze->my_y-1] == 4){
                    maze->map[maze->my_x][maze->my_y]=1;
                    maze->map[maze->my_x][maze->my_y-1]=2;
                    maze->my_y=maze->my_y-1;
                }
                // 在这里添加向左移动的逻辑
                break;
            case Qt::Key_S:
                if(maze->map[maze->my_x+1][maze->my_y] == 1 || maze->map[maze->my_x+1][maze->my_y] == 4){
                    maze->map[maze->my_x][maze->my_y]=1;
                    maze->map[maze->my_x+1][maze->my_y]=2;
                    maze->my_x=maze->my_x+1;
                }
                // 在这里添加向下移动的逻辑
                break;
            case Qt::Key_D:
                if(maze->map[maze->my_x][maze->my_y+1] == 1 || maze->map[maze->my_x][maze->my_y+1] == 4){
                    maze->map[maze->my_x][maze->my_y]=1;
                    maze->map[maze->my_x][maze->my_y+1]=2;
                    maze->my_y=maze->my_y+1;
                }
                // 在这里添加向右移动的逻辑
                 break;
            default:
                break;
            }
            showMaze(maze); // 显示新的图片
            nextLevel(maze);    // 下一关
        }
        else if(this->mode == 2 || this->mode == 4){
            switch (event->key()) { // 捕获键盘事件按下的键
            // W键逻辑-向上移动
            case Qt::Key_W:
                // 如果角色上面为路，改变矩阵当前位置为1（路），上方为2（人），下同
                if(nestmaze->inNest){
                    if(nestmaze->nestMap[nestmaze->myNest_x-1][nestmaze->myNest_y] == 1 || nestmaze->nestMap[nestmaze->myNest_x-1][nestmaze->myNest_y] == 4){
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y]=1;
                        nestmaze->nestMap[nestmaze->myNest_x-1][nestmaze->myNest_y]=2;
                        nestmaze->myNest_x=nestmaze->myNest_x-1;
                    }
                }
                else{
                    if(nestmaze->map[nestmaze->my_x-1][nestmaze->my_y] == 1 || nestmaze->map[nestmaze->my_x-1][nestmaze->my_y] == 4){
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y]=1;
                        nestmaze->map[nestmaze->my_x-1][nestmaze->my_y]=2;
                        nestmaze->my_x=nestmaze->my_x-1;
                    }
                }
                break;
            case Qt::Key_A:
                if(nestmaze->inNest){
                    if(nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y-1] == 1 || nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y-1] == 4){
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y]=1;
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y-1]=2;
                        nestmaze->myNest_y=nestmaze->myNest_y-1;
                    }
                    else if(nestmaze->myNest_x == nestmaze -> mazeLevel / 2 && nestmaze->myNest_y == 0){
                        nestmaze->inNest = false;
                        nestmaze->isShowSmall = true;
                        nestmaze->my_y=nestmaze->my_y-1;
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y]=2;
                    }
                }
                else{
                    if(nestmaze->map[nestmaze->my_x][nestmaze->my_y-1] == 1 || nestmaze->map[nestmaze->my_x][nestmaze->my_y-1] == 4){
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y]=1;
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y-1]=2;
                        nestmaze->my_y=nestmaze->my_y-1;
                    }
                    else if(nestmaze->map[nestmaze->my_x][nestmaze->my_y-1] == 3){
                        nestmaze->inNest = true;
                        nestmaze->isShowLarge = true;
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y] = 1;
                        nestmaze->myNest_x=nestmaze->mazeLevel / 2;
                        nestmaze->myNest_y=nestmaze->mazeLevel - 1;
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y] = 2;
                        nestmaze->my_y=nestmaze->my_y-1;
                    }
                }
                // 在这里添加向左移动的逻辑
                break;
            case Qt::Key_S:
                if(nestmaze->inNest){
                    if(nestmaze->nestMap[nestmaze->myNest_x+1][nestmaze->myNest_y] == 1 || nestmaze->nestMap[nestmaze->myNest_x+1][nestmaze->myNest_y] == 4){
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y]=1;
                        nestmaze->nestMap[nestmaze->myNest_x+1][nestmaze->myNest_y]=2;
                        nestmaze->myNest_x=nestmaze->myNest_x+1;
                    }
                }
                else{
                    if(nestmaze->map[nestmaze->my_x+1][nestmaze->my_y] == 1 || nestmaze->map[nestmaze->my_x+1][nestmaze->my_y] == 4){
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y]=1;
                        nestmaze->map[nestmaze->my_x+1][nestmaze->my_y]=2;
                        nestmaze->my_x=nestmaze->my_x+1;
                    }
                }
                // 在这里添加向下移动的逻辑
                break;
            case Qt::Key_D:
                if(nestmaze->inNest){
                    if(nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y+1] == 1 || nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y+1] == 4){
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y]=1;
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y+1]=2;
                        nestmaze->myNest_y=nestmaze->myNest_y+1;
                    }
                    else if(nestmaze->myNest_x == nestmaze -> mazeLevel / 2 && nestmaze->myNest_y == nestmaze->mazeLevel - 1){
                        nestmaze->inNest = false;
                        nestmaze->isShowSmall = true;
                        nestmaze->my_y=nestmaze->my_y + 1;
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y]=2;
                    }
                }
                else{
                    if(nestmaze->map[nestmaze->my_x][nestmaze->my_y+1] == 1 || nestmaze->map[nestmaze->my_x][nestmaze->my_y+1] == 4){
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y]=1;
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y+1]=2;
                        nestmaze->my_y=nestmaze->my_y+1;
                    }
                    else if(nestmaze->map[nestmaze->my_x][nestmaze->my_y+1] == 3){
                        nestmaze->inNest = true;
                        nestmaze->isShowLarge = true;
                        nestmaze->map[nestmaze->my_x][nestmaze->my_y] = 1;
                        nestmaze->myNest_x=nestmaze->mazeLevel / 2;
                        nestmaze->myNest_y=0;
                        nestmaze->nestMap[nestmaze->myNest_x][nestmaze->myNest_y] = 2;
                        nestmaze->my_y=nestmaze->my_y+1;
                    }
                }
                // 在这里添加向右移动的逻辑
                break;
            default:
                break;
            }
            if(!nestmaze->inNest){
                if(nestmaze->isShowSmall){
                    nestmaze->isShowSmall = false;
                    this->smallNest(nestmaze->getNestCell());
                }
                showMaze(nestmaze);
            }
            else{
                if(nestmaze->isShowLarge){
                    nestmaze->isShowLarge = false;
                    this->largeNest(nestmaze->getNestCell());
                }

                showNestCell(nestmaze);
            }
            nextLevel(nestmaze);    // 下一关
        }
        else if(this->mode == 5 || this->mode == 6){
            bool isChange = false;
            bool isUP = false;
            bool isDOWN = false;
            switch (event->key()) { // 捕获键盘事件按下的键
            // W键逻辑-向上移动
            case Qt::Key_W:
                // 如果角色上面为路，改变矩阵当前位置为1（路），上方为2（人），下同
                if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y] == 1 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y] == 4 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y] == 5 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y] == 8){
                    isChange = false;
                    isUP = false;
                    isDOWN = false;
                    if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y] == 5){
                        isChange = true;
                        isUP = true;
                        threedmaze->my_z++;
                    }
                    else if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y] == 8){
                        isChange = true;
                        isDOWN = true;
                        threedmaze->my_z--;
                    }
                    if(!isChange){
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y]=1;
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y]=2;
                        threedmaze->my_x=threedmaze->my_x-1;
                    }
                    else{
                        if(isUP){
                            threedmaze->threeDMap[threedmaze->my_z-1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y]=2;
                            threedmaze->my_x=threedmaze->my_x-1;
                        }
                        if(isDOWN){
                            threedmaze->threeDMap[threedmaze->my_z+1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x-1][threedmaze->my_y]=2;
                            threedmaze->my_x=threedmaze->my_x-1;
                        }
                    }
                }
                break;
            case Qt::Key_A:
                if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1] == 1 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1] == 4 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1] == 5 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1] == 8){
                    isChange = false;
                    isUP = false;
                    isDOWN = false;
                    if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1] == 5){
                        isChange = true;
                        isUP = true;
                        threedmaze->my_z++;
                    }
                    else if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1] == 8){
                        isChange = true;
                        isDOWN = true;
                        threedmaze->my_z--;
                    }
                    if(!isChange){
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y]=1;
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1]=2;
                        threedmaze->my_y=threedmaze->my_y-1;
                    }
                    else{
                        if(isUP){
                            threedmaze->threeDMap[threedmaze->my_z-1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1]=2;
                            threedmaze->my_y=threedmaze->my_y-1;
                        }
                        if(isDOWN){
                            threedmaze->threeDMap[threedmaze->my_z+1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y-1]=2;
                            threedmaze->my_y=threedmaze->my_y-1;
                        }
                    }
                }
                // 在这里添加向左移动的逻辑
                break;
            case Qt::Key_S:
                if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y] == 1 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y] == 4 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y] == 5 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y] == 8){
                    isChange = false;
                    isUP = false;
                    isDOWN = false;
                    if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y] == 5){
                        isChange = true;
                        isUP = true;
                        threedmaze->my_z++;
                    }
                    else if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y] == 8){
                        isChange = true;
                        isDOWN = true;
                        threedmaze->my_z--;
                    }
                    if(!isChange){
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y]=1;
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y]=2;
                        threedmaze->my_x=threedmaze->my_x+1;
                    }
                    else{
                        if(isUP){
                            threedmaze->threeDMap[threedmaze->my_z-1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y]=2;
                            threedmaze->my_x=threedmaze->my_x+1;
                        }
                        if(isDOWN){
                            threedmaze->threeDMap[threedmaze->my_z+1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x+1][threedmaze->my_y]=2;
                            threedmaze->my_x=threedmaze->my_x+1;
                        }
                    }
                }
                // 在这里添加向下移动的逻辑
                break;
            case Qt::Key_D:
                if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1] == 1 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1] == 4 ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1] == 5  ||
                    threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1] ==  8){
                    isChange = false;
                    isUP = false;
                    isDOWN = false;
                    if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1] == 5){
                        isChange = true;
                        isUP = true;
                        threedmaze->my_z++;
                    }
                    else if(threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1] == 8){
                        isChange = true;
                        isDOWN = true;
                        threedmaze->my_z--;

                    }
                    if(!isChange){
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y]=1;
                        threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1]=2;
                        threedmaze->my_y=threedmaze->my_y+1;
                    }
                    else{
                        if(isUP){
                            threedmaze->threeDMap[threedmaze->my_z-1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1]=2;
                            threedmaze->my_y=threedmaze->my_y+1;
                        }
                        if(isDOWN){
                            threedmaze->threeDMap[threedmaze->my_z+1][threedmaze->my_x][threedmaze->my_y]=1;
                            threedmaze->threeDMap[threedmaze->my_z][threedmaze->my_x][threedmaze->my_y+1]=2;
                            threedmaze->my_y=threedmaze->my_y+1;
                        }
                    }

                }
                // 在这里添加向右移动的逻辑
                break;
            default:
                break;
            }
            threedmaze->resetTransfer();
            showMaze(threedmaze); // 显示新的图片
            nextLevel(threedmaze);    // 下一关
        }
        else if(this->mode == 7){
            switch (event->key()) { // 捕获键盘事件按下的键
            // W键逻辑-向上移动
            case Qt::Key_W:
                // 如果角色上面为路，改变矩阵当前位置为1（路），上方为2（人），下同
                if(taskmaze->map[taskmaze->my_x-1][taskmaze->my_y] == 1 ||
                    taskmaze->map[taskmaze->my_x-1][taskmaze->my_y] == 4 ||
                    taskmaze->map[taskmaze->my_x-1][taskmaze->my_y] == 6 ||
                    taskmaze->map[taskmaze->my_x-1][taskmaze->my_y] == 7){
                    if(taskmaze->map[taskmaze->my_x-1][taskmaze->my_y] == 6){
                        quesBoxJudge->createJudgeQuestion();
                        quesBoxJudge->setQuestion();
                        quesBoxJudge->show();
                    }
                    else if(taskmaze->map[taskmaze->my_x-1][taskmaze->my_y] == 7){
                        quesBoxPoem->createPoemQuestion();
                        quesBoxPoem->setQuestion();
                        quesBoxPoem->show();
                    }
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y]=1;
                    taskmaze->map[taskmaze->my_x-1][taskmaze->my_y]=2;
                    taskmaze->my_x=taskmaze->my_x-1;
                }
                break;
            case Qt::Key_A:
                if(taskmaze->map[taskmaze->my_x][taskmaze->my_y-1] == 1 ||
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y-1] == 4 ||
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y-1] == 6 ||
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y-1] == 7){
                    if(taskmaze->map[taskmaze->my_x][taskmaze->my_y-1] == 6){
                        quesBoxJudge->createJudgeQuestion();
                        quesBoxJudge->setQuestion();
                        quesBoxJudge->show();
                    }
                    else if(taskmaze->map[taskmaze->my_x][taskmaze->my_y-1] == 7){
                        quesBoxPoem->createPoemQuestion();
                        quesBoxPoem->setQuestion();
                        quesBoxPoem->show();
                    }
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y]=1;
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y-1]=2;
                    taskmaze->my_y=taskmaze->my_y-1;
                }
                // 在这里添加向左移动的逻辑
                break;
            case Qt::Key_S:
                if(taskmaze->map[taskmaze->my_x+1][taskmaze->my_y] == 1 ||
                    taskmaze->map[taskmaze->my_x+1][taskmaze->my_y] == 4 ||
                    taskmaze->map[taskmaze->my_x+1][taskmaze->my_y] == 6 ||
                    taskmaze->map[taskmaze->my_x+1][taskmaze->my_y] == 7){
                    if(taskmaze->map[taskmaze->my_x+1][taskmaze->my_y] == 6){
                        quesBoxJudge->createJudgeQuestion();
                        quesBoxJudge->setQuestion();
                        quesBoxJudge->show();
                    }
                    else if(taskmaze->map[taskmaze->my_x+1][taskmaze->my_y] == 7){
                        quesBoxPoem->createPoemQuestion();
                        quesBoxPoem->setQuestion();
                        quesBoxPoem->show();
                    }
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y]=1;
                    taskmaze->map[taskmaze->my_x+1][taskmaze->my_y]=2;
                    taskmaze->my_x=taskmaze->my_x+1;
                }
                // 在这里添加向下移动的逻辑
                break;
            case Qt::Key_D:
                if(taskmaze->map[taskmaze->my_x][taskmaze->my_y+1] == 1 ||
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y+1] == 4 ||
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y+1] == 6 ||
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y+1] == 7){
                    if(taskmaze->map[taskmaze->my_x][taskmaze->my_y+1] == 6){
                        quesBoxJudge->createJudgeQuestion();
                        quesBoxJudge->setQuestion();
                        quesBoxJudge->show();
                    }
                    else if(taskmaze->map[taskmaze->my_x][taskmaze->my_y+1] == 7){
                        quesBoxPoem->createPoemQuestion();
                        quesBoxPoem->setQuestion();
                        quesBoxPoem->show();
                    }
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y]=1;
                    taskmaze->map[taskmaze->my_x][taskmaze->my_y+1]=2;
                    taskmaze->my_y=taskmaze->my_y+1;
                }
                // 在这里添加向右移动的逻辑
                break;
            default:
                break;
            }
            showMaze(taskmaze); // 显示新的图片
            nextLevel(taskmaze);    // 下一关
        }
    }
}

void MainWindow::largeNest(QImage orimage){
    lock = true;
    for(int i=10; i < ui->mazeGraphicsView->height(); i=i+3){
        QGraphicsScene *scene = new QGraphicsScene;
        QImage scaledImage;

        scaledImage = orimage.scaled(i,i);

        scene->addPixmap(QPixmap::fromImage(scaledImage));
        ui->mazeGraphicsView->setScene(scene);
        ui->mazeGraphicsView->show();

        QEventLoop loop;
        QTimer::singleShot(10, &loop, &QEventLoop::quit);
        loop.exec();
    }
    lock = false;
}

void MainWindow::smallNest(QImage orimage){
    lock = true;
    for(int i= ui->mazeGraphicsView->height(); i > 10; i=i-3){
        QGraphicsScene *scene = new QGraphicsScene;
        QImage scaledImage;

        scaledImage = orimage.scaled(i,i);

        scene->addPixmap(QPixmap::fromImage(scaledImage));
        ui->mazeGraphicsView->setScene(scene);
        ui->mazeGraphicsView->show();

        QEventLoop loop;
        QTimer::singleShot(10, &loop, &QEventLoop::quit);
        loop.exec();
    }
    lock = false;
}

void MainWindow::nextLevel(Maze* maze1){
    if(maze1->map[maze1->mazeLevel-2][maze1->mazeLevel-1]==2){
        //通关逻辑
        if(this->mode == 1){
            userLog->usercurrent->levelPutong++;
            initMaze();
        }
        else if(this->mode == 2){
            userLog->usercurrent->levelNeiqian++;
            initNestMaze();
        }
        else if(this->mode == 3){
            timer->stop();
            timeCNT->timeEnd();
            userLog->usercurrent->timePutong = timeCNT->getTime();
            //不再接受键盘信号
            lock = true;
        }
        else if(this->mode == 4){
            timer->stop();
            timeCNT->timeEnd();
            userLog->usercurrent->timeNeiqian = timeCNT->getTime();
            //不再接受键盘信号
            lock = true;
        }
        else if(this->mode == 7){
            if(taskmaze->taskIsFinish())
                initTaskMaze();
            else
                qDebug()<<"快去做任务";
        }
    }
    if(this->mode == 7){
        if(threedmaze->threeDMap[threedmaze->layer-1][threedmaze->mazeLevel-2][threedmaze->mazeLevel-1] == 2){
            if(this->mode == 5){
                init3DMaze();
            }
            else if(this->mode == 6){
                timer->stop();
                timeCNT->timeEnd();
                //不再接受键盘信号
                lock = true;
            }
        }
    }
}


void MainWindow::on_actionHelp_triggered()
{
    QGraphicsScene *scene = new QGraphicsScene;
    QImage orimage(10,10,QImage::Format_RGB888);
    orimage.fill(QColor(Qt::black));
    scene->addPixmap(QPixmap::fromImage(orimage));
    ui->mazeGraphicsView->setScene(scene);
    ui->mazeGraphicsView->show();
}


void MainWindow::on_actionGame_triggered()
{
    QGraphicsScene *scene = ui->mazeGraphicsView->scene();
    scene->clear();
}


void MainWindow::on_mode11_triggered()
{
    this->mode=1;
}


void MainWindow::on_mode12_triggered()
{
    this->mode=2;
}

void MainWindow::on_mode21_triggered()
{
    this->mode=3;
    timeCNT = new TimeCount();
}


void MainWindow::on_mode22_triggered()
{
    this->mode=4;
    timeCNT = new TimeCount();
}

void MainWindow::on_action13_triggered()
{
    this->mode = 5;
}


void MainWindow::on_action23_triggered()
{
    this->mode = 6;
}


void MainWindow::on_mazeAuto_clicked()
{
    //弹出交互框：去哪里？
    autoPathBox = new autoPathDes();
    autoPathBox->setMazeLevel(this->mazeSize);

    autoPathBox->show();  // 显示对话框
    connect(autoPathBox, &autoPathDes::destinationConfirmed, this, &MainWindow::findPath);
}

void MainWindow::findPath(){
    int des_x=autoPathBox->getDes_x();
    int des_y=autoPathBox->getDes_y();
    //
    if(mode == 1 || mode == 3){
        maze->autoFindPath(des_x,des_y);
        maze->map[maze->my_x][maze->my_y]=2;
        showMaze(maze);
    }
    else if (mode == 2 || mode == 4){
        nestmaze->autoFindPath(des_x,des_y);
        nestmaze->map[nestmaze->my_x][nestmaze->my_y] = 2;
        nestmaze->map[nestmaze->getnestx()][nestmaze->getnesty()] = 3;
        showMaze(nestmaze);
    }
    // else if(mode == 5 || mode == 6){
    //     threedmaze->
    // }
    else if (mode == 7){
        taskmaze->autoFindPath(des_x,des_y);
        taskmaze->map[taskmaze->my_x][taskmaze->my_y]=2;
        QVector<taskpos*> pos = taskmaze->gettaskposs();
        for(int i = 0 ; i < pos.length() ; i++){
            taskmaze->map[pos[i]->task_x][pos[i]->task_y]=pos[i]->task_type;
        }
        showMaze(taskmaze);
    }
}

void MainWindow::taskTotalPlus(){
    userLog->usercurrent->taskTotal++;
}

void MainWindow::taskRightPlus(){
    userLog->usercurrent->taskRight++;
    userLog->usercurrent->taskAccu = (double)userLog->usercurrent->taskRight / userLog->usercurrent->taskTotal;
    qDebug()<<"你的准确率是："<<userLog->usercurrent->taskAccu;
}

void MainWindow::on_action31_triggered()
{
    this->mode = 7;
}


void MainWindow::on_actionRanklist_triggered()
{
    ranklist = new rankList(userLog->userInfos);
    ranklist->show();
}

void MainWindow::showDuanwei(){
    QString imagePath = "C:/Users/86135/Desktop/段位/" + QString::number(user_my->duanwei) + ".png";
    QImage image;
    image.load(imagePath);
    this->ui->duanwei->setPixmap(QPixmap::fromImage(image));
}

