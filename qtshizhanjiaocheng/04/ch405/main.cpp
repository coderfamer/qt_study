#include "clock.h"
#include "digiclock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Clock w;
//    w.show();
    DigiClock clock;
    clock.show();


    return a.exec();
}
