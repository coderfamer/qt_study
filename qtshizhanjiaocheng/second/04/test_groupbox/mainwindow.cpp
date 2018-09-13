#include <QGridLayout>
#include <QGroupBox>
#include <QRadioButton>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Group Boxes"));
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(createFirstExclusiveGroup(), 0, 0);
    grid->addWidget(createSeondExclusiveGroup(), 0, 1);
    grid->addWidget(createPushButtonGroup(), 1, 0);
    grid->addWidget(createNonExclusiveGroup(), 1, 1);

}

MainWindow::~MainWindow()
{

}

QGroupBox *MainWindow::createFirstExclusiveGroup()
{
    groupBox = new QGroupBox(tr("Exclusive Raido Buttons"));
    QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;

}

QGroupBox *MainWindow::createSeondExclusiveGroup()
{

}

QGroupBox *MainWindow::createPushButtonGroup()
{

}

QGroupBox *MainWindow::createNonExclusiveGroup()
{

}
