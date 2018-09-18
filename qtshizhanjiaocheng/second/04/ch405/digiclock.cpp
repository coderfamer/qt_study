#include <QTimer>
#include <QTime>
#include <QDebug>
#include "digiclock.h"

DigiClock::DigiClock(QWidget *parent)
    : QLCDNumber(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);

    setWindowFlags(Qt::FramelessWindowHint);

    setWindowOpacity(0.5);
    //setStyleSheet("border:2pxsolidgreen;color:red;background:silver;");
    setDigitCount(13);//default word length is 5

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()) );
    timer->start(1000);
    showTime();
    resize(300, 60);
    showColon = true;
}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();
    qDebug() << time;
    QString text = time.toString("hh:mm:ss.zzz");
    qDebug() <<  text;
    if (showColon)
    {
        text[2] = ':';
        text[5] = ':';
        showColon = false;
    }
    else
    {
        text[2] = ' ';
        text[5] = ' ';
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
    if (event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}
