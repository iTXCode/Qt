#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //spinBox数字改变  slider跟着滑动
    //修改QSpinBox的最值 需要两个组件的范围一样才会起作用

    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(100);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setMinimum(1);
    void (QSpinBox:: *signal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,signal,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox, &QSpinBox::setValue);


}

SmallWidget::~SmallWidget()
{
    delete ui;
}

void SmallWidget::setData(int val)
{
    ui->horizontalSlider->setValue(val);
}

int SmallWidget::getData()
{
    return ui->horizontalSlider->value();
}
