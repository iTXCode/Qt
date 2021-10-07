#include "qpainter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPainter w;
    w.show();

    return a.exec();
}
