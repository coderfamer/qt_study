#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{

    QStringList nationStr, provStr;
    nationStr << "中国" << "印度" << "美国" << "米国" << "巴拿马" ;
    provStr << "中国" << "印度" << "美国" << "米国" << "巴拿马" ;
    QLabel *nationLabel = new QLabel(tr("国家/地址:"));
    QComboBox *nationComBox = new QComboBox;
    nationComBox->addItems(nationStr);
    QLabel *provinceLabel = new QLabel(tr("省份:"));
    QComboBox *provinceComBox = new QComboBox;
    provinceComBox->addItems(provStr);
    QLabel *cityLabel = new QLabel(tr("城市:"));
    QLineEdit *cityLineEdit = new QLineEdit;
    QLabel  *descriptionLabel = new QLabel(tr("个人说明:"));
    QTextEdit *descriptionTextEdit = new QTextEdit;

    QGridLayout *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(nationLabel, 0, 0);
    mainLayout->addWidget(nationComBox, 0, 1);
    mainLayout->addWidget(provinceLabel, 1, 0);
    mainLayout->addWidget(provinceComBox, 1, 1);
    mainLayout->addWidget(cityLabel, 2, 0);
    mainLayout->addWidget(cityLineEdit, 2, 1);
    mainLayout->addWidget(descriptionLabel, 3, 0);
    mainLayout->addWidget(descriptionTextEdit, 3, 1);

}
