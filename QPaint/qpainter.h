#ifndef QPAINTER_H
#define QPAINTER_H

#include <QWidget>

namespace Ui {
class QPainter;
}

class QPainter : public QWidget
{
    Q_OBJECT

public:
    explicit QPainter(QWidget *parent = nullptr);
    ~QPainter();

private:
    Ui::QPainter *ui;
};

#endif // QPAINTER_H
