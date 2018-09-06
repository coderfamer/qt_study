#include <QString>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框实例"));

    fileBtn = new QPushButton;
    fileBtn->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;

    colorBtn = new QPushButton(tr("颜色标准对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    //colorFrame->setPalette(QPalette());
    colorFrame->setAutoFillBackground(true);

    fontBtn = new QPushButton(tr("字体标准对话框实例"));
    fontLineEdit =new QLineEdit;
    fontLineEdit->setText(tr("Welcome!!!"));

    inputBtn = new QPushButton(tr("标准输入对话框实例"));

    msgBtn = new QPushButton(tr("标准消息对话框实例"));

    customBtn= new QPushButton(tr("自定义对话框实例"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLineEdit, 0, 1);
    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);
    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLineEdit, 2, 1);
    mainLayout->addWidget(inputBtn, 3, 0);
    mainLayout->addWidget(msgBtn, 3, 1);
    mainLayout->addWidget(customBtn, 4, 0);

    connect(fileBtn, SIGNAL(clicked(bool)), this, SLOT(showFile()) );
    connect(colorBtn, SIGNAL(clicked(bool)), this, SLOT(showColor()) );
    connect(fontBtn, SIGNAL(clicked(bool)), this, SLOT(showFont()) );
    connect(inputBtn, SIGNAL(clicked(bool)), this, SLOT(showInputDlg()) );
    connect(msgBtn, SIGNAL(clicked(bool)), this, SLOT(showMsgDlg()) );
    connect(customBtn, SIGNAL(clicked(bool)), this, SLOT(showCustomDlg()) );
}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QString s =
            QFileDialog::getOpenFileName(this, tr("open file"),
                                             "/",
                                             tr("Images (*.png *.xpm *.jpg);;"
                                                "Text files (*.txt)"));
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if (c.isValid())
    {
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if (ok)
    {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg(this);
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    customDlg = new CustomDlg(this);
    customDlg->show();
}
