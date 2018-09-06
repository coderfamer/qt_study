#include <QFont>
#include <QSplitter>
#include <QTextEdit>

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font("ZYsong18030", 12);
    a.setFont(font);

    //主分割窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    //这是tu拖拽时分割条是否实时更新显示
    splitterMain->setOpaqueResize(false);
    QString text = "Left Widget";
    QTextEdit *textLeft = new QTextEdit(text, splitterMain);
    //QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"), splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);

    //右部分窗口
    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    //splitterRight->setOpaqueResize(false);
    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"), splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textButtom = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);
    textButtom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));


    splitterMain->show();
//    MainWindow w;
//    w.show();

    return a.exec();
}
