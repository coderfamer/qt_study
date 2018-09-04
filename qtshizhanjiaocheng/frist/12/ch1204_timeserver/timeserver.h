#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>

class Dialog;
class TimeServer;

class TimeServer : public QTcpServer
{
public:
    TimeServer(QObject *parent = 0);
public slots:
    void slotShow();
protected:
    void incomingConnection(int socketDescriptor);
private:
    Dialog *dlg;
    TimeServer *timeServer;
    int count;
};

#endif // TIMESERVER_H
