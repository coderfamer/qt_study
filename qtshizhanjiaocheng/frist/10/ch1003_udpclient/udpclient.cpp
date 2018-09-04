#include <QMessageBox>
#include <QHostAddress>

#include "udpclient.h"

UdpClient::UdpClient(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UDP Client"));

    receiveTextEdit = new QTextEdit(this);
    closeBtn = new QPushButton(tr("close"), this);
    connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(CloseBtnClicked()) );
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(receiveTextEdit);
    mainLayout->addWidget(closeBtn);
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()) );

    port = 5555;
    bool result = udpSocket->bind(port);
    if (!result)
    {
        QMessageBox::information(this, tr("error"), tr("udp socket create error!!!"));
        return;
    }
}

UdpClient::~UdpClient()
{

}

void UdpClient::CloseBtnClicked()
{
    close();
}

void UdpClient::dataReceived()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString msg = datagram.data();
        receiveTextEdit->insertPlainText(msg);
    }
}
