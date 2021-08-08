#include "mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //重置窗口尺寸
    resize(700,350);

    //1.菜单栏 只有一个
    QMenuBar* bar  = menuBar();
    //将菜单栏创建到主窗口中
    this->setMenuBar(bar);

    //添加菜单
    QMenu* fileMenu = bar->addMenu("文件");

    //给菜单栏添加内容
    QAction* newAction = fileMenu->addAction("新建");

    //添加分割线
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开");
    //添加分割线
    fileMenu->addSeparator();
    QAction* saveAction = fileMenu->addAction("保存");

    //给菜单栏中的子项添加内容
    QMenu* subMenu = new QMenu;
    subMenu->addAction("文章");
    subMenu->addAction("项目");
    subMenu->addAction("演示");
    newAction->setMenu(subMenu);


/**** 工具栏  *****/
    QToolBar* toolbar = new QToolBar(this);
    //将工具栏绑定到主窗口中
    addToolBar(Qt::LeftToolBarArea, toolbar);//设置工具栏默认的停靠位置

    //设置只允许左右停靠
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    toolbar->setFloatable(false);


    //设置移动--禁止拖拽
    toolbar->setMovable(false);

    //工具栏中添加菜单项
    toolbar->addAction(newAction);
    toolbar->addAction(openAction);

/*****  状态栏(只能有一个)  *****/
    QStatusBar* sBar = statusBar();
    setStatusBar(sBar);   //设置到主窗口中
    QLabel* lab = new QLabel("左侧信息",this);
    sBar->addWidget(lab);

    //右侧添加
    QLabel* lab1 = new QLabel("右侧信息",this);
    sBar->addPermanentWidget(lab1);

    //往主窗口下面的中间位置插入状态栏
    QLabel* lab2 = new QLabel("中间信息");
    sBar->insertWidget(1,lab2);

/***** 铆接部件 浮动窗口  *****/
    //可以多个
    QDockWidget* dock = new QDockWidget("铆接部件",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);

/*****  核心部件  *****/
    //只能一个

    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{

}
