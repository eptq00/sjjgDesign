#include "mazekeyevent.h"

mazeKeyEvent::mazeKeyEvent(QWidget *parent)
    : QGraphicsView(parent), Maze(){}

void mazeKeyEvent::keyPressEvent(QKeyEvent *event){
    emit sendToMaze(event); // 发射信号
    switch (event->key()) {
    case Qt::Key_W:
        if(map[my_x-1][my_y] == 1){
            map[my_x][my_y]=1;
            map[my_x-1][my_y]=2;
            my_x=my_x-1;
            //moved=true;
        }
        // 在这里添加向上移动的逻辑
        break;
    case Qt::Key_A:
        if(map[my_x][my_y-1] == 1){
            map[my_x][my_y]=1;
            map[my_x][my_y-1]=2;
            my_y=my_y-1;
            //moved=true;
        }
        // 在这里添加向左移动的逻辑
        break;
    case Qt::Key_S:
        if(map[my_x+1][my_y] == 1){
            map[my_x][my_y]=1;
            map[my_x+1][my_y]=2;
            my_x=my_x+1;
            //moved=true;
        }
        // 在这里添加向下移动的逻辑
        break;
    case Qt::Key_D:
        if(map[my_x][my_y+1] == 1){
            map[my_x][my_y]=1;
            map[my_x][my_y+1]=2;
            my_y=my_y+1;
            //moved=true;
        }
        // 在这里添加向右移动的逻辑
        break;
    default:
        QGraphicsView::keyPressEvent(event); // 其他按键传递给基类处理
        break;
    }
}
