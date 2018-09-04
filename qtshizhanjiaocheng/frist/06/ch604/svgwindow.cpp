#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent)
    :QScrollArea(parent)
{
    svgWidget = new SvgWidget;
    setWidget(svgWidget);
}

void SvgWindow::setFile(QString fileName)
{
    svgWidget->load(fileName);//将新的SVG文件加载到svgWidget中显示
    QSvgRenderer *render = svgWidget->renderer();
    svgWidget->resize(render->defaultSize());//窗体按照svgWidget图片的默认尺寸显示
}
void SvgWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressPos = event->pos();

    scrollBarValueOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValueOnMousePress.ry() = verticalScrollBar()->value();
    event->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
    horizontalScrollBar()->setValue(scrollBarValueOnMousePress.x()-
                                    event->pos().x() + mousePressPos.x());
    verticalScrollBar()->setValue(scrollBarValueOnMousePress.y() -
                                  event->pos().y() + mousePressPos.y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    event->accept();
}
