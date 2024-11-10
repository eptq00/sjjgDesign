#ifndef THREEDMAZE_H
#define THREEDMAZE_H
#include "maze.h"

class threeDMaze : public Maze
{
public:
    int layer;
    int ***threeDMap;
    threeDMaze();
    void create3DMaze();


private:
    virtual void base();
};

#endif // THREEDMAZE_H
