#include "lbasedialog.h"
#include "iconhelper.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QDebug>


/***********************************LBaseDialogPrivate********************************************************/
class LBaseDialogPrivate : public QObject
{
    Q_OBJECT
public:
    explicit LBaseDialogPrivate(LBaseDialog *parent):QObject(parent),dd(parent),m_isMove(true)
      ,m_buttonPress(false),m_isMax(false),m_pIconLabel(0),
        m_pTitleLabel(0),m_pSkinButton(0),m_pSetButton(0),m_pMinimizeButton(0),m_pMaximizeButton(0)
      ,m_pCloseButton(0),m_titleWidget(0)
    {

    }
    ~LBaseDialogPrivate()
    {

    }

    LBaseDialog* const dd;
    bool m_isMove;
    bool m_buttonPress;
    bool m_isMax;
    QRect m_location;
    QPoint m_mousePoint;
    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QPushButton *m_pSkinButton;
    QPushButton *m_pSetButton;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;
    QWidget *m_titleWidget;
};

#include "lbasedialog.moc"

LBaseDialog::LBaseDialog(QWidget *parent) :
    QDialog(parent),dp(new LBaseDialogPrivate(this))
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    dp->m_location = this->geometry();
    setMouseTracking(true);
}

LBaseDialog::~LBaseDialog()
{

}

void LBaseDialog::createTitleBar(QWidget *iParent, uint iFlag, const QString &iTitle, int iTitleHeight)
{
//    if(isFixed)
//        iParent->setFixedHeight(iTitleHeight);
    dp->m_titleWidget = iParent;
    dp->m_titleWidget->setObjectName("widget_title");
    iParent->setGeometry(0,0,this->width(),iTitleHeight);
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pCloseButton = new QPushButton(iParent);
        dp->m_pCloseButton->setFixedSize(27, 22);
        dp->m_pCloseButton->setObjectName("btn_menuClose");
        IconHelper::Instance()->SetIcon(dp->m_pCloseButton,QChar(0xf00d),10);
        dp->m_pCloseButton->setToolTip("关闭");
    }
    iFlag = iFlag/2;
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pMinimizeButton = new QPushButton(iParent);
        dp->m_pMinimizeButton->setFixedSize(27, 22);
        dp->m_pMinimizeButton->setObjectName("btn_menuHint");
        IconHelper::Instance()->SetIcon(dp->m_pMinimizeButton,QChar(0xf068),10);
        dp->m_pMinimizeButton->setToolTip("最小化");
    }
    iFlag = iFlag/2;
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pMaximizeButton = new QPushButton(iParent);
        dp->m_pMaximizeButton->setFixedSize(27, 22);
        dp->m_pMaximizeButton->setObjectName("btn_menuMax");
        IconHelper::Instance()->SetIcon(dp->m_pMaximizeButton,QChar(0xf096),10);
        dp->m_pMaximizeButton->setToolTip("最大化");
    }
    iFlag = iFlag/2;
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pSkinButton = new QPushButton(iParent);
        dp->m_pSkinButton->setFixedSize(27, 22);
        dp->m_pSkinButton->setObjectName("btn_menuSkin");
        QIcon c(":/image/image/skin.png");
        IconHelper::Instance()->SetIcon(dp->m_pSkinButton,c,QSize(16,16));
        dp->m_pSkinButton->setToolTip("皮肤");
    }
    iFlag = iFlag/2;
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pSetButton = new QPushButton(iParent);
        dp->m_pSetButton->setFixedSize(27,22);
        dp->m_pSetButton->setObjectName("btn_menuSet");
        IconHelper::Instance()->SetIcon(dp->m_pSetButton,QChar(0xf013),10);
        dp->m_pSetButton->setToolTip("设置");
    }
    iFlag = iFlag/2;
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pIconLabel = new QLabel(iParent);
        dp->m_pIconLabel->setFixedSize(20, 20);
        dp->m_pIconLabel->setScaledContents(true);
        dp->m_pIconLabel->setObjectName("lab_icon");
        IconHelper::Instance()->SetIcon(dp->m_pIconLabel, QChar(0xf015),12);
    }
    iFlag = iFlag/2;
    if(iFlag > 0 && iFlag%2 == 1)
    {
        dp->m_pTitleLabel = new QLabel(iParent);
        dp->m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        dp->m_pTitleLabel->setObjectName("lab_title");
        dp->m_pTitleLabel->setText(iTitle);
    }
    QSpacerItem* hSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QHBoxLayout *pLayout = new QHBoxLayout(iParent);
    if(dp->m_pIconLabel)
        pLayout->addWidget(dp->m_pIconLabel);
    pLayout->addSpacing(5);
    if(dp->m_pTitleLabel)
        pLayout->addWidget(dp->m_pTitleLabel);
    pLayout->addSpacerItem(hSpacer);
    if(dp->m_pSkinButton)
        pLayout->addWidget(dp->m_pSkinButton);
    if(dp->m_pSetButton)
        pLayout->addWidget(dp->m_pSetButton);
    if(dp->m_pMinimizeButton)
        pLayout->addWidget(dp->m_pMinimizeButton);
    if(dp->m_pMaximizeButton)
        pLayout->addWidget(dp->m_pMaximizeButton);
    if(dp->m_pCloseButton)
        pLayout->addWidget(dp->m_pCloseButton);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0,0,0,5);

    if(dp->m_pSkinButton)
        connect(dp->m_pSkinButton, SIGNAL(clicked(bool)), this, SLOT(doToolButtonSkin()));
    if(dp->m_pSetButton)
        connect(dp->m_pSetButton, SIGNAL(clicked(bool)), this, SLOT(doToolButtonSet()));
    if(dp->m_pMinimizeButton)
        connect(dp->m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(doToolButtonMin()));
    if(dp->m_pMaximizeButton)
        connect(dp->m_pMaximizeButton,SIGNAL(clicked(bool)),this,SLOT(doToolButtonMax()));
    if(dp->m_pCloseButton)
        connect(dp->m_pCloseButton,SIGNAL(clicked(bool)),this,SLOT(doToolButtonClose()));

    iParent->setLayout(pLayout);
}

