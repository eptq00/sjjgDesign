#include "threedmaze.h"
#include "transferpos.h"
#include <QVector>
#include <QPainter>
#include <QDebug>

threeDMaze::threeDMaze() : Maze() {}

void threeDMaze::base() {
    layer = this->mazeLevel/7;
    for(int i=0 ; i<layer ; i++){
        threeDMap = new int**[mazeLevel];
        for (int j = 0; j < mazeLevel; j++) {
            threeDMap[j] = new int*[mazeLevel];
        }

        for (int j = 0; j < mazeLevel; j++) {
            for (int k = 0; k < mazeLevel; k++) {
                threeDMap[j][k] = 0;
            }
        }
    }
}

void threeDMaze::create3DMaze(){
    threeDMaze::base();
    for(int i=0 ; i<layer ; i++){
        this->createMaze();
        for(int x=0;x<mazeLevel;x++){
            for(int y=0;y<mazeLevel;y++){
                threeDMap[i][x][y]=this->map[x][y];
            }
        }
        if(i==0){
            threeDMap[i][this->mazeLevel-2][this->mazeLevel-1]=0;
        }
        else if(i == this->layer - 1){
            threeDMap[i][1][0]=0;
        }
        else{
            threeDMap[i][this->mazeLevel-2][this->mazeLevel-1]=0;
            threeDMap[i][1][0]=0;
        }
    }
}

void threeDMaze::setTransfer(){
    for (int i=0;i<layer-2 ;i++){
        transferPos* pos = new transferPos();
        while(true){
            pos->trans_x=rand()%mazeLevel;
            pos->trans_y=rand()%mazeLevel;
            if(threeDMap[i][pos->trans_x][pos->trans_y] == 1 && threeDMap[i+1][pos->trans_x][pos->trans_y] == 1){
                threeDMap[i][pos->trans_x][pos->trans_y] = 5;
                threeDMap[i+1][pos->trans_x][pos->trans_y] = 5;
                // 把第i和第i+1层的传送门坐标存放在transfers[i]处
                transfers.push_back(pos);
                break;
            }
        }
    }
    for (int i = 0; i<transfers.length();i++){
        qDebug() <<"("<<transfers[i]->trans_x<<","<<transfers[i]->trans_y<<")";
    }
}

QImage threeDMaze::mazeMap(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    QImage mazeTip(10,10,QImage::Format_RGB888);
    QImage mazeTrans(10,10,QImage::Format_RGB888);
    mazeWall.fill(QColor(Qt::black));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));
    mazeTip.fill(QColor(Qt::yellow));
    mazeTrans.fill(QColor(Qt::blue));

    // 创建一个新的QImage对象，大小为迷宫的宽度和高度
    QImage mazeImage(mazeLevel * 10, mazeLevel * 10, QImage::Format_ARGB32);
    QPainter painter(&mazeImage); // 创建QPainter对象，用于绘制图像

    // 遍历迷宫数组
    for (int row = 0; row < mazeLevel; row++) {
        for (int col = 0; col < mazeLevel; col++) {
            // 1-绘制路图片
            if (threeDMap[my_z][row][col] == 1) {
                painter.drawImage(col * 10, row * 10, mazeRoad);
            }
            // 0-绘制墙图片
            else if(threeDMap[my_z][row][col] == 0) {
                painter.drawImage(col * 10, row * 10, mazeWall);
            }
            // 2-绘制角色图片
            else if(threeDMap[my_z][row][col] == 2) {
                painter.drawImage(col * 10, row * 10, mazeMy);
            }
            else if(threeDMap[my_z][row][col] == 4) {
                painter.drawImage(col * 10, row * 10, mazeTip);
            }
            else if(threeDMap[my_z][row][col] == 5) {
                painter.drawImage(col * 10, row * 10, mazeTrans);
            }
        }
    }
    return mazeImage; // 返回生成的迷宫图像
}

