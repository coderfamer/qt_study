#include "commix.h"
#include "lfilesystem.h"
#include "ldataconverter.h"
#include "lcombobox.h"
#include "iconhelper.h"
#include "device.h"
#include "myhelper.h"
#include "lstyledialog.h"
#include "mythread.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QPicture>
#include <QDesktopWidget>
#include <QSpacerItem>
#include <QGraphicsDropShadowEffect>
#include <QGroupBox>
#include <QFormLayout>
#include <QSerialPortInfo>
#include <QTextEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTime>
#include <QCheckBox>
#include <QSpinBox>
#include <QMetaObject>
#include <QtConcurrent/QtConcurrent>
#include <QEventLoop>
#include <QMutex>
#include <unistd.h>

/*************************************LSkinLabel********************************************************/

class LSkinLabel : public QLabel
{
    Q_OBJECT
public:
    explicit LSkinLabel(QWidget *parent = 0):QLabel(parent),m_checkLabel(0),m_ischeck(false),m_isMousePress(false)
    {
        initLayout();
    }
    void setChecked(bool isChecked);
signals:
    void clicked(const QString &iStyle);
    void leaveEvent();
public slots:
    void doSkinChecked();
protected slots:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QLabel *m_checkLabel;
    bool m_ischeck;
    bool m_isMousePress;

    void initLayout();
};

void LSkinLabel::doSkinChecked()
{
    if(m_ischeck)
        return;
    else
        m_ischeck = true;
    m_checkLabel->setVisible(true);
}

void LSkinLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    if(m_ischeck)
        return;
    myHelper::SetStyle(this->objectName().replace("Skin",""));
    m_checkLabel->setVisible(true);
}

void LSkinLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        m_isMousePress = true;
}

void LSkinLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(m_isMousePress)
        emit clicked(this->objectName());
    m_isMousePress = false;
}

void LSkinLabel::setChecked(bool isChecked)
{
    m_ischeck = isChecked;
    if(m_ischeck)
        m_checkLabel->setVisible(true);
    else
        m_checkLabel->setVisible(false);
}

void LSkinLabel::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    if(m_ischeck)
        return;
    m_checkLabel->setVisible(false);
    emit leaveEvent();
}

void LSkinLabel::initLayout()
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::gray);
    shadow_effect->setBlurRadius(8);
    this->setGraphicsEffect(shadow_effect);

    QSpacerItem *vspacer = new QSpacerItem(20,20,QSizePolicy::Fixed,QSizePolicy::Expanding);
    QSpacerItem *hspaver = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Fixed);
    m_checkLabel = new QLabel(this);
    m_checkLabel->setVisible(false);
    connect(this,SIGNAL(clicked(QString)),this,SLOT(doSkinChecked()));
    QIcon c(":/image/image/right.png");
    IconHelper::Instance()->SetIcon(m_checkLabel,c,QSize(15,15));
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addSpacerItem(hspaver);
    hbox->addWidget(m_checkLabel);
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addSpacerItem(vspacer);
    vbox->addLayout(hbox);
    this->setLayout(vbox);
}

/**************************LSkinDialog***************************************************/
class LSkinDialog : public LBaseDialog
{
    Q_OBJECT
public :
    explicit LSkinDialog(QWidget *parent = 0);

public  slots:
    void loadStyle();
    void styleChanged(const QString &iStyle);

protected slots:
    void leaveEvent(QEvent *event);

private:
    void initLayout();
    QWidget *m_widget_title;
    QString m_currentSkin;
    QMap<QString,QMap<LSkinLabel*,bool> > m_skinLabelMap;
};

LSkinDialog::LSkinDialog(QWidget *parent ):LBaseDialog(parent),m_widget_title(0),m_currentSkin("blueSkin")
{
    initLayout();

    QMap<LSkinLabel *,bool> map_ = m_skinLabelMap.value(m_currentSkin);
    map_.insert(map_.keys().at(0),true);
    m_skinLabelMap.insert(m_currentSkin,map_);

    LSkinLabel * skinLabel = m_skinLabelMap.value("blueSkin").keys().at(0);
    skinLabel->setChecked(true);
}

