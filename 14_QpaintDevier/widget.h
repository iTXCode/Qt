#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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

    //利用Image访问像素点
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
