#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>

class MsgBoxDlg : public QDialog
{
    Q_OBJECT

public:
    MsgBoxDlg(QWidget *parent = 0);

private:
    QLabel *label;
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warnintBtn;
    QPushButton *cirticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aoubtQtBtn;

    QGridLayout *mainLayout;
private slots:
    void showQuestionMsg();
    void showInformationMsg();
    void showWarnintMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();
};

#endif // MSGBOXDLG_H
