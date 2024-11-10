#ifndef NESTMAZE_H
#define NESTMAZE_H

#include "maze.h"

class nestMaze : public Maze
{
public:
    int **nestMap;
    bool inNest = false;
    bool isShowLarge = false;
    bool isShowSmall = false;
    nestMaze();
    int myNest_x,myNest_y;
    virtual QImage mazeMap();
    void createNestMaze();
    void nestCoordinate();
    QImage getNestCell();
private:
    int nest_x,nest_y;
    QImage nestCell();
    virtual void base();
};

#endif // NESTMAZE_H
