#include "lfilesystem.h"
#include <QDir>

LFileSystem::LFileSystem(QObject *parent) :
    QObject(parent)
{
}

QString LFileSystem::fileString(const QString &iFileName, bool *oOk, const QString &iCodec)
{
    Q_UNUSED(oOk);
    QFile f(iFileName);
    QString text;
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Open failed.";
        return "";
    }
    QTextCodec *codec = QTextCodec::codecForName(iCodec.toStdString().c_str());
    text =  codec->toUnicode(f.readAll());
    f.close();
    return text;
}

bool LFileSystem::createFile(const QString &iFileName, const QString &iData, const QString &iCodec, bool iBom, bool iAppend)
{
    QFile f(iFileName);
    if(iAppend)
    {
        if(!f.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            qWarning() << "打开或创建文件失败!";
            return false;
        }
    }else
    {
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qWarning() << "打开或创建文件失败!";
            return false;
        }
    }
    QTextStream write(&f);
    write.setCodec(iCodec.toStdString().c_str());
    write << iData;
    f.close();
    return true;
}

bool LFileSystem::removeFile(const QString &iFileName)
{
    QFile f(iFileName);
    if(!f.exists())
    {
        qWarning() << "文件不存在";
        return false;
    }
    return f.remove();
}

bool LFileSystem::removeDir(const QString &iDirName)
{
    QDir dir(iDirName);
    if(!dir.exists())
    {
        qWarning() << iDirName + "文件不存在";
        return false;
    }
    QFileInfoList fileList;
    QFileInfo curFile;
    fileList = dir.entryInfoList(QDir::Dirs|QDir::Files
                                   |QDir::Readable|QDir::Writable
                                   |QDir::Hidden|QDir::NoDotAndDotDot
                                   ,QDir::Name);
    while(fileList.size() > 0)//跳出条件
        {
            int infoNum = fileList.size();
            for(int i = infoNum - 1;i >=0;i--)
            {
                curFile=fileList[i];
                if(curFile.isFile())//如果是文件，删除文件
                {
                    QFile fileTemp(curFile.filePath());
                    fileTemp.remove();
                    fileList.removeAt(i);
                }
                else if(curFile.isDir())//如果是文件夹
                {
                      //removeDir(curFile);
                }
            }
        }
    return true;
}

QByteArray LFileSystem::fileToByteArrayWithName(const QString &iFileName)
{
    QByteArray array;
    QFile f(iFileName);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Open failed.";
        return array;
    }
    array = f.readAll();
    f.close();
    return array;
}

//bool LFileSystem::fileFromByteArrayWithName(QByteArray iByteArray, const QString &iFolder)
//{
//    QFile f(iFolder);
//    if(iAppend)
//    {
//        if(!f.open(QIODevice::WriteOnly | QIODevice::Append))
//        {
//            qWarning() << "打开或创建文件失败!";
//            return false;
//        }
//    }else
//    {
//        if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
//        {
//            qWarning() << "打开或创建文件失败!";
//            return false;
//        }
//    }
//    QTextStream write(&f);
//    write.setCodec(iCodec.toStdString().c_str());
//    write << iByteArray;
//    f.close();
//    return true;
//}
