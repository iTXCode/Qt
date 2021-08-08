#ifndef MYSIGNAL_H
#define MYSIGNAL_H

#include <QWidget>
#include "teacher.h"
#include "student.h"


class MySignal : public QWidget
{
    Q_OBJECT

public:
    explicit MySignal(QWidget *parent = nullptr);
    ~MySignal();

    Teacher* m_th;
    Student* m_st;

    //下课函数
    void ClassDown();
};

#endif // MYSIGNAL_H
