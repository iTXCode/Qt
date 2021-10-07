#include "mymenu.h"
#include "ui_mymenu.h"

MyMenu::MyMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyMenu)
{
    ui->setupUi(this);
}

MyMenu::~MyMenu()
{
    delete ui;
}
