#include "dialog.h"
#include <QGridLayout>
#include <QDebug>

const static double PI = 3.1416;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    label1 = new QLabel(this);
    label1->setText(tr("请输入圆的半径："));
    lineEdit = new QLineEdit(this);
    label1->setBuddy(lineEdit);
    label2 = new QLabel(this);
    btn = new QPushButton(this);
    btn->setText(tr("显示圆的面积"));
    label3 = new QLabel(this);
    label3->setText(tr("面积"));
    lineEdit3 = new QLineEdit(this);
    QGridLayout *mainLayout = new QGridLayout(this);//布局管理器，将所有的控件位置固定
    mainLayout->addWidget(label1, 0, 0);
    mainLayout->addWidget(lineEdit, 0, 1);
    mainLayout->addWidget(label2, 1, 0);
    mainLayout->addWidget(btn, 1, 1);
    mainLayout->addWidget(label3, 2, 0);
    mainLayout->addWidget(lineEdit3, 2, 1);
    qDebug() << "hello" ;

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showArea()) );
    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(showArea2()) );
//    connect(lineEdit, "clicked()", this, "showArea()" );
}

Dialog::~Dialog()
{

}

void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt*valueInt*PI;
    char f = 'g';
    label2->setText(tempStr.setNum(area, f));
//    label2->setText(area);
}

void Dialog::showArea2()
{
    bool ok;
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt*valueInt*PI;
    char f = 'g';
    lineEdit3->setText(tempStr.setNum(area, f));
}

