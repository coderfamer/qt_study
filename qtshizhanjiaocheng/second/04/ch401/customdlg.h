#ifndef CUSTOMDLG_H
#define CUSTOMDLG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class CustomDlg : public QDialog
{
    Q_OBJECT
public:
    CustomDlg(QWidget *parent = 0);

private:
    QPushButton *customBtn;
    QLabel *label;
    QGridLayout *mainLayout;
private slots:
    void showCustomDlg();
};

#endif // CUSTOMDLG_H
