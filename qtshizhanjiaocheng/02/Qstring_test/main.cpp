#include <QCoreApplication>
#include <QDebug>
#include <QRegExp>
#include <QTextStream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int c;
    cin >> c;
    cout << c << endl;

    QString test;
    for (int i=0; i<9000; i++)
    {
        test.append("a");
        cout << test.size() << endl;
    }


    return a.exec();
}
