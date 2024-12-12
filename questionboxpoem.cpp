#include "questionboxpoem.h"
#include "ui_questionboxpoem.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QRandomGenerator>

questionBoxPoem::questionBoxPoem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::questionBoxPoem)
{
    ui->setupUi(this);
    setWindowTitle("古诗提问箱"); // 设置题目名称
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint);
}

questionBoxPoem::~questionBoxPoem()
{
    delete ui;
}

void questionBoxPoem::createPoemQuestion() {
    QFile file("C:/Users/86135/Desktop/poem.txt"); // 打开文件
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
        int questionMarkIndex = line.indexOf("，"); // 查找逗号的位置

        if (questionMarkIndex != -1) { // 确保找到,
            int randomNumber = rand() % 2;
            if(randomNumber == 0){
                ui->answerEdit->move(90 , 80);
                ui->questionLabel->move(90 , 40);
                question = line.left(questionMarkIndex+1); // 获取问题（包括,号）
                answer = line.mid(questionMarkIndex + 1).trimmed(); // 获取答案并去除前后空格
            }
            else{
                ui->answerEdit->move(90 , 40);
                ui->questionLabel->move(90 , 80);
                answer = line.left(questionMarkIndex+1);
                question = line.mid(questionMarkIndex + 1).trimmed();
            }
        }
    }

    file.close(); // 关闭文件

    // 输出读取的随机问题和答案
    qDebug() << "Random Question:" << this->question << ", Answer:" << this->answer;
}

void questionBoxPoem::setQuestion(){
    this->ui->questionLabel->setText(question);
}

bool questionBoxPoem::judgePoem(){
    return (answer == myAnswer);
}

void questionBoxPoem::on_sureButton_clicked()
{
    this->myAnswer = ui->answerEdit->text();
    ui->answerEdit->clear();
    emit problemTotalPlus();
    if(this->judgePoem()){
        emit problemRightPlus();
        hide();
    }
    else{
        createPoemQuestion();
        setQuestion();
    }
}