void LSkinDialog::initLayout()
{
    setMoveAble(false);
    this->setFixedSize(200,150);
    this->setObjectName("skinDialog");
    m_widget_title = new QWidget(this);
    m_widget_title->setObjectName("skin_title");
    m_widget_title->setGeometry(0,0,this->geometry().width(),30);
    createTitleBar(m_widget_title,ToolTitle,"更换皮肤");

    LSkinLabel *blackSkin = new LSkinLabel(this);
    blackSkin->setObjectName("blackSkin");
    connect(blackSkin,SIGNAL(leaveEvent()),this,SLOT(loadStyle()));
    connect(blackSkin,SIGNAL(clicked(QString)),this,SLOT(styleChanged(QString)));

    LSkinLabel *blueSkin = new LSkinLabel(this);
    blueSkin->setObjectName("blueSkin");
    connect(blueSkin,SIGNAL(leaveEvent()),this,SLOT(loadStyle()));
    connect(blueSkin,SIGNAL(clicked(QString)),this,SLOT(styleChanged(QString)));

    LSkinLabel *graySkin = new LSkinLabel(this);
    graySkin->setObjectName("graySkin");
    connect(graySkin,SIGNAL(leaveEvent()),this,SLOT(loadStyle()));
    connect(graySkin,SIGNAL(clicked(QString)),this,SLOT(styleChanged(QString)));

    LSkinLabel *navySkin = new LSkinLabel(this);
    navySkin->setObjectName("navySkin");
    connect(navySkin,SIGNAL(leaveEvent()),this,SLOT(loadStyle()));
    connect(navySkin,SIGNAL(clicked(QString)),this,SLOT(styleChanged(QString)));

    QMap<LSkinLabel *,bool> map;
    map.insert(blackSkin,false);
    m_skinLabelMap.insert("blackSkin",map);
    map.clear();
    map.insert(blueSkin,false);
    m_skinLabelMap.insert("blueSkin",map);
    map.clear();
    map.insert(graySkin,false);
    m_skinLabelMap.insert("graySkin",map);
    map.clear();
    map.insert(navySkin,false);
    m_skinLabelMap.insert("navySkin",map);

    QVBoxLayout *leftvbox = new QVBoxLayout();
    leftvbox->addWidget(blackSkin);
    leftvbox->addWidget(blueSkin);
    QVBoxLayout *rightvbox = new QVBoxLayout();
    rightvbox->addWidget(graySkin);
    rightvbox->addWidget(navySkin);

    QHBoxLayout *bottombox = new QHBoxLayout();
    bottombox->addLayout(leftvbox);
    bottombox->addLayout(rightvbox);

    QVBoxLayout *mainbox = new QVBoxLayout(this);
    mainbox->addWidget(m_widget_title);

    mainbox->addLayout(bottombox);
    mainbox->setContentsMargins(0,0,0,0);
    this->setLayout(mainbox);

}

void LSkinDialog::loadStyle()
{
    QString ss = m_currentSkin;
    myHelper::SetStyle(ss.replace("Skin",""));
}

void LSkinDialog::styleChanged(const QString& iStyle)
{
    if(m_currentSkin != iStyle && !m_currentSkin.isEmpty())
    {
        LSkinLabel * skinLabel = m_skinLabelMap.value(m_currentSkin).keys().at(0);
        skinLabel->setChecked(false);
        QMap<LSkinLabel *,bool> map;
        map.insert(skinLabel,false);
        m_skinLabelMap.insert(m_currentSkin,map);

        m_currentSkin = iStyle;
        skinLabel = m_skinLabelMap.value(m_currentSkin).keys().at(0);
        skinLabel->setChecked(true);
        map.clear();
        map.insert(skinLabel,true);
        m_skinLabelMap.insert(m_currentSkin,map);
        loadStyle();
    }

}

void LSkinDialog::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    this->hide();
}


/**************************CommixPrivate*************************************/
class CommixPrivate : public QObject
{
    Q_OBJECT
public:
    explicit CommixPrivate(Commix *parent):QObject(parent),dd(parent),m_widgetTitle(0),m_skinDialog(0),
        m_openButton(0),m_startTestBtn(0),m_sendBtn(0),m_isOpen(false),m_isTest(false),m_portCombox(0),m_baudRateCombox(0),m_parityCombox(0),
        m_dataCombox(0),m_stopCombox(0),m_controlCombox(0),m_inputHex_radioBtn(0),
        m_inputAsc_radioBtn(0),m_outputHex_radioBtn(0),m_outputAsc_radioBtn(0),
        m_moudbusCheckBox(0),m_regexpCheckBox(0),m_inputTextEdit(0),m_outTextEdit(0),
        m_testTextEdit(0), m_configTextEdit(0),m_timeSpinbox(0),m_dateSpinbox(0),m_testResultLabel(0),
        m_device(0),m_thread(0),m_sendCount(0),m_recvCount(0)
    {
        m_time = QTime(0,0,0,0);
        m_device = Device::instance();
        connect(m_device,SIGNAL(recvData2(QByteArray &)),this,SLOT(recvData(QByteArray &)));
    }

