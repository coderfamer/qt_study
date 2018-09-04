#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class Dialog : public QDialog
{
    Q_OBJECT//启动QT元对象系统的一些特性（如信号和槽等），必须放置到类定义的私有区

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QLabel *label1, *label2, *label3;
    QLineEdit *lineEdit, *lineEdit3;
    QPushButton *btn;
private slots:
    void showArea();
    void showArea2();
};

#endif // DIALOG_H
