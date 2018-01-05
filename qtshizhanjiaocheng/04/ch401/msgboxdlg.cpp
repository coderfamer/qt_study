#include "msgboxdlg.h"
#include <QMessageBox>
MsgBoxDlg::MsgBoxDlg(QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle(tr("标准消息对话框的实例"));
    label = new QLabel;
    label->setText(tr("请选择一种对话框"));

    questionBtn = new QPushButton;
    questionBtn->setText(tr("QuestionMsg"));

    informationBtn = new QPushButton;
    informationBtn->setText(tr("InformaitonMsg"));

    warningBtn = new QPushButton;
    warningBtn->setText(tr("WarningMsg"));

    criticalBtn = new QPushButton;
    criticalBtn->setText(tr("CriticalMsg"));

    aboutBtn = new QPushButton;
    aboutBtn->setText(tr("AboutMsg"));

    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(tr("AboutQtMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0, 1, 2);
    mainLayout->addWidget(questionBtn, 1, 0);
    mainLayout->addWidget(informationBtn, 1, 1);
    mainLayout->addWidget(warningBtn, 2, 0);
    mainLayout->addWidget(criticalBtn, 2, 1);
    mainLayout->addWidget(aboutBtn, 3, 0);
    mainLayout->addWidget(aboutQtBtn, 3, 1);

    connect(questionBtn, SIGNAL(clicked(bool)), this, SLOT(showQuestionMsg()) );
    connect(informationBtn, SIGNAL(clicked(bool)), this, SLOT(showInformationMsg()) );
    connect(warningBtn, SIGNAL(clicked(bool)), this, SLOT(showWaringMsg()) );
    connect(criticalBtn, SIGNAL(clicked(bool)), this, SLOT(showCriticalMsg()) );
    connect(aboutBtn, SIGNAL(clicked(bool)), this, SLOT(showAboutMsg()) );
    connect(aboutQtBtn, SIGNAL(clicked(bool)), this, SLOT(showAboutQtMsg()) );

}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch (QMessageBox::question(this, tr("Question消息框"),
                                  tr("您现在已经修改完成，是否要结束程序？"),
                                  QMessageBox::Ok|QMessageBox::Cancel,
                                  QMessageBox::Ok)) {
    case QMessageBox::Ok:
        label->setText("Question button/OK");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this, tr("Information消息框"),
                             tr("这是information消息框测试，欢迎您!!"));
    return;

}
void MsgBoxDlg::showWaringMsg()
{
    label->setText(tr("Warning Message Box"));
    switch (QMessageBox::warning(this, tr("warnint消息框"),
                                 tr("您修改的东西还未保存，是否保存"),
                                 QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,
                                 QMessageBox::Save)) {
    case QMessageBox::Save:
        label->setText(tr("Waring button/save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Waring button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Waring button/Cancel"));
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this, tr("Critical消息框"),
                          tr("这是一个Critical消息框测试"));
    return;
}
void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this, tr("About消息框"),tr("这是一个About消息测试"));
    return;
}
void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("AbouQt Message Box"));
    QMessageBox::aboutQt(this, tr("这是一个AboutQt消息测试"));
}