    void formInCenter(QWidget *frm);
    QMenu *createActions();
    QVariantList portList();
    QVariantList baudRateList();
    QVariantList parityList();
    QVariantList dataBits();
    QVariantList stopBits();
    QVariantList flowControl();

    Commix * const dd;
    QWidget *m_widgetTitle;
    QPoint m_mousePoint;
    LSkinDialog *m_skinDialog;
    QPushButton *m_openButton,*m_startTestBtn,*m_sendBtn;
    bool m_isOpen,m_isTest;
    LComboBox *m_portCombox,*m_baudRateCombox,*m_parityCombox,*m_dataCombox,*m_stopCombox,*m_controlCombox;
    QRadioButton * m_inputHex_radioBtn,*m_inputAsc_radioBtn,*m_outputHex_radioBtn,*m_outputAsc_radioBtn;
    QCheckBox *m_moudbusCheckBox,*m_regexpCheckBox;
    QTextEdit *m_inputTextEdit,*m_outTextEdit,*m_testTextEdit,*m_configTextEdit;
    QSpinBox *m_timeSpinbox,*m_dateSpinbox;
    QLabel *m_testResultLabel;
    Device *m_device;
    QTime m_time;
    MyThread *m_thread;
    int m_sendCount,m_recvCount;
    QList<int> m_timeList;

public slots:
    void recvData(QByteArray &iData);
};

void CommixPrivate::formInCenter(QWidget *frm)
{
    int frmX = frm->width();
    int frmY = frm->height();
    QDesktopWidget w;
    int deskWidth = w.width();
    int deskHeight = w.height();
    QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
    frm->move(movePoint);
}

QMenu* CommixPrivate::createActions()
{
    //创建菜单、菜单项
    QMenu *pop_menu = new QMenu();
    QList<QAction *> list;
    QAction *about_us_action = new QAction(0);
    about_us_action->setText("关于");
    list << about_us_action;
    pop_menu->addActions(list);
    //连接信号与槽
    connect(about_us_action, SIGNAL(triggered()), dd, SLOT(doAboutUs()));
    return pop_menu;
}

QVariantList CommixPrivate::portList()
{
    QVariantList list;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QVariantMap map;
        map.insert("name",info.portName().toLower());
        map.insert("text",info.portName().toUpper());
        list << map;
    }
    return list;
}

QVariantList CommixPrivate::baudRateList()
{
    return LDataConverter::json2Var(LFileSystem::fileString(":/config/config/baudRate.json")).toList();
}

QVariantList CommixPrivate::parityList()
{
    return LDataConverter::json2Var(LFileSystem::fileString(":/config/config/parity.json")).toList();
}

QVariantList CommixPrivate::dataBits()
{
    return LDataConverter::json2Var(LFileSystem::fileString(":/config/config/dataBits.json")).toList();
}

QVariantList CommixPrivate::stopBits()
{
    return LDataConverter::json2Var(LFileSystem::fileString(":/config/config/stopBits.json")).toList();
}

QVariantList CommixPrivate::flowControl()
{
    return LDataConverter::json2Var(LFileSystem::fileString(":/config/config/flowControl.json")).toList();
}

