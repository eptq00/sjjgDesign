#ifndef NESTMAZE_H
#define NESTMAZE_H

#include "maze.h"

class nestMaze : public Maze
{
public:
    int **nestMap;
    int **recordNestMap;
    bool inNest = false;
    bool isShowLarge = false;
    bool isShowSmall = false;
    QList<int> autoNestPath_x;
    QList<int> autoNestPath_y;
    nestMaze();
    int myNest_x,myNest_y;
    virtual QImage mazeMap();
    void createNestMaze();
    void nestCoordinate();
    QImage getNestCell();
    virtual void autoFindPath(int des_x, int des_y);
    int getnestx();
    int getnesty();

private:
    int nest_x,nest_y;
    QImage nestCell();
    virtual void base();
    void baseRecordNestMap();
    void autoFindNestPath();
};

#endif // NESTMAZE_H
