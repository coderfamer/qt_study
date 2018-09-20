#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>
#include <QKeySequence>
#include <QToolButton>
#include <QWidget>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("action"));

    openAction = new QAction(QIcon(":/flower.png"), tr("&open..."), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("open a file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QToolButton *toolBtn = new QToolButton;
    toolBtn->setAutoFillBackground(true);
    toolBtn->setPalette(QPalette(Qt::blue));
    connect(toolBtn, &QToolButton::clicked, this, &MainWindow::btnClicked );

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *fileToolBar = addToolBar("&File");
    fileToolBar->addAction(openAction);
    fileToolBar->addWidget(toolBtn);

    statusBar();

}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    QMessageBox::information(this, tr("info"), tr("infor me"));
}

void MainWindow::btnClicked()
{
    QDialog *widget = new QDialog(this);
    widget->setWindowTitle(tr("hello dialog"));
    widget->show();
}
