#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFile data("data.txt");

    if (data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out << QObject::tr("score:") << qSetPadChar('n') << qSetFieldWidth(10) << left << 190 << endl;
    }


    return a.exec();
}
