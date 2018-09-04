#ifndef CONTENT_H
#define CONTENT_H

#include <QDialog>
#include <QPushButton>
#include <QStackedWidget>

#include "baseinfo.h"
#include "contact.h"
#include "detail.h"


class Content : public QFrame
{
    Q_OBJECT

public:
    Content(QWidget *parent = 0);
    ~Content();

    QPushButton *AmendBtn;
    QPushButton *CloseBtn;

    QStackedWidget *stack;

    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
};

#endif // CONTENT_H
