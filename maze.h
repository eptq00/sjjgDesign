#ifndef MAZE_H
#define MAZE_H

#include <QMainWindow>
#include <QKeyEvent>

class Maze
{
public:
    Maze();
    Maze(int x);
    virtual ~Maze();

    int my_x = 1,my_y = 0;
    int** map;              //0-墙 1-路 2-人 3-内嵌迷宫 4-自动寻路 5-向下传送门 6-判断题 7-古诗题 8-向上传送门
    int** recordMap;
    int mazeLevel = 0;
    bool moved;
    QList<int> autoPath_x;
    QList<int> autoPath_y;
    void createMaze();//生成迷宫
    void setMazeLevel(int x);//设置迷宫地图大小
    virtual QImage mazeMap();
    virtual void autoFindPath(int des_x, int des_y);

protected:
    int** move;
    int start_x, start_y;//迷宫起点
    void resetDir(bool* up, bool* down, bool* left, bool* right);
    virtual void base();//生成基础单元格
    void baseRecordMap();
    void randomDelete();
};

#endif // MAZE_H
