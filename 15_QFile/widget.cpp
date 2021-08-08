#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QByteArray>
#include <QFileInfo>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选择文件按钮，弹出文件对话框，读取桌面文件
    //文件路径放入到lineEdit中,内容放在TextEdit中

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "E:\\Code\\Qt\\QTCode\\15_QFile", "(*.cpp)");

        if(filePath.isEmpty())
        {
            QMessageBox::warning(this, "警告", "路径不能为空");
        }
        else
        {
            ui->lineEdit->setText(filePath);


            //指定编码格式
            QTextCodec* codec = QTextCodec::codecForName("gbk");


            //读取文件信息
            QFile file(filePath);
            //指定打开方式
            file.open(QIODevice::ReadOnly);

            QByteArray arr;
            //arr = file.readAll();  //读取全部信息

            while( !file.atEnd())
            {
                arr += file.readLine();  //按行去读
            }
            //默认支持编码格式  utf-8
            //ui->textEdit->setText(arr);

            ui->textEdit->setText(codec->toUnicode(arr));

            //关闭文件
            file.close();

            //写文件
            file.open(QIODevice::WriteOnly);
            //file.write("哈哈哈哈哈哈,小垃圾");
            file.close();


            //文件信息类
            QFileInfo info(filePath);
            qDebug()<<"后缀名"<<info.suffix().toUtf8().data() <<"文件大小" <<info.size();
            qDebug()<<"文件名"<<info.fileName().toUtf8().data()<<"文件路径"<<info.path().toUtf8().data();
            qDebug()<<"创建日期"<<info.created().toString("yyyy-MM-dd hh:mm:ss");

        }
    });
}

Widget::~Widget()
{
    delete ui;
}
