#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QString>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QLabel *m_label1, *m_label2;
    QLineEdit *m_lineEdit;
    QPushButton *m_btn;

private slots:
    void showArea();
};

#endif // DIALOG_H
