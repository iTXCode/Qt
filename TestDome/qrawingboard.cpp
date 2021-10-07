#include "qrawingboard.h"
#include <QSvgRenderer>

QrawingBoard::QrawingBoard(QWidget *parent)
    : QWidget(parent), currShapeCode(PictureStyle::Mouse), shape(nullptr), perm(false)
{
   setAttribute(Qt::WA_StyledBackground);
}

void QrawingBoard::setCurrentShape(PictureStyle::ShapeStyle s)
{
    if(s != currShapeCode) {
        currShapeCode = s;
    }
}

void QrawingBoard::paintSvgPicture(QSvgGenerator* svgGenerator)
{
    //将绘图板上的图片绘制成svg格式

    if (!svgGenerator)
          return;

     QPainter painter;
     painter.begin(svgGenerator);
     for(size_t i = 0; i < shapeList.size(); i++)
     {
         shapeList[i]->paint(painter);
     }
     if (m_SvgRend.isValid())
     {
         m_SvgRend.render(&painter,this->rect());
     }
     painter.end();
}



void QrawingBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.setBrush(Qt::white);
    painter.drawRect(0, 0, size().width(), size().height());
    foreach(PictureStyle * list, shapeList) {
        list->paint(painter);
        //TODO

    }
    if(shape) {
        shape->paint(painter);
    }

    if (m_SvgRend.isValid())
    {
        m_SvgRend.render(&painter,this->rect());
    }
}

void QrawingBoard::setSvgRender(QFileInfo& info,QString& fileName)
{
    if(info.exists() && !fileName.isEmpty())
        m_SvgRend.load(fileName);
}

void QrawingBoard::mousePressEvent(QMouseEvent *event)
{
    switch(currShapeCode)
    {
        case PictureStyle::Mouse:
        {
            shape = nullptr;
            break;
        }
        case PictureStyle::Line:
        {
            shape = new DrawLine;
            break;
        }
        case PictureStyle::Rect:
        {
            shape = new DrawRect;
            break;
        }
        case PictureStyle::Ellipse:
        {
            shape = new DrawEllipse;
            break;
        }
    }

    if (shape != nullptr)
    {
        perm = false;
        shapeList<<shape;
        shape->setStart(event->pos());
        shape->setEnd(event->pos());
    }
}

void QrawingBoard::mouseMoveEvent(QMouseEvent *event)
{
        if(shape && !perm) {
                shape->setEnd(event->pos());
                update();
        }
}

void QrawingBoard::mouseReleaseEvent(QMouseEvent *event)
{
    perm = true;
}

void QrawingBoard::setsPaletteColor(const QColor& color)
{
    if (color.isValid())
        m_color = color;
    qDebug()<<m_color;
    this->setStyleSheet("background-color:" + m_color.name()+";border: 0.5px solid #000;");
}
