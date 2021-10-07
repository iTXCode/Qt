#ifndef QEVENTOVERRIDE_H
#define QEVENTOVERRIDE_H

#include <QWidget>

namespace Ui {
class QEventOverride;
}

class QEventOverride : public QWidget
{
    Q_OBJECT

public:
    explicit QEventOverride(QWidget *parent = nullptr);
    ~QEventOverride();

private:
    Ui::QEventOverride *ui;
};

#endif // QEVENTOVERRIDE_H
