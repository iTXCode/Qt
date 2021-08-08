#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QTabBar>
#include <QString>
#include <QVariant>
#include <QLine>
#include <QDate>
#include <QPoint>
#include <QTime>
#include <QElapsedTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QPushButton* btnA = new QPushButton("按钮A",this);
//    btnA->move(10,10);
//    btnA->setFixedSize(400,100);

//    QPushButton* btnB = new QPushButton("按钮B", btnA);
//    btnB->move(50,50);

//    qintptr a=10;

//    int ret = dataPlus(10,20).toInt();
//    qDebug()<<ret;

//    //字符串相加

//    QString  str = dataPlus("hello "," world!").toString();
//    qDebug()<<str;

    //自定义类型测试

    Person ps;
    ps.m_age =18;
    ps.m_name = "你大爷";


    //封装数据
#if 0
    QVariant v;
    v.setValue(ps);
#else
    QVariant v = QVariant::fromValue(ps);
#endif

    //取出v对象中的数据
    if(v.canConvert<Person>())
    {
        Person tmp = v.value<Person>();
        qDebug()<<"m_age:"<<tmp.m_age<<",m_name:"<<tmp.m_name;
    }


    QLine line(QPoint(100,200),QPoint(150,250));
    QLine newline = line.translated(20,20);
    qDebug()<<"平移前的坐标点:"<<line;
    qDebug()<<"平移后的坐标点:"<<newline;

    QDate date = QDate::currentDate();
    qDebug()<<date;

    //第一种方式
    qDebug()<<"year:"<<date.year()<<"month:"<<date.month()<<"day:"<<date.day();

    //以String方式输出
    QString str = date.toString("yyyy-MM-dd");
    qDebug()<<str;


    QTime tm = QTime::currentTime();

    qDebug()<<tm.hour()<<"时"<<tm.minute()<<"分"<<tm.second()<<"秒";

    QString str_tm = tm.toString("A:HH-mm-ss-zzz");
    qDebug()<<str_tm.toUtf8().data();


//    QTime tt;
    QElapsedTimer tt;
    tt.start();
    randNumbers(100);
    int ms = tt.elapsed();
    qDebug()<<"函数执行所用事件的长度为:"<<ms<<"毫秒";

    QDateTime dat = QDateTime::currentDateTime();

    qDebug()<<dat;

    QString sd = dat.toString("yyyy/MM/dd ap  hh/mm/ss/zzz ");
    qDebug()<<sd;

    qDebug()<<sd.toUtf8().data();

    QPushButton* btn = new QPushButton("关闭",this);
    btn->setIcon(QIcon(":/image/Sunny.jpg"));
    btn->move(this->height(),0);
    connect(btn,&QPushButton::clicked,this,&QMainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QVariant MainWindow::dataPlus(QVariant a, QVariant b)
{
    //首先判断两个变量是整数类型还是字符串类型
    QVariant ret;

    if(a.type() == QVariant::String &&  b.type() == QVariant::String)
    {
        ret = QVariant(a.toString() + b.toString());
    }
    else if(a.type() == QVariant::Int && b.type() == QVariant::Int)
    {
        ret = QVariant(a.toInt() + b.toInt());
    }

    return ret;

}

void MainWindow::randNumbers(int count)
{
    srand(time(NULL));

    for(int i = 0;i < count;i++)
    {
        int num = rand()%10000;
        qDebug()<<num;
    }
}
