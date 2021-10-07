#ifndef DRAWLINE_H
#define DRAWLINE_H
#include <QtGui>
#include "picturestyle.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class DrawLine : public PictureStyle
{
public:
    DrawLine();
    void paint(QPainter &painter);
};

#endif // DRAWLINE_H
