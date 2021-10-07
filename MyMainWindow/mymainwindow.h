#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QWidget>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