void CommixPrivate::recvData(QByteArray &iData)
{
    QMutex mutex;
    QMutexLocker locker(&mutex);
    if(m_isTest)
    {
        int time = m_device->getTime();
        if( time != 0)
        {
            int differ = QTime::currentTime().msecsSinceStartOfDay() - time;
            m_testTextEdit->append(QString("(%1)").arg(differ));
            m_timeList << differ;
        }
        if(m_testTextEdit->textColor() == QColor("green"))
        {
            m_testTextEdit->moveCursor(QTextCursor::End);
            m_testTextEdit->insertPlainText(QString(iData.toHex()));;
        }else{
            m_testTextEdit->setTextColor("green");
            m_testTextEdit->append(QString(iData.toHex()));
            m_recvCount++;
        }
    }else{
        if(m_time != QTime(0,0,0,0))
        {
            m_outTextEdit->append(QString("(%1)").arg(QTime::currentTime().msecsSinceStartOfDay() - m_time.msecsSinceStartOfDay()));
            m_time.setHMS(0,0,0,0);
        }
        if(m_outTextEdit->textColor() == QColor("green"))
        {
            m_outTextEdit->moveCursor(QTextCursor::End);
            m_outTextEdit->insertPlainText(QString(iData.toHex()));
            qDebug() <<"green";
        }else{
            m_outTextEdit->setTextColor("green");
            if(m_outputHex_radioBtn->isChecked())
            {
                m_outTextEdit->append(QString(iData.toHex()));
            }else{
                m_outTextEdit->append(QString(iData));
            }
        }
    }
}


/*****************************Commix***********************************************/
#include "commix.moc"

Commix::Commix(QWidget *parent) :
    LBaseDialog(parent),dp(new CommixPrivate(this))
{
    initLayout();
    dp->m_thread = new MyThread();
    connect(this,SIGNAL(resetSignal(int,int,int,int,int)),dp->m_device,SLOT(resetting(int,int,int,int,int)));
    connect(dp->m_thread,SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));
    connect(dp->m_thread,SIGNAL(runEnd()),this,SLOT(startTest()));
}

