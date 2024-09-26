#ifndef MYKEYEVENT_H
#define MYKEYEVENT_H

#include <QMainWindow>
#include <QGraphicsView>
#include "maze.h"

class myKeyEvent : public QGraphicsView {
    Q_OBJECT

public:
    myKeyEvent(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void sendToMap(QWheelEvent *event);
};

#endif // MYKEYEVENT_H
