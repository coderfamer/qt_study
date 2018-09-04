#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("textFile.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line = file.readLine();
            qDebug() << line;
        }
//        char buffer[2048];
//        qint64 lineLen = file.readLine(buffer, sizeof(buffer));
//        qDebug() << "length" <<lineLen;
//        if (lineLen != -1)
//        {
//            qDebug() << buffer;
//        }
    }


    return a.exec();
}
