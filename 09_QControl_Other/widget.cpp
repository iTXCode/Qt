#include "widget.h"
#include "ui_widget.h"
#include <QPicture>
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    /*将三个控件放到了一个stack widget 中，而执行的结果没有显示出可以切换的按钮
     * 所以使用了三个Qpushbutton的按钮来完成切换的操作,将按钮和控件中的内容进行关联
     *
     * */

    //当然可以设置默认出现的那个界面
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->btn_Scroll, &QPushButton::clicked, [=](){
        //设置当前索引
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_tool, &QPushButton::clicked, [=](){
        //设置当前索引
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_tab, &QPushButton::clicked, [=](){
        //设置当前索引
        ui->stackedWidget->setCurrentIndex(2);
    });

    //combo  Box 下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("兰博基尼");

    //点击按钮就定位到选项
    connect(ui->btn_car, &QPushButton::clicked, [=](){
       ui->comboBox->setCurrentIndex(1);
    });

    //利用QLabel 显示图片
    QPixmap pix;
    pix.load(":/Image/Luffy.png");

    ui->lab->setPixmap(QPixmap(pix));
    ui->lab->setFixedSize(pix.width(),pix.height());

    //使用QLabel 显示gif
    QMovie* mov = new QMovie(":/Image/mario.gif");
    ui->lab_g->setMovie(mov);
    mov->start();

    mov->setSpeed(300);

    connect(mov,&QMovie::frameChanged,[=](int frameId){
        if(frameId == mov->frameCount() - 1)
        {
            mov->stop();
            //播放完一遍后直接停止播放
        }
    });

}

Widget::~Widget()
{
    delete ui;
}
