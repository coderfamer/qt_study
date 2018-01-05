#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QPoint>
#include <QMouseEvent>


class DigiClock : public QLCDNumber
{
public:
    DigiClock(QWidget *parent=0);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

public slots:
    void showTime();
private:
    QPoint dragPosition;
    bool showColon;
};

#endif // DIGICLOCK_H
