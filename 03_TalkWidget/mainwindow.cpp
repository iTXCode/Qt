#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QIcon>
#include <QColorDialog>   //颜色对话框
#include <QFontDialog>   //字体对话框
#include <QFileDialog>    //文件对话框
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->actionnewFile->setIcon(QIcon(":/Image/Luffy.png"));

    //点击新建,弹出对话框
    connect(ui->actionnewFile, &QAction::triggered, [=](){
        qDebug()<<"弹出对话框";


        //模态对话框
//        QDialog dig(this);
//        dig.resize(100,100);
//        dig.exec();

       //非模态对话框 创建在堆上,避免对话框弹出就消失的情况发生
//        QDialog* dlg = new QDialog(this);
//        dlg->resize(200,200);
//        dlg->show();


//        //设置属性
//        dlg->setAttribute(Qt::WA_DeleteOnClose);

        //QMessageBox 消息对话框
        //错误提示
        //QMessageBox::critical(this,"对话框","错误");

        //信息提示
        //QMessageBox::information(this,"info","信息提示!");

//        //询问提示框
//        if(QMessageBox::Save == QMessageBox::question(this,"question","询问提示！",QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save))
//        //参数一：父窗口
//        //参数二：标题
//        //参数三：中间显示的文本
//        //参数四即为询问对话框对应的选项
//        //参数五默认关联那个选项
//        //返回值即为选择的按钮选项
//        {
//            qDebug()<<"保存文本!";
//        }else{
//            qDebug()<<"取消操作!";
//        }

//        //警告提示框

//        QMessageBox::warning(this,"warning","警告");


//        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        //返回值即为用户所选中的颜色
//        qDebug()<<color.red()<<color.green()<<color.blue();


       //字体对话框
//        bool ok;
//        QFont ft = QFontDialog::getFont(&ok, QFont("华文彩云",36) );
//        qDebug()<<"字体:" <<ft.family()<< "字号： "<<ft.pointSize()
//                <<"加粗: "<<ft.bold() << "倾斜:" <<ft.italic();

        //文件对话框
        QString str = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\王世贤\\Desktop\\B站资料分享","(*.png *.doc)");
        //参数1：父亲
        //参数2: 窗口名字
        //参数3： 打开文件的路径
        //参数4： 过滤文件的类型
        //返回值为其筛选中的文件路径

        qDebug()<<str;
 });



}

MainWindow::~MainWindow()
{
    delete ui;
}

