#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "maze.h"
#include <QTime>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::showMaze(){
    Maze* maze = new Maze();
    maze->setMazeLevel(this->mazeSize);
    maze->createMaze();
    QImage mazeWall(10,10,QImage::Format_RGB888);
    mazeWall.fill(QColor(Qt::black));
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(maze->mazeMap()));

    ui->mazeGraphicsView->setScene(scene);
    ui->mazeGraphicsView->show();
}

void MainWindow::on_pushButton_clicked()
{
    if(mazeSize!=-1){
        this->showMaze();
    }
}

