#include "taskmaze.h"
#include <QDebug>
#include <QPainter>
#include <QVector>
#include "taskpos.h"

taskMaze::taskMaze() {}

int taskMaze::gettaskx(){
    return this->task_x;
}

int taskMaze::gettasky(){
    return this->task_y;
}

QVector<taskpos*> taskMaze::gettaskposs(){
    return this->taskpositions;
}

void taskMaze::setTask(){
    int type0;
    int cnt = 0;
    while(true){
        task_x=rand()%mazeLevel;
        task_y=rand()%mazeLevel;
        type0 = rand()%2 + 6;
        if(map[task_x][task_y] == 1){
            if(map[task_x][task_y-1]==1 && this->task_y != this->mazeLevel-1){
                map[task_x][task_y] = type0;//6-任务点
                taskpos* pos = new taskpos(this->task_x,this->task_y,type0);
                taskpositions.append(pos);
                cnt++;
                if(cnt >=mazeLevel/5){
                    break;
                }
            }
        }
    }
    for(int i = 0 ;i < taskpositions.length(); i++){
        if(taskpositions[i]->task_type == 6)
            qDebug()<<"判断任务点：（"<<taskpositions[i]->task_x<<","<<taskpositions[i]->task_y<<")";
        else if(taskpositions[i]->task_type == 7)
            qDebug()<<"古诗任务点：（"<<taskpositions[i]->task_x<<","<<taskpositions[i]->task_y<<")";
    }
}

QImage taskMaze::mazeMap(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    QImage mazeTip(10,10,QImage::Format_RGB888);
    QImage mazeTask(10,10,QImage::Format_RGB888);
    mazeWall.fill(QColor(Qt::black));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));
    mazeTip.fill(QColor(Qt::yellow));
    mazeTask.fill(QColor(255, 192, 203)); //pink

    // 创建一个新的QImage对象，大小为迷宫的宽度和高度
    QImage mazeImage(mazeLevel * 10, mazeLevel * 10, QImage::Format_ARGB32);
    QPainter painter(&mazeImage); // 创建QPainter对象，用于绘制图像

    // 遍历迷宫数组
    for (int row = 0; row < mazeLevel; row++) {
        for (int col = 0; col < mazeLevel; col++) {
            // 1-绘制路图片
            if (map[row][col] == 1) {
                painter.drawImage(col * 10, row * 10, mazeRoad);
            }
            // 0-绘制墙图片
            else if(map[row][col] == 0) {
                painter.drawImage(col * 10, row * 10, mazeWall);
            }
            // 2-绘制角色图片
            else if(map[row][col] == 2) {
                painter.drawImage(col * 10, row * 10, mazeMy);
            }
            else if(map[row][col] == 4) {
                painter.drawImage(col * 10, row * 10, mazeTip);
            }
            else if(map[row][col] == 6 || map[row][col] == 7) {
                painter.drawImage(col * 10, row * 10, mazeTask);
            }
        }
    }
    return mazeImage; // 返回生成的迷宫图像
}

bool taskMaze::taskIsFinish(){
    for(int i= 0; i<taskpositions.length();i++){
        if(this->map[taskpositions[i]->task_x][taskpositions[i]->task_y] == 6 ||
            this->map[taskpositions[i]->task_x][taskpositions[i]->task_y] == 7)
            return false;
    }
    return true;
}
