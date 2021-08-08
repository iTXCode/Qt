#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::streat()
{
    qDebug() << "请老师吃饭!";
}

void Student::streat(QString foodName)
{
    qDebug() << "请老师吃:"<<foodName.toUtf8().data();
    //需要将QString转成char* 输出
    //QString 类型的字符串是带""号的
}
