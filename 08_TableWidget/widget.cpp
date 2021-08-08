#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Widget::setWindowTitle("表格控件使用");

    //表格控件的使用
    //1、设置列数
    ui->tableWidget->setColumnCount(3);
    //2、设置水平表头的标签
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"英雄"<<"性别"<<"年龄");
    //3、设置行数
    ui->tableWidget->setRowCount(5);
    //填入内容
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
//    ui->tableWidget->setItem(0,1,new QTableWidgetItem("男"));
//    ui->tableWidget->setItem(0,2,new QTableWidgetItem("13"));
    QStringList nameList;
    nameList<<"亚瑟"<<"妲己"<<"韩信"<<"孙悟空"<<"梦琪";

    QStringList sexList;
    sexList<<"男"<<"女"<<"男"<<"男"<<"男";

    QStringList ageList;
    ageList<<"19"<<"18"<<"19"<<"20"<<"21";


    for(int i=0;i<5;++i)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(18+i)));
    }

    //点击添加赵云按钮  实现添加功能
    connect(ui ->btn_add, &QPushButton::clicked, [=](){
            //如果有赵云了，就不添加了
        if (ui->tableWidget->findItems("赵云",Qt::MatchExactly).isEmpty()) //去表格中查找是否有对应的匹配规则
        {
            //结果为空则没有匹配到对应的结果可以直接进行添加
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("赵云")));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString("男")));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(19)));
        }
        else
        {
            //进行添加操作
            QMessageBox::warning(this,"警告","已经有赵云了，添加失败");
        }
    });

    //点击删除赵云按钮  实现删除功能
    connect(ui ->btn_delete, &QPushButton::clicked, [=](){
            //如果有赵云了，就不添加了
        if (ui->tableWidget->findItems("赵云",Qt::MatchExactly).isEmpty()) //去表格中查找是否有对应的匹配规则
        {
            //结果为空则没有匹配到对应的结果不需要进行删除操作
            QMessageBox::warning(this,"警告","没有该用户,删除失败!");
        }
        else
        {
            //进行删除操作
            int rowNum = ui->tableWidget->findItems("赵云",Qt::MatchExactly).first()->row();
            ui->tableWidget->removeRow(rowNum); //删除某行
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
