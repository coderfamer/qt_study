#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>

class InputDlg : public QDialog
{
    Q_OBJECT

public:
    InputDlg(QWidget *parent = 0);

private:
    QLabel *nameLabel1;
    QLabel *nameLabel2;
    QPushButton *nameBtn;
    QLabel *ageLabel1;
    QLabel *ageLabel2;
    QPushButton *ageBtn;
    QLabel *sexLabel1;
    QLabel *sexLabel2;
    QPushButton *sexBtn;
    QLabel *scoreLabel1;
    QLabel *scoreLabel2;
    QPushButton *scoreBtn;

    QGridLayout *mainLayout;

private slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeSocre();
};

#endif // INPUTDLG_H
