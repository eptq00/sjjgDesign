#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "maze.h"
#include "nestmaze.h"
#include <QTime>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->mazeGraphicsView, SIGNAL(&mazeKeyEvent::sendToMaze), this, SLOT(&MainWindow::keyboardEvent));
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    if(expression != ""){
        expression.append("0");
        ui->mazeSizeLine->setText(expression);
    }
    else{
        expression = "";
    }

}


void MainWindow::on_mazeSizeSure_clicked()
{
    mazeSize=expression.toInt();
    if ( mazeSize >= 100 ){
        ui->mazeSizeLine->setText("Error input! Try again!");
        expression = "";
        mazeSize = -1;
    }
    else if ( mazeSize < 2){
        ui->mazeSizeLine->setText("Error input! Try again!");
        mazeSize = -1;
    }
    else {
        ui->mazeSizeLine->setText("");
        ui->mazeTipLabel1->setText("     当前迷宫阶数为:"+expression);
        expression = "";
    }
}

//退格
void MainWindow::on_mazeSizeBack_clicked()
{
    expression.erase(expression.end()-1);
    ui->mazeSizeLine->setText(expression);
}

void MainWindow::keyboardEvent(QKeyEvent *event){
    QGraphicsScene *scene = new QGraphicsScene;
    QImage orimage;
    QImage scaledImage;

    orimage = maze->mazeMap();
    if(ui->mazeGraphicsView->width() > ui->mazeGraphicsView->height())
        scaledImage = orimage.scaled(ui->mazeGraphicsView->height(), ui->mazeGraphicsView->height());
    else
        scaledImage = orimage.scaled(ui->mazeGraphicsView->width(), ui->mazeGraphicsView->width());
    scene->addPixmap(QPixmap::fromImage(scaledImage));

    ui->mazeGraphicsView->setScene(scene);
    ui->mazeGraphicsView->show();
}

void MainWindow::initMaze(){
    maze = new Maze();
    maze->setMazeLevel(this->mazeSize);
    maze->createMaze();
    QImage orimage = maze->mazeMap();
    showMaze();
}

void MainWindow::initNestMaze(){
    nestmaze = new nestMaze();
    //showMaze();
}

void MainWindow::showMaze(){
    QGraphicsScene *scene = new QGraphicsScene;
    QImage orimage;
    QImage scaledImage;

    orimage = maze->mazeMap();
    if(ui->mazeGraphicsView->width() > ui->mazeGraphicsView->height())
        scaledImage = orimage.scaled(ui->mazeGraphicsView->height(), ui->mazeGraphicsView->height());
    else
        scaledImage = orimage.scaled(ui->mazeGraphicsView->width(), ui->mazeGraphicsView->width());
    scene->addPixmap(QPixmap::fromImage(scaledImage));

    ui->mazeGraphicsView->setScene(scene);
    ui->mazeGraphicsView->show();
}

void MainWindow::on_pushButton_clicked()
{
    if(mazeSize!=-1){
        this->initMaze();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_W:
        if(maze->map[maze->my_x-1][maze->my_y] == 1){
            maze->map[maze->my_x][maze->my_y]=1;
            maze->map[maze->my_x-1][maze->my_y]=2;
            maze->my_x=maze->my_x-1;
            //moved=true;
        }
        // 在这里添加向上移动的逻辑
        break;
    case Qt::Key_A:
        if(maze->map[maze->my_x][maze->my_y-1] == 1){
            maze->map[maze->my_x][maze->my_y]=1;
            maze->map[maze->my_x][maze->my_y-1]=2;
            maze->my_y=maze->my_y-1;
            //moved=true;
        }
        // 在这里添加向左移动的逻辑
        break;
    case Qt::Key_S:
        if(maze->map[maze->my_x+1][maze->my_y] == 1){
            maze->map[maze->my_x][maze->my_y]=1;
            maze->map[maze->my_x+1][maze->my_y]=2;
            maze->my_x=maze->my_x+1;
            //moved=true;
        }
        // 在这里添加向下移动的逻辑
        break;
    case Qt::Key_D:
        if(maze->map[maze->my_x][maze->my_y+1] == 1){
            maze->map[maze->my_x][maze->my_y]=1;
            maze->map[maze->my_x][maze->my_y+1]=2;
            maze->my_y=maze->my_y+1;
            //moved=true;
        }
        // 在这里添加向右移动的逻辑
         break;
    default:
        //QGraphicsView::keyPressEvent(event); // 其他按键传递给基类处理
        break;
    }
    showMaze();

    if(maze->map[maze->mazeLevel-2][maze->mazeLevel-1]==2){
        //通关逻辑
        ui->mazeSizeLine->setText("你赢了");
        initNestMaze();
    }

}
