#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>

int main()
{
    double a = -19, b = 9.7;
    double c = qAbs(a);
    double max = qMax(b, c);

    int bn = qRound(b);
    int cn = qRound(c);

    qDebug() << "a = " << a;
    qDebug() << "b = " << b;
    qDebug() << "c = qAbs(a) = " << c;
    qDebug() << "qMax(b, c) = " << max;
    qDebug() << "bn = qRound(b) = " << bn;
    qDebug() << "cn = qRoudn(c) = " << cn;

    return 0;
}
