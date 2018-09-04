#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication w(argc, argv);

    double a = -19.3;
    double b=9.7;
    double c = qAbs(a);//绝对值
    double max = qMax(b, c);//返回最大值

    int bn = qRound(b);
    int cn = qRound(c);

    qDebug() << "a= " << a;
    qDebug() << "b= " << b;

    qDebug() << "c = qAbs(a) = " << c;
    qDebug() << "bn = qRound(b) = " << bn;
    qDebug() << "cn = qRound(c) = " << cn;

    qSwap(bn, cn);
    qDebug() << "qSwap(bn, cn):"<<"bn="<<bn<<", cn=" << cn;


    return w.exec();
}
