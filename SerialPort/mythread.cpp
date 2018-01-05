#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
    m_device = Device::instance();
}

void MyThread::setConfig(int iTime, int iDate)
{
    m_date = iDate;
    m_time = iTime;
}

void MyThread::run()
{
    QByteArray b = m_device->getConfig();
    while(m_time > 0)
    {
        msleep(m_date);
        m_device->write(b);
        m_device->setTime();
        QString str = QString(b.toHex());
        emit textChanged(str);
        m_time--;
    }
    emit runEnd();
}
