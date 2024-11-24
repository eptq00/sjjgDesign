#include "userlogin.h"
#include "ui_userlogin.h"
#include <QFile>
#include <QDebug>

userLogin::userLogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userLogin)
{
    this->loadUserFile();
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

userLogin::~userLogin()
{
    delete ui;
}

void userLogin::loadUserFile(){
    QFile file("C:/Users/86135/Desktop/userfile.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        userInfo* user = new userInfo;
        user->username = in.readLine().trimmed(); // 第一行：用户名
        if (in.atEnd()) break;
        user->password = in.readLine().trimmed(); // 第二行：密码
        if (in.atEnd()) break;
        user->levelPutong = in.readLine().trimmed().toInt(); // 第三行：无尽模式普通模式通关关数
        if (in.atEnd()) break;
        user->levelNeiqian = in.readLine().trimmed().toInt(); // 第四行：无尽模式内嵌模式通关关数
        if (in.atEnd()) break;
        user->timePutong = in.readLine().trimmed().toDouble(); // 第五行：计时模式普通模式最短时间
        if (in.atEnd()) break;
        user->timeNeiqian = in.readLine().trimmed().toDouble(); // 第六行：计时模式内嵌模式最短时间
        if (in.atEnd()) break;
        user->taskTotal = in.readLine().trimmed().toInt(); // 第七行：任务模式总做题数
        if (in.atEnd()) break;
        user->taskRight = in.readLine().trimmed().toInt(); // 第七行：任务模式总做题数
        if (in.atEnd()) break;
        user->taskAccu = in.readLine().trimmed().toDouble(); // 第八行：任务模式做题总正确率
        if (in.atEnd()) break;
        user->duanwei = in.readLine().trimmed().toInt(); // 第七行：任务模式总做题数

        userInfos.append(user); // 添加到用户数组中
    }

    file.close();
}

void userLogin::saveUserFile() {
    QFile file("C:/Users/86135/Desktop/userfile.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&file);

    for (auto& user : userInfos) {
        if (user->username == usercurrent->username) {
            // 替换旧数据为新的用户数据
            user = new userInfo(usercurrent);
        }

        // 写入用户数据
        out << user->username << "\n"
            << user->password << "\n"
            << user->levelPutong << "\n"
            << user->levelNeiqian << "\n"
            << user->timePutong << "\n"
            << user->timeNeiqian << "\n"
            << user->taskTotal << "\n"
            << user->taskRight << "\n"
            << user->taskAccu << "\n"
            << user->duanwei <<"\n";
    }

    file.close();
}


userInfo* userLogin::getUser(){
    return usercurrent;
}

bool userLogin::getLoginState(){
    return this->isLogin;
}

void userLogin::on_login_clicked()
{
    this->username = ui->usernameEdit->text();
    this->password = ui->passwordEdit->text();
    qDebug()<<this->username<<"     "<<this->password;
    for (const auto& user : userInfos) {
        if (user->username == username) { // 检查用户名是否匹配
            if (user->password == password) { // 检查密码是否匹配
                qDebug() << "Login successful for user:" << username;
                // 登录成功
                usercurrent = new userInfo(user);
                this->isLogin = true;
                break;

            } else {
                qWarning() << "Incorrect password for user:" << username;
                // 密码错误
                break;
            }
        }
    }

    int i;
    if(isLogin){
        //登陆成功
        emit userIsLogin();
        switch(usercurrent->duanwei){
        case 0:i=0;break;
        case 1:i=0;break;
        case 2:i=0;break;
        case 3:i=0;break;
        case 4:i=0;break;
        }
        close();
    }
    else{
        qWarning() << "Username not found:" << username;
        ui->passwordEdit->clear();
    }
}


void userLogin::on_registerbutton_clicked()
{
    this->username = ui->usernameEdit->text();
    this->password = ui->passwordEdit->text();
    // 检查用户名是否已存在
    for (const userInfo* user : userInfos) {
        if (user->username == username) {
            qDebug() << "注册失败：用户名已存在！";
        }
    }

    // 创建新用户并初始化数据
    userInfo* newUser = new userInfo();
    newUser->username = username;
    newUser->password = password;

    // 添加到用户列表
    userInfos.append(newUser);
}


