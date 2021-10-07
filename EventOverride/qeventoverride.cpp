#include "qeventoverride.h"
#include "ui_qeventoverride.h"

QEventOverride::QEventOverride(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QEventOverride)
{
    ui->setupUi(this);
}

QEventOverride::~QEventOverride()
{
    delete ui;
}
