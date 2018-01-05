#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <device.h>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void setConfig(int iTime, int iDate);

signals:
    void textChanged(const QString &);
    void runEnd();

public slots:

protected slots:
    void run();

private:
    Device *m_device;
    int m_date;
    int m_time;

};

#endif // MYTHREAD_H
