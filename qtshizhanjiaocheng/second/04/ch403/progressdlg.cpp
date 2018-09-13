#include <QProgressDialog>
#include <QFont>

#include "progressdlg.h"

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("progress"));

    fileNumLabel = new QLabel(tr("file num:"));
    fileNumLineEdit = new QLineEdit;
    fileNumLineEdit->setText(tr("10000"));
    typeLabel = new QLabel(tr("show type:"));
    typeComboBox = new QComboBox;
    typeComboBox->addItem(tr("progressBar"));
    typeComboBox->addItem(tr("progressDlg"));
    fileProgressBar = new QProgressBar;
    beginBtn = new QPushButton(tr("begin"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileNumLabel, 0, 0);
    mainLayout->addWidget(fileNumLineEdit, 0, 1);
    mainLayout->addWidget(typeLabel, 1, 0);
    mainLayout->addWidget(typeComboBox, 1, 1);
    mainLayout->addWidget(fileProgressBar, 2, 0, 1, 2);
    mainLayout->addWidget(beginBtn, 3, 1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(beginBtn, SIGNAL(clicked(bool)), this, SLOT(startProgress()) );
}

ProgressDlg::~ProgressDlg()
{

}

void ProgressDlg::startProgress()
{
    int num = fileNumLineEdit->text().toInt();
    if (typeComboBox->currentIndex() == 0)
    {
        fileProgressBar->setRange(0, num);
        for (int i = 1; i <= num; i++)
        {
            fileProgressBar->setValue(i);
        }
    }
    else if (typeComboBox->currentIndex() == 1)
    {
        QProgressDialog *fileProgressDlg = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        fileProgressDlg->setFont(font);
        fileProgressDlg->setWindowModality(Qt::WindowModal);
        fileProgressDlg->setMinimumDuration(5);
        fileProgressDlg->setWindowTitle(tr("Please wait"));
        fileProgressDlg->setLabelText(tr("Copying..."));
        fileProgressDlg->setCancelButtonText(tr("Cancel"));
        fileProgressDlg->setRange(0, num);
        for (int i = 1; i <= num; i++)
        {
            fileProgressDlg->setValue(i);
            if (fileProgressDlg->wasCanceled())
                return;
        }
    }
}
