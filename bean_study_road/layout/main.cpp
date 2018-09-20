#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QObject>
#include <QToolButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget mainWindow;

    QSpinBox *spinBox = new QSpinBox(&mainWindow);
    QSlider *slider = new QSlider(Qt::Horizontal,&mainWindow);
    spinBox->setRange(0, 100);
    slider->setRange(0, 100);

    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue );
//    void(QSpinBox::*spinBoxSingal)(int) = NULL;
//    spinBoxSingal =  &QSpinBox::valueChanged;
    typedef void (QSpinBox::*spinSingal)(int);
    spinSingal spinBoxSingal = &QSpinBox::valueChanged; // same 19,20
    QObject::connect(spinBox, spinBoxSingal, slider, &QSlider::setValue );
    spinBox->setValue(22);

    //QToolButton *toolBtn = new QToolButton;

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(spinBox);
    mainLayout->addWidget(slider);

    mainWindow.setLayout(mainLayout);
    mainWindow.show();

    return a.exec();
}
