#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器  单位是毫秒级
    this->Timer_id1 = startTimer(1000);
    this->Timer_id2 = startTimer(2000);//第二个定时器
    this->num = 1;

    //定时器的类
    QTimer* tm = new QTimer(this);
    tm->start(500);

    //监听定时器
    connect(tm, &QTimer::timeout, [=](){
        static int nu = 1;
        ui->label_3->setText(QString::number(nu++));
    });

    //点击暂停按钮 实现停止定时器

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        tm->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}


//定时器事件    Event *)
void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == Timer_id1)
    {
        ui->label->setText(QString::number(num++));
        return;
    }
    if(e->timerId() == Timer_id2)
    {
        static int num1 = 1;
        ui->label_2->setText(QString::number(num1++));
    }
}
