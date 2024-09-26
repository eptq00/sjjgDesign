#include "rescaleimg.h"
#include <QWheelEvent>

rescaleImg::rescaleImg(QWidget *parent):QGraphicsView(parent) {}

void rescaleImg::wheelEvent(QWheelEvent *event){
    int wheelValue = event->angleDelta().y();
    double scalenum = (double)wheelValue/(double)1200+1;
    QPoint p(-100,100);
    QPoint q(100,-100);
    if((mapFromScene(p).rx()-mapFromScene(q).rx())>(p.rx()-q.rx()+60)){
        if(scalenum>1)
            scale(scalenum,scalenum);
    }
    else
        scale(scalenum,scalenum);
    emit sendToMap(event);
}

void rescaleImg::mouseMoveEvent(QMouseEvent *event){
    QGraphicsView::mouseMoveEvent(event);
    QWheelEvent* e=NULL;
    emit sendToMap(e);
}
