#ifndef GRILFRIEND_H
#define GRILFRIEND_H

#include <QObject>
#include <QString>

class GrilFriend : public QObject
{
    Q_OBJECT
public:
    explicit GrilFriend(QObject *parent = nullptr);

signals:

    void hungry();

public slots:
};

#endif // GRILFRIEND_H
