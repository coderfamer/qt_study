#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include "public.h"

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = 0);

private:
    QLabel *nationLabel;
    QComboBox *nationComBox;
    QLabel *provinceLabel;
    QComboBox *provinceComBox;
    QLabel *cityLabel;
    QLineEdit *cityLineEdit;
    QLabel  *descriptionLabel;
    QTextEdit *descriptionTextEdit;

    QGridLayout *mainLayout;
signals:

public slots:
};

#endif // DETAIL_H
