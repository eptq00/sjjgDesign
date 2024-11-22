#ifndef AUTOPATHDES_H
#define AUTOPATHDES_H

#include "maze.h"
#include <QWidget>

namespace Ui {
class autoPathDes;
}

class autoPathDes : public QWidget
{
    Q_OBJECT

public:
    explicit autoPathDes(QWidget *parent = nullptr);
    ~autoPathDes();
    int getDes_x();
    int getDes_y();
    bool judge(Maze* maze);
    void setMazeLevel(int mazeLevel);

private slots:
    void on_sureButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::autoPathDes *ui;
    int des_x,des_y;
    int mazeLevel;

signals:
    void destinationConfirmed();
};

#endif // AUTOPATHDES_H
