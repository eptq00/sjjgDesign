#include "ranklist.h"
#include "ui_ranklist.h"

rankList::rankList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rankList)
{
    ui->setupUi(this);
}

rankList::~rankList()
{
    delete ui;
}
