#include <QMessageBox>
#include <QPixmap>
#include "customdlg.h"

CustomDlg::CustomDlg(QWidget *parent) :
    QDialog(parent)
{
    customBtn = new QPushButton(tr("用户自定义消息对话框"));
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(customBtn, 0, 0);
    mainLayout->addWidget(label, 0, 1);

    connect(customBtn, SIGNAL(clicked(bool)), this, SLOT(showCustomDlg()) );
}

void CustomDlg::showCustomDlg()
{
    label->setText(tr("custom message box"));

    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框"));

    QPushButton *yesBtn = customMsgBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QPushButton *noBtn = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton *cancelBtn = customMsgBox.addButton(QMessageBox::Cancel);

    customMsgBox.setText(tr("这是一个用户自定义消息框"));
    customMsgBox.setIconPixmap(QPixmap(":/qt.png"));
    customMsgBox.exec();

    if (customMsgBox.clickedButton() == yesBtn)
        label->setText("Custom Message Box/Yes");
    if (customMsgBox.clickedButton() == noBtn)
        label->setText("Custom Message Box/no");
    if (customMsgBox.clickedButton() == cancelBtn)
        label->setText("Custom Message Box/cancel");
    return;
}
