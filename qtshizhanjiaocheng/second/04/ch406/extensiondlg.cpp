#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>

#include "extensiondlg.h"

ExtensionDlg::ExtensionDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Wxtension Dialog"));

    createBaseInfo();
    createDetialInfo();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(baseWidget);
    layout->addWidget(detailWidget);

    layout->setSizeConstraint(QLayout::SetFixedSize);//fixed window size
    layout->setSpacing(10);
}

ExtensionDlg::~ExtensionDlg()
{

}

void ExtensionDlg::createBaseInfo()
{
    baseWidget = new QWidget;

    QLabel *nameLabel = new QLabel(tr("name:"));
    QLineEdit *nameLineEdit = new QLineEdit;

    QLabel *sexLabel = new QLabel(tr("sex:"));
    QComboBox *sexComboBox = new QComboBox;
    sexComboBox->insertItem(0, tr("woman"));
    sexComboBox->insertItem(1, tr("man"));

    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(nameLabel, 0, 0);
    leftLayout->addWidget(nameLineEdit, 0, 1);
    leftLayout->addWidget(sexLabel, 1, 0);
    leftLayout->addWidget(sexComboBox, 1, 1);

    QPushButton *okBtn = new QPushButton(tr("OK"));
    QPushButton *detailBtn = new QPushButton(tr("detial"));
    QDialogButtonBox *btnBox = new QDialogButtonBox(Qt::Vertical);
    btnBox->addButton(okBtn, QDialogButtonBox::ActionRole);
    btnBox->addButton(detailBtn, QDialogButtonBox::ActionRole);

    QHBoxLayout *mainLayout = new QHBoxLayout(baseWidget);
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(btnBox);
    connect(detailBtn, SIGNAL(clicked(bool)), this, SLOT(showDetailInfo()) );
}

void ExtensionDlg::createDetialInfo()
{
    detailWidget = new QWidget;

    QLabel  *ageLabel = new QLabel(tr("age:"));
    QLineEdit *ageLineEdit = new QLineEdit;
    ageLineEdit->setText(tr("30"));

    QLabel *departmentLabel = new QLabel(tr("department"));
    QComboBox *departmentComboBox = new QComboBox;
    departmentComboBox->addItem(tr("department1"));
    departmentComboBox->addItem(tr("department2"));
    departmentComboBox->addItem(tr("department3"));
    departmentComboBox->addItem(tr("department4"));

    QLabel *emailLabel = new QLabel(tr("email:"));
    QLineEdit *emailLineEdit = new QLineEdit;

    QGridLayout *mainLayout = new QGridLayout(detailWidget);
    mainLayout->addWidget(ageLabel, 0, 0);
    mainLayout->addWidget(ageLineEdit, 0, 1);
    mainLayout->addWidget(departmentLabel, 1, 0);
    mainLayout->addWidget(departmentComboBox, 1, 1);
    mainLayout->addWidget(emailLabel, 2, 0);
    mainLayout->addWidget(emailLineEdit, 2, 1);

    detailWidget->hide();
}

void ExtensionDlg::showDetailInfo()
{
    if (detailWidget->isHidden())
        detailWidget->show();
    else
        detailWidget->hide();
}
