#ifndef CONTACT_H
#define CONTACT_H

#include "public.h"

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);

private:
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QLabel *postLabel;
    QLineEdit *postLineEdit;
    QLabel *mobileLabel;
    QLineEdit *mobileLineEdit;
    QCheckBox *mobileCheckBox;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;

    QGridLayout *mainLayout;

signals:

public slots:
};

#endif // CONTACT_H
