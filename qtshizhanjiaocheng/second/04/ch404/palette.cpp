#include <QHBoxLayout>
#include <QSize>
#include "palette.h"

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    createLeftFrame();
    createRgithFrame();
    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(leftFrame);
    mainLayout->addWidget(rightFrame);
}

Palette::~Palette()
{

}

void Palette::createLeftFrame()
{
    leftFrame = new QFrame;
    //leftFrame->setFrameShape(QFrame::Box);

    windowLabel = new QLabel(tr("QPalette::Window"));
    windowComboBox = new QComboBox;
    windowTextLabel = new QLabel(tr("QPalette::WindowText"));
    windowTextComboBox = new QComboBox;
    buttonLabel = new QLabel(tr("QPalette::Button"));
    buttonComboBox = new QComboBox;
    buttonTextLabel = new QLabel(tr("QPalette::ButtonText"));
    buttonTextComboBox = new QComboBox;
    baseLabel = new QLabel(tr("QPalette::Base"));
    baseComboBox = new QComboBox;
//            QPalette::Window
//            QPalette::WindowText
//            QPalette::Button
//            QPalette::ButtonText
//            QPalette::Base
    QGridLayout *leftLayout = new QGridLayout(leftFrame);
//    leftLayout->setColumnStretch(0, 1);
//    leftLayout->setColumnStretch(1, 6);

    leftLayout->addWidget(windowLabel, 0, 0);
    leftLayout->addWidget(windowComboBox, 0, 1);
    leftLayout->addWidget(windowTextLabel, 1, 0);
    leftLayout->addWidget(windowTextComboBox, 1, 1);
    leftLayout->addWidget(buttonLabel, 2, 0);
    leftLayout->addWidget(buttonComboBox, 2, 1);
    leftLayout->addWidget(buttonTextLabel, 3, 0);
    leftLayout->addWidget(buttonTextComboBox, 3, 1);
    leftLayout->addWidget(baseLabel, 4, 0);
    leftLayout->addWidget(baseComboBox, 4, 1);

    leftLayout->setSpacing(20);


}

void Palette::createRgithFrame()
{
    rightFrame = new QFrame;
    rightFrame->setFrameShape(QFrame::Panel);

    choseLabel = new QLabel(tr("pls chose a string"));
    choseComboBox = new QComboBox;
    inputLabel = new QLabel(tr("pls enter a string"));
    inputLineEdit = new QLineEdit;
    textEdit = new QTextEdit;

    QGridLayout *rightLayout = new QGridLayout(rightFrame);
    rightLayout->addWidget(choseLabel, 0, 0);

}
