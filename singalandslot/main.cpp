#include "mysignal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySignal w;
    w.show();

    return a.exec();
}
