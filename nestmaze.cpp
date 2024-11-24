#include "nestmaze.h"
#include <QPainter>
#include <QStack>

nestMaze::nestMaze() : Maze() {}

QImage nestMaze::nestCell(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    QImage mazeTip(10,10,QImage::Format_RGB888);
    mazeWall.fill(QColor(Qt::red));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));
    mazeTip.fill(QColor(Qt::yellow));

    // 创建一个新的QImage对象，大小为迷宫的宽度和高度
    QImage mazeImage(mazeLevel * 10, mazeLevel * 10, QImage::Format_ARGB32);
    QPainter painter(&mazeImage); // 创建QPainter对象，用于绘制图像

    // 遍历迷宫数组
    for (int row = 0; row < mazeLevel; row++) {
        for (int col = 0; col < mazeLevel; col++) {
            // 1-绘制路图片
            if (nestMap[row][col] == 1) {
                painter.drawImage(col * 10, row * 10, mazeRoad);
            }
            // 0-绘制墙图片
            else if(nestMap[row][col] == 0) {
                painter.drawImage(col * 10, row * 10, mazeWall);
            }
            else if(nestMap[row][col] == 2) {
                if(inNest){
                    painter.drawImage (col * 10, row * 10, mazeMy);
                }
                else{
                    painter.drawImage(col * 10, row * 10, mazeRoad);
                }
            }
            else if(nestMap[row][col] == 4) {
                painter.drawImage(col * 10, row * 10, mazeTip);
            }
        }
    }

    return mazeImage;
}

void nestMaze::base() {
    nestMap = new int*[mazeLevel];
    for (int i = 0; i < mazeLevel; i++) {
        nestMap[i] = new int[mazeLevel];
    }

    for (int i = 0; i < mazeLevel; i++) {
        for (int j = 0; j < mazeLevel; j++) {
            nestMap[i][j] = 0;
        }
    }
}

