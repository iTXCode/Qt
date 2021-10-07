#include "testpainter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestPainter w;
    w.show();

    return a.exec();
}
