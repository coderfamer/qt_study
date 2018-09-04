#include <QString>
#include "dialog.h"
#include "ui_dialog.h"

const static double PI = 3.1416;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_countBtn_clicked()
{
    bool ok;
    QString tempStr;
    //QString text() const
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    //setText(const QString &)
    ui->areaLabel_2->setText(tempStr.setNum(area));
}

void Dialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt();
    double area = valueInt * valueInt * PI;
    //与 setNum用法类似，都是数字转字符串
    ui->areaLabel_3->setText(QString::number(area));
}
