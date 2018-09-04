#include "baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("UserInfo"));
    /************左侧**************/
    UserNameLabel = new QLabel(tr("用户名:"));
    UserNameLineEdit = new QLineEdit;
    NameLabel = new QLabel(tr("姓名:"));
    NameLineEdit = new QLineEdit;
    SexLabel = new QLabel(tr("性别:"));
    SexComboBox = new QComboBox;
    SexComboBox->addItem(tr("男"));
    SexComboBox->addItem(tr("女"));
    DepartmentLabel = new QLabel(tr("部门:"));
    DepartmentTextEdit = new QTextEdit;
    AgeLabel = new QLabel(tr("年龄:"));
    AgeLineEdit = new QLineEdit;
    OtherLabel = new QLabel(tr("其他:"));
    OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);//设置控件风格

    LeftLayout = new QGridLayout();//不是主布局，不用指定父窗口
    LeftLayout->addWidget(UserNameLabel, 0, 0);
    LeftLayout->addWidget(UserNameLineEdit, 0, 1);
    LeftLayout->addWidget(NameLabel, 1, 0);
    LeftLayout->addWidget(NameLineEdit, 1, 1);
    LeftLayout->addWidget(SexLabel, 2, 0);
    LeftLayout->addWidget(SexComboBox, 2, 1);
    LeftLayout->addWidget(DepartmentLabel, 3, 0);
    LeftLayout->addWidget(DepartmentTextEdit, 3, 1);
    LeftLayout->addWidget(AgeLabel, 4, 0);
    LeftLayout->addWidget(AgeLineEdit, 4, 1);
    LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);

    /*设置两列分别占用空间的比例，即使对话框大小改变了，两列之间的宽度比依然保持不变*/
    LeftLayout->setColumnStretch(0, 1);
    LeftLayout->setColumnStretch(1, 3);

    /*********************右侧*************************/
    //右上角
    HeadLabel = new QLabel(tr("头像:"));
    HeadIconLabel = new QLabel;
    QPixmap icon(":/images/go.png");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(), icon.height());
    UpdateHeadBtn = new QPushButton(tr("更新"));

    TopRightLayout = new QHBoxLayout();
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadBtn);

    //右下角部分
    IntroductionLabel = new QLabel(tr("个人说明:"));
    IntroductionTextEdit = new QTextEdit;

    RightLayout = new QVBoxLayout();
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);

    /*--------------底部-------------------*/
    OkBtn = new QPushButton(tr("确定"));
    CancelBtn = new QPushButton(tr("取消"));

    BottomLayout = new QHBoxLayout();
    BottomLayout->addStretch();//占位符
    BottomLayout->addWidget(OkBtn);
    BottomLayout->addWidget(CancelBtn);
//    BottomLayout->addStretch();



    /*********************************************/
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addLayout(LeftLayout, 0, 0);
    mainLayout->addLayout(RightLayout, 0, 1);
    mainLayout->addLayout(BottomLayout, 1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
