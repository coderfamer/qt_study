#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("TCP Server"));
    ContentListWidget = new QListWidget;

    PortLabel = new QLabel(tr("端口:"));
    PortLineEdit = new QLineEdit;
    CreatBtn = new QPushButton(tr("创建聊天室:"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget, 0, 0, 1, 2);
    mainLayout->addWidget(PortLabel, 1, 0);
    mainLayout->addWidget(PortLineEdit, 1, 1);
    mainLayout->addWidget(CreatBtn, 2, 0, 1, 2);

    port = 8010;
    PortLineEdit->setText(QString::number(port));

    connect(CreatBtn, SIGNAL(clicked(bool)), this,
            SLOT(slotCreateServer()) );
}

TcpServer::~TcpServer()
{

}

void TcpServer::slotCreateServer()
{
    server = new Server(this, port);
    connect(server, SIGNAL(updateServer(QString,int)), this,
            SLOT(updateServer(QString,int)) );
    CreatBtn->setEnabled(false);
}

void TcpServer::updateServer(QString msg, int length)
{
    ContentListWidget->addItem(msg.left(length));
}
