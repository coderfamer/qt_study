#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QDate>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileFun();
}

MainWindow::~MainWindow()
{

}

void MainWindow::fileFun()
{
    QFile file("binary.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file);
    out <<QString(tr("陈西西:"));
    out << QDate::fromString("1994/09/25", "yyyy/MM/dd");
    out << (qint32)19;
    file.close();

    file.setFileName("binary.dat");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "error!";
        return;
    }

    QDataStream in(&file);
    QString name;
    QDate birthday;
    qint32 age;
    in >> name >> birthday >> age;
    qDebug() << name << birthday << age;
    file.close();
}
