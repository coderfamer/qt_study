//#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main()
{
    //QCoreApplication a(argc, argv);
    QList<int> ilist;
    for (int i = 0; i < 10; i++)
        ilist.insert(ilist.end(), i);
    auto i = ilist.begin();
    for (;i != ilist.end(); ++i)
    {
        qDebug() << *i;
        *i = (*i) * 10;
    }

    for (const auto ci : ilist)
        qDebug() << ci;


    return 0;
}