void nestMaze::createNestMaze(){
    nestMaze::base();
    this->start_x = mazeLevel / 2;
    this->start_y = 1;
    this->nestMap[this->start_x][this->start_y]=1;
    int currpoint_x = start_x, currpoint_y = start_y;
    bool up=false, down=false, left=false, right=false;
    QStack<int> MazeStack_x;
    QStack<int> MazeStack_y;
    this->nestMap[mazeLevel / 2][0] = 1;
    this->nestMap[mazeLevel / 2][mazeLevel - 1] = 1;
    while(true){
        int ranNum=rand()%4;
        switch(ranNum){
        case 0://上
            if(!up && currpoint_x>2 && this->nestMap[currpoint_x-2][currpoint_y] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->nestMap[currpoint_x-2][currpoint_y] = 1;
                this->nestMap[currpoint_x-1][currpoint_y] = 1;
                currpoint_x = currpoint_x - 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                up=true;
            }
            break;
        case 1://下
            if(!down && currpoint_x<mazeLevel-3 && this->nestMap[currpoint_x+2][currpoint_y] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->nestMap[currpoint_x+2][currpoint_y] = 1;
                this->nestMap[currpoint_x+1][currpoint_y] = 1;
                currpoint_x = currpoint_x + 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                down=true;
            }
            break;
        case 2://左
            if(!left && currpoint_y>2 && this->nestMap[currpoint_x][currpoint_y-2] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->nestMap[currpoint_x][currpoint_y-2] = 1;
                this->nestMap[currpoint_x][currpoint_y-1] = 1;
                currpoint_y = currpoint_y - 2;
                this->resetDir(&up,&down,&left,&right);
            }
            else{
                left=true;
            }
            break;
        case 3://右
            if(!right && currpoint_y<mazeLevel-3 && this->nestMap[currpoint_x][currpoint_y+2] == 0){
                MazeStack_x.push(currpoint_x);
                MazeStack_y.push(currpoint_y);
                this->nestMap[currpoint_x][currpoint_y+2] = 1;
                this->nestMap[currpoint_x][currpoint_y+1] = 1;
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

void nestMaze::nestCoordinate(){
    while(true){
        nest_x=rand()%mazeLevel;
        nest_y=rand()%mazeLevel;
        if(map[nest_x][nest_y] == 1){
            if(map[nest_x][nest_y-1]==1 && map[nest_x][nest_y+1]==1 && map[nest_x-1][nest_y]!=1 && map[nest_x+1][nest_y]!=1){
                map[nest_x][nest_y]=3;//3 嵌套
                break;
            }
        }
    }
}

QImage nestMaze::mazeMap(){
    QImage mazeWall(10,10,QImage::Format_RGB888);
    QImage mazeRoad(10,10,QImage::Format_RGB888);
    QImage mazeMy(10,10,QImage::Format_RGB888);
    QImage mazeTip(10,10,QImage::Format_RGB888);
    QImage nestMazeCell=this->nestCell();
    nestMazeCell = nestMazeCell.scaled(10,10); 
    mazeWall.fill(QColor(Qt::black));
    mazeRoad.fill(QColor(Qt::white));
    mazeMy.fill(QColor(Qt::green));
    mazeTip.fill(QColor(Qt::yellow));

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
            else if(map[row][col] == 3) {
                painter.drawImage(col * 10, row * 10, nestMazeCell);
            }
            else if(map[row][col] == 4) {
                painter.drawImage(col * 10, row * 10, mazeTip);
            }
        }
    }
    return mazeImage; // 返回生成的迷宫图像
}

void nestMaze::autoFindPath(int des_x, int des_y){
    this->baseRecordMap();
    QList<int> MazeList_x;
    QList<int> MazeList_y;
    int temp_x, temp_y, temp_state;
    recordMap[des_x][des_y]=0;  //出口位置标记为已经访问过,0为墙
    //MazeList_x.clear();
    //MazeList_y.clear();
    //autoPath_x.clear();
    //autoPath_y.clear();

    MazeList_x.push_back(des_x);    //寻路终点入list
    MazeList_y.push_back(des_y);

    int i , j;
    while(!MazeList_x.isEmpty() && !MazeList_x.isEmpty())
    {
        int top_x = MazeList_x.back();
        int top_y = MazeList_y.back();
        MazeList_x.pop_back();
        MazeList_y.pop_back();

        if(!autoPath_x.isEmpty() && !autoPath_y.isEmpty() && !(top_x==autoPath_x.back()) && !(top_y==autoPath_y.back())){
            autoPath_x.push_back(top_x);
            autoPath_y.push_back(top_y);
        }
        if(autoPath_x.isEmpty() && autoPath_y.isEmpty()){
            autoPath_x.push_back(top_x);
            autoPath_y.push_back(top_y);
        }

        i = top_x;
        j = top_y;
        int d = 0;  // 用于表示方向 (0: 上, 1: 右, 2: 下, 3: 左)
        while(d < 4)
        {
            // 根据方向移动
            switch(d)
            {
            case 0: temp_x = i - 1; temp_y = j; break; // 上
            case 1: temp_x = i; temp_y = j + 1; break; // 右
            case 2: temp_x = i + 1; temp_y = j; break; // 下
            case 3: temp_x = i; temp_y = j - 1; break; // 左
            }

            if(temp_x == my_x && temp_y == my_y)
            {
                MazeList_x.push_back(top_x);
                MazeList_y.push_back(top_y);
                MazeList_x.push_back(temp_x);
                MazeList_y.push_back(temp_y);
                autoPath_x.push_back(temp_x);
                autoPath_y.push_back(temp_y);

                for(int k=0 ; k<MazeList_x.size();k++)
                {
                    qDebug() << "(" << MazeList_x[k] << "," << MazeList_y[k] << ")";
                }

                for (int k = 0; k < MazeList_x.size(); k++) {
                    map[MazeList_x[k]][MazeList_y[k]] = 4;  // 标记为路径
                }
                if(des_x == this->mazeLevel - 2 && des_y == this->mazeLevel - 2)
                    map[mazeLevel-2][mazeLevel-1]=4;
                return;
            }

            if (((map[temp_x][temp_y] == 1) || (map[temp_x][temp_y] == 3) || (map[temp_x][temp_y] == 4)) && recordMap[temp_x][temp_y] == 1) {
                if(map[temp_x][temp_y] == 3){
                    autoFindNestPath();
                }
                recordMap[temp_x][temp_y] = 0;  // 标记已访问
                MazeList_x.push_back(top_x);
                MazeList_y.push_back(top_y);
                MazeList_x.push_back(temp_x);
                MazeList_y.push_back(temp_y);
                autoPath_x.push_back(temp_x);
                autoPath_y.push_back(temp_y);
                break;  // 找到可走的路径，跳出方向循环
            }
            d++;
        }
        if(d==4){
            autoPath_x.push_back(MazeList_x.back());
            autoPath_y.push_back(MazeList_y.back());
        }
    }
}

void nestMaze::baseRecordNestMap(){
    recordNestMap = new int*[mazeLevel];
    for (int i = 0; i < mazeLevel; i++) {
        recordNestMap[i] = new int[mazeLevel];
    }

    for (int i = 0; i < mazeLevel; i++) {
        for (int j = 0; j < mazeLevel; j++) {
            this->recordNestMap[i][j] = 1;
        }
    }
}

void nestMaze::autoFindNestPath(){
    this->baseRecordNestMap();
    QList<int> MazeList_x;
    QList<int> MazeList_y;
    int temp_x, temp_y, temp_state;
    recordNestMap[this->mazeLevel / 2][this->mazeLevel-2]=0;  //出口位置标记为已经访问过,0为墙
    MazeList_x.push_back(this->mazeLevel / 2);    //寻路终点入list
    MazeList_y.push_back(this->mazeLevel - 2);

    int i , j;
    while(!MazeList_x.isEmpty() && !MazeList_x.isEmpty())
    {
        int top_x = MazeList_x.back();
        int top_y = MazeList_y.back();
        MazeList_x.pop_back();
        MazeList_y.pop_back();

        if(!autoNestPath_x.isEmpty() && !autoNestPath_y.isEmpty() && !(top_x==autoNestPath_x.back()) && !(top_y==autoNestPath_y.back())){
            autoNestPath_x.push_back(top_x);
            autoNestPath_y.push_back(top_y);
        }
        if(autoNestPath_x.isEmpty() && autoNestPath_y.isEmpty()){
            autoNestPath_x.push_back(top_x);
            autoNestPath_y.push_back(top_y);
        }

        i = top_x;
        j = top_y;
        int d = 0;  // 用于表示方向 (0: 上, 1: 右, 2: 下, 3: 左)
        while(d < 4)
        {
            // 根据方向移动
            switch(d)
            {
            case 0: temp_x = i - 1; temp_y = j; break; // 上
            case 1: temp_x = i; temp_y = j + 1; break; // 右
            case 2: temp_x = i + 1; temp_y = j; break; // 下
            case 3: temp_x = i; temp_y = j - 1; break; // 左
            }

            if(temp_x == mazeLevel / 2 && temp_y == 1)
            {
                MazeList_x.push_back(top_x);
                MazeList_y.push_back(top_y);
                MazeList_x.push_back(temp_x);
                MazeList_y.push_back(temp_y);
                autoNestPath_x.push_back(temp_x);
                autoNestPath_y.push_back(temp_y);

                for(int k=0 ; k<MazeList_x.size();k++)
                {
                    qDebug() << "(" << MazeList_x[k] << "," << MazeList_y[k] << ")";
                }

                for (int k = 0; k < MazeList_x.size(); k++) {
                    nestMap[MazeList_x[k]][MazeList_y[k]] = 4;  // 标记为路径
                }
                //if(des_x == this->mazeLevel - 2 && des_y == this->mazeLevel - 2)
                nestMap[mazeLevel / 2][mazeLevel-1]=4;
                nestMap[mazeLevel / 2][0]=4;
                return;
            }

            if (((nestMap[temp_x][temp_y] == 1) || (nestMap[temp_x][temp_y] == 4)) && recordNestMap[temp_x][temp_y] == 1) {
                recordNestMap[temp_x][temp_y] = 0;  // 标记已访问
                MazeList_x.push_back(top_x);
                MazeList_y.push_back(top_y);
                MazeList_x.push_back(temp_x);
                MazeList_y.push_back(temp_y);
                autoNestPath_x.push_back(temp_x);
                autoNestPath_y.push_back(temp_y);
                break;  // 找到可走的路径，跳出方向循环
            }
            d++;
        }
        if(d==4){
            autoNestPath_x.push_back(MazeList_x.back());
            autoNestPath_y.push_back(MazeList_y.back());
        }
    }
}

QImage nestMaze::getNestCell(){
    return this->nestCell();
}

int nestMaze::getnestx(){
    return this->nest_x;
}

int nestMaze::getnesty(){
    return this->nest_y;
}
