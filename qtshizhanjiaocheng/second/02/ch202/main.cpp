//#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <list>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    QList<int> ilist;
    QMutableListIterator<int> i(ilist);
    for (int j = 0; j < 10; ++j)
        i.insert(j);

    for (i.toFront();i.hasNext();)
        qDebug() << i.next();

    for (i.toBack();i.hasPrevious();)
    {
        if (i.previous() % 2 == 0)
            i.remove();
        else
            i.setValue(i.peekNext() * 10);
    }

    for (i.toFront();i.hasNext();)
        qDebug() << i.next();

    return 0;
}
