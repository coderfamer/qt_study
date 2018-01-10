#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QtSvg>
#include <QSvgWidget>
#include <QSvgRenderer>

class SvgWidget : public QSvgWidget
{
    Q_OBJECT
public:
    SvgWidget(QWidget *parent=0);
    void wheelEvent(QWheelEvent *);//响应鼠标的滚轮事件，使svg图片能够滚动缩放
private:
    QSvgRenderer *render;
};

#endif // SVGWIDGET_H
