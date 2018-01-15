#include <QHostAddress>

#include "udpserver.h"

UdpServer::UdpServer(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UDP Server"));

    timerLabel = new QLabel(tr("计时"), this);
    textLineEdit = new QLineEdit(this);

    startBtn = new QPushButton(tr("开始"), this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(timerLabel);
    mainLayout->addWidget(textLineEdit);
    mainLayout->addWidget(startBtn);

    connect(startBtn, SIGNAL(clicked(bool)), this,
            SLOT(StartBtnClicked()) );
    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()) );//定时发送广播信息


}

UdpServer::~UdpServer()
{

}

void UdpServer::StartBtnClicked()
{
    if (!isStarted)
    {
        startBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted = true;
    }
    else
    {
        startBtn->setText(tr("开始"));
        isStarted = false;
        timer->stop();
    }
}

void UdpServer::timeout()
{
    QString msg = textLineEdit->text();
    int length = 0;
    if (msg == "")
    {
        return;
    }
    //qint64 writeDatagram(const char *data, qint64 len, const QHostAddress &host, quint16 port);
    if ((length = udpSocket->writeDatagram(msg.toLatin1(), msg.length(),
                                           QHostAddress::Broadcast, port )) != msg.length());
    {
        return;
    }
}
