#ifndef NESTMAZE_H
#define NESTMAZE_H

#include "maze.h"

class nestMaze : public Maze
{
public:
    int **nestMap;
    nestMaze();
    QImage mazeMap();

private:
    QImage nestCell();
};

#endif // NESTMAZE_H
