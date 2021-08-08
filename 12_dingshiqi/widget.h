#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //定时器事件

    void timerEvent(QTimerEvent *);
    int num;
    int Timer_id1;
    int Timer_id2;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
