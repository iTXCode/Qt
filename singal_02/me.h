#ifndef ME_H
#define ME_H

#include <QObject>
#include <QString>

class Me : public QObject
{
    Q_OBJECT
public:
    explicit Me(QObject *parent = nullptr);

signals:

public slots:

    //void eating();
    void eating(QString);

    //槽函数
};

#endif // ME_H
