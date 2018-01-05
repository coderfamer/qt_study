#ifndef LFILESYSTEM_H
#define LFILESYSTEM_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextCodec>

class LFileSystem : public QObject
{
    Q_OBJECT
private:
    explicit LFileSystem(QObject *parent = 0);

public slots:
    static QString fileString(const QString &iFileName, bool *oOk = 0,
                              const QString &iCodec = QString("UTF-8"));
    static bool createFile(const QString &iFileName, const QString &iData,
                           const QString &iCodec = QString("UTF-8"), bool iBom = true,
                           bool iAppend = false);
    static bool removeFile(const QString &iFileName);
    static bool removeDir(const QString &iDirName);

    static QByteArray fileToByteArrayWithName(const QString &iFileName);

    //static bool fileFromByteArrayWithName(QByteArray iByteArray, const QString &iFolder);

    //static QByteArray fileToByteArray(const QString &iFileName);

    //static bool byteArrayToFile(const QByteArray& iByteArray, const QString &iFileName);

    //static bool isFileUsed(const QString &iFileName);
};

#endif // LFILESYSTEM_H
