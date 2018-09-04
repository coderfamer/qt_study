#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    QList<int> ilist;
    ilist << 1 << 2 << 3 << 4 << 5;
    int it;
    cin >> it;
    QListIterator<int> i(ilist);
    for (;i.hasNext();)
        cout << i.next();
    cout << endl;
    return 0;
}
