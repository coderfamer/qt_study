#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent)
    :QSvgWidget(parent)
{
    render = renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *e)
{
    const double diff = 0.1;//设置比例
    QSize size = render->defaultSize();//获取图片区的尺寸大小
    int width = size.width();
    int height = size.height();
    if (e->delta() > 0)
    {
        width = int(this->width() + this->width()*diff);
        height = int(this->height()+this->height()*diff);
    }
    else
    {
        width = int(this->width()-this->width()*diff);
        height = int(this->height()-this->height()*diff);
    }
    resize(width, height);
}
