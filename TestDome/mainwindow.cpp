#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QToolButton>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QtSvg/QSvgGenerator>
#include <QPainter>
#include <QHBoxLayout>
#include <QSvgRenderer>
#include <QGraphicsView>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QToolButton>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_mainTitleBar(nullptr),
    m_menuFile(nullptr),
    m_editorFile(nullptr),
    m_optionTool(nullptr),
    m_viewTool(nullptr),
    m_openFile(nullptr),
    m_saveFile(nullptr),
    m_newFile(nullptr),
    m_leftToolBar(nullptr),
    m_rightToolBar(nullptr),
    m_drawBoard(nullptr),
    m_widthSpinBox(nullptr),
    m_highSpinBox(nullptr)
{
    initUI();
}


MainWindow::~MainWindow()
{
    if(m_mainTitleBar)
        delete m_mainTitleBar,m_mainTitleBar = nullptr;
    if(m_editorFile)
        delete m_editorFile,m_editorFile = nullptr;
    if (m_optionTool)
        delete m_optionTool,m_optionTool = nullptr;
    if (m_viewTool)
        delete m_viewTool,m_viewTool = nullptr;
    if (m_openFile)
        delete m_openFile,m_openFile = nullptr;
    if (m_saveFile)
        delete m_saveFile,m_saveFile = nullptr;
    if (m_newFile)
        delete m_newFile,m_newFile = nullptr;
    if(m_menuFile)
        delete m_menuFile,m_menuFile = nullptr;
    if (m_leftToolBar)
        delete m_leftToolBar, m_leftToolBar = nullptr;
    if (m_widthSpinBox)
        delete m_widthSpinBox,m_widthSpinBox = nullptr;
    if (m_highSpinBox)
        delete m_highSpinBox,m_highSpinBox = nullptr;
    if (m_rightToolBar)
        delete m_rightToolBar,m_rightToolBar = nullptr;
    if (m_drawBoard)
        delete m_drawBoard,m_drawBoard = nullptr;

}

void MainWindow::initUI()
{
    this->setMinimumWidth(1000);
    this->setMinimumHeight(700);
    initWindow();
    initLeftToolBar();
    initRightToolBar();
}



void MainWindow::initWindow()
{
    m_mainTitleBar = new QMenuBar(this);
    m_mainTitleBar->setStyleSheet("background-color:#707070");
    this->setMenuBar(m_mainTitleBar);

    m_menuFile = new QMenu(this);
    m_menuFile->setTitle("文件");
    m_mainTitleBar->addSeparator();

    m_editorFile = new QMenu(this);
    m_editorFile->setTitle("编辑");
    m_editorFile->addSeparator();

    m_optionTool = new QMenu(this);
    m_optionTool->setTitle("选项");
    m_optionTool->addSeparator();

    m_viewTool = new QMenu(this);
    m_viewTool->setTitle("视图");
    m_viewTool->addSeparator();

    m_mainTitleBar->addAction(m_menuFile->menuAction());
    m_mainTitleBar->addAction(m_editorFile->menuAction());
    m_mainTitleBar->addAction(m_optionTool->menuAction());
     m_mainTitleBar->addAction(m_viewTool->menuAction());


    m_openFile = new QAction("打开文件",this);
    m_saveFile = new QAction("保存文件",this);
    m_newFile = new QAction("新建文件",this);
    connect(m_saveFile, &QAction::triggered, this , &MainWindow::actionSaveSvg);
    connect(m_openFile, &QAction::triggered, this, &MainWindow::openSvgFile);
    connect(m_newFile, &QAction::triggered, this, &MainWindow::newSvgFile);


    m_menuFile->addSeparator();
    m_menuFile->addAction(m_openFile);
    m_menuFile->addSeparator();
    m_menuFile->addAction(m_saveFile);
    m_menuFile->addSeparator();
    m_menuFile->addAction(m_newFile);
}

