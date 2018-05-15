#include "network_message.h"

#include <QByteArray>
#include <QJsonDocument>

QString NetworkMessage::j_msg = QString("msg");
QString NetworkMessage::j_kwargs = QString("kwargs");
QString NetworkMessage::j_err = QString("err");

NetworkMessage::NetworkMessage()
    : message_()
    , kwargs_()
    , error_()
{}

NetworkMessage::NetworkMessage(const QString &msg, const QJsonObject &kwargs, const QString &error)
    : message_(msg)
    , kwargs_(kwargs)
    , error_(error)
{}

NetworkMessage::~NetworkMessage()
{}

void NetworkMessage::setMessage(const QString &msg)
{
    message_ = msg;
}

void NetworkMessage::setKwargs(const QJsonObject &kwargs)
{
    kwargs_ = kwargs;
}

void NetworkMessage::setError(const QString &err)
{
    error_ = err;
}

const QString &NetworkMessage::getMessage() const
{
    return message_;
}

const QJsonObject &NetworkMessage::getKwargs() const
{
    return kwargs_;
}

const QString &NetworkMessage::getError() const
{
    return error_;
}

NetworkMessage NetworkMessage::fromByteArray(const QByteArray &arr)
{
    NetworkMessage msg;
    QJsonDocument doc = QJsonDocument::fromJson(arr);
    if(doc.isEmpty() || doc.isNull() || doc.isArray())
        return msg;
    QJsonObject obj = doc.object();
    if(!isWellFormed(obj))
        return msg;
    msg.setMessage(obj[j_msg].toString());
    msg.setKwargs(obj[j_kwargs].toObject());
    if(!obj[j_err].isNull())
        msg.setError(obj[j_err].toString());
    return msg;
}

const QByteArray NetworkMessage::toByteArray() const
{
    QJsonObject obj;
    obj[j_msg] = message_;
    obj[j_kwargs] = kwargs_;
    if(error_.size() > 0)
        obj[j_err] = error_;
    QJsonDocument doc(obj);
    return doc.toJson();
}

bool NetworkMessage::isValid() const
{
    return message_.size() > 0;
}

bool NetworkMessage::isWellFormed(const QJsonObject &o)
{
    return o.contains(j_msg) && o[j_msg].isString() &&
           o.contains(j_kwargs) && o[j_kwargs].isObject() &&
           o.contains(j_err) && (o[j_err].isString() || o[j_err].isNull());
}
