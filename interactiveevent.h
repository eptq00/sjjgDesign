#ifndef INTERACTIVEEVENT_H
#define INTERACTIVEEVENT_H
#include <QGraphicsView>

class QWheelEvent;
class QKeyEvent;

class InteractiveEvent : public QGraphicsView
{
public:
    InteractiveEvent();

protected:
    //void keyPressEvent(QKeyEvent *event);//按压键盘
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseWheelEvent(QMouseEvent *event);

public:
    void biggerImg();
    void smallerImg();
    void translateImg(QPointF delta)//平移;

private:
    Qt::MouseButton m_translateButton;  // 平移按钮
    qreal m_zoomDelta;  // 缩放的增量
    bool m_bMouseTranslate;  // 平移标识
    QPoint m_lastMousePos;  // 鼠标最后按下的位置
    qreal m_scale;  // 缩放值
};

#endif // INTERACTIVEEVENT_H
