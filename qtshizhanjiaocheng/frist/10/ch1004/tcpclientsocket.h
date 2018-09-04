#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT//添加宏是为了实现信号与槽的通信
public:
    TcpClientSocket(QObject *parent = 0);

signals:
    void updateClients(QString, int);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();

};

#endif // TCPCLIENTSOCKET_H
