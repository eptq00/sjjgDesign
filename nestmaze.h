#ifndef NESTMAZE_H
#define NESTMAZE_H

#include "maze.h"

class nestMaze : public Maze
{
public:
    int **nestMap;
    bool inNest = false;
    nestMaze();
    virtual QImage mazeMap();
    void createNestMaze();

private:
    QImage nestCell();
    //QImage nestMazeCell;
    virtual void base();
};

#endif // NESTMAZE_H
