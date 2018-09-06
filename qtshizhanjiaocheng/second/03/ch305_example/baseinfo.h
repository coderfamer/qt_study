#ifndef BASEINFO_H
#define BASEINFO_H

#include "public.h"

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = 0);

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
signals:

public slots:
};

#endif // BASEINFO_H