void Commix::initLayout()
{
    this->setObjectName("Commix");
    QVBoxLayout *vbox = new QVBoxLayout();
    dp->m_widgetTitle = new QWidget(this);
    dp->m_widgetTitle->setObjectName("widget_title");
    createTitleBar(dp->m_widgetTitle,ToolClose | ToolIcon | ToolMax | ToolMin |ToolSet | ToolSkin | ToolTitle,"Commix演示");
    //QSpacerItem *vSpacer = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);

    QGridLayout *settingLayout = new QGridLayout();
    QHBoxLayout *hbox = new QHBoxLayout();

    QFormLayout *portformLayout = new QFormLayout;
    QGroupBox *settingGroup = new QGroupBox();
    dp->m_portCombox = new LComboBox();
    dp->m_portCombox->setBoxItems(dp->portList());
    portformLayout->addRow(tr("端口:"), dp->m_portCombox);

    QFormLayout *baudRateformLayout = new QFormLayout;
    dp->m_baudRateCombox = new LComboBox();
    dp->m_baudRateCombox->setBoxItems(dp->baudRateList());
    baudRateformLayout->addRow(tr("波特率:"), dp->m_baudRateCombox);
    connect(dp->m_baudRateCombox,SIGNAL(currentIndexChanged(int)),this,SLOT(doReset()));

    QFormLayout *parityformLayout = new QFormLayout;
    dp->m_parityCombox = new LComboBox();
    dp->m_parityCombox->setBoxItems(dp->parityList());
    parityformLayout->addRow(tr("校验位:"), dp->m_parityCombox);
    connect(dp->m_parityCombox,SIGNAL(currentIndexChanged(int)),this,SLOT(doReset()));


    QFormLayout *dataformLayout = new QFormLayout;
    dp->m_dataCombox = new LComboBox();
    dp->m_dataCombox->setBoxItems(dp->dataBits());
    dataformLayout->addRow(tr("数据位:"), dp->m_dataCombox);
    connect(dp->m_dataCombox,SIGNAL(currentIndexChanged(int)),this,SLOT(doReset()));


    QFormLayout *stopformLayout = new QFormLayout;
    dp->m_stopCombox = new LComboBox();
    dp->m_stopCombox->setBoxItems(dp->stopBits());
    stopformLayout->addRow(tr("停止位:"), dp->m_stopCombox);
    connect(dp->m_stopCombox,SIGNAL(currentIndexChanged(int)),this,SLOT(doReset()));

    QFormLayout *controlformLayout = new QFormLayout;
    dp->m_controlCombox = new LComboBox();
    dp->m_controlCombox->setBoxItems(dp->flowControl());
    controlformLayout->addRow(tr("流控制:"), dp->m_controlCombox);
    connect(dp->m_controlCombox,SIGNAL(currentIndexChanged(int)),this,SLOT(doReset()));


    dp->m_moudbusCheckBox = new QCheckBox("Modbus协议");
    dp->m_regexpCheckBox = new QCheckBox("正则匹配");

    QFormLayout *inputformLayout = new QFormLayout;
    QHBoxLayout *inputHbox = new QHBoxLayout();
    QButtonGroup *inputBtnGroup = new QButtonGroup(this);
    dp->m_inputHex_radioBtn = new QRadioButton("输入HEX");
    dp->m_inputAsc_radioBtn = new QRadioButton("输入ASC");
    dp->m_inputHex_radioBtn->setChecked(true);
    inputBtnGroup->addButton(dp->m_inputHex_radioBtn);
    inputBtnGroup->addButton(dp->m_inputAsc_radioBtn);
    inputHbox->addWidget(dp->m_inputHex_radioBtn);
    inputHbox->addWidget(dp->m_inputAsc_radioBtn);
    inputformLayout->addRow(tr("输入:"),inputHbox);

    QFormLayout *outputformLayout = new QFormLayout;
    QButtonGroup *outputBtnGroup = new QButtonGroup(this);
    QHBoxLayout *outputHbox = new QHBoxLayout();
    dp->m_outputHex_radioBtn = new QRadioButton("输出HEX");
    dp->m_outputAsc_radioBtn = new QRadioButton("输出ASC");
    dp->m_outputHex_radioBtn->setChecked(true);
    outputBtnGroup->addButton(dp->m_outputHex_radioBtn);
    outputBtnGroup->addButton(dp->m_outputAsc_radioBtn);
    outputHbox->addWidget(dp->m_outputHex_radioBtn);
    outputHbox->addWidget(dp->m_outputAsc_radioBtn);
    outputformLayout->addRow(tr("输出:"),outputHbox);

    QFormLayout *configformLayout = new QFormLayout;
    dp->m_configTextEdit = new QTextEdit();
    dp->m_configTextEdit->setText(LFileSystem::fileString(":/config/modbus.cfg"));
    configformLayout->addRow(tr("\n\n\n选项:"), dp->m_configTextEdit);


    QTabWidget *tabwidget = new QTabWidget();
    QWidget * tab1 = new QWidget();
    QWidget *tab2 = new QWidget();
    dp->m_inputTextEdit = new QTextEdit();
    dp->m_outTextEdit = new QTextEdit();
    dp->m_outTextEdit->setReadOnly(true);
    dp->m_testTextEdit = new QTextEdit();
    dp->m_testTextEdit->setReadOnly(true);
    dp->m_inputTextEdit->setFixedHeight(80);
    dp->m_sendBtn = new QPushButton("发送");
    dp->m_sendBtn->setFixedSize(100,20);
    QPushButton *clearBtn = new QPushButton("清空");
    connect(dp->m_sendBtn,SIGNAL(clicked()),this,SLOT(sendMessage()));
    connect(clearBtn,SIGNAL(clicked()),this,SLOT(freeClear()));
    clearBtn->setFixedSize(100,20);
    QHBoxLayout *tab1hBox = new QHBoxLayout();
    QVBoxLayout *vbox1 = new QVBoxLayout();
    vbox1->addWidget(dp->m_sendBtn);
    vbox1->addWidget(clearBtn);
    tab1hBox->addWidget(dp->m_inputTextEdit);
    tab1hBox->addLayout(vbox1);
    QVBoxLayout *tabVbox = new QVBoxLayout();
    tabVbox->addLayout(tab1hBox);
    tabVbox->addWidget(dp->m_outTextEdit);
    tab1->setLayout(tabVbox);

    QGroupBox *testGroup = new QGroupBox();
    testGroup->setTitle("测试设置");
    QGridLayout *testgroupLayout = new QGridLayout();
    QFormLayout *timeformLayout = new QFormLayout();
    QFormLayout *dateformLayout = new QFormLayout();
    QFormLayout *resultFormLayout = new QFormLayout();

    dp->m_timeSpinbox = new QSpinBox();
    dp->m_dateSpinbox = new QSpinBox();
    dp->m_timeSpinbox->setMaximum(20000);
    dp->m_dateSpinbox->setMaximum(3000);
    dp->m_timeSpinbox->setSuffix("次");
    dp->m_dateSpinbox->setSuffix("毫秒");
    dp->m_startTestBtn = new QPushButton("开始测试");
    QPushButton *testClearBtn = new QPushButton("清空");
    connect(dp->m_startTestBtn,SIGNAL(clicked()),this,SLOT(startTest()));
    connect(testClearBtn,SIGNAL(clicked()),this,SLOT(testClear()));
    dp->m_testResultLabel = new QLabel("总数:0,成功数:0\n成功率:0.00,平均耗时0.00毫秒");
    dateformLayout->addRow("测试间隔:",dp->m_dateSpinbox);
    timeformLayout->addRow("次数:",dp->m_timeSpinbox);
    resultFormLayout->addRow("测试统计:",dp->m_testResultLabel);

    testgroupLayout->addLayout(timeformLayout,0,0,1,1);
    testgroupLayout->addLayout(dateformLayout,0,1,1,1);
    testgroupLayout->addWidget(dp->m_startTestBtn,1,0,1,1);
    testgroupLayout->addWidget(testClearBtn,1,1,1,1);
    testgroupLayout->addLayout(resultFormLayout,2,0,1,2);

    testGroup->setLayout(testgroupLayout);

    QSpacerItem *testSpacer = new QSpacerItem(20,20,QSizePolicy::Fixed,QSizePolicy::Expanding);
    QSpacerItem *midSpacer = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Fixed);

    dp->m_timeSpinbox->setValue(100);
    dp->m_dateSpinbox->setValue(50);

    QVBoxLayout *tab2VBox = new QVBoxLayout();
    QHBoxLayout *tab2HBox = new QHBoxLayout();
    tab2VBox->addWidget(testGroup);
    tab2VBox->addItem(testSpacer);
    tab2HBox->addLayout(tab2VBox);
    tab2HBox->addWidget(dp->m_testTextEdit);
    tab2->setLayout(tab2HBox);
    tabwidget->addTab(tab1,"自由发送");
    tabwidget->addTab(tab2,"测试");

    dp->m_openButton = new QPushButton();
    dp->m_openButton->setFixedSize(100,20);
    dp->m_openButton->setText("打开串口");
    connect(dp->m_openButton,SIGNAL(clicked()),this,SLOT(doOpen()));

    settingLayout->addLayout(portformLayout,0,0,1,1);
    settingLayout->addLayout(baudRateformLayout,0,1,1,1);
    settingLayout->addLayout(dataformLayout,1,0,1,1);
    settingLayout->addLayout(parityformLayout,1,1,1,1);
    settingLayout->addLayout(stopformLayout,2,0,1,1);
    settingLayout->addLayout(controlformLayout,2,1,1,1);
    settingLayout->addLayout(inputformLayout,3,0,1,1);
    settingLayout->addLayout(outputformLayout,4,0,1,1);
    settingLayout->addLayout(configformLayout,0,2,5,2);
    settingLayout->addWidget(dp->m_moudbusCheckBox,3,1,1,1);
    //settingLayout->addWidget(dp->m_regexpCheckBox,4,1,1,1);

    settingGroup->setTitle("通信设置");
    settingGroup->setLayout(settingLayout);
    hbox->addWidget(settingGroup);
    hbox->setContentsMargins(5,5,5,5);

    QHBoxLayout *midHBox = new QHBoxLayout();
    midHBox->addItem(midSpacer);
    midHBox->setContentsMargins(0,0,5,0);
    midHBox->addWidget(dp->m_openButton);
    vbox->addWidget(dp->m_widgetTitle);
    vbox->addLayout(hbox);
    vbox->addItem(midHBox);
    vbox->addWidget(tabwidget);
    this->setLayout(vbox);
    vbox->setContentsMargins(0,0,0,0);
    dp->m_widgetTitle->installEventFilter(this);

    dp->formInCenter(this);

    dp->m_skinDialog = new LSkinDialog(this);
    dp->m_skinDialog->hide();
    resize(622, 496);
}

