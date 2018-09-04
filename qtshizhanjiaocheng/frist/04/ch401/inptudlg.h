#ifndef INPTUDLG_H
#define INPTUDLG_H

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>


class InptuDlg : public QDialog
{
    Q_OBJECT
public:
    InptuDlg(QWidget* parent=0);
private slots:
    void ChangeName();
    void ChangeSex();
    void ChangeAge();
    void ChangeScore();
private:
    QLabel *nameLabel1;
    QLabel *sexLabel1;
    QLabel *ageLabel1;
    QLabel *scoreLabel1;
    QLabel *nameLabel2;
    QLabel *sexLabel2;
    QLabel *ageLabel2;
    QLabel *scoreLabel2;
    QPushButton *nameBtn;
    QPushButton *sexBtn;
    QPushButton *ageBtn;
    QPushButton *scoreBtn;

    QGridLayout *mainLayout;
};

#endif // INPTUDLG_H
