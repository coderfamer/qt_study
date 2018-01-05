#include "paintex.h"

PaintEx::PaintEx(QWidget *parent)
    : QWidget(parent)
{
    paintArea = new PaintArea;

    shapeLabel = new QLabel(tr("形状:"));
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Line"), PaintArea::Line);
    shapeComboBox->addItem(tr("Rectangle"), PaintArea::RecTangle);
    shapeComboBox->addItem(tr("RoundRect"), PaintArea::RoundRect);
    shapeComboBox->addItem(tr("Ellipse"), PaintArea::Ellipse);
    shapeComboBox->addItem(tr("Polygon"), PaintArea::Polygon);
    shapeComboBox->addItem(tr("Polyline"), PaintArea::Polyline);
    shapeComboBox->addItem(tr("Points"), PaintArea::Points);
    shapeComboBox->addItem(tr("Arc"), PaintArea::Arc);
    shapeComboBox->addItem(tr("Path"), PaintArea::Path);
    shapeComboBox->addItem(tr("Text"), PaintArea::Text);
    shapeComboBox->addItem(tr("Pixmap"), PaintArea::Pixmap);

    rightLayout = new QGridLayout;
    rightLayout->addWidget(shapeLabel, 0, 0);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintArea, 1);
    mainLayout->setStretchFactor(rightLayout, 0);

}

PaintEx::~PaintEx()
{

}
