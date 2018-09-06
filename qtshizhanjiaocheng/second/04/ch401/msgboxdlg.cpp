#include <QMessageBox>
#include "msgboxdlg.h"

MsgBoxDlg::MsgBoxDlg(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("标准消息对话框实例"));
    label = new QLabel(tr("请选择一种消息框"));

    questionBtn = new QPushButton(tr("questionMsg"));
    informationBtn = new QPushButton(tr("informationMsg"));
    warnintBtn = new QPushButton(tr("warnintMsg"));
    cirticalBtn = new QPushButton(tr("cirticalMsg"));
    aboutBtn = new QPushButton(tr("aboutBtnMsg"));
    aoubtQtBtn = new QPushButton(tr("aoubtQtBtnMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0, 1, 2);
    mainLayout->addWidget(questionBtn, 1, 0);
    mainLayout->addWidget(informationBtn, 1, 1);
    mainLayout->addWidget(warnintBtn, 2, 0);
    mainLayout->addWidget(cirticalBtn, 2, 1);
    mainLayout->addWidget(aboutBtn, 3, 0);
    mainLayout->addWidget(aoubtQtBtn, 3, 1);

    connect(questionBtn, SIGNAL(clicked(bool)), this, SLOT(showQuestionMsg()) );
    connect(informationBtn, SIGNAL(clicked(bool)), this, SLOT(showInformationMsg()) );
    connect(warnintBtn, SIGNAL(clicked(bool)), this, SLOT(showWarnintMsg()) );
    connect(cirticalBtn, SIGNAL(clicked(bool)), this, SLOT(showCriticalMsg()) );
    connect(aboutBtn, SIGNAL(clicked(bool)), this, SLOT(showAboutMsg()) );
    connect(aoubtQtBtn, SIGNAL(clicked(bool)), this, SLOT(showAboutQtMsg()) );
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    QString title = "question 消息框";
    QString hint = "您现在已近修改完成，是否要结束程序";
    int question = QMessageBox::question(
                this, title, hint, QMessageBox::Ok , QMessageBox::Cancel);
    switch (question)
    {
    case QMessageBox::Ok:
        label->setText("Qusetion button/ok");
        break;
    case QMessageBox::Cancel:
        label->setText("Qusetion button/cancel");
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QString title = "Information 消息框";
    QString hint = "Information 消息测试";
    QMessageBox::information(this, title, hint, QMessageBox::Yes, QMessageBox::No);

}
void MsgBoxDlg::showWarnintMsg()
{
    label->setText(tr("Warnint Message Box"));
    QString title = "Warnint 消息框";
    QString hint = "warnning warning waning!!!!";
    int warn = QMessageBox::warning(this, title, hint, QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (warn)
    {
    case QMessageBox::Save:
        label->setText(tr("Warnint button/Save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warnint button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Warnint button/Cancel"));
        break;
    default:
        break;
    }
}

void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QString title = "Critical 消息框";
    QString hint = "Critical 消息测试";
    QMessageBox::critical(this, title, hint);
}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QString title = "About 消息框";
    QString hint = "About 消息测试";
    QMessageBox::about(this, title, hint);
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("aboutQt Message Box"));
    QString title = "aboutQt 消息框";
    //QString hint = "aboutQt 消息测试";
    QMessageBox::aboutQt(this, title);
}

