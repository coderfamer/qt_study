#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    NationalLabel = new QLabel(tr("国家/地址:"));
    NationalComBox = new QComboBox;
    NationalComBox->insertItem(0, tr("中国"));
    NationalComBox->insertItem(0, tr("美国"));
    NationalComBox->insertItem(0, tr("英国"));
    NationalComBox->insertItem(0, tr("德国"));

    ProvinceLabel = new QLabel(tr("省份:"));
    ProvinceComBox = new QComboBox;
    ProvinceComBox->insertItem(0, tr("安徽省"));
    ProvinceComBox->insertItem(1, tr("山东省"));
    ProvinceComBox->insertItem(2, tr("上海市"));

    CityLabel = new QLabel(tr("城市:"));
    CityLineEdit = new QLineEdit;

    IntroductLabel = new QLabel(tr("个人说明:"));
    IntroductTextEdit = new QTextEdit;

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(NationalLabel, 0, 0);
    mainLayout->addWidget(NationalComBox, 0, 1);
    mainLayout->addWidget(ProvinceComBox, 1, 1);
    mainLayout->addWidget(ProvinceLabel, 1, 0);
    mainLayout->addWidget(CityLabel, 2, 0);
    mainLayout->addWidget(CityLineEdit, 2, 1);
    mainLayout->addWidget(IntroductLabel, 3, 0);
    mainLayout->addWidget(IntroductTextEdit, 3, 1);
}
