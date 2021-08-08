#include "widget.h"
#include "ui_widget.h"
#include <QListWidgetItem>
#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //listWidget使用
    Widget::setWindowTitle("吟诗一首");
    QListWidgetItem* item = new QListWidgetItem("锄禾日当午");

    ui->listWidget->addItem(item);

    //设置文本对齐方式
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //QStringList -> QList<QString> ->list<string>
    QStringList list;
    list<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);
    //参数为QStringList
}

Widget::~Widget()
{
    delete ui;
}
