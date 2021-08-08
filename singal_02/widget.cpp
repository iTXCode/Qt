#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <QMainWindow>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

     m_me = new Me;
     m_gril = new GrilFriend;
     QPushButton* btn = new QPushButton("饿了",this);
//     btn->move(0,10);
//     connect(btn,&QPushButton::clicked,this,&Widget::hungrySlot);
//     connect(btn,&QPushButton::clicked,this,&Widget::eatSlot);
//     connect(m_gril,&GrilFriend::hungry,m_me,&Me::eating);
     //信号槽连接到一起，但是hungry不是框架的信号,框架不会发射，需要自己去发射信号
     //使用了按钮点击和调用hungruSlot槽函数的方式让框架明白需要调用hungey信号

     //信号连接信号
//     QPushButton* hun = new QPushButton("hungry",this);
//     hun->move(100,100);
//     connect(hun,&QPushButton::clicked,m_gril,&GrilFriend::hungry);
//     connect(m_gril,&GrilFriend::hungry,m_me,&Me::eating);

     //此处使用的是信号连接信号的方式，让框架明白了hungry是个信号

     //////使用Qt4的方式进行连接/////////////

     //connect(m_gril,SIGNAL(hungry()),m_me,SLOT(eating()));


     QMainWindow* mainw = new QMainWindow(this);
     mainw->setWindowTitle("选菜窗口");
     mainw->setFixedSize(200,200);
     QPushButton* xuancai = new QPushButton("选菜",this);
     xuancai->move(0,50);
     xuancai->setHidden(true);
     connect(btn,&QPushButton::clicked,xuancai,&QPushButton::show);
     connect(xuancai,&QPushButton::clicked,mainw,&QMainWindow::show);


     QPushButton* btnA = new QPushButton("青椒炒肉",mainw);
     btnA->move(0,0);
     btnA->setStyleSheet("QPushButton{border:2px groove gray;border-radius:8px;padding:2px 4px;background-color: rgb(225, 0,0);}");
     connect(btnA,&QPushButton::clicked,[=](){
        m_me->eating("青椒炒肉");
     });

     QPushButton* btnB = new QPushButton("木耳炒肉",mainw);
     btnB->move(0,30);
     connect(btnB,&QPushButton::clicked,[=](){
        m_me->eating("木耳炒肉");
     });

     QPushButton* btnC = new QPushButton("葱爆肉",mainw);
     btnC->move(0,60);
     connect(btnC,&QPushButton::clicked,[=](){
        m_me->eating("葱爆肉");
     });

     QPushButton* btnD = new QPushButton("凉拌黄瓜",mainw);
     btnD->move(0,90);
     connect(btnD,&QPushButton::clicked,[=](){
        m_me->eating("凉拌黄瓜");
     });

     QPushButton* btnE = new QPushButton("面皮子",mainw);
     btnE->move(0,120);
     connect(btnE,&QPushButton::clicked,[=](){
        m_me->eating("面皮子");
     });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::hungrySlot()
{
    //发射自定义信号
    m_gril->hungry();
}


