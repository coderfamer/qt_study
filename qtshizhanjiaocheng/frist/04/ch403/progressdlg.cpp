
#include "progressdlg.h"
#include <QProgressDialog>

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong18030", 12);
    setFont(font);
    setWindowTitle(tr("Progress"));

    FileNum = new QLabel;
    FileNum->setText(tr("文件数目"));
    FileNumLineEdit = new QLineEdit;
    FileNumLineEdit->setText(tr("100000"));

    ProgressType = new QLabel;
    ProgressType->setText(tr("显示类型"));
    comboBox = new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));

    progressBar = new QProgressBar;

    startBtn = new QPushButton;
    startBtn->setText(tr("开始"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(FileNum, 0, 0);
    mainLayout->addWidget(FileNumLineEdit, 0, 1);
    mainLayout->addWidget(ProgressType, 1, 0);
    mainLayout->addWidget(comboBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 0);
    mainLayout->addWidget(cancelBtn, 3, 1);
    mainLayout->setSpacing(10);
    mainLayout->setMargin(15);

    connect(startBtn, SIGNAL(clicked(bool)), this, SLOT(starProgress()) );
}

ProgressDlg::~ProgressDlg()
{

}

void ProgressDlg::starProgress()
{
    bool ok;
    bool queren;
    int num = FileNumLineEdit->text().toInt(&ok);//获取当前需要复制的文件数

    if (comboBox->currentIndex() == 0)//采用进度条的方式显示进度
    {
        progressBar->setRange(0, num);//设置进度条的范围
        for (int i=1; i<num+1; i++)
        {
            progressBar->setValue(i);
        }

    }
    else if (comboBox->currentIndex() == 1)
    {
        //创建一个进度条对话框
        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        progressDialog->setFont(font);
        /*
         * 设置对话框采用模态的方式进行显示，即显示进度的同时，其他窗口将不响应
         * 输入信号
        */
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);//设置进度对话框出现需等待的时间
        progressDialog->setWindowTitle(tr("Please Wait"));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0, num);
        for (int i=1; i<num+1; i++)
        {
            progressDialog->setValue(i);
            if (progressDialog->wasCanceled())
            {
                return;
            }
        }
    }
}