void LBaseDialog::setTitle(const QString &iTitle)
{
    dp->m_pTitleLabel->setText(iTitle);
}

void LBaseDialog::setMoveAble(bool isMove)
{
    dp->m_isMove = isMove;
}

void LBaseDialog::setIcon(const QIcon &iIcon)
{
    dp->m_pIconLabel->setPixmap(iIcon.pixmap(20,20));
}

void LBaseDialog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        dp->m_buttonPress = true;
        dp->m_mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void LBaseDialog::mouseMoveEvent(QMouseEvent *e)
{
    if(!dp->m_isMove)
        return;
    if (dp->m_buttonPress && (e->buttons() && Qt::LeftButton) && !dp->m_isMax) {
        this->move(e->globalPos() - dp->m_mousePoint);
        e->accept();
    }
}

void LBaseDialog::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    dp->m_buttonPress = false;
}

void LBaseDialog::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    if(dp->m_titleWidget)
        dp->m_titleWidget->setGeometry(0,0,this->width(),30);
}


void LBaseDialog::doToolButtonClose()
{
    this->close();
}

void LBaseDialog::doToolButtonMax()
{
    if (dp->m_isMax) {
        this->setGeometry(dp->m_location);
        IconHelper::Instance()->SetIcon(dp->m_pMaximizeButton, QChar(0xf096), 10);
        dp->m_pMaximizeButton->setToolTip("最大化");
    } else {
        dp->m_location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::Instance()->SetIcon(dp->m_pMaximizeButton, QChar(0xf079), 10);
        dp->m_pMaximizeButton->setToolTip("还原");
    }
    dp->m_isMax = !dp->m_isMax;
}

void LBaseDialog::doToolButtonMin()
{
    this->showMinimized();
}

void LBaseDialog::doToolButtonSet()
{
    qDebug()<<"setting";
}

void LBaseDialog::doToolButtonSkin()
{
    qDebug() << "skin";
}
