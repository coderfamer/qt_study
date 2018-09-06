#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>

#include "inputdlg.h"
#include "msgboxdlg.h"
#include "customdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    QPushButton *inputBtn;
    InputDlg *inputDlg;

    QPushButton *msgBtn;
    MsgBoxDlg *msgDlg;

    QPushButton *customBtn;
    CustomDlg *customDlg;

    QGridLayout *mainLayout;
private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();
};

#endif // DIALOG_H
