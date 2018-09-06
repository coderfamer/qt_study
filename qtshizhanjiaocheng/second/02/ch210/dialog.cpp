#include <QRegExp>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{1,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    connect(ui->okButton, SIGNAL(clicked(bool)), this, SLOT(accept()) );
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()) );
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textCanged()) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textCanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
