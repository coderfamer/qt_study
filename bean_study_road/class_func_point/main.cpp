#include <QCoreApplication>
#include <iostream>
#include <cstdio>

using namespace std;
class A
{
public:
    A() {}
    A(int a) : m_a(a)
    {

    }
    void setA(int a)
    {
        m_a = a;
    }
    virtual void print()
    {
        cout << "A: " << m_a << endl;
    }
    virtual void printa()
    {
        cout << "A1: " << m_a << endl;
    }
private:
    int m_a;
};

class B : public A
{
public:
    B() : A(),m_b(0) {}
    B(int a, int b) : A(a), m_b(b)
    {}
    void setB(int b)
    {
        m_b = b;
    }
    void print()
    {
        A::print();
        cout << "B:" << m_b << endl;
    }
    void printa()
    {
        A::printa();
        cout << "B: " << m_b << endl;
    }
private:
    int m_b;
};

class C
{
public:
     void (C::*p1)();
     void (*p2)();


    C()
    {
        p1 = &C::printA;
        p2 = &C::printB;
    }

    void printA()
    {
        cout << "A" << endl;
    }

    static void printB()
    {
        cout << "B" << endl;
    }

};


int main(int argc, char *argv[])
{
    QCoreApplication arc(argc, argv);

    A a;
    B b;
    void (A::*ptr)(int) = &A::setA;
    A *pa = &a;

    printf("A.setA:%p\n", &A::setA);
    printf("B::print:%p\n", &A::print);
    printf("B::printa:%p\n", &A::printa);

    a.print();
    a.setA(10);
    a.print();
    a.setA(100);
    a.printa();

    (pa->*ptr)(1000);
    pa->print();

    a.print();
    (a.*ptr)(500);
    a.print();

    C c;
    void (C::*p)();
    (c.*c.p1)();

    p = c.p1;
    (c.*p)();

    void (*pp)();
    pp = &C::printB;
    pp();

    return arc.exec();
}

