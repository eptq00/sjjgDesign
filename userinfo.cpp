#include "userinfo.h"

userInfo::userInfo() {
    this->username="";
    this->password="";
    this->levelPutong=0;
    this->levelNeiqian=0;
    this->timePutong=0;
    this->timeNeiqian=0;
    this->taskTotal=0;
    this->taskRight=0;
    this->taskAccu=0;
    this->duanwei=0;
}

userInfo::userInfo(userInfo* other) {
    this->username = other->username;
    password = other->password;
    levelPutong = other->levelPutong;
    levelNeiqian = other->levelNeiqian;
    timePutong = other->timePutong;
    timeNeiqian = other->timeNeiqian;
    taskTotal = other->taskTotal;
    taskRight = other->taskRight;
    taskAccu = other->taskAccu;
    duanwei = other->duanwei;
}
