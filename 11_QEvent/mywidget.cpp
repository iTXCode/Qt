#include "mywidget.h"
#include "ui_mywidget.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);


    //利用事件过滤器，拦截label的鼠标按下事件
    //1.先给控件安装过滤器
    ui->label->installEventFilter(this);
    //2.重写过滤器事件
}

//过滤器事件
MyWidget::~MyWidget()
{
    delete ui;
}

//过滤器事件
//参数1：用于判断过滤的是那个控件
//参数2：判断事件
bool MyWidget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->label )
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* ev = static_cast<QMouseEvent*>(e);
            QString str = QString("在eventFilter中鼠标被按下了，鼠标移动的位置坐标 x=%1,y=%2").arg(ev->x()).arg(ev->y());
            qDebug()<<str;
            return true;  //拦截事件,不向下分发事件
        }
    }
    //其他的抛给父类
    return QWidget::eventFilter(obj,e);
}

