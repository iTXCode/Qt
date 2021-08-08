#include "mysignal.h"
#include <QPushButton>


//创建两个类： 教师类  学生类
//下课后  老师发出饿了的信号，学生进行回应，请老师吃饭

MySignal::MySignal(QWidget *parent) :
    QWidget(parent)
{
    this->m_th = new Teacher(this);
    this->m_st = new Student(this);

    //连接信号和槽

    //connect(this->m_th,&Teacher::hungry,this->m_st,&Student::streat);


    //连接有参数的
    //函数指针指向函数地址
//    void (Teacher:: * teacerSignal) (QString) = &Teacher::hungry;
//    void (Student:: * studentSlot)(QString) = &Student::streat;
//    connect(this->m_th,teacerSignal,this->m_st,studentSlot);
    //下课函数调用
    //ClassDown();

    QPushButton* btn = new QPushButton(this);
    btn->move(20,30);
    btn->setText("下课");
    this->resize(500,400);
//    connect(btn,&QPushButton::clicked,this,&MySignal::close);

    void (Teacher:: * teacerSignal) () = &Teacher::hungry;
    void (Student:: * studentSlot)() = &Student::streat;
   // connect(this->m_th,teacerSignal,this->m_st,studentSlot);

    //信号和槽的拓展
    //1.信号连接信号
    connect(btn,&QPushButton::clicked,this->m_th,teacerSignal);

    //2.一个信号可以连接多个槽函数


    //3.多个信号可以绑定同一个槽函数

    //4.信号和槽的参数类型 必须一一对应
    //5.信号和参数个数可以多于槽函数，反之不可以，相同个数的参数类型也要一一对应

    //断开连接  怎么连接的就怎么断开连接
    //disconnect(btn,&QPushButton::clicked,this->m_th,teacerSignal);


    //QT4版本的信号和槽的写法
    //连接有参数的信号和槽
    //优点:参数直观，写法简答
    //缺点:编辑器不检测参数类型,不会 提示语法错误

    connect(this->m_th,SIGNAL(hungry()),this->m_st,SLOT(streat()));
    //connect(this->m_th,SIGNAL(hungry()),this->m_st,SLOT(streat(QString)));
    //运行时爆出错误
    //ClassDown();

    connect(btn,&QPushButton::clicked,[=](){
        btn->setText("继续");
        this->m_st->streat("葱爆肉");
        this->close();
    });
}

MySignal::~MySignal()
{

}

void MySignal::ClassDown()
{
    //触发自定义的信号
    emit this->m_th->hungry();
    emit this->m_th->hungry("牛肉面");
}
