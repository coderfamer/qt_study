
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QDebug>
#include <QWidget>

#include "news.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();



    QWidget window;
    window.setMinimumSize(600, 400);
    QVBoxLayout mainLayout(&window);

    News news("A");
    Reader reader;
    QObject::connect(&news, &News::newPaper, &reader, &Reader::readNews);
    news.send();

    QPushButton btn1("quit");
    QObject::connect(&btn1, &QPushButton::clicked, &QApplication::quit);

    QPushButton btn2("quit2");
    QObject::connect(&btn2, &QPushButton::clicked, [](bool){
        qDebug() << "you click me!!!" ;
    });

    mainLayout.addWidget(&btn1);
    mainLayout.addWidget(&btn2);



    window.show();



    return a.exec();
}
