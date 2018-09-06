#include <QPixmap>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *mainLayout = new QGridLayout(this);
    QGridLayout *leftLayout = new QGridLayout();
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QHBoxLayout *topRightLayout = new QHBoxLayout;
    QHBoxLayout *bottomLayout = new QHBoxLayout();

    //左侧
    QLabel *userNameLabel = new QLabel(tr("用户名:"));
    QLineEdit *userNameLineEdit = new QLineEdit();
    QLabel *nameLabel = new QLabel(tr("姓名:"));
    QLineEdit *nameLineEdit = new QLineEdit;
    QLabel *sexLabel = new QLabel(tr("性别:"));
    QComboBox *sexComboBox = new QComboBox;
    QLabel *departmentLabel = new QLabel(tr("部门:"));
    QTextEdit *departmentTextEdit = new QTextEdit;
    QLabel *ageLabel = new QLabel(tr("年龄:"));
    QLineEdit *agelLineEdit = new QLineEdit;
    QLabel *otherLabel = new QLabel(tr("备注:"));
    otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //左侧
    leftLayout->addWidget(userNameLabel, 0, 0);
    leftLayout->addWidget(userNameLineEdit, 0, 1);
    leftLayout->addWidget(nameLabel, 1, 0);
    leftLayout->addWidget(nameLineEdit, 1, 1);
    leftLayout->addWidget(sexLabel, 2, 0);
    leftLayout->addWidget(sexComboBox, 2, 1);
    leftLayout->addWidget(departmentLabel, 3, 0);
    leftLayout->addWidget(departmentTextEdit, 3, 1);
    leftLayout->addWidget(ageLabel, 4, 0);
    leftLayout->addWidget(agelLineEdit, 4, 1);
    leftLayout->addWidget(otherLabel, 5, 0, 1, 2);
    leftLayout->setColumnStretch(0, 1);
    leftLayout->setColumnStretch(1, 3);
    //右侧
    QLabel *headLabel = new QLabel(tr("头像:"));
    QLabel *headIconLabel = new QLabel;
    QPixmap img(":/img/sex.png");
    headIconLabel->setPixmap(img);
    headIconLabel->resize(img.width(), img.height());
    QPushButton *updateHeadBtn = new QPushButton(tr("更新"));
    QLabel *descriptionLabel = new QLabel(tr("个人说明:"));
    QTextEdit *descriptionTextEdit = new QTextEdit;

    //右侧
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(headLabel);
    topRightLayout->addWidget(headIconLabel);
    topRightLayout->addWidget(updateHeadBtn);
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(descriptionLabel);
    rightLayout->addWidget(descriptionTextEdit);

    //底部
    QPushButton *okBtn = new QPushButton(tr("确定"));
    QPushButton *cancelBtn = new QPushButton(tr("取消"));

    //底部
    bottomLayout->addStretch();
    bottomLayout->addWidget(okBtn);
    bottomLayout->addWidget(cancelBtn);

    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);
    mainLayout->addLayout(bottomLayout, 1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

Dialog::~Dialog()
{

}
