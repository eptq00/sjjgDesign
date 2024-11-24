#ifndef USERINFO_H
#define USERINFO_H
#include <QString>

class userInfo
{
public:
    userInfo();
    userInfo(userInfo* other);
    QString username;
    QString password;
    int levelPutong;
    int levelNeiqian;
    double timePutong;
    double timeNeiqian;
    int taskTotal;
    int taskRight;
    double taskAccu;
    int duanwei;
};

#endif // USERINFO_H
