#include "me.h"
#include <QDebug>

Me::Me(QObject *parent) : QObject(parent)
{

}

//void Me::eating()
//{
//    qDebug()<<"请女朋友吃火锅";
//}

void Me::eating(QString food)
{
    QString str = QString("请女朋友吃%1").arg(food);
    qDebug()<<str;
}
