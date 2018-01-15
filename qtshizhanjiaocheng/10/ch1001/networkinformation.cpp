#include "networkinformation.h"
#include <QDebug>
#include <QMessageBox>

NetworkInformation::NetworkInformation(QWidget *parent)
    : QWidget(parent)
{
    hostLabel = new QLabel(tr("主机名："));
    LineEditLocalHostName = new QLineEdit;
    ipLabel = new QLabel(tr("IP地址："));
    LineEditAddress = new QLineEdit;

    detailBtn = new QPushButton(tr("详细"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(LineEditLocalHostName, 0, 1);
    mainLayout->addWidget(ipLabel, 1, 0);
    mainLayout->addWidget(LineEditAddress, 1, 1);
    mainLayout->addWidget(detailBtn, 2, 0, 1, 2);

    getHostInformation();

    connect(detailBtn, SIGNAL(clicked(bool)), this,
            SLOT(slotDetail()) );
}

NetworkInformation::~NetworkInformation()
{

}

void NetworkInformation::getHostInformation()
{
    QString localHostName = QHostInfo::localHostName();//获取本机主机名
    LineEditLocalHostName->setText(localHostName);

    QHostInfo hostInfo = QHostInfo::fromName(localHostName);//根据主机名获得相关信息，包括IP地址等
    QList<QHostAddress> listAddress = hostInfo.addresses();//获取IP地址列表
    qDebug() << hostInfo.addresses().toStdList();
    if (!listAddress.isEmpty())
    {
        LineEditAddress->setText(listAddress.first().toString());
    }
}

void NetworkInformation::slotDetail()
{
    QString detail = "";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    qDebug() << "list count is "<<list.count();
    for (int i=0; i<list.count(); i++)
    {
        QNetworkInterface interface = list.at(i);
        detail = detail + tr("设备名称：") + interface.name() + "\n";
        detail = detail + tr("硬件地址:") + interface.hardwareAddress() + "\n";
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for (int j=0; j<entryList.count(); j++)
        {
            QNetworkAddressEntry entry = entryList.at(j);
            detail = detail + tr("IP地址:") + entry.ip().toString() + " ";
            detail = detail + tr("子网掩码:") + entry.netmask().toString() + " ";
            detail = detail + tr("广播地址") + entry.broadcast().toString() + " ";
        }
    }
    QMessageBox::information(this, tr("detail"), detail);
}
