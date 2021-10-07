#include "drawellipse.h"

DrawEllipse::DrawEllipse()
{

}

void DrawEllipse::paint(QPainter &painter)
{
    painter.drawEllipse(start.x(), start.y(),
                                     end.x() - start.x(), end.y() - start.y());
}
