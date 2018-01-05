#ifndef LDATACONVERTER_H
#define LDATACONVERTER_H

#include <QObject>
#include <QVariant>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class LDataConverter : public QObject
{
    Q_OBJECT
private:
    explicit LDataConverter(QObject *parent = 0);
public:
    static QVariant json2Var(const QString &iJson, QString *oErr = 0);
    static QString var2Json(const QVariant &iVariant);
    static QVariant xml2Var(const QString &iXml,
                            const QString &iRoot = QString(),
                            const QVariant &iOption = QVariant(),
                            QString *oErr = 0);

    static QString number2ChineseCapital(double iValue);

    static QString int2Str(const QVariant &iValue, int iFieldWidth = 0, QChar iFillChar = QLatin1Char('0'));
    static QString double2Str(const QVariant &iValue, int iPrecision = 2);
    static QString numberAddPerThousandSign(const QVariant &iValue, int iPrecision = 2);
    static QString int2FileSize(qint64 iValue, bool iAppendDetail = false);
    static QString strAbbreviation(const QString &iString, int iLength = 16);

public slots:

};

#endif // LDATACONVERTER_H
