#include "qpainter.h"
#include "ui_qpainter.h"

QPainter::QPainter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPainter)
{
    ui->setupUi(this);
}

QPainter::~QPainter()
{
    delete ui;
}
