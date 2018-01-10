#include <QColorDialog>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);//新建一个DrawWidget对象作为主窗口中的中央窗体

    createToolBar();//实现一个工具栏

    setMinimumSize(600, 400);//设置主窗体的最小尺寸
    ShowStyle();
    drawWidget->setWidth(widthSpinBox->value());
    drawWidget->setColor(Qt::black);

}

MainWindow::~MainWindow()
{

}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar("Tool");
}

void MainWindow::ShowStyle()
{

}

void MainWindow::ShowColor()
{

}
