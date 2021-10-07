#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QSizeF>
#include <QGraphicsSceneMouseEvent>
#include <QSvgGenerator>
#include <QPaintEvent>
#include <QPen>
#include <QLabel>
#include <QGraphicsView>
#include <QSvgWidget>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include "picturestyle.h"
#include "qrawingboard.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initUI();
    void initWindow();
    void initLeftToolBar();
    void initRightToolBar();
    void initPaletteStyle();

signals:
    void changeCurrentShape(PictureStyle::ShapeStyle newShape);

private slots:
    void drawMouseActionTriggred();
    void drawLineActionTriggered();
    void drawRectActionTriggered();
    void drawEllipseActionTriggered();
    void arrowPrint(bool);
    void actionSaveSvg();
    void openSvgFile();
    void newSvgFile();
    void setColor();
    void setPaletteWidth(int value);
    void setPaletteHigh(int value);
    void paintEvent(QPaintEvent* ev);
    void wheelEvent(QWheelEvent* ev);

private:
    QMenuBar* m_mainTitleBar;
    QMenu* m_menuFile;
    QMenu* m_editorFile;
    QMenu* m_optionTool;
    QMenu* m_viewTool;
    QAction* m_openFile;
    QAction* m_saveFile;
    QAction* m_newFile;

    QToolBar* m_leftToolBar;
    QToolBar* m_rightToolBar;

    QrawingBoard* m_drawBoard;

    //设置画布长宽的地方
    QSpinBox* m_widthSpinBox;
    QSpinBox* m_highSpinBox;

    int m_width;
    int m_high;

    QToolButton* m_selectColor;
};

#endif // MAINWINDOW_H
