#ifndef TASKMAZE_H
#define TASKMAZE_H
#include "maze.h"
#include "taskpos.h"
#include <Qvector>

class taskMaze : public Maze
{
public:
    bool inTask = false;
    bool taskFinish = false;

    taskMaze();
    void setTask();
    int gettaskx();
    int gettasky();
    QImage mazeMap();
    void createQuestion();
    QVector<taskpos*> gettaskposs();
    bool taskIsFinish();
    QVector<taskpos*> taskpositions;

private:
    int task_x, task_y;

};

#endif // TASKMAZE_H
