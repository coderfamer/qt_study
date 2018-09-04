#include "dialog.h"

const static double PI = 3.1416;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_label1 = new QLabel(this);
    m_label1->setText(tr("请输入圆的半径:"));
    m_lineEdit = new QLineEdit(this);
    m_label2 = new QLabel(this);
    m_btn = new QPushButton(this);
    m_btn->setText(tr("显示圆的面积:"));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(m_label1, 0, 0);
    mainLayout->addWidget(m_lineEdit, 0, 1);
    mainLayout->addWidget(m_label2, 1, 0);
    mainLayout->addWidget(m_btn, 1, 1);

    //connect(m_btn, SIGNAL(clicked()),this, SLOT(showArea()) );
    connect(m_btn, SIGNAL(clicked(bool)), this, SLOT(showArea()) );
    //connect(m_btn, "clicked()", this, "showArea()" );
}

Dialog::~Dialog()
{

}


void Dialog::showArea()
{
    QString valueStr = m_lineEdit->text();
    int valueInt = valueStr.toInt();
    double area = valueInt * valueInt * PI;
    m_label2->setText(QString::number(area));
}
