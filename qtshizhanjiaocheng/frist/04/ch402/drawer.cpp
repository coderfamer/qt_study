#include "drawer.h"

#include <QGroupBox>
#include <QVBoxLayout>

Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
    :QToolBox(parent, f)
{
    setWindowTitle(tr("My QQ"));

    toolBtn1_1 = new QToolButton;//创建一个toolbutton实例
    toolBtn1_1->setText(tr("张三"));//设置按钮文字
    //toolBtn1_1->setIcon(QPixmap("E:/qt_study/qtshizhanjiaocheng/04/ch402/images/test.png"));
    toolBtn1_1->setIcon(QPixmap(":/images/test.png"));//设置按钮图标
    toolBtn1_1->setIconSize(QPixmap(":/images/test.png").size());//设置按钮大小
    toolBtn1_1->setAutoRaise(true);//当鼠标离开的时候，按钮自动恢复为弹起状态
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置文字和图标的显示方式

    toolBtn1_2 = new QToolButton;
    toolBtn1_2->setText(tr("李四"));
    toolBtn1_2->setIcon(QPixmap(":/images/user1.png"));
    toolBtn1_2->setIconSize(QPixmap(":/images/user1.png").size());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 = new QToolButton;
    toolBtn1_3->setText(tr("王五"));
    toolBtn1_3->setIcon(QPixmap(":/images/user.png"));
    toolBtn1_3->setIconSize(QPixmap(":/images/user.png").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_4 = new QToolButton;
    toolBtn1_4->setText(tr("汐汐"));
    toolBtn1_4->setIcon(QPixmap(":/images/user2.png"));
    toolBtn1_4->setIconSize(QPixmap(":/images/user2.png").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_5 = new QToolButton;
    toolBtn1_5->setText(tr("西西"));
    toolBtn1_5->setIcon(QPixmap(":/images/user3.png"));
    toolBtn1_5->setIconSize(QPixmap(":/images/user3.png").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    QGroupBox *groupBox1 = new QGroupBox;//
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(15);
    layout1->setAlignment(Qt::AlignCenter);
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);
    layout1->addStretch();
    /*按钮之后插入一个占位符，使得所有按钮能够靠上对齐，并且在整个抽屉
    *大小发生变化的时候，保证按钮的大小不发生变化*/

    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText(tr("陌生人"));
    toolBtn2_1->setIcon(QPixmap(":/images/user.png"));
    toolBtn2_1->setIconSize(QPixmap(":/images/user.png").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText(tr("权哥"));
    toolBtn2_2->setIcon(QPixmap(":/images/user1.png"));
    toolBtn2_2->setIconSize(QPixmap(":/images/user1.png").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2 = new QGroupBox;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(15);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);
    layout2->addStretch();

    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(tr("陌生人"));
    toolBtn3_1->setIcon(QPixmap(":/images/user4.png"));
    toolBtn3_1->setIconSize(QPixmap(":/images/user4.png").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn3_2 = new QToolButton;
    toolBtn3_2->setText(tr("权哥"));
    toolBtn3_2->setIcon(QPixmap(":/images/user2.png"));
    toolBtn3_2->setIconSize(QPixmap(":/images/user2.png").size());
    toolBtn3_2->setAutoRaise(true);
    toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox3 = new QGroupBox;
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(15);
    layout3->setAlignment(Qt::AlignCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);
    layout3->addStretch();

    this->addItem((QWidget *)groupBox1, tr("我的好友"));
    this->addItem((QWidget *)groupBox2, tr("陌生人"));
    this->addItem((QWidget *)groupBox3, tr("黑名单"));
}
