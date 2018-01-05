#include "ldataconverter.h"
#include <QString>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

LDataConverter::LDataConverter(QObject *parent) :
    QObject(parent)
{
}

QVariant LDataConverter::json2Var(const QString &iJson, QString *oErr)
{
    Q_UNUSED(oErr)
    QJsonParseError json_error;
    QJsonDocument document = QJsonDocument::fromJson(iJson.toUtf8(), &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(!document.isEmpty())
        {
            return document.toVariant();
        }
    }
    qWarning()<<json_error.errorString();
    return QVariant();
}

QString LDataConverter::var2Json(const QVariant &iVariant)
{
    return QString(QJsonDocument::fromVariant(iVariant).toJson());
}

QVariant LDataConverter::xml2Var(const QString &iXml, const QString &iRoot, const QVariant &iOption, QString *oErr)
{

}
