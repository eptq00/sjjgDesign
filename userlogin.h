#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include <QVector>
#include "userinfo.h"

namespace Ui {
class userLogin;
}

class userLogin : public QWidget
{
    Q_OBJECT

public:
    explicit userLogin(QWidget *parent = nullptr);
    ~userLogin();
    QVector<userInfo*> userInfos;
    userInfo* usercurrent;
    userInfo* getUser();
    void saveUserFile();
    bool getLoginState();

private slots:
    void on_login_clicked();

    void on_registerbutton_clicked();

private:
    Ui::userLogin *ui;
    void loadUserFile();
    QString username;
    QString password;
    bool isLogin = false;

signals:
    void userIsLogin();
};

#endif // USERLOGIN_H
