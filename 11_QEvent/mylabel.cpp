#include "mylabel.h"
#include <QtDebug>
#include <QMouseEvent>
#include <QString>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true); //设置一个鼠标追踪,即不用点击就移动也可感应到
}

void MyLabel::enterEvent(QEvent *)
{
    //qDebug()<<"鼠标进入了!";
}

void MyLabel::leaveEvent(QEvent *)
{
    //qDebug()<<"鼠标离开了!";
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    //如果是鼠标左键按下， 才会打印下面的信息，所以需要做一个判断
    if(ev->button() == Qt::LeftButton )
    {//鼠标为左键才管用
        QString str = QString("鼠标按下了，鼠标按下的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
        //字符串拼接
        qDebug()<<str;
    }

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
     if(ev->button() == Qt::LeftButton )
     {
        QString str = QString("鼠标释放了，鼠标释放的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
     }

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //1.仅仅可以完成点击移动，左右键都可以
    //         QString str = QString("鼠标移动了，鼠标移动的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
    //         qDebug()<<str;
    //         //需要点击之后移动


    //  2.左右键按下之后移动不会被感应到，存在联合按键的现象(是一个连续事件，不是点击或者释放)
//         if(ev->button() == Qt::LeftButton )
//         {
//             QString str = QString("鼠标移动了，鼠标移动的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
//             qDebug()<<str;
//             //需要点击之后移动
//         }

    //3. 点击左键之后移动会有提示
//    if(ev->buttons() & Qt::LeftButton)
//    {
//        QString str = QString("鼠标移动了，鼠标移动的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
//        qDebug()<<str;
//        //需要点击之后移动
//    }


    //设置不用点击鼠标之后再移动

    QString str = QString("鼠标移动了，鼠标移动的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;



}


//事件分发器
//在该过程中的鼠标按下事件已经被拦截了，不会再被分化下去。
//所以只显示"在event中鼠标被按下了，鼠标移动的位置坐标 x=155,y=73"
//而不显示  "鼠标按下了，鼠标按下的位置坐标 x=%1,y=%2
bool MyLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* ev = static_cast<QMouseEvent*>(e);
        QString str = QString("在event中鼠标被按下了，鼠标移动的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
        return true;  //拦截事件,不向下分发事件
    }

    //其他事件交给父类处理
    return QLabel::event(e);
}

/****
事件过滤器
1、给控件安装过滤器
2、重写过滤器事件
bool eventFilter(两个参数);

 */