void MainWindow::initLeftToolBar()
{
    //工具栏设置
    m_leftToolBar = new QToolBar(this);
    m_leftToolBar->setMovable(false);
    m_leftToolBar->setStyleSheet("background-color:#707070;border:2px");
    this->addToolBar(Qt::LeftToolBarArea,m_leftToolBar);

    //箭头A
    QToolButton* arrow = new QToolButton(this);
    arrow->setFixedSize(30,30);
    arrow->setStyleSheet("QToolButton{color:#00CCFF;}"
                         "QToolButton::indicator{width:0px;height:0px}"
                         "QToolButton::pressed{background-color:#00CCFF}");
    arrow->setIcon(QIcon(":/res/image/arrow_svg.svg"));
    arrow->setIconSize(QSize(30,30));


    //画笔
    QToolButton* painter = new QToolButton(this);
    painter->setFixedSize(30,30);
    painter->setIcon(QIcon(":/res/image/MySvg.svg"));
    painter->setIconSize(QSize(30,30));


    //划线
    QToolButton* linePainter = new QToolButton(this);
    linePainter->setFixedSize(30,30);
    linePainter->setIcon(QIcon(":/res/image/line_svg.svg"));
    linePainter->setIconSize(QSize(30,30));

    //矩形
    QToolButton* rectPainter = new QToolButton(this);
    rectPainter->setFixedSize(30,30);
    rectPainter->setIcon(QIcon(":/res/image/rect_svg.svg"));
    rectPainter->setIconSize(QSize(30,30));

    //椭圆
    QToolButton* ellipsePainter = new QToolButton(this);
    ellipsePainter->setFixedSize(30,30);
    ellipsePainter->setIcon(QIcon(":/res/image/ellipse_svg.svg"));
    ellipsePainter->setIconSize(QSize(30,30));

    //清除
    QToolButton* clearPaint = new QToolButton(this);
    clearPaint->setFixedSize(30,30);
    clearPaint->setIcon(QIcon(":/res/image/clear_svg.svg"));
    clearPaint->setIconSize(QSize(30,30));

    m_leftToolBar->addWidget(arrow);
    m_leftToolBar->addSeparator();
    m_leftToolBar->addWidget(painter);
    m_leftToolBar->addSeparator();
    m_leftToolBar->addWidget(linePainter);
    m_leftToolBar->addSeparator();
    m_leftToolBar->addWidget(rectPainter);
    m_leftToolBar->addSeparator();
    m_leftToolBar->addWidget(ellipsePainter);
    m_leftToolBar->addSeparator();
    m_leftToolBar->addWidget(clearPaint);

    initPaletteStyle();
    connect(arrow, SIGNAL(clicked(bool)), this, SLOT(drawMouseActionTriggred()));
    connect(painter, SIGNAL(clicked(bool)), this, SLOT(arrowPrint(bool)));
    connect(linePainter, SIGNAL(clicked(bool)), this, SLOT(drawLineActionTriggered()));
    connect(rectPainter, SIGNAL(clicked(bool)), this, SLOT(drawRectActionTriggered()));
    connect(ellipsePainter, SIGNAL(clicked(bool)), this, SLOT(drawEllipseActionTriggered()));
    connect(this, SIGNAL(changeCurrentShape(PictureStyle::ShapeStyle)),
                           m_drawBoard, SLOT(setCurrentShape(PictureStyle::ShapeStyle)));
    connect(clearPaint, SIGNAL(clicked()),this,SLOT(newSvgFile()));
}


void MainWindow::initRightToolBar()
{
    m_rightToolBar = new QToolBar(this);
    m_rightToolBar->setStyleSheet("background-color:#707070;width:90;border:2px");
    m_rightToolBar->setMovable(false);
    this->addToolBar(Qt::RightToolBarArea,m_rightToolBar);

    //设置右侧工具栏的内容
    //调色板
    m_selectColor = new QToolButton(this);
    m_selectColor->setFixedSize(40,30);
    m_selectColor->setStyleSheet("background-color:red;");
    connect(m_selectColor, &QToolButton::clicked, this, &MainWindow::setColor);


    m_highSpinBox = new QSpinBox(this);
    m_highSpinBox->setFixedSize(40,30);
    m_highSpinBox->setRange(230,100000);
    m_highSpinBox->setStyleSheet("QSpinBox{border:1px solid #242424;}"
                                "QSpinBox::up-button{width:0px;}"
                                "QSpinBox::down-button{width:0px}");

    m_widthSpinBox = new QSpinBox(this);
    m_widthSpinBox->setFixedSize(40,30);
    m_widthSpinBox->setRange(380,100000);
    m_widthSpinBox->setStyleSheet("QSpinBox{border:1px solid #242424;}"
                                "QSpinBox::up-button{width:0px;}"
                                "QSpinBox::down-button{width:0px}");



    connect(m_widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setPaletteWidth(int)));
    connect(m_highSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setPaletteHigh(int)));

    m_rightToolBar->addWidget(m_selectColor);
    m_rightToolBar->addWidget(m_highSpinBox);
    m_rightToolBar->addWidget(m_widthSpinBox);
}

void MainWindow::initPaletteStyle()
{
    QScrollArea* scrollWidget = new QScrollArea(this);
    setCentralWidget(scrollWidget);
    if (m_drawBoard != nullptr)
        delete m_drawBoard;
    m_drawBoard = new QrawingBoard(this);
    scrollWidget->setWidget(m_drawBoard);
    scrollWidget->setStyleSheet("border:none");
    m_drawBoard->setStyleSheet("background-color:#FF0000;border: 0.5px solid #000;");
    m_drawBoard->setMinimumSize(QSize(this->width()/2,this->height()/2));

    connect(this, SIGNAL(changeCurrentShape(PictureStyle::ShapeStyle)),
            m_drawBoard, SLOT(setCurrentShape(PictureStyle::ShapeStyle)));
}

