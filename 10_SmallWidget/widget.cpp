#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮将spinBox的值设置为一半
    connect(ui->btn_half,&QPushButton::clicked,[=](){
        ui->widget->setData(50);
    });

    //点击获取当前值
    connect(ui->btn_current,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getData();
    });
}

Widget::~Widget()
{
    delete ui;
}
