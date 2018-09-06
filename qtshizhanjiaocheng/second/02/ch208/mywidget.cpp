#include <qpushbutton.h>
#include <qfont.h>
#include <qapplication.h>
#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(200 ,120);//设置最小尺寸
    setMaximumSize(200, 120);

    QPushButton *quit = new QPushButton("Quit", this);
    quit->setGeometry(40, 20, 100, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()) );
}

MyWidget::~MyWidget()
{

}
