#ifndef PALETTE_H
#define PALETTE_H

#include <QDialog>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QPalette>

class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = 0);
    ~Palette();

    void createLeftFrame();
    void createRgithFrame();
    void fillColorList(QComboBox *combobox);

private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();

private:
    //left
    QFrame *leftFrame;
    QLabel *windowLabel;
    QComboBox *windowComboBox;
    QLabel *windowTextLabel;
    QComboBox *windowTextComboBox;
    QLabel *buttonLabel;
    QComboBox *buttonComboBox;
    QLabel *buttonTextLabel;
    QComboBox *buttonTextComboBox;
    QLabel *baseLabel;
    QComboBox *baseComboBox;

    //right
    QFrame *rightFrame;
    QLabel *choseLabel;
    QComboBox *choseComboBox;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QTextEdit *textEdit;

    QPushButton *confirmBtn;
    QPushButton *cancelBtn;

    //main layout
    QHBoxLayout *mainLayout;
};

#endif // PALETTE_H
