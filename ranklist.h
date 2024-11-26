#ifndef RANKLIST_H
#define RANKLIST_H

#include <QWidget>
#include <QVector>
#include "userinfo.h"

namespace Ui {
class rankList;
}

class rankList : public QWidget
{
    Q_OBJECT

public:
    explicit rankList(QWidget *parent = nullptr);
    explicit rankList(QVector<userInfo*> userInfos, QWidget *parent = nullptr);
    ~rankList();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::rankList *ui;
    QVector<userInfo*> userInfos;
    QVector<userInfo*> userInfoOrder;
    void orderByTaskTotal();
    void orderByTaskRight();
    void orderByTaskAccu();
    void orderByDuanwei();
    void initUserOrder();
    void printUserInfo(QString orderMethod);
};

#endif // RANKLIST_H
