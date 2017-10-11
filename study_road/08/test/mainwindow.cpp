#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("main window"));

    openAction = new QAction(QIcon(":/myimage/test"), tr("&open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open );

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));
    toolBar2->addAction(openAction);
/*
    QStatusBar *statBar = statusBar();
    statBar->addAction(openAction);
    setStatusBar(statBar);*/
    statusBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Infromation"), tr("Open"));
}
