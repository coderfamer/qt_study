#include "dialog.h"
#include <QApplication>
#include <QDebug>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QList<int> list;
    list << 1 << 2 << 3 << 4 << 5;
    QListIterator<int> i(list);
    for (;i.hasNext();)
    {
        qDebug() << i.next();
    }
    qDebug() << "==============";
    i.toBack();
    while (i.hasNext())
    {
        qDebug() << i.previous();
    }

    return a.exec();
}
