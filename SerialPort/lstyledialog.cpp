#include "lstyledialog.h"
#include "lbasedialog.h"
#include <QMutex>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>

LStyleDialog::LStyleDialog(QObject *iParent)
{
    Q_UNUSED(iParent)
}

LStyleDialog *LStyleDialog::instance()
{
    static QMutex mutex;
    static LStyleDialog *gInstance = NULL;
    if (!gInstance) {
        QMutexLocker locker(&mutex);
        if (!gInstance) {
            gInstance = new LStyleDialog();
        }
    }
    return gInstance;
}

void LStyleDialog::aboutUs(QWidget *iParent)
{
    LBaseDialog *lsDlg = new LBaseDialog(iParent);
    lsDlg->setObjectName("aboutUsDlg");
    QWidget *title_widget = new QWidget(lsDlg);
    lsDlg->createTitleBar(title_widget,LBaseDialog::ToolClose | LBaseDialog::ToolIcon  | LBaseDialog::ToolTitle,"关于我们");
    lsDlg->resize(300,180);
    lsDlg->setModal(true);
    QSpacerItem *spacer = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);
    QPushButton *btton = new QPushButton("确定");
    btton->setFixedWidth(100);
    connect(btton,SIGNAL(clicked()),lsDlg,SLOT(close()));

    QHBoxLayout *topHbox = new QHBoxLayout();
    QLabel *about_icon = new QLabel;
    about_icon->setObjectName("about_iconLabel");
    QLabel *context = new QLabel("Commix 工业控制串口调试工具\n\n版本：1.0  运行于 Windows/linux\n\n 张贺飞 543046154@qq.com");
    context->setObjectName("context_label");
    topHbox->addWidget(about_icon);
    topHbox->addWidget(context);
    topHbox->setContentsMargins(10,10,10,10);


    QHBoxLayout *bottomHbox = new QHBoxLayout();
    bottomHbox->addItem(spacer);
    bottomHbox->addWidget(btton);
    bottomHbox->setContentsMargins(10,10,10,10);

    QVBoxLayout *mainBox = new QVBoxLayout();
    mainBox->addWidget(title_widget);
    mainBox->addLayout(topHbox);
    mainBox->addLayout(bottomHbox);
    mainBox->setContentsMargins(0,0,0,5);
    lsDlg->setLayout(mainBox);
    lsDlg->show();
}

void LStyleDialog::error(const QString &iText, QWidget *iParent, const QString &iTitle, int iAutoCloseSeconds)
{
    Q_UNUSED(iAutoCloseSeconds)
    LBaseDialog *lsDlg = new LBaseDialog(iParent);
    lsDlg->setObjectName("aboutUsDlg");
    QWidget *title_widget = new QWidget(lsDlg);
    lsDlg->createTitleBar(title_widget,LBaseDialog::ToolClose | LBaseDialog::ToolIcon  | LBaseDialog::ToolTitle,iTitle);
    lsDlg->resize(300,180);
    lsDlg->setModal(true);
    QSpacerItem *spacer = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);
    QPushButton *btton = new QPushButton("确定");
    btton->setFixedWidth(100);
    connect(btton,SIGNAL(clicked()),lsDlg,SLOT(close()));
    QSpacerItem *vspacer = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);

    QHBoxLayout *topHbox = new QHBoxLayout();
    QLabel *context = new QLabel("   "+iText);
    context->setFixedSize(200,80);
    QLabel *error_label = new QLabel;
    error_label->setFixedSize(80,80);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(context);
    vbox->addItem(vspacer);
    error_label->setObjectName("error_label");

    context->setObjectName("context_label");
    topHbox->addWidget(error_label);
    topHbox->addLayout(vbox);
    topHbox->setContentsMargins(10,5,5,5);


    QHBoxLayout *bottomHbox = new QHBoxLayout();
    bottomHbox->addItem(spacer);
    bottomHbox->addWidget(btton);

    QGroupBox * groupBox = new QGroupBox();

    QVBoxLayout *mainBox = new QVBoxLayout();
    QVBoxLayout *bottomVbox = new QVBoxLayout();
    bottomVbox->addLayout(topHbox);
    bottomVbox->addLayout(bottomHbox);
    groupBox->setLayout(bottomVbox);


    QVBoxLayout *group_box = new QVBoxLayout();
    group_box->addWidget(groupBox);
    group_box->setContentsMargins(10,10,5,5);

    mainBox->addWidget(title_widget);
    mainBox->addLayout(group_box);
    mainBox->setContentsMargins(0,0,0,0);
    lsDlg->setLayout(mainBox);
    lsDlg->show();
}
