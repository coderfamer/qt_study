#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

#include "inptudlg.h"
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
    QGridLayout *mainLayout;
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
    QPushButton *inputBtn;
    QPushButton *msgBtn;
    QPushButton *customBtn;
    QLabel *label;

    InptuDlg *inputDlg;
    MsgBoxDlg *msgBoxDlg;

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();
};

#endif // DIALOG_H
