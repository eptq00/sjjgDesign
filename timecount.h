#ifndef TIMECOUNT_H
#define TIMECOUNT_H
#include<QString>
#include<QTime>

class TimeCount
{
public:
    TimeCount();
    void timeStart();
    QString refreshTime();
    void timeEnd();
private:
    QTime startTime;
};

#endif // TIMECOUNT_H
