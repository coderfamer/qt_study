#include "paintex.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintEx w;
    w.show();

    return a.exec();
}
