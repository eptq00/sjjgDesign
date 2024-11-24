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
    QVector<transferPos*> transfersup;
    QVector<transferPos*> transfersdown;
    virtual QImage mazeMap();
    void setTransfer();

private:
    //void createMaze();
};

#endif // THREEDMAZE_H
