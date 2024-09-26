#include "nestmaze.h"
#include <QPainter>

nestMaze::nestMaze() : Maze() {}

QImage nestMaze::nestCell(){
    QImage nestImg1(10,10,QImage::Format_RGB888);
    QImage nestImg2(10,10,QImage::Format_RGB888);
    nestImg1.fill(QColor(Qt::red));
    nestImg2.fill(QColor(Qt::white));

    QImage nestImg3(11*10, 11*10, QImage::Format_ARGB32);
    QPainter painter(&nestImg3); // 创建QPainter对象，用于绘制图像
    for (int i=0;i<11;i++){
        for (int j=0;j<11;j++){
            if(j==4||j==5||j==6)
                painter.drawImage(j*10,i*10,nestImg2);
            else
                painter.drawImage(j*10,i*10,nestImg1);
        }
    }
    nestImg3.scaled(10,10);
    return nestImg3;
}

QImage nestMaze::mazeMap(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    QImage nestMazeCell=this->nestCell();
    mazeWall.fill(QColor(Qt::black));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));

    while(true){
        int nest_x=rand()%mazeLevel;
        int nest_y=rand()%mazeLevel;
        if(map[nest_x-1][nest_y]==1&&map[nest_x+1][nest_y]==1)
            map[nest_x][nest_y]=3;//3 嵌套
        break;
    }
    // 创建一个新的QImage对象，大小为迷宫的宽度和高度
    QImage nestMazeImage(mazeLevel * 10, mazeLevel * 10, QImage::Format_ARGB32);
    QPainter painter(&nestMazeImage); // 创建QPainter对象，用于绘制图像

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
            else if(map[row][col] == 2){
                painter.drawImage(col * 10, row * 10, mazeMy);
            }
            else{
                painter.drawImage(col * 10, row * 10, nestMazeCell);
            }
        }
    }
    return nestMazeImage; // 返回生成的迷宫图像
}
