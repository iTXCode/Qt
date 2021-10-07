#include "qeventoverride.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QEventOverride w;
    w.show();

    return a.exec();
}
