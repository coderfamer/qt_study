#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/test"), tr("&open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &MainWindow::open );

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    /*
     * 应用程序级别的模态画面
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Hello, dialog!!"));
    //dialog.exec();
    dialog.show();*/

    //窗口级别的模态画面
    /*
    QDialog *dialog = new QDialog;//堆上建立,内存泄漏，没有delete
    dialog->setWindowTitle(tr("Hello, dialog!!"));
    //dialog.exec();
    dialog->show();*/

    QDialog *dialog = new QDialog;
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Hello, dialog!!"));
    dialog->show();



}
