#include <QCoreApplication>
#include <QDebug>
#include <QRegExp>
#include <QTextStream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string test;
    cin >> test;
    QRegExp testRegExp("(c)");
    cout << test << endl;
    //cin >> test;
//    if (test.isValid())
//    {
//        cout << "true" << endl;
//    }


    return a.exec();
}
