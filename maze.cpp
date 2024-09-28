#include "maze.h"
#include <QTime>
#include <QtGlobal>    //qsrand和qrand这两个函数在这里面>
#include <QStack>
#include <QPainter>

Maze::Maze() {}

Maze::Maze(int x){
    this->mazeLevel=x;
}

Maze::~Maze() {
}

// 初始化地图，所有设成墙
void Maze::base() {
    map = new int*[mazeLevel];
    for (int i = 0; i < mazeLevel; i++) {
        map[i] = new int[mazeLevel];
    }

    for (int i = 0; i < mazeLevel; i++) {
        for (int j = 0; j < mazeLevel; j++) {
            this->map[i][j] = 0;
        }
    }
}

// 重新设置方向
void Maze::resetDir(bool* up, bool* down, bool* left, bool* right){
    *up=false;
    *down=false;
    *left=false;
    *right=false;
}

// 设置迷宫阶数
void Maze::setMazeLevel(int x){
    this->mazeLevel=x;
}

// 创建二维迷宫
void Maze::createMaze(){
    Maze::base();
    this->start_x = 1;
    this->start_y = 1;
    this->map[this->start_x][this->start_y]=1;
    int currpoint_x = start_x, currpoint_y = start_y;
    bool up=false, down=false, left=false, right=false;
    QStack<int> MazeStack_x;
    QStack<int> MazeStack_y;
    this->map[1][0]=2;
    this->map[mazeLevel-2][mazeLevel-1]=1;
    while(true){
        int ranNum=rand()%4;
        switch(ranNum){
        case 0://上
            if(!up && currpoint_x>2 && this->map[currpoint_x-2][currpoint_y] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->map[currpoint_x-2][currpoint_y] = 1;
                this->map[currpoint_x-1][currpoint_y] = 1;
                currpoint_x = currpoint_x - 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                up=true;
            }
            break;
        case 1://下
            if(!down && currpoint_x<mazeLevel-3 && this->map[currpoint_x+2][currpoint_y] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->map[currpoint_x+2][currpoint_y] = 1;
                this->map[currpoint_x+1][currpoint_y] = 1;
                currpoint_x = currpoint_x + 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                down=true;
            }
            break;
        case 2://左
            if(!left && currpoint_y>2 && this->map[currpoint_x][currpoint_y-2] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->map[currpoint_x][currpoint_y-2] = 1;
                this->map[currpoint_x][currpoint_y-1] = 1;
                currpoint_y = currpoint_y - 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                left=true;
            }
            break;
        case 3://右
            if(!right && currpoint_y<mazeLevel-3 && this->map[currpoint_x][currpoint_y+2] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->map[currpoint_x][currpoint_y+2] = 1;
                this->map[currpoint_x][currpoint_y+1] = 1;
                currpoint_y = currpoint_y + 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                right=true;
            }
            break;
        default: break;
        }
        if(up&&down&&right&&left)//如果当前访问节点四个方向都没有可拆的节点，回溯
        {
            if(!MazeStack_x.empty() && !MazeStack_y.empty())
            {
                currpoint_x = MazeStack_x.top();
                currpoint_y = MazeStack_y.top();
                MazeStack_x.pop();
                MazeStack_y.pop();
                this->resetDir(&up,&down,&left,&right);
            }
            else//如果栈为空的话就返回，此时迷宫矩阵已经创建完毕
            {
                return;
            }
        }
    }
}

// 生成迷宫地图
QImage Maze::mazeMap(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    mazeWall.fill(QColor(Qt::black));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));

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
            else{
                painter.drawImage(col * 10, row * 10, mazeMy);
            }
        }
    }
    return mazeImage; // 返回生成的迷宫图像
}



