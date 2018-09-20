#ifndef READER_H
#define READER_H
#include <QObject>
#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    void readNews(const QString &name)
    {
        qDebug() << name << " sub me!!!" << endl;
    }
private:
    QString m_name;
};

#endif // READER_H
