#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "grilfriend.h"
#include "me.h"

#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    Me* m_me;
    GrilFriend* m_gril;

    void hungrySlot(); //添加槽函数,来完成自定义信号和槽函数的连接


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
