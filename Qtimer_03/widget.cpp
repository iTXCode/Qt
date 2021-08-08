#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include "widget1.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* close = new QPushButton("关闭窗口",this);
    this->setFixedSize(500,250);
    this->window()->setWindowFlag(Qt::FramelessWindowHint);
    close->move(this->width()-75,0);
    connect(close,&QPushButton::clicked,this,&QWidget::close);
    //this->setWindowFlags(Qt::FramelessWindowHint);//设置让窗口隐藏标题栏
//    this->setStyleSheet("QWidget{border-radius:15px;}");

    Widget::setWindowTitle("你妹的");
    m_tm = new QTimer(this);
    QPushButton* btn = new QPushButton("定时器开关",this);
    connect(btn,&QPushButton::clicked,this,[=](){
       if(m_tm->isActive())
       {
           //定时器启动了
           m_tm->stop();
           btn->setText("启动");
       }
       else {
           m_tm->start(1000);
           btn->setText("停止");
       }
    });

    QLabel* lab = new QLabel(this);
    lab->setFixedWidth(120);
    lab->move(btn->width(),0);
    lab->setStyleSheet("border:2px solid red;border-radius:8px;");
    //btnA->setStyleSheet("QPushButton{border:2px groove gray;border-radius:8px;padding:2px 4px;background-color: rgb(225, 0,0);}");
    lab->show();
    connect(m_tm,&QTimer::timeout,[=](){
        QTime tm = QTime::currentTime();

        QString str = tm.toString("hh:mm:ss:zzz");
        lab->setText(str);

    });

    //发射一次信号



//    widget1 * win = new widget1(this);
//    win->show();



}

Widget::~Widget()
{
    delete ui;
}
