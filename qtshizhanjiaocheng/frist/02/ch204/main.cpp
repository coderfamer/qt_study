#include "dialog.h"
#include <QApplication>
#include <QDebug>
#include <QMap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QMap<QString, QString> map;//创建一个map栈对象
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "031");

    QMapIterator<QString, QString> i(map);//只读迭代器
    for (;i.hasNext();)
    {
        qDebug() << " " << i.key() << " " << i.next().value();
    }
//    QMutableMapIterator<QString, QString> mi(map);
//    if (mi.findNext("111"))
//    {
//        mi.setValue("999");
//    }
    QMap<QString, QString>::iterator mi;
    mi = map.find("beijing");
    if (mi != map.end())
    {
        mi.value() = "888";
    }
    QMapIterator<QString, QString> modi(map);
    qDebug() << " ";
    for (;modi.hasNext();)
    {
        qDebug() << "" << modi.key() << " " << modi.next().value();
    }

    return a.exec();
}
