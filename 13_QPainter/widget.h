#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写绘图事件
    void paintEvent(QPaintEvent*);

    //x的坐标位置
    int posX;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
