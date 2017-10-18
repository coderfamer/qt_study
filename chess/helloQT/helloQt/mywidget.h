#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();

    virtual void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

private:
    QPoint m_ptClick;
};

#endif // MYWIDGET_H
