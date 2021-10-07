#include "picturestyle.h"

PictureStyle::PictureStyle()
{

}

void PictureStyle::setStart(QPoint s)
{
    start = s;
}

void PictureStyle::setEnd(QPoint e)
{
     end = e;
}

QPoint PictureStyle::startPoint()
{
    return start;
}

QPoint PictureStyle::endPoint()
{
    return end;
}
