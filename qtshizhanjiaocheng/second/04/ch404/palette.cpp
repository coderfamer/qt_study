#include <QHBoxLayout>
#include <QSize>
#include <QStringList>
#include <QColor>
#include <QString>
#include <QPixmap>
#include <QIcon>
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
    //windowLabel->setFrameShape(QFrame::Box);
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    connect(windowComboBox, SIGNAL(activated(int)), this, SLOT(showWindow()) );

    windowTextLabel = new QLabel(tr("QPalette::WindowText"));
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox, SIGNAL(activated(int)), this, SLOT(showWindowText()) );

    buttonLabel = new QLabel(tr("QPalette::Button"));
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    connect(buttonComboBox, SIGNAL(activated(int)), this, SLOT(showButton()) );

    buttonTextLabel = new QLabel(tr("QPalette::ButtonText"));
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(showButtonText()) );


    baseLabel = new QLabel(tr("QPalette::Base"));
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    connect(baseComboBox, SIGNAL(activated(int)), this, SLOT(showBase()) );
//            QPalette::Window
//            QPalette::WindowText
//            QPalette::Button
//            QPalette::ButtonText
//            QPalette::Base
    QGridLayout *leftLayout = new QGridLayout(leftFrame);
    leftLayout->setColumnStretch(0, 1);
    leftLayout->setColumnStretch(1, 3);


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
    //rightFrame->setFrameShape(QFrame::Panel);

    choseLabel = new QLabel(tr("pls chose a string"));
    choseComboBox = new QComboBox;
    inputLabel = new QLabel(tr("pls enter a string"));
    inputLineEdit = new QLineEdit;
    textEdit = new QTextEdit;

    confirmBtn = new QPushButton(tr("OK"));
    cancelBtn = new QPushButton(tr("Cancel"));

    QGridLayout *rightTopLayout = new QGridLayout();
    rightTopLayout->addWidget(choseLabel, 0, 0);
    rightTopLayout->addWidget(choseComboBox, 0, 1);
    rightTopLayout->addWidget(inputLabel, 1, 0);
    rightTopLayout->addWidget(inputLineEdit, 1, 1);
    rightTopLayout->addWidget(textEdit, 2, 0, 1, 2);

    QHBoxLayout *rightButtomLayout = new QHBoxLayout();
    rightButtomLayout->addStretch(1);
    rightButtomLayout->addWidget(confirmBtn);
    rightButtomLayout->addWidget(cancelBtn);

    QVBoxLayout *rightLayout = new QVBoxLayout(rightFrame);
    rightLayout->addLayout(rightTopLayout);
    rightLayout->addLayout(rightButtomLayout);


}

void Palette::fillColorList(QComboBox *combobox)
{
    QStringList colorList = QColor::colorNames();//return QT color to colorlist
    QString color;
    foreach(color, colorList)
    {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        combobox->addItem(QIcon(pix), NULL);
        combobox->setIconSize(QSize(70, 20));
        combobox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void Palette::showWindow()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);

    QPalette p = rightFrame->palette();
    p.setColor(QPalette::Window, color);
    rightFrame->setPalette(p);

    rightFrame->update();
}

void Palette::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowTextComboBox->currentIndex()]);

    QPalette p = rightFrame->palette();
    p.setColor(QPalette::WindowText, color);
    rightFrame->setPalette(p);

    rightFrame->update();
}

void Palette::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonComboBox->currentIndex()]);

    QPalette p = rightFrame->palette();
    p.setColor(QPalette::Button, color);
    rightFrame->setPalette(p);

    rightFrame->update();
}

void Palette::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonTextComboBox->currentIndex()]);

    QPalette p = rightFrame->palette();
    p.setColor(QPalette::ButtonText, color);
    rightFrame->setPalette(p);

    rightFrame->update();
}

void Palette::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[baseComboBox->currentIndex()]);

    QPalette p = rightFrame->palette();
    p.setColor(QPalette::Base, color);
    rightFrame->setPalette(p);

    rightFrame->update();
}
