#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    //过滤器事件
    bool eventFilter(QObject *, QEvent* );

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
