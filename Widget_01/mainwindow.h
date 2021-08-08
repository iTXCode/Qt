#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //两个变量进行加法运算 变量可能是整形也可能是字符串
    QVariant dataPlus(QVariant a, QVariant b);

    void randNumbers(int count);

private:
    Ui::MainWindow *ui;
};

struct Person
{
    QString  m_name;
    int m_age;
};

Q_DECLARE_METATYPE(Person);


#endif // MAINWINDOW_H
