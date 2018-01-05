#ifndef MYQQEXAMPLE_H
#define MYQQEXAMPLE_H

#include <QDialog>

class MyQQExample : public QDialog
{
    Q_OBJECT

public:
    MyQQExample(QWidget *parent = 0);
    ~MyQQExample();
};

#endif // MYQQEXAMPLE_H
