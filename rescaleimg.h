#ifndef RESCALEIMG_H
#define RESCALEIMG_H

#include <QGraphicsView>
#include <QMainWindow>

class rescaleImg : public QGraphicsView
{ Q_OBJECT
public:
    explicit rescaleImg(QWidget *parent = nullptr);

signals:
    void sendToMap(QWheelEvent *event);

private:
    double m_scalnum; //缩放系数
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // RESCALEIMG_H
