#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);

    createToolBar();

    setMinimumSize(600, 400);

}

MainWindow::~MainWindow()
{

}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar(tr("tool"));

    lineStyleLabel = new QLabel(tr("LineStyle"));
    lineStyleComboBox = new QComboBox;
    lineWidthLabel = new QLabel(tr("LineWidth"));
    lineWidthSpinBox = new QSpinBox;
    lineWidthSpinBox->setRange(1, 20);
    colorBtn = new QToolButton;
    colorBtn->setAutoFillBackground(true);
    colorBtn->setPalette(QPalette(Qt::blue));
    delBtn = new QToolButton;
    delBtn->setText(tr("clear"));

    //toolBar->
    toolBar->addWidget(lineStyleLabel);
    toolBar->addWidget(lineStyleComboBox);
    toolBar->addWidget(lineWidthLabel);
    toolBar->addWidget(lineWidthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(delBtn);
}
