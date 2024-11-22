#ifndef QUESTIONBOXJUDGE_H
#define QUESTIONBOXJUDGE_H

#include <QWidget>

namespace Ui {
class questionBoxJudge;
}

class questionBoxJudge : public QWidget
{
    Q_OBJECT

public:
    explicit questionBoxJudge(QWidget *parent = nullptr);
    ~questionBoxJudge();
    void setQuestion();
    bool judgeJudge();
    void createJudgeQuestion();

private slots:
    void on_trueButton_clicked();

    void on_falseButton_clicked();

private:
    Ui::questionBoxJudge *ui;
    QString question;
    bool answer;
    bool myAnswer;
};

#endif // QUESTIONBOXJUDGE_H
