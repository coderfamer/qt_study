#ifndef CLOCK_H
#define CLOCK_H

#include <QDialog>

class Clock : public QDialog
{
    Q_OBJECT

public:
    Clock(QWidget *parent = 0);
    ~Clock();
};

#endif // CLOCK_H
