#ifndef RANKLIST_H
#define RANKLIST_H

#include <QWidget>

namespace Ui {
class rankList;
}

class rankList : public QWidget
{
    Q_OBJECT

public:
    explicit rankList(QWidget *parent = nullptr);
    ~rankList();

private:
    Ui::rankList *ui;
};

#endif // RANKLIST_H
