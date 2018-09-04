#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHostInfo>
#include <QNetworkInterface>

class NetworkInformation : public QWidget
{
    Q_OBJECT

public:
    NetworkInformation(QWidget *parent = 0);
    ~NetworkInformation();

    void getHostInformation();

private:
    QLabel *hostLabel;
    QLineEdit *LineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *LineEditAddress;

    QPushButton *detailBtn;
    QGridLayout *mainLayout;

public slots:
    void slotDetail();

};

#endif // NETWORKINFORMATION_H
