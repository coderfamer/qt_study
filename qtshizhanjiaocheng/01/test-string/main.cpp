#include "dialog.h"
#include <QApplication>
#include <QDebug>
#include <QByteArray>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QString str = " Welcome to you! ";
    QByteArray ba = str.toLatin1();
    qDebug() << ba;
    ba.append("hello wrold! ");
    qDebug() << ba.data();


    return a.exec();
}
