#include <QTextCodec>
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
