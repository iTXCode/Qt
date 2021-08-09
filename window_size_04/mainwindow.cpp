#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QRect>
#include <QDebug>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QFont>
#include <QFontDialog>
#include <QLabel>
#include <QInputDialog>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);

//    //设置窗口的最大尺寸
//    this->setMaximumSize(600,600);
//    //设置窗口的最小尺寸
//    this->setMinimumSize(200,200);
    //设置窗口的股顶尺寸
    //this->setFixedSize(300,300);
    //设置窗口标题
    this->setWindowTitle("窗口操作");

    QPushButton* btnA = new QPushButton("移动窗口位置",this);
    connect(btnA, &QPushButton::clicked,[=](){
        QRect rect = this->frameGeometry();
        move(rect.topLeft()+QPoint(10,10));
    });

    QPushButton* btnB = new QPushButton("获取窗口当前位置",this);
    btnB->move(0,30);
    connect(btnB, &QPushButton::clicked,[=](){
        QRect rect = this->frameGeometry();
        qDebug()<<"左上角:"<<rect.topLeft()
                <<"右上角:"<<rect.topRight()
                <<"左下角:"<<rect.bottomLeft()
                <<"右下角:"<<rect.bottomRight()
                <<"宽度:"<<rect.width()
                <<"高度:"<<rect.height();
    });


    QPushButton* btnC = new QPushButton("修改当前窗口位置",this);
    btnC->move(0,60);
    connect(btnC,&QPushButton::clicked,[=](){
       QRect rect = this->frameGeometry();

       int x = 100 + rand()%100;
       int y = 100 + rand()%100;
       int width = this->width()+10;
       int height  = this->height()+10;
       this->setGeometry(x,y,width,height);
    });

    QPushButton* btnD = new QPushButton("修改窗口图标",this);
    btnD->move(this->width()-btnD->width(),0);
    connect(btnD,&QPushButton::clicked,[=](){
        this->setWindowTitle("窗口");
        this->setWindowIcon(QIcon("E://Code//Qt//QTCode//window_size_04//image//sunny.png"));
    });
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,&MainWindow::customContextMenuRequested,this,[=](){
        QMenu menu;
        menu.addAction("葱爆肉");
        menu.addAction("炒葫芦");
        menu.addAction("青菜炒牛肉");
        menu.addAction("爆炒羊肉");
        menu.exec(QCursor::pos());
    });

    QPushButton* btn_file = new QPushButton("文件选择按钮",this);
    btn_file->move(0,120);
    connect(btn_file,&QPushButton::clicked,[=](){
        //显示目录
//        QString dirName = QFileDialog::getExistingDirectory(this,"打开目录","E://Code//Qt//QTCode//window_size_04//image");
//        QMessageBox::information(this,"文本对话框显示","您选择的目录是:",dirName);


        //选择单个文件打开
//        QString arg("Text files (*.txt)");
//        QString fileName = QFileDialog::getOpenFileName(
//                    this,tr("OPen File"),"E://Code//Qt//QTCode//window_size_04//image",
//                    tr("Images(*.png *.jpg);;Text files(*.txt"),&arg);
//        QMessageBox::information(this,"打开文件","您的选择是:"+fileName);

        //可选择多个文件打开
//        QStringList fileList = QFileDialog::getOpenFileNames(
//                    this,tr("OPen File"),"E://Code//Qt//QTCode//window_size_04//image",
//                    tr("Images(*.png *.jpg);;Text files(*.txt"));
//        QString names;
//        for(int i=0;i<fileList.size();++i)
//        {
//            names += fileList.at(i) + " ";
//        }
//        QMessageBox::information(this,"打开文件","您的选择是:"+names);




        //保存
        QString fileName = QFileDialog::getSaveFileName(this,"保存文件","E://Code//Qt//QTCode//window_size_04//image");
        QMessageBox::information(this,"保存文件","您指定的保存数据的文件是:"+fileName);

    });


    QLabel*lab = new QLabel("天空飘来五个字",this);
    lab->resize(300,100);
    lab->move(200,200);
    lab->setStyleSheet("border:2px solid red;");

    QPushButton* btn_font = new QPushButton("字体选择",this);
    btn_font->move(0,90);
    //connect(btn_font,&QPushButton::clicked,this,&MainWindow::font_show);
    connect(btn_font,&QPushButton::clicked,[=]()mutable{
        bool ok;
        QFont ft= QFontDialog::getFont(
                    &ok,QFont("华文彩云",12,QFont::Bold),this,"选择字体");
        lab->setFont(ft);
    });
    
    QPushButton* btn_input = new QPushButton("input_dialog",this);
    btn_input->move(300,100);
