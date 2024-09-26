#include "mykeyevent.h"
#include <QKeyEvent>

myKeyEvent::myKeyEvent(QWidget *parent) : QGraphicsView() {}

void myKeyEvent::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_W:
        // 在这里添加按下 W 键时的效果
        break;
    case Qt::Key_A:
        // 在这里添加按下 A 键时的效果
        break;
    case Qt::Key_S:
        // 在这里添加按下 S 键时的效果
        break;
    case Qt::Key_D:
        // 在这里添加按下 D 键时的效果
        break;
    default:
        break;
    }
}
