#ifndef CONTENT_H
#define CONTENT_H


#include "baseinfo.h"
#include "contact.h"
#include "public.h"
#include "detail.h"

class Content : public QFrame
{
    Q_OBJECT
public:
    Content(QWidget *parent = 0);

    QStackedWidget *stack;
    QPushButton *amendBtn;
    QPushButton *cancelBtn;

    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
};

#endif // CONTENT_H
