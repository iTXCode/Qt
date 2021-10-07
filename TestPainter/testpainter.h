#ifndef TESTPAINTER_H
#define TESTPAINTER_H

#include <QWidget>

namespace Ui {
class TestPainter;
}

class TestPainter : public QWidget
{
    Q_OBJECT

public:
    explicit TestPainter(QWidget *parent = nullptr);
    ~TestPainter();

private:
    Ui::TestPainter *ui;
};

#endif // TESTPAINTER_H
