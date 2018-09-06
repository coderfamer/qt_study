#include "contact.h"

Contact::Contact(QWidget *parent) :
    QWidget(parent)
{
    QLabel *emailLabel = new QLabel(tr("电子邮件:"));
    QLineEdit *emailLineEdit = new QLineEdit();
    QLabel *addressLabel = new QLabel(tr("联系地址:"));
    QLineEdit *addressLineEdit = new QLineEdit;
    QLabel *postLabel = new QLabel(tr("邮政编码:"));
    QLineEdit *postLineEdit = new QLineEdit;
    QLabel *mobileLabel = new QLabel(tr("移动电话:"));
    QLineEdit *mobileLineEdit = new QLineEdit;
    QCheckBox *mobileCheckBox = new QCheckBox(tr("接收留言:"));
    QLabel *phoneLabel = new QLabel(tr("办公电话:"));
    QLineEdit *phoneLineEdit = new QLineEdit;

    QGridLayout *mainLayout = new QGridLayout(this);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(emailLabel, 0, 0);
    mainLayout->addWidget(emailLineEdit, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0);
    mainLayout->addWidget(addressLineEdit, 1, 1);
    mainLayout->addWidget(postLabel, 2, 0);
    mainLayout->addWidget(postLineEdit, 2, 1);
    mainLayout->addWidget(mobileLabel, 3, 0);
    mainLayout->addWidget(mobileLineEdit, 3, 1);
    mainLayout->addWidget(mobileCheckBox, 3, 2);
    mainLayout->addWidget(phoneLabel, 4, 0);
    mainLayout->addWidget(phoneLineEdit, 4, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
