#ifndef NEWS_H
#define NEWS_H

#include <QObject>

class News : public QObject
{
    Q_OBJECT
public:
    News(const QString &name) : m_name(name)
    {}

    void send()
    {
        emit newPaper(m_name);
    }

signals:
    void newPaper(const QString &name);

private:
    QString m_name;
};

#endif // NEWS_H
