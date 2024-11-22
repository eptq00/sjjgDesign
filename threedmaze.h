#ifndef THREEDMAZE_H
#define THREEDMAZE_H
#include "maze.h"
#include "transferpos.h"
#include <Qvector>

class threeDMaze : public Maze
{
public:
    int layer;
    int ***threeDMap;
    int my_z = 0;
    threeDMaze();
    void create3DMaze();
    QVector<transferPos*> transfers;
    virtual QImage mazeMap();


private:
    virtual void base();
    void setTransfer();
};

#endif // THREEDMAZE_H
