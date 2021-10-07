#ifndef MYMENU_H
#define MYMENU_H

#include <QWidget>

namespace Ui {
class MyMenu;
}

class MyMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MyMenu(QWidget *parent = nullptr);
    ~MyMenu();

private:
    Ui::MyMenu *ui;
};

#endif // MYMENU_H
