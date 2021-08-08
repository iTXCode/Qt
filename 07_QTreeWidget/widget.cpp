#include "widget.h"
#include "ui_widget.h"
#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Widget::setWindowTitle("树控件使用");

    //treewidget 树控件
    //1.设置头的标签
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    //2.Item  创建
    QTreeWidgetItem* treeItem = new QTreeWidgetItem(QStringList()<<"力量");
    //添加顶层级别的Item
    ui->treeWidget->addTopLevelItem(treeItem);

    QTreeWidgetItem* treeItem1 = new QTreeWidgetItem(QStringList()<<"敏捷");
    ui->treeWidget->addTopLevelItem(treeItem1);

    QTreeWidgetItem* treeItem2 = new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(treeItem2);

    //3. 创建子Item  挂载到顶层的Item上
    QTreeWidgetItem* l1 = new QTreeWidgetItem(QStringList()<<"刚被猪"<<"前排坦克，在吸收伤害的同时造成可观的范围伤害");
    treeItem->addChild(l1);

    QTreeWidgetItem* l2 = new QTreeWidgetItem(QStringList()<<"月骑"<<"中排输出，可以使用分裂利刃攻击多个目标");
    treeItem1->addChild(l2);
}

Widget::~Widget()
{
    delete ui;
}
