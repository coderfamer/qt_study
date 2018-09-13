#include "drawer.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QPixmap>

Drawer::Drawer(QWidget *parent, Qt::WindowFlags f) :
    QToolBox(parent, f)
{
    setWindowTitle(tr("My QQ"));


    toolBtn1_1 = new QToolButton;
    toolBtn1_1->setText(tr("hang"));
    toolBtn1_1->setIcon(QPixmap(":/11.png"));
    toolBtn1_1->setIconSize(QPixmap(":/11.png").size());
    toolBtn1_1->setAutoRaise(true);
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_2 = new QToolButton;
    toolBtn1_2->setText(tr("lirong"));
    toolBtn1_2->setIcon(QPixmap(":/12.png"));
    toolBtn1_2->setIconSize(QPixmap(":/12.png").size());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 = new QToolButton;
    toolBtn1_3->setText(tr("jielun"));
    toolBtn1_3->setIcon(QPixmap(":/13.png"));
    toolBtn1_3->setIconSize(QPixmap(":/13.png").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_4 = new QToolButton;
    toolBtn1_4->setText(tr("xingchi"));
    toolBtn1_4->setIcon(QPixmap(":/14.png"));
    toolBtn1_4->setIconSize(QPixmap(":/14.png").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_5 = new QToolButton;
    toolBtn1_5->setText(tr("long"));
    toolBtn1_5->setIcon(QPixmap(":/15.png"));
    toolBtn1_5->setIconSize(QPixmap(":/15.png").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox1 = new QGroupBox;
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignCenter);
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);
    layout1->addStretch();

    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText(tr("temulup"));
    toolBtn2_1->setIcon(QPixmap(":/21.png"));
    toolBtn2_1->setIconSize(QPixmap(":/21.png").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText(tr("aobama"));
    toolBtn2_2->setIcon(QPixmap(":/22.png"));
    toolBtn2_2->setIconSize(QPixmap(":/22.png").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2 = new QGroupBox;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);
    layout2->addStretch();


    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(tr("lisa"));
    toolBtn3_1->setIcon(QPixmap(":/31.png"));
    toolBtn3_1->setIconSize(QPixmap(":/31.png").size());
    //当鼠标离开时，按钮自动恢复为弹起状态
    toolBtn3_1->setAutoRaise(true);
    //设置图标和文字显示方式
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn3_2 = new QToolButton;
    toolBtn3_2->setText(tr("jack"));
    toolBtn3_2->setIcon(QPixmap(":/32.png"));
    toolBtn3_2->setIconSize(QPixmap(":/32.png").size());
    toolBtn3_2->setAutoRaise(true);
    toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    QGroupBox *groupBox3 = new QGroupBox;
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);
    layout3->addStretch();


    this->addItem((QWidget*)groupBox1, tr("friend"));
    this->addItem((QWidget*)groupBox2, tr("stranger"));
    this->addItem((QWidget*)groupBox3, tr("blacklist"));
}
