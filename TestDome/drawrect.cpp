#include "drawrect.h"

DrawRect::DrawRect()
{
}

void DrawRect::paint(QPainter &painter)
{
        painter.drawRect(start.x(), start.y(),
                                         end.x() - start.x(), end.y() - start.y());
}
