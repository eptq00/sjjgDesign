#include "questionbox.h"
#include "ui_questionbox.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QRandomGenerator>

questionBox::questionBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::questionBox)
{
    ui->setupUi(this);
    setWindowTitle("提问箱"); // 设置题目名称
}

questionBox::~questionJudgeBox()
{
    delete ui;
}

void questionBox::createJudgeQuestion() {
    QFile file("C:/Users/86135/Desktop/question.txt"); // 打开文件
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    if (!file.isOpen()) { // 检查文件是否成功打开
        qDebug() << "Unable to open the file!";
        return;
    }

    QTextStream in(&file); // 创建文本流

    // 获取文件的总行数
    int totalLines = 0;
    while (!in.atEnd()) {
        in.readLine();
        totalLines++;
    }

    // 生成一个随机数，范围为 0 到 totalLines-1
    int randomIndex = QRandomGenerator::global()->bounded(totalLines);

    // 将文件流重新指向文件开始位置
    file.seek(0);
    QTextStream inAgain(&file); // 再次创建文本流读取文件

    // 读取到随机选择的第 randomIndex 行
    for (int i = 0; i <= randomIndex; i++) {
        QString line = inAgain.readLine();
        int questionMarkIndex = line.indexOf(' '); // 查找空格的位置

        if (questionMarkIndex != -1) { // 确保找到问号
            question = line.left(questionMarkIndex); // 获取问题（包括问号）
            QString answerget = line.mid(questionMarkIndex + 1).trimmed(); // 获取答案并去除前后空格

            // 判断答案是true还是false
            if (answerget == "true") {
                answer = true;
            }
            else if (answerget == "false") {
                answer = false;
            }
        }
    }

    file.close(); // 关闭文件

    // 输出读取的随机问题和答案
    qDebug() << "Random Question:" << this->question << ", Answer:" << this->answer;
}

void questionJudgeBox::setQuestion(){
    this->ui->questionLabel->setText(question);
}

bool questionBox::judgeJudge(){
    return (answer == myAnswer);
}

void questionBox::on_trueButton_clicked()
{
    this->myAnswer = true;
    this->hide();
}


void questionBox::on_pushButton_2_clicked()
{
    this->myAnswer = false;
    this->hide();
}

