#include "digiclock.h"

#include <QPalette>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>

DigiClock::DigiClock(QWidget *parent)
    :QLCDNumber(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);//设置窗体标识
    setWindowOpacity(0.5);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()) );
    timer->start(1000);
    showTime();
    resize(150, 60);
    showColon = true;
}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();//获取当前系统时间
    QString text = time.toString("hh:mm");
    if (showColon)//控制电子时钟时分之间的两个点的闪显功能
    {
        text[2] = ':';
        showColon = false;
    }
    else
    {
        text[2] = ' ';
        showColon = true;
    }
    display(text);
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if (event->button() == Qt::RightButton)
    {
        close();
    }

}
void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
