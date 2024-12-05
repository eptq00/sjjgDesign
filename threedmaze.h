#ifndef THREEDMAZE_H
#define THREEDMAZE_H
#include "maze.h"
#include "transferpos.h"
#include "taskpos.h"
#include <Qvector>

class threeDMaze : public Maze
{
public:
    int layer;
    int ***threeDMap;
    int my_z = 0;
    threeDMaze();
    virtual void base();
    void create3DMaze();
    void setLayer(int layer);
    virtual QImage mazeMap();
    void setTransfer();
    void resetTransfer();

private:
    void createMaze();
    QVector<transferPos*> transfersup;
    QVector<transferPos*> transfersdown;
};

#endif // THREEDMAZE_H
