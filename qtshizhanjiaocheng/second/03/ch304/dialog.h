#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    //左侧
    QLabel *userNameLabel;
    QLineEdit *userName;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *sexLabel;
    QComboBox *sexComboBox;
    QLabel *departmentLabel;
    QTextEdit *departmentTextEdit;
    QLabel *ageLabel;
    QLineEdit *agelLineEdit;
    QLabel *otherLabel;


    //右侧
    QLabel *headLabel;
    QLabel *headIconLabel;
    QPushButton *updateHeadBtn;
    QLabel *descriptionLabel;
    QTextEdit *descriptionTextEdit;

    //底部
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    QGridLayout *mainLayout;
    QGridLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *topRightLayout;
    QHBoxLayout *bottomLayout;
};

#endif // DIALOG_H
