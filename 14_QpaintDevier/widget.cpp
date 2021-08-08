#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPixmap 做绘图设备 对不同的平台做了显示的优化

//    QPixmap pix(300,300);
//    pix.fill(Qt::white);  //将背景填充成了白色
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    pix.save("E:\\pix.png");


     //QImage 做绘图设备       专门为像素级的访问做了优化
//     QImage img(300, 300, QImage::Format_RGB30);
//     img.fill(Qt::white);
//     QPainter pt(&img);
//     pt.setPen(QPen(Qt::black));
//     pt.drawEllipse(QPoint(150,150),100,100);
//     img.save("E:\\img.png");


        //QPicture 做绘图设备  记录和重现画家的绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);

    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150,150),100,100);
    painter.end();
    pic.save("E:\\pic.zt");

}

void Widget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);

//    QImage img;
//    img.load(":/image/Luffy.png");

//    for(int i = 50; i < 100; ++i)
//    {
//        for(int j = 50; j < 100; ++j)
//        {
//            QRgb val = qRgb(255, 0, 0);
//            img.setPixel(i, j ,val);
//        }
//    }
//    painter.drawImage(0,0,img);

    //重现Qpicture的绘图指令
    QPainter painter(this);
    QPicture pic;
    pic.load("E:\\pic.zt");
    painter.drawPicture(0,0,pic);


}

Widget::~Widget()
{
    delete ui;
}
