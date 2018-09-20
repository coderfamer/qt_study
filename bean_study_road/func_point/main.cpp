#include <QCoreApplication>
#include <QDebug>
int test_func1(int a);
int test_func2(int (*func1)(int),int a);

void t1();
void t2();
void t3();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int (*func1)(int) = test_func1;
    qDebug() << func1(20);

    typedef int (*func2)(int);
    func2 func22 = test_func1;
    qDebug() << func22(22);

    func2 func23 = test_func1;
    qDebug() << test_func2(func23, 10);


    typedef void (*func33)(void);
    func33 test[3] = {t1, t2, t3};

    test[0]();

    return a.exec();
}

int test_func1(int a)
{
    return a;
}

int test_func2(int (*func1)(int),int a)
{
    return func1(20) + a;
}

void t1()
{
    qDebug() << "test1";
}
void t2()
{
    qDebug() << "test2";
}
void t3()
{
    qDebug() << "test3";
}
