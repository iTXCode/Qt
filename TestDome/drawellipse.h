#ifndef DRAWELLIPSE_H
#define DRAWELLIPSE_H

#include "picturestyle.h"

class DrawEllipse : public PictureStyle
{
public:
    DrawEllipse();
    void paint(QPainter &painter);
};

#endif // DRAWELLIPSE_H
