#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QRect>
#include <QDebug>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);

//    //设置窗口的最大尺寸
//    this->setMaximumSize(600,600);
//    //设置窗口的最小尺寸
//    this->setMinimumSize(200,200);
    //设置窗口的股顶尺寸
    //this->setFixedSize(300,300);
    //设置窗口标题
    this->setWindowTitle("窗口操作");

    QPushButton* btnA = new QPushButton("移动窗口位置",this);
    connect(btnA, &QPushButton::clicked,[=](){
        QRect rect = this->frameGeometry();
        move(rect.topLeft()+QPoint(10,10));
    });

    QPushButton* btnB = new QPushButton("获取窗口当前位置",this);
    btnB->move(0,30);
    connect(btnB, &QPushButton::clicked,[=](){
        QRect rect = this->frameGeometry();
        qDebug()<<"左上角:"<<rect.topLeft()
                <<"右上角:"<<rect.topRight()
                <<"左下角:"<<rect.bottomLeft()
                <<"右下角:"<<rect.bottomRight()
                <<"宽度:"<<rect.width()
                <<"高度:"<<rect.height();
    });


    QPushButton* btnC = new QPushButton("修改当前窗口位置",this);
    btnC->move(0,60);
    connect(btnC,&QPushButton::clicked,[=](){
       QRect rect = this->frameGeometry();

       int x = 100 + rand()%100;
       int y = 100 + rand()%100;
       int width = this->width()+10;
       int height  = this->height()+10;
       this->setGeometry(x,y,width,height);
    });

    QPushButton* btnD = new QPushButton("修改窗口图标",this);
    btnD->move(this->width()-btnD->width(),0);
    connect(btnD,&QPushButton::clicked,[=](){
        this->setWindowTitle("窗口");
        this->setWindowIcon(QIcon("E://Code//Qt//QTCode//window_size_04//image//sunny.png"));
    });
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,&MainWindow::customContextMenuRequested,this,[=](){
        QMenu menu;
        menu.addAction("葱爆肉");
        menu.addAction("炒葫芦");
        menu.addAction("青菜炒牛肉");
        menu.addAction("爆炒羊肉");
        menu.exec(QCursor::pos());
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
