#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //放在构造函数的最上方

    ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionopen->setIcon(QIcon(":/Image/LuffyQ.png"));
    ui->actionsave->setIcon(QIcon(":/Image/sunny.png"));



/***** 往Qt中导入资源  *****/
    //1.将准备好的图片放到项目路径下
    //2.添加资源文件
    //3.添加新文件->Qt->ResourceFile->起名字->生成.qrc文件
    //4. 添加资源文件
    //4.1 添加前缀  添加资源
    //4.2  语法:  ":/前缀名/文件名"

}

MainWindow::~MainWindow()
{
    delete ui;
}
