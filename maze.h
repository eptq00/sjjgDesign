#ifndef MAZE_H
#define MAZE_H
#include "mainwindow.h"

class Maze
{
public:
    Maze();
    Maze(int x);
    ~Maze();

    void createMaze();//生成迷宫
    void setMazeLevel(int x);//设置迷宫地图大小
    QImage mazeMap();

private:
    int mazeLevel = 0;
    int** map;
    int start_x, start_y;//迷宫起点
    void resetDir(bool* up, bool* down, bool* left, bool* right);
    void base();//生成基础单元格
};

#endif // MAZE_H
