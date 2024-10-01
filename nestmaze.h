#ifndef NESTMAZE_H
#define NESTMAZE_H

#include "maze.h"

class nestMaze : public Maze
{
public:
    int **nestMap;
    bool inNest = false;
    nestMaze();
    int myNest_x,myNest_y;
    virtual QImage mazeMap();
    void createNestMaze();
    void nestCoordinate();

private:
    int nest_x,nest_y;
    QImage nestCell();
    //QImage nestMazeCell;
    virtual void base();
};

#endif // NESTMAZE_H
