#ifndef DEVICE_H
#define DEVICE_H
#include "lglobal.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Device : public QSerialPort
{
    Q_OBJECT
    L_DECLARE_PRIVATE(Device)
private:
    explicit Device();
    ~Device();
public:
    static Device *instance();
signals:
    void recvData2(QByteArray &);
    void closePort();

public slots:
    bool openPort( QString portName, OpenMode iOpenMode = QIODevice::ReadWrite,
                   QSerialPort::BaudRate iBaudRate = QSerialPort::Baud115200,
                   QSerialPort::StopBits iStopBits = QSerialPort::OneStop,
                   QSerialPort::DataBits iDataBits = QSerialPort::Data8,
                   QSerialPort::FlowControl iFlowControl = QSerialPort::NoFlowControl,
                   QSerialPort::Parity iParity = QSerialPort::NoParity);
   void send(QByteArray message);
   void resetting(int baudRate, int stopBits, int dataBits, int flowControl, int parity);
   void recvData();
   QByteArray getCRC16(const QByteArray &iData);
   void  setConfig(QVariantMap &iDataMap);
   QByteArray getConfig();
   int getTime();
   void setTime();
};

#endif // DEVICE_H
