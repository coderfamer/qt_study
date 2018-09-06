#include <QListWidget>
#include <QHBoxLayout>


#include "stackdlg.h"

StackDlg::StackDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this);
    QStringList labels;
    labels << "Window1" << "Window2" << "Window3" << "Window4";
    list->insertItems(0, labels);

    label1 = new QLabel(tr("WindowsTest1"));
    label2 = new QLabel(tr("WindowsTest2"));
    label3 = new QLabel(tr("WindowsTest3"));
    btn4 = new QPushButton(tr("Windowtest4"));

    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);
    stack->addWidget(btn4);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack ,0, Qt::AlignHCenter);
    mainLayout->setStretchFactor(list, 1);
    mainLayout->setStretchFactor(stack, 3);

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)) );

}

StackDlg::~StackDlg()
{

}
