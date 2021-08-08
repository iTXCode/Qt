#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
}

widget::~widget()
{
    delete ui;
}
