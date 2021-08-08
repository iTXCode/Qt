#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
#include <QDebug>
#include <QCheckBox>
#include <QDialogButtonBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //单选按钮 设置默认值为男
    ui->btn_man->setChecked(true);
     sex = false;

    //监听 用户选中的选项
    connect(ui->btn_woman, &QRadioButton::clicked, [=](){
        sex = true;
    });
    connect(ui->btn_man, &QRadioButton::clicked, [=](){
        sex = false;
    });

    connect(ui->btn_commit, &QPushButton::clicked, [=](){
        if(sex){
            qDebug()<<"女的";
        }
        else
        {
            qDebug()<<"男的";
        }
    });


    //复选按钮
    //监听环境优雅这个选项是否选中
    ui->checkBox->setTristate(true); //第三种状态 半选中状态
    connect(ui->checkBox, &QCheckBox::stateChanged,[=](int status){
        qDebug()<<status; //选中是2  半选中是1  选不中是0
    });

    connect(ui->buttonBox, &QDialogButtonBox::accepted, [=](){
        qDebug()<<"窗口继续保持";
    });
    connect(ui->buttonBox, &QDialogButtonBox::rejected,this,&Widget::close);


}

Widget::~Widget()
{
    delete ui;
}
