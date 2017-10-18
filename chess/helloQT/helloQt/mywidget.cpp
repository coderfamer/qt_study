#include "mywidget.h"
#include <QPainter>
#include <QMouseEvent>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
}

myWidget::~myWidget()
{

}

void myWidget::paintEvent(QPaintEvent * )
{
    //QPainter绘制类
    QPainter painter(this);
    painter.setPen(QColor(255, 0, 0));
    painter.setBrush(QBrush(QColor(255,255,0)));
    painter.drawLine(QPoint(0,0), QPoint(100, 300));
    painter.drawText(200, 200, "hello QT");
    painter.drawEllipse(QPoint(300,400), 50, 60);
}

void myWidget::mousePressEvent(QMouseEvent *event)
{

}
