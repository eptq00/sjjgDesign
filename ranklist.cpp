#include "ranklist.h"
#include "ui_ranklist.h"

rankList::rankList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rankList)
{
    ui->setupUi(this);
}

rankList::rankList(QVector<userInfo*> userInfos, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rankList)
{
    for (userInfo* user : userInfos) {
        // 创建新的 userInfo 对象，并通过复制构造函数将数据复制进来
        userInfo* newUser = new userInfo(*user);
        this->userInfos.append(newUser);
    }
    this->initUserOrder();
    ui->setupUi(this);
}

rankList::~rankList()
{
    delete ui;
}

void rankList::initUserOrder(){
    for (userInfo* user : userInfos) {
        // 创建新的 userInfo 对象，并通过复制构造函数将数据复制进来
        userInfo* newUser = new userInfo(*user);
        this->userInfoOrder.append(newUser);
    }
}

// 根据 taskTotal 排序
void rankList::orderByTaskTotal() {
    std::sort(userInfoOrder.begin(), userInfoOrder.end(), [](const userInfo* a, const userInfo* b) {
        return a->taskTotal > b->taskTotal; // 降序排序，如果需要升序，改成 a->taskTotal < b->taskTotal
    });
}

// 根据 taskRight 排序
void rankList::orderByTaskRight() {
    std::sort(userInfoOrder.begin(), userInfoOrder.end(), [](const userInfo* a, const userInfo* b) {
        return a->taskRight > b->taskRight; // 降序排序
    });
}

// 根据 taskAccu 排序
void rankList::orderByTaskAccu() {
    std::sort(userInfoOrder.begin(), userInfoOrder.end(), [](const userInfo* a, const userInfo* b) {
        return a->taskAccu > b->taskAccu; // 降序排序
    });
}

// 根据 duanwei 排序
void rankList::orderByDuanwei() {
    std::sort(userInfoOrder.begin(), userInfoOrder.end(), [](const userInfo* a, const userInfo* b) {
        return a->duanwei > b->duanwei; // 降序排序
    });
}

void rankList::printUserInfo(QString orderMethod) {
    // 确保清空 QTextBrowser 的内容
    this->ui->textBrowser->clear();
    int i = 0;

    // 遍历 userInfoOrder 并逐行添加内容
    for (const userInfo* user : userInfoOrder) {
        i++;

        // 根据 orderMethod 动态设置第四个参数的值
        QString value;
        if (orderMethod == "做题数") {
            value = QString::number(user->taskTotal); // taskTotal 转为字符串
        } else if (orderMethod == "正确数") {
            value = QString::number(user->taskRight); // taskRight 转为字符串
        } else if (orderMethod == "准确率") {
            value = QString::number(user->taskAccu);   // duanwei 转为字符串
        }else if (orderMethod == "段位") {
            value = QString::number(user->duanwei);   // duanwei 转为字符串
        } else {
            value = "未知"; // 兜底情况，防止意外
        }

        QString line = QString("第%1名    %2    %3 : %4")
                           .arg(i)
                           .arg(user->username)
                           .arg(orderMethod)
                           .arg(value);

        this->ui->textBrowser->append(line); // 将字符串追加到 QTextBrowser
    }
}

void rankList::on_comboBox_currentIndexChanged(int index)
{
    this->ui->textBrowser->clear();

    if(index == 1){
        this->orderByDuanwei();
        printUserInfo("做题数");
    }
    else if(index == 2){
        this->orderByDuanwei();
        printUserInfo("正确数");
    }
    else if(index == 3){
        this->orderByDuanwei();
        printUserInfo("准确率");
    }
    else if(index == 4){
        this->orderByDuanwei();
        printUserInfo("段位");
    }
}

