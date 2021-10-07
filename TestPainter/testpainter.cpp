#include "testpainter.h"
#include "ui_testpainter.h"

TestPainter::TestPainter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestPainter)
{
    ui->setupUi(this);
}

TestPainter::~TestPainter()
{
    delete ui;
}
