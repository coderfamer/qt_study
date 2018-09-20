#ifndef PAINTEX_H
#define PAINTEX_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QSpinBox>
#include <QColorDialog>
#include "paintarea.h"

class PaintEx : public QWidget
{
    Q_OBJECT

public:
    PaintEx(QWidget *parent = 0);
    ~PaintEx();

private slots:
    void showShape(int value);
    void showPenColor();
    void showPenWidth(int width);
    void showPenStyle(int style);
    void showPenCap(int cap);
    void showPenJoin(int join);
    void showSpreadStyle();
    void showFileRule();
    void showBrushColor();
    void showBrush(int brush);

private:
    PaintArea *paintArea;
    QGradient::Spread spread;

    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    QLabel *penColorLabel;
    QFrame *penColorFrame;
    QPushButton *penColorBtn;
    QLabel *penWidthLabel;
    QSpinBox *penWidthSpinBox;
    QLabel *penStyleLabel;
    QComboBox *penStyleComboBox;
    QLabel *penHoodLabel;
    QComboBox *penHoodComboBox;
    QLabel *penJoinLabel;
    QComboBox *penJoinComboBox;
    QLabel *fillModeLabel;
    QComboBox *fillModeComboBox;
    QLabel *spreadLabel;
    QComboBox *spreadComboBox;
    QLabel *brushColorLabel;
    QFrame *brushColorFrame;
    QPushButton *brushColorBtn;
    QLabel *brushStyleLabel;
    QComboBox *brushStyleboBox;

    QHBoxLayout *mainLayout;

};

#endif // PAINTEX_H