void MainWindow::drawMouseActionTriggred()
{
    emit changeCurrentShape(PictureStyle::Mouse);
}

void MainWindow::drawLineActionTriggered()
{
     emit changeCurrentShape(PictureStyle::Line);
}

void MainWindow::drawRectActionTriggered()
{
    emit changeCurrentShape(PictureStyle::Rect);
}

void MainWindow::drawEllipseActionTriggered()
{
     emit changeCurrentShape(PictureStyle::Ellipse);
}


void MainWindow::arrowPrint(bool ch)
{
    //测试按钮是否能正常使用
    qDebug()<<ch;
}

void MainWindow::actionSaveSvg()
{
    QString filePath = QFileDialog::getSaveFileName( this ,  "Save SVG" ,

                                                     "" ,  "SVG FILES (*.svg)" );
     if  (filePath.isEmpty() )
         return ;
    QSvgGenerator generator;
    generator.setFileName(filePath);
    generator.setSize(QSize( this ->width(),  this ->height()));
    generator.setViewBox(QRect( 0 ,  0 ,  this ->width(),  this ->height()));
    m_drawBoard->paintSvgPicture(&generator);
}

void MainWindow::openSvgFile()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择单个文件","./");
    if(filePath.isEmpty())
        return;
    QFileInfo fileInfo(filePath);
    m_drawBoard->setSvgRender(fileInfo,filePath);
}

void MainWindow::newSvgFile()
{
    initPaletteStyle();
}

void MainWindow::setColor()
{
     QColorDialog color;
     QColor getColor= color.getColor();
     if(!getColor.isValid())
         return;
     m_selectColor->setStyleSheet("background-color:" + getColor.name());
     m_drawBoard->setsPaletteColor(getColor);

}

void MainWindow::setPaletteHigh(int value)
{
    m_width = m_drawBoard->width();
    m_drawBoard->resize(QSize(m_width,value));
}
void MainWindow::setPaletteWidth(int value)
{
    m_high = m_drawBoard->height();
    m_drawBoard->resize(QSize(value,m_high));
}


void MainWindow::paintEvent(QPaintEvent *ev)
{
    m_drawBoard->move((this->width()/2)-(m_drawBoard->width()/2),(this->height()/2)-(m_drawBoard->height()/2));
}

void MainWindow::wheelEvent(QWheelEvent *ev)
{
    QPoint numDegrees;
    numDegrees = ev->angleDelta();
    int step = 0;
    if(!numDegrees.isNull())
    {
        step = numDegrees.y();
    }

    ev->accept();
    int currentWidth = m_drawBoard->width();
    int currentHigh = m_drawBoard->height();

    currentWidth+=step;
    currentHigh+=step;
    m_widthSpinBox->setValue(currentWidth);
    m_highSpinBox->setValue(currentHigh);

    if(step>0)
    {
        QString imagesize = QString("画布放大，尺寸为:%1*%2")
                .arg(currentWidth).arg(currentHigh);
        qDebug()<<imagesize;
    }
    else
    {
        QString imagesize = QString("画布缩小,尺寸为:%1*%2")
                .arg(currentWidth).arg(currentHigh);
        qDebug()<<imagesize;
    }
    m_drawBoard->resize(currentWidth,currentHigh);
}

/*
void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees;                                     // 定义指针类型参数numDegrees用于获取滚轮转角
    numDegrees = event->angleDelta();                      // 获取滚轮转角
    int step = 0;                                          // 设置中间参数step用于将获取的数值转换成整数型
    if (!numDegrees.isNull())                              // 判断滚轮是否转动
    {
        step = numDegrees.y();                             // 将滚轮转动数值传给中间参数step
    }
    event->accept();                                       // 获取事件
    int currentWidth = imgLabel->width();                  // 获取当前图像的宽
    int currentHeight = imgLabel->height();                // 获取当前图像的高
    currentWidth += step;                                  // 对当前图像的高累加
    currentHeight += step;                                 // 对当前图像的宽累加
    if (step > 0)                                          // 判断图像是放大还是缩小
    {
        QString imgsize = QString("图像放大,尺寸为：%1 * %2")
                .arg(currentWidth).arg(currentHeight);
        qDebug() << imgsize;                               // 打印放大后的图像尺寸
    }
    else
    {
        QString imgsize = QString("图像缩小,尺寸为：%1 * %2")
                .arg(currentWidth).arg(currentHeight);
        qDebug() << imgsize;                                // 打印缩小后的图像尺寸
    }
    imgLabel->resize(currentWidth, currentHeight);          // 通过更新图像显示控件的大小来更新图像大小
}

*/



