#ifndef QRAWINGBOARD_H
#define QRAWINGBOARD_H

#include <QtGui>
#include <QWidget>
#include <QDebug>
#include <QPaintEvent>
#include "picturestyle.h"
#include "drawline.h"
#include "drawrect.h"
#include "drawellipse.h"
#include <QSvgGenerator>
#include <QSvgRenderer>

class QrawingBoard : public QWidget
{
    Q_OBJECT

public:
    QrawingBoard(QWidget *parent = 0);
     void setsPaletteColor(const QColor&);

public slots:
    void setCurrentShape(PictureStyle::ShapeStyle s);

    void paintSvgPicture(QSvgGenerator* svgGenerator);
    void setSvgRender(QFileInfo& info,QString& fileName);
protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    PictureStyle::ShapeStyle currShapeCode;
    PictureStyle *shape;
    bool perm;
    QList<PictureStyle*> shapeList;
    QSvgRenderer m_SvgRend;
    QColor m_color;
};

#endif // QRAWINGBOARD_H
