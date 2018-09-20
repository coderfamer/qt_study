#include "paintex.h"

PaintEx::PaintEx(QWidget *parent)
    : QWidget(parent)
{
    paintArea = new PaintArea;

    shapeLabel = new QLabel(tr("shape:"));
    shapeComboBox = new  QComboBox;
    shapeComboBox->addItem(tr("Line"), PaintArea::Line);
    shapeComboBox->addItem(tr("Rectangle"), PaintArea::Rectangle);
    shapeComboBox->addItem(tr("RoundRect"), PaintArea::RoundRect);
    shapeComboBox->addItem(tr("Ellipse"), PaintArea::Ellipse);
    shapeComboBox->addItem(tr("Polygon"), PaintArea::Polygon);
    shapeComboBox->addItem(tr("Polyline"), PaintArea::Polyline);
    shapeComboBox->addItem(tr("Points"), PaintArea::Points);
    shapeComboBox->addItem(tr("Arc"), PaintArea::Arc);
    shapeComboBox->addItem(tr("Path"), PaintArea::Path);
    shapeComboBox->addItem(tr("Text"), PaintArea::Text);
    shapeComboBox->addItem(tr("Pixmap"), PaintArea::Pixmap);
    connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(showShape(int)) );

    penColorLabel = new QLabel(tr("penColor:"));;
    penColorFrame = new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(QPalette(Qt::blue));
    penColorBtn = new QPushButton(tr("change"));
    connect(penColorBtn, SIGNAL(clicked(bool)), this, SLOT(showPenColor()) );

    penWidthLabel = new QLabel(tr("penWidth:"));;
    penWidthSpinBox = new  QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(showPenWidth(int)) );


    penStyleLabel = new QLabel(tr("penStyle:"));;
    penStyleComboBox = new  QComboBox;
    penStyleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
    connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(showPenStyle(int)) );

    penHoodLabel = new QLabel(tr("penHood"));;
    penHoodComboBox = new  QComboBox;
    penHoodComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
    penHoodComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
    penHoodComboBox->addItem(tr("RoundCap"), Qt::RoundCap);
    connect(penHoodComboBox, SIGNAL(activated(int)), this, SLOT(showPenCap(int)) );

    penJoinLabel = new QLabel(tr("penJoin"));;
    penJoinComboBox = new  QComboBox;
    penJoinComboBox->addItem(tr("BevelJoin"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);
    connect(penJoinComboBox, SIGNAL(activated(int)), this, SLOT(showPenJoin(int)) );

    fillModeLabel = new QLabel(tr("fillModel"));;
    fillModeComboBox = new  QComboBox;
    fillModeComboBox->addItem(tr("OddEvenFill"), Qt::OddEvenFill);
    fillModeComboBox->addItem(tr("WindingFill"), Qt::WindingFill);
    connect(fillModeComboBox, SIGNAL(activated(int)), this, SLOT(showFileRule()) );

    spreadLabel = new QLabel(tr("spraed"));;
    spreadComboBox = new  QComboBox;
    spreadComboBox->addItem(tr("PadSpread"),QGradient::PadSpread);
    spreadComboBox->addItem(tr("RepeatSpread"),QGradient::RepeatSpread);
    spreadComboBox->addItem(tr("ReflectSpread"),QGradient::ReflectSpread);
    connect(spreadComboBox, SIGNAL(activated(int)), this, SLOT(showSpreadStyle()) );

    brushColorLabel = new QLabel(tr("brush"));;
    brushColorFrame = new  QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(QPalette(Qt::green));
    brushColorBtn = new QPushButton(tr("change"));
    connect(brushColorBtn, SIGNAL(clicked(bool)), this, SLOT(showBrushColor()) );

    brushStyleLabel = new QLabel(tr("brushStyle"));;
    brushStyleboBox = new  QComboBox;
    brushStyleboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
    brushStyleboBox->addItem(tr("Dense1Pattern"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleboBox->addItem(tr("Dense2Pattern"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleboBox->addItem(tr("Dense3Pattern"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleboBox->addItem(tr("Dense4Pattern"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleboBox->addItem(tr("Dense5Pattern"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleboBox->addItem(tr("Dense6Pattern"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleboBox->addItem(tr("Dense7Pattern"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleboBox->addItem(tr("HorPattern"), static_cast<int>(Qt::HorPattern));
    brushStyleboBox->addItem(tr("VerPattern"), static_cast<int>(Qt::VerPattern));
    brushStyleboBox->addItem(tr("CrossPattern"), static_cast<int>(Qt::CrossPattern));
    brushStyleboBox->addItem(tr("BDiagPattern"), static_cast<int>(Qt::BDiagPattern));
    brushStyleboBox->addItem(tr("FDiagPattern"), static_cast<int>(Qt::FDiagPattern));
    brushStyleboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
    brushStyleboBox->addItem(tr("DiagCrossPattern"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleboBox->addItem(tr("LinearGradientPattern"), static_cast<int>(Qt::LinearGradientPattern));
    brushStyleboBox->addItem(tr("ConicalGradientPattern"), static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleboBox->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
    brushStyleboBox->addItem(tr("TexturePattern"), static_cast<int>(Qt::TexturePattern));
    connect(brushStyleboBox, SIGNAL(activated(int)), this, SLOT(showBrush(int)) );

    QGridLayout *rightLayout = new QGridLayout;
    rightLayout->addWidget(shapeLabel, 0, 0);
    rightLayout->addWidget(shapeComboBox, 0, 1);
    rightLayout->addWidget(penColorLabel, 1, 0);
    rightLayout->addWidget(penColorFrame, 1, 1);
    rightLayout->addWidget(penColorBtn, 1, 2);
    rightLayout->addWidget(penWidthLabel, 2, 0);
    rightLayout->addWidget(penWidthSpinBox, 2, 1);
    rightLayout->addWidget(penStyleLabel, 3, 0);
    rightLayout->addWidget(penStyleComboBox, 3, 1);
    rightLayout->addWidget(penHoodLabel, 4, 0);
    rightLayout->addWidget(penHoodComboBox, 4, 1);
    rightLayout->addWidget(penJoinLabel, 5, 0);
    rightLayout->addWidget(penJoinComboBox, 5, 1);
    rightLayout->addWidget(fillModeLabel, 6, 0);
    rightLayout->addWidget(fillModeComboBox, 6, 1);
    rightLayout->addWidget(spreadLabel, 7, 0);
    rightLayout->addWidget(spreadComboBox, 7, 1);
    rightLayout->addWidget(brushColorLabel, 8, 0);
    rightLayout->addWidget(brushColorFrame, 8, 1);
    rightLayout->addWidget(brushColorBtn, 8, 2);
    rightLayout->addWidget(brushStyleLabel, 9, 0);
    rightLayout->addWidget(brushStyleboBox, 9, 1);


    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintArea,1);
    mainLayout->setStretchFactor(rightLayout,0);
}

PaintEx::~PaintEx()
{

}

void PaintEx::showShape(int value)
{
    PaintArea::Shape shape = PaintArea::Shape(shapeComboBox->itemData(value).toInt());
    paintArea->setShape(shape);
}



void PaintEx::showPenColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    penColorFrame->setPalette(QPalette(color));
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                          penStyleComboBox->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penHoodComboBox->itemData(
                                              penHoodComboBox->currentIndex()).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                 penJoinComboBox->currentIndex()).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void PaintEx::showPenWidth(int width)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                          penStyleComboBox->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penHoodComboBox->itemData(
                                              penHoodComboBox->currentIndex()).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                 penJoinComboBox->currentIndex()).toInt());
    paintArea->setPen(QPen(color, width, style, cap, join));
}

void PaintEx::showPenStyle(int stylevalue)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                          stylevalue).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penHoodComboBox->itemData(
                                              penHoodComboBox->currentIndex()).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                 penJoinComboBox->currentIndex()).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void PaintEx::showPenCap(int capValue)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                          penStyleComboBox->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penHoodComboBox->itemData(
                                              capValue).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                 penJoinComboBox->currentIndex()).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void PaintEx::showPenJoin(int joinValue)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                          penStyleComboBox->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penHoodComboBox->itemData(
                                              penHoodComboBox->currentIndex()).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                 joinValue).toInt());
    paintArea->setPen(QPen(color, value, style, cap, join));
}

void PaintEx::showSpreadStyle()
{
    spread = QGradient::Spread(spreadComboBox->itemData(
                                   spreadComboBox->currentIndex()).toInt());
}

void PaintEx::showFileRule()
{
    Qt::FillRule rule = Qt::FillRule(fillModeComboBox->itemData(
                                         fillModeComboBox->currentIndex()).toInt());
    paintArea->setFillRule(rule);
}

void PaintEx::showBrushColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    brushColorFrame->setPalette(QPalette(color));
    showBrush(brushStyleboBox->currentIndex());
}

void PaintEx::showBrush(int brush)
{
    QColor color = brushColorFrame->palette().color(QPalette::Window);
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleboBox->itemData(
                                              brush).toInt());
    if (style == Qt::LinearGradientPattern)
    {
        QLinearGradient linearGradient(0, 0, 400, 400);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, color);
        linearGradient.setColorAt(1.0, Qt::black);
        linearGradient.setSpread(spread);
        paintArea->setBrush(linearGradient);
    }
    else if (style == Qt::RadialGradientPattern)
    {
        QRadialGradient radialGradient(200, 290, 150, 150, 100);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, color);
        radialGradient.setColorAt(1.0, Qt::black);
        radialGradient.setSpread(spread);

        paintArea->setBrush(radialGradient);
    }
    else if (style == Qt::ConicalGradientPattern)
    {
        QConicalGradient conicalGradient(200, 300, 30);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, color);
        conicalGradient.setColorAt(1.0, Qt::black);

        paintArea->setBrush(conicalGradient);
    }
    else if (style == Qt::TexturePattern)
    {
        paintArea->setBrush(QBrush(QPixmap(":/flower.png")));
    }
    else
    {
        paintArea->setBrush(QBrush(color, style));
    }
}
