#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
class UdpClient : public QDialog
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = 0);
    ~UdpClient();

private:
    QTextEdit *receiveTextEdit;
    QPushButton *closeBtn;

    QVBoxLayout *mainLayout;

public slots:
    void CloseBtnClicked();
    void dataReceived();

private:
    int port;
    QUdpSocket *udpSocket;
};

#endif // UDPCLIENT_H
