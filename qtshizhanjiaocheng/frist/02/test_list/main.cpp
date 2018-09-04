#include "dialog.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QList<int> list;
    for (int j=0; j<10; j++)
    {
        list << j;
    }
    for (int i=0; i<list.count(); i++)
    {
        qDebug() << i;
    }
    QList<int>::iterator i;
    for (i=list.begin(); i != list.end(); ++i)
    {
        qDebug() << (*i);
        *i = (*i)*10;
    }
    QList<int>::const_iterator ci;
    for (ci=list.constBegin(); ci!=list.constEnd();++ci)
    {
        qDebug() << *ci;
    }
    return a.exec();
}