bool Commix::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->doToolButtonMax();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void Commix::doToolButtonSkin()
{

    dp->m_skinDialog->move(this->geometry().width()-250,30);
    dp->m_skinDialog->show();
}

void Commix::doOpen()
{
    if(dp->m_isOpen)
    {
        dp->m_openButton->setText("打开串口");
        dp->m_device->close();
        dp->m_portCombox->setEnabled(true);
        dp->m_isOpen = false;
        dp->m_isTest = false;
        dp->m_startTestBtn->setText("开始测试");
    }else{
        bool b = dp->m_device->openPort(dp->m_portCombox->currentText().toUpper());
        if(!b){
            LsDlg->error("串口打开失败！",0,"错误");
            return;
        }
        dp->m_isOpen = true;
        dp->m_openButton->setText("关闭串口");
        doReset();
        dp->m_portCombox->setEnabled(false);
    }
}

void Commix::doReset()
{
    qDebug() << dp->m_isOpen;

    if(!dp->m_isOpen)
        return;
    int baudRate = dp->m_baudRateCombox->currentData().toInt();
    int dataBits = dp->m_dataCombox->currentData().toInt();
    int stopbits = dp->m_stopCombox->currentData().toInt();
    int parity = dp->m_parityCombox->currentData().toInt();
    int flowControl = dp->m_controlCombox->currentData().toInt();
    emit resetSignal(baudRate,stopbits,dataBits,flowControl,parity);
}

