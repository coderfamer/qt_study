#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>

class TimerThread : public QThread
{
    Q_OBJECT
public:
    TimerThread(int socketDescriptor, QObject *parent = 0);
    void run();
signals:
    void error(QTcpSocket::SocketError socketError);
private:
    int socketDescriptor;
};

#endif // TIMERTHREAD_H
