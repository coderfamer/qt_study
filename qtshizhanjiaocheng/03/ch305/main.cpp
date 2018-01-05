#include "content.h"
#include <QApplication>
#include <QFont>
#include <QSplitter>
#include <QTextCodec>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Content w;
//    w.show();
    QFont font("AR PL KaitiM GB", 12);//设置整个程序采用对的字体和字号
    a.setFont(font);

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);//新建一个水平分割对象
    splitterMain->setOpaqueResize(true);

    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));

    Content *content = new Content(splitterMain);
    QObject::connect(list, SIGNAL(currentRowChanged(int)),
                     content->stack, SLOT(setCurrentIndex(int)) );

    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();

    return a.exec();
}
