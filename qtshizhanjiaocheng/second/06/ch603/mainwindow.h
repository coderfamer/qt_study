#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QFrame>
#include <QToolButton>
#include <QToolBar>
#include "drawwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createToolBar();
public slots:
    //void showColor();
private:
    DrawWidget *drawWidget;

    QLabel *lineStyleLabel;
    QComboBox *lineStyleComboBox;
    QLabel *lineWidthLabel;
    QSpinBox *lineWidthSpinBox;
    QToolButton *colorBtn;



    QToolButton *delBtn;

    QToolBar toolBar;

};

#endif // MAINWINDOW_H
