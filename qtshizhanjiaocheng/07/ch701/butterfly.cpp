#include "butterfly.h"
#include <math.h>

const static double PI = 3.1416;

Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up = true;
    pix_up.load(":/up.png");
    pix_down.load(":/down.png");
    startTimer(100);
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-pix_up.width()/2-adjust, -pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2, pix_up.height()+adjust*2);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    if(up)
    {
        painter->drawPixmap(boundingRect().topLeft(), pix_up);
        up != up;
    }
    else
    {
        painter->drawPixmap(boundingRect().topLeft(), pix_down);
    }
}
