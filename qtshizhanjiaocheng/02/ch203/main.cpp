#include "dialog.h"
#include <QApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();


    qDebug() << "hello world!!!";

    return a.exec();
}
