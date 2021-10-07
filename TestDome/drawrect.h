#ifndef DRAWRECT_H
#define DRAWRECT_H
#include <QtGui>
#include "picturestyle.h"

class DrawRect : public PictureStyle
{
public:
    DrawRect();
    void paint(QPainter &painter);
};

#endif // DRAWRECT_H
