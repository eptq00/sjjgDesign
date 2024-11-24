#ifndef QUESTIONBOXPOEM_H
#define QUESTIONBOXPOEM_H

#include <QWidget>

namespace Ui {
class questionBoxPoem;
}

class questionBoxPoem : public QWidget
{
    Q_OBJECT

public:
    explicit questionBoxPoem(QWidget *parent = nullptr);
    ~questionBoxPoem();
    void setQuestion();
    bool judgePoem();
    void createPoemQuestion();

private slots:
    void on_sureButton_clicked();

private:
    Ui::questionBoxPoem *ui;
    QString question;
    QString answer;
    QString myAnswer;

signals:
    void problemTotalPlus();
    void problemRightPlus();
};

#endif // QUESTIONBOXPOEM_H
