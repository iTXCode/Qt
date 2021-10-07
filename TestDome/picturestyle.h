#ifndef PICTURESTYLE_H
#define PICTURESTYLE_H

#include <QtGui>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

class PictureStyle
{
public:
    enum ShapeStyle{
      Mouse,
      Line,
      Rect,
      Ellipse
    };
    PictureStyle();
    void setStart(QPoint s);

    void setEnd(QPoint e);
    QPoint startPoint();

    QPoint endPoint();

    void virtual paint(QPainter & painter) = 0;

protected:
        QPoint start;
        QPoint end;
};

#endif // PICTURESTYLE_H
