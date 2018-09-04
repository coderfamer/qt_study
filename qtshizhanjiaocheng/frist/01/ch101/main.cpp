
/*wa每一个使用QT图形化应用程序都必须使用一个QApplication对象。QApplication管理了
各种各样的图形化应用程序的广泛资源、基本设置、控制流程及事件处理等wa*/
#include "dialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
