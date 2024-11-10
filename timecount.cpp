#include "timecount.h"
#include<QString>
#include<QTime>

TimeCount::TimeCount() {}

void TimeCount::timeStart(){
    startTime = QTime::currentTime();
}

QString TimeCount::refreshTime(){
    QString timeStr;
    //timeLabel上显示的timeStr
    double elapsedSeconds = startTime.msecsTo(QTime::currentTime()) / 1000.0;
    timeStr = QString("Time: %1 s").arg(QString::number(elapsedSeconds, 'f', 1));
    return timeStr;
}

void TimeCount::timeEnd(){
    double elapsedSeconds = startTime.msecsTo(QTime::currentTime()) / 1000.0;
    qDebug() << "经过的时间:" << elapsedSeconds<<"s";
}
