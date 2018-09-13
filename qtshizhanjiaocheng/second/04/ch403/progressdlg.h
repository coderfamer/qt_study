#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>

class ProgressDlg : public QDialog
{
    Q_OBJECT

public:
    ProgressDlg(QWidget *parent = 0);
    ~ProgressDlg();

private slots:
    void startProgress();
private:
    QLabel *fileNumLabel;
    QLineEdit *fileNumLineEdit;
    QLabel *typeLabel;
    QComboBox *typeComboBox;
    QProgressBar *fileProgressBar;
    QPushButton *beginBtn;

    QGridLayout *mainLayout;

};

#endif // PROGRESSDLG_H
