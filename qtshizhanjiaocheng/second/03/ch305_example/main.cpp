
#include <QApplication>
#include <QFont>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>

#include "content.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font("AR PL KaitiM GB", 12);
    a.setFont(font);

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);

    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息:"));
    list->insertItem(1, QObject::tr("联系方式:"));
    list->insertItem(2, QObject::tr("详细资料:"));

    Content *content = new Content(splitterMain);

    QObject::connect(list, SIGNAL(currentRowChanged(int)), content->stack,
                     SLOT(setCurrentIndex(int)) );


    splitterMain->show();
    return a.exec();
}