void Commix::freeClear()
{
    dp->m_outTextEdit->clear();
}

void Commix::testClear()
{
    dp->m_testTextEdit->clear();
    //dp->m_testResultLabel->setText("总数:0,成功数:0\n成功率:0.00,平均耗时0.00毫秒");
}

void Commix::doAboutUs()
{
    LsDlg->aboutUs();
}

void Commix::doToolButtonSet()
{
    QMenu *menu = dp->createActions();
    QPoint point = QCursor::pos();
    point +=QPoint(5,5);
    menu->exec(QPoint(this->width()-100+this->pos().x(),30+this->pos().y()));
}

void Commix::sendMessage()
{
    if(dp->m_inputTextEdit->toPlainText().trimmed().isEmpty())
    {
        LsDlg->error("输入框不能为空!");
        return;
    }
    if(!dp->m_isOpen)
    {
        LsDlg->error("串口未打开！");
        return;
    }
    if(dp->m_isTest)
    {
        LsDlg->error("请先结束当前测试");
        return;
    }
    QByteArray array;
    array = dp->m_inputTextEdit->toPlainText().trimmed().toUpper().toUtf8();
    if(dp->m_inputAsc_radioBtn->isChecked())
    {
        dp->m_device->write(array);
    }else{
        array = QByteArray::fromHex(array);
        if(dp->m_moudbusCheckBox->isChecked())
        {
            QByteArray c = array;
            QByteArray b = dp->m_device->getCRC16(c);
            array += b;
        }
        dp->m_device->write(array);
    }
    dp->m_outTextEdit->setTextColor("gray");
    dp->m_outTextEdit->append(QString(array.toHex()).toUpper());
    dp->m_time = QTime::currentTime();
}

void Commix::startTest()
{
    if(!dp->m_isTest)
    {
        dp->m_testResultLabel->setText("总数:0,成功数:0\n成功率:0.00,平均耗时0.00毫秒");
        dp->m_sendCount = 0;
        dp->m_recvCount = 0;
        dp->m_timeList.clear();
        QMutex mutex;
        QMutexLocker locker(&mutex);
        dp->m_isTest = true;
        QVariantMap map = LDataConverter::json2Var(dp->m_configTextEdit->toPlainText().trimmed()).toMap();
        int time = dp->m_timeSpinbox->value();
        int date = dp->m_dateSpinbox->value();
        dp->m_thread->setConfig(time,date);
        dp->m_device->setConfig(map);
        dp->m_thread->start();
        dp->m_startTestBtn->setText("结束测试");
    }else{
        QMutex mutex;
        QMutexLocker locker(&mutex);
        dp->m_thread->terminate();
        dp->m_startTestBtn->setText("开始测试");
        QTimer::singleShot(500,this,SLOT(endTest()));
    }
}

void Commix::endTest()
{
    dp->m_isTest = false;
}

void Commix::textChanged(const QString &iText)
{
    dp->m_sendCount++;
    dp->m_time = QTime::currentTime();
    dp->m_testTextEdit->setTextColor("red");
    dp->m_testTextEdit->append(iText.toUpper());
    QTimer::singleShot(50,this,SLOT(changedResult()));
}

void Commix::changedResult()
{
    double sum = 0;
    foreach (int value, dp->m_timeList) {
        sum+=value;
    }
    if(dp->m_timeList.count() != 0)
        sum = sum/dp->m_timeList.count();
    QString text = QString("总数:%1,成功数:%2\n成功率:%3,平均耗时%4毫秒").arg(dp->m_sendCount).arg(dp->m_recvCount).arg(QString::number(dp->m_recvCount/1.0/dp->m_sendCount, 'f', 2)).arg(QString::number(sum,'f',2));
    dp->m_testResultLabel->setText(text);
}

