#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initUI()
{
    QPushButton* btn = new QPushButton(this);
    btn->setText("最大化");
    btn->setStyleSheet("QPushButton{font-size:24px;background-color:black;color:red;border-radius:4px;}");
    connect(btn, &QPushButton::clicked, this, &QWidget::showMaximized);

    QPushButton* btn1 = new QPushButton("可选择按钮",this);
    btn1->setCheckable(true);
    btn1->move(100,100);
    connect(btn1, SIGNAL(clicked(bool)), this,SLOT(onClicked(bool)));
    btn1->setStyleSheet("QPushButton{font-size:24px;background-color:black;color:red;border-radius:4px;}");
    connect(btn1, &QPushButton::pressed, this, &Widget::Press);
    connect(btn1, &QPushButton::released, this, &Widget::Release);


    QPushButton* quick = new QPushButton(this);
    quick->setText("快捷键");
    quick->move(50,50);
    quick->setShortcut(tr("Alt+q"));
    connect(quick, &QPushButton::clicked, this, &Widget::Press);
    quick->setStyleSheet("QPushButton{background-color:rgb(39, 211, 245);color:rgb(255,255,255);border-radius:6px;"
                         "font-size:40px}");
}

void Widget::onClicked(bool ch)
{
    qDebug()<<ch;
}

void Widget::Press()
{
    qDebug()<<"press";
}

void Widget::Release()
{
    qDebug()<<"release";
}
