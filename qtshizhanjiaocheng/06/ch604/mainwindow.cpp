#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("SVG Viewer"));
    createMenu();


}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenu()
{
    QMenu *fileMneu = menuBar()->addMenu(tr("文件"));

    QAction *openAct = new QAction(tr("打开"), this);
    connect(openAct, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()) );
    fileMneu->addAction(openAct);
}

void MainWindow::slotOpenFile()
{
    QString name = QFileDialog::getOpenFileName(this,
                                                "打开", "/", "svg files(*.svg)");
    svgWindow->setFile(name);
}
