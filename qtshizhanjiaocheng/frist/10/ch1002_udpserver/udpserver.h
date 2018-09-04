#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>

class UdpServer : public QDialog
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = 0);
    ~UdpServer();

private:
    QLabel *timerLabel;
    QLineEdit *textLineEdit;
    QPushButton *startBtn;

    QVBoxLayout *mainLayout;

public slots:
    void StartBtnClicked();
    void timeout();

private:
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;

};

#endif // UDPSERVER_H
