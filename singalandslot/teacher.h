#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号需要写到signals下
    //1.返回值为void
    //2.只需要声明、不需要实现
    //3.可以有参数，可以重载

    void hungry();

    void hungry(QString foodName);

public slots:
};

#endif // TEACHER_H
