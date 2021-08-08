#include "widget.h"
#include "ui_widget.h"
#include <QPoint>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QTimer>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Widget::setWindowTitle("作画的秘密");



    posX = 0;
    connect(ui->btn_move,&QPushButton::clicked,[=](){
        posX += 10;
        //手动调用绘图事件
        update();
    });

    QTimer* t = new QTimer(this);
    t->start(50);

    connect(t, &QTimer::timeout, [=](){
        posX++;
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //画画
//    QPainter pt(this); //this代表绘图设备，画家向当前窗口画画

    /////////////////// 基本绘图  ////////////////////

//    //画笔
//    QPen pen(QColor(255,0,0));


//    pen.setWidth(3);
//    //设置画笔宽度

//    pen.setStyle(Qt::DashLine);
//    //设置画笔风格
//    pt.setPen(pen);  //让画家使用画笔

//    QBrush brush(Qt::cyan);
//    //画刷 可以填充封闭的图案

//    brush.setStyle(Qt::Dense5Pattern);

//    pt.setBrush(brush);
//    //画家使用画刷



//    pt.drawLine(QPoint(0,0),QPoint(100,100));

//    //画圆

//    pt.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    pt.drawRect(50,50,100,100);
//    pt.drawRect(QRect(100,100,100,100));


//    //画字
//    pt.setFont(QFont("华文彩云",20));
//    pt.drawText(QRect(0,200,200,200),"好好学习，天天向上.");


    ////////////////// 高级绘图////////////////////
//      QPainter pt(this); //this代表绘图设备，画家向当前窗口画画

////      pt.drawEllipse(QPoint(100,100),50,50);

////      //设置抗锯齿效果
////      pt.setRenderHint(QPainter::Antialiasing);
////      pt.drawEllipse(QPoint(100,100),100,100);

//      pt.drawRect(QRect(20,20,50,50));

//      pt.translate(100,0);//移动画家
//      pt.save();  //保存状态
//      pt.drawRect(QRect(20,20,50,50));

//      pt.translate(100,0);//移动画家
//      pt.restore();  //恢复状态
//      pt.drawRect(QRect(20,20,50,50));

   //////////////// 画成品图案/////////////////


    QPainter pt(this);
    QPixmap pix;
    pix.load(":/image/Luffy.png");

    //this->width()  窗口宽度
    //this->height();  //窗口高度
    if(posX > this->width())
    {
        posX = -pix.width();
    }
    pt.drawPixmap(posX,0,pix);

}
