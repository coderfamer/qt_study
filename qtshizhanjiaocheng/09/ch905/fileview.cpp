#include "fileview.h"

FileView::FileView(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setWindowTitle(tr("File view"));

    fileLineEdit = new QLineEdit(tr("/"));
    fileListWidget = new QListWidget;

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);

    connect(fileLineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)) );
    connect(fileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(slotDirShow(QListWidgetItem*)) );

    QString root = "/";
    QDir rootDir(root);
    QStringList string;
    string << "*";
    QFileInfoList list = rootDir.entryInfoList(string);
    showFileInfoList(list);
}

FileView::~FileView()
{

}

void FileView::slotShow(QDir dir)
{
    QStringList string;
    string << "*";
    QFileInfoList list = dir.entryInfoList(string, QDir::AllEntries, QDir::DirsFirst);
    showFileInfoList(list);
}

void FileView::slotDirShow(QListWidgetItem *item)
{

}

void FileView::showFileInfoList(QFileInfoList list)
{

}
