#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = 0);

private:
    QLabel *NationalLabel;
    QComboBox *NationalComBox;
    QLabel *ProvinceLabel;
    QComboBox *ProvinceComBox;
    QLabel *CityLabel;
    QLineEdit *CityLineEdit;
    QLabel *IntroductLabel;
    QTextEdit *IntroductTextEdit;


    QGridLayout *mainLayout;
signals:

public slots:
};

#endif // DETAIL_H
