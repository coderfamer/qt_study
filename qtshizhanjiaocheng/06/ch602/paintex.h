#ifndef PAINTEX_H
#define PAINTEX_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <QGradient>

#include "paintarea.h"

class PaintEx : public QWidget
{
    Q_OBJECT

public:
    PaintEx(QWidget *parent = 0);
    ~PaintEx();
private:
    PaintArea *paintArea;

    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    QLabel *penWidthLabel;
    QSpinBox *penWidthSpinBox;
    QLabel *penColorLabel;
    QFrame *penColorFrame;
    QPushButton *penColorBtn;
    QLabel *penStyleLabel;
    QComboBox *penStyleComboBox;
    QLabel *penCapLabel;
    QComboBox *penCapComboBox;
    QLabel *penJoinLabel;
    QComboBox *penJoinComboBox;
    QLabel *fillRuleLabel;
    QComboBox *fillRuleComboBox;
    QLabel *spreadLabel;
    QComboBox *spreadComboBox;
    QGradient::Spread spread;
    QLabel *brushStyleLabel;
    QComboBox *brushStyleComboBox;
    QLabel *brushColorLabel;
    QFrame *brushColorFrame;
    QPushButton *BrushColorBtn;

    QGridLayout *rightLayout;

protected slots:
    void ShowShape(int);
    void ShowPenColor();
    void ShowPenWidth(int);
    void ShowPenStyle(int);
    void ShowPenCap(int);
    void ShowPenJoin(int);
    void ShowFillRule();
    void ShowSpreadStyle();
    void ShowBrushColor();
    void ShowBrush(int);
};

#endif // PAINTEX_H