#define MULTILINE
    connect(btn_input,&QPushButton::clicked,[=](){

#ifdef INT
        int ret = QInputDialog::getInt(this,"年龄","您当前的年龄",10,1,100,2);
        QMessageBox::information(this,"年龄","您多当前年龄:",QString::number(ret));
#endif

#ifdef DOUBLE
        int ret = QInputDialog::getDouble(this,"工资","您的工资",2000,1000,6000,2);
        QMessageBox::information(this,"工资","您当前的工资:",QString::number(ret));
#endif

#ifdef ITEM
        QStringList items;
        items<<"晴子"<<"流川枫"<<"樱木花道"<<"赤木刚宪"<<"三井寿"<<"宫城";
        QString item = QInputDialog::getItem(this,"请选择你喜欢的球员","你最喜欢的球员",items,1,false);
        //数字1：标识默认选择的是第一个,参数false:下拉选项不可修改
        QMessageBox::information(this,"球员","您最喜欢的球员是:",item);
#endif

#ifdef TEXT
        QString ret = QInputDialog::getText(this,"密码","请输入新的密码",QLineEdit::Password,"nimeide");
        QMessageBox::information(this,"密码","您设置的密码:"+ret);
#endif
#ifdef MULTILINE
        QString ret = QInputDialog::getMultiLineText(this,"表白","你最相对你女神说:","爱你");
        QMessageBox::information(this,"女神","您最想说的是:"+ret);
#endif
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::font_show()
{
    bool ok;
    QFont ft= QFontDialog::getFont(
                &ok,QFont("宋体",12,QFont::Bold),this,"选择字体");
    QLabel lab;
    lab.setFont(ft);
}


#if 0
// 得到一个可以输入浮点数的对话框窗口, 返回对话框窗口中输入的浮点数
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - value: 对话框窗口中显示的浮点值, 默认为 0
  - min: 对话框窗口支持显示的最小数值
  - max: 对话框窗口支持显示的最大数值
  - decimals: 浮点数的精度, 默认保留小数点以后1位
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
*/
[static] double QInputDialog::getDouble(
            QWidget *parent, const QString &title,
            const QString &label, double value = 0,
            double min = -2147483647, double max = 2147483647,
            int decimals = 1, bool *ok = nullptr,
            Qt::WindowFlags flags = Qt::WindowFlags());

// 得到一个可以输入整形数的对话框窗口, 返回对话框窗口中输入的整形数
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - value: 对话框窗口中显示的整形值, 默认为 0
  - min: 对话框窗口支持显示的最小数值
  - max: 对话框窗口支持显示的最大数值
  - step: 步长, 通过对话框提供的按钮调节数值每次增长/递减的量
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
*/
[static] int QInputDialog::getInt(
            QWidget *parent, const QString &title,
            const QString &label, int value = 0,
            int min = -2147483647, int max = 2147483647,
            int step = 1, bool *ok = nullptr,
            Qt::WindowFlags flags = Qt::WindowFlags());

// 得到一个带下来菜单的对话框窗口, 返回选择的菜单项上边的文本信息
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - items: 字符串列表, 用于初始化窗口中的下拉菜单, 每个字符串对应一个菜单项
  - current: 通过菜单项的索引指定显示下拉菜单中的哪个菜单项, 默认显示第一个(编号为0)
  - editable: 设置菜单项上的文本信息是否可以进行编辑, 默认为true, 即可以编辑
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
  - inputMethodHints: 设置显示模式, 默认没有指定任何特殊显示格式, 显示普通文本字符串
    - 如果有特殊需求, 可以参数帮助文档进行相关设置
*/
[static] QString QInputDialog::getItem(
            QWidget *parent, const QString &title,
            const QString &label, const QStringList &items,
            int current = 0, bool editable = true, bool *ok = nullptr,
            Qt::WindowFlags flags = Qt::WindowFlags(),
            Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

// 得到一个可以输入多行数据的对话框窗口, 返回用户在窗口中输入的文本信息
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - text: 指定显示到多行输入框中的文本信息, 默认是空字符串
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
  - inputMethodHints: 设置显示模式, 默认没有指定任何特殊显示格式, 显示普通文本字符串
    - 如果有特殊需求, 可以参数帮助文档进行相关设置
*/
[static] QString QInputDialog::getMultiLineText(
            QWidget *parent, const QString &title, const QString &label,
            const QString &text = QString(), bool *ok = nullptr,
            Qt::WindowFlags flags = Qt::WindowFlags(),
            Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

// 得到一个可以输入单行信息的对话框窗口, 返回用户在窗口中输入的文本信息
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - mode: 指定单行编辑框中数据的反馈模式, 是一个 QLineEdit::EchoMode 类型的枚举值
    - QLineEdit::Normal: 显示输入的字符。这是默认值
    - QLineEdit::NoEcho: 不要展示任何东西。这可能适用于连密码长度都应该保密的密码。
    - QLineEdit::Password: 显示与平台相关的密码掩码字符，而不是实际输入的字符。
    - QLineEdit::PasswordEchoOnEdit: 在编辑时按输入显示字符，否则按密码显示字符。
  - text: 指定显示到单行输入框中的文本信息, 默认是空字符串
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
  - inputMethodHints: 设置显示模式, 默认没有指定任何特殊显示格式, 显示普通文本字符串
     - 如果有特殊需求, 可以参数帮助文档进行相关设置
*/
[static] QString QInputDialog::getText(
            QWidget *parent, const QString &title, const QString &label,
            QLineEdit::EchoMode mode = QLineEdit::Normal,
            const QString &text = QString(), bool *ok = nullptr,
            Qt::WindowFlags flags = Qt::WindowFlags(),
            Qt::InputMethodHints inputMethodHints = Qt::ImhNone);


#endif
