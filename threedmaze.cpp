#include "threedmaze.h"
#include "transferpos.h"
#include <QVector>
#include <QPainter>
#include <QDebug>
#include <QStack>

threeDMaze::threeDMaze() : Maze() {}

void threeDMaze::base() {
    threeDMap = new int**[mazeLevel];
    for (int i = 0; i < layer; ++i) {
        threeDMap[i] = new int*[mazeLevel];
        for (int j = 0; j < mazeLevel; ++j) {
            threeDMap[i][j] = new int[mazeLevel];
            // 初始化每个元素为0
            for (int k = 0; k < mazeLevel; ++k) {
                threeDMap[i][j][k] = 0;
            }
        }
    }
}

void threeDMaze::setLayer(int layer){
    this->layer=layer;
}

void threeDMaze::create3DMaze(){
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

void threeDMaze::createMaze(){
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
                this->randomDelete();
                return;
            }
        }
    }

}

void threeDMaze::setTransfer(){
    for (int i=0;i<layer-1 ;i++){
        transferPos* pos = new transferPos();
        while(true){
            pos->trans_x=rand()%mazeLevel;
            pos->trans_y=rand()%mazeLevel;
            if(threeDMap[i][pos->trans_x][pos->trans_y] == 1 && threeDMap[i+1][pos->trans_x][pos->trans_y] == 1){
                threeDMap[i][pos->trans_x][pos->trans_y] = 5; //上层到下层-5
                threeDMap[i+1][pos->trans_x][pos->trans_y] = 8; // 下层到上层-8
                // 把第i和第i+1层的传送门坐标存放在transfers[i]处
                transfersup.append(pos); //第i+1层到i层
                transfersdown.append(pos); //第i层到i+1层
                break;
            }
        }
    }
    for (int i = 0; i<transfersup.length();i++){
        qDebug() <<"("<<transfersup[i]->trans_x<<","<<transfersup[i]->trans_y<<")";
    }
}

QImage threeDMaze::mazeMap(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    QImage mazeTip(10,10,QImage::Format_RGB888);
    QImage mazeTransup(10,10,QImage::Format_RGB888);
    QImage mazeTransdown(10,10,QImage::Format_RGB888);
    mazeWall.fill(QColor(Qt::black));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));
    mazeTip.fill(QColor(Qt::yellow));
    mazeTransup.fill(QColor(0,0,255));
    mazeTransdown.fill(QColor(135,206,250));

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
                painter.drawImage(col * 10, row * 10, mazeTransup);
            }
            else if(threeDMap[my_z][row][col] == 8) {
                painter.drawImage(col * 10, row * 10, mazeTransdown);
            }
        }
    }
    return mazeImage; // 返回生成的迷宫图像
}

void threeDMaze::resetTransfer(){
    for(int i=0;i<transfersup.length();i++){
        threeDMap[i][transfersup[i]->trans_x][transfersup[i]->trans_y] = 5;
    }
    for(int i=0;i<transfersdown.length();i++){
        threeDMap[i+1][transfersup[i]->trans_x][transfersup[i]->trans_y] = 8;
    }
}
