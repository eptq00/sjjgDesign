#include "autopathdes.h"
#include "ui_autopathdes.h"

autoPathDes::autoPathDes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::autoPathDes)
{
    ui->setupUi(this);
    setWindowTitle("请输入你想去哪");
}

autoPathDes::~autoPathDes()
{
    delete ui;
}

void autoPathDes::on_sureButton_clicked()
{
    this->des_x = ui->rowEdit->text().toInt();
    this->des_y = ui->colEdit->text().toInt();
    emit destinationConfirmed(); // 发送信号
    close();
    ui->colEdit->clear();
    ui->rowEdit->clear();
}

bool autoPathDes::judge(Maze* maze){
    if(maze->map[des_x][des_y] == 0){
        return false;
    }
    else{
        return true;
    }
}

void autoPathDes::setMazeLevel(int mazeLevel){
    this->mazeLevel=mazeLevel;
}

int autoPathDes::getDes_x(){
    return des_x;
}

int autoPathDes::getDes_y(){
    return des_y;
}

void autoPathDes::on_exitButton_clicked()
{
    this->des_x=mazeLevel-2;
    this->des_y=mazeLevel-2;
    emit destinationConfirmed(); // 发送信号
    close();
}

