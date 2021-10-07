#include "drawline.h"
#include <QGraphicsItem>
#include <QLineF>

DrawLine::DrawLine()
{


}

void DrawLine::paint(QPainter &painter)
{
        painter.drawLine(start, end);
}
