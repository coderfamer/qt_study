#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QDebug>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    QMap<QString, QString> smap;
    smap.insert("beijing", "111");
    smap.insert("shanghai", "021");
    smap.insert("jinan", "0531");

    auto i = smap.constBegin();
    for (;i != smap.constEnd(); i++)
        qDebug() << " " << i.key() << " " << i.value();

    auto mi = smap.find("beijing");
    if (mi != smap.end())
        mi.value() = "010";

    qDebug() << " ";
    for (auto modi = smap.constBegin(); modi != smap.constEnd(); modi++)
    {
        qDebug() << " " << modi.key() << " " << modi.value();
    }


    return 0;
}
