#include <QtWidgets/QApplication>
#include <QObject>
#include <QDialog>
#include <QStatusBar>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QMainWindow w;
//    w.setGeometry(10, 30, 200, 200);
//    w.statusBar()->showMessage(QObject::tr("Normal"));
//    w.show();

    QMainWindow window1;
    window1.setGeometry(10, 10, 100, 100);
    //只有一个关闭按钮
    window1.setWindowFlags(Qt::Window);
    window1.show();

    QMainWindow window2;
    window2.setGeometry(150, 10, 100, 100);
    window2.setWindowFlags(Qt::Widget);
    window2.show();

    QMainWindow window3;
    window3.setGeometry(290, 10, 100, 100);
    window3.setWindowFlags(Qt::Dialog);
    window3.show();

    QMainWindow window4;
    window4.setGeometry(430, 10, 100, 100);
    window4.setWindowFlags(Qt::Sheet);
    window4.show();

    QMainWindow windo5;
    windo5.setGeometry(570, 10, 100, 100);
    windo5.setWindowFlags(Qt::Drawer);
    windo5.show();

    QMainWindow window6;
    window6.setGeometry(710, 10, 100, 100);
    window6.setWindowFlags(Qt::Popup);
    window6.show();

    QMainWindow window7;
    window7.setGeometry(850, 10, 100, 100);
    window7.setWindowFlags(Qt::Tool);
    window7.show();


    QMainWindow window8;
    window8.setGeometry(990, 10, 100, 100);
    window8.setWindowFlags(Qt::ToolTip);
    window8.show();

    QMainWindow window9;
    window9.setGeometry(1130, 10, 100, 100);
    window9.setWindowFlags(Qt::SplashScreen);
    window9.show();

    QMainWindow window10;
    window10.setGeometry(1270, 10, 100, 100);
    window10.setWindowFlags(Qt::Desktop);
    window10.show();

    QMainWindow window11;
    window11.setGeometry(1410, 10, 100, 100);
    window11.setWindowFlags(Qt::SubWindow);
    window11.show();

    QMainWindow window12;
    window12.setGeometry(1550, 10, 100, 100);
    window12.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    window12.show();


//    QMainWindow w2;
//    w2.setGeometry(440, 30, 200, 200);
//    w2.setWindowFlags(Qt::WindowContextHelpButtonHint);
//    w2.show();

//    QMainWindow window3;
//    window3.setGeometry(655, 30, 200, 200);
//    window3.setWindowFlags(Qt::CustomizeWindowHint);
//    window3.show();




    return a.exec();
}
