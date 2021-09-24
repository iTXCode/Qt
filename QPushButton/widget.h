#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void initUI();

private slots:

    void onClicked(bool ch);
    void Press();
    void Release();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
