#include <QApplication>
#include "device.h"
#include <QDebug>
#include <QThread>
#include "ldataconverter.h"
#include "lfilesystem.h"
#include "commix.h"
#include "myhelper.h"
#include <QtWebKitWidgets/QWebView>
#include <windows.h>
#include <lbasedialog.h>
#include <QTextCodec>
#include "lstyledialog.h"
#include "ldataconverter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myHelper::SetUTF8Code();
    myHelper::SetStyle("blue");//蓝色风格
    myHelper::SetChinese();
    Commix com;
    com.show();

    return a.exec();
}
