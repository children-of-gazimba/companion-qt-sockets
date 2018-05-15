#ifndef NETWORK_MESSAGE_H
#define NETWORK_MESSAGE_H

#include <QString>
#include <QJsonObject>

class QByteArray;

class NetworkMessage
{
public:
    explicit NetworkMessage();
    explicit NetworkMessage(const QString& msg, const QJsonObject& kwargs, const QString& error = "");
    virtual ~NetworkMessage();

    void setMessage(const QString& msg);
    void setKwargs(const QJsonObject& kwargs);
    void setError(const QString&);

    const QString& getMessage() const;
    const QJsonObject& getKwargs() const;
    const QString& getError() const;

    static NetworkMessage fromByteArray(const QByteArray& arr);
    const QByteArray toByteArray() const;

    bool isValid() const;

protected:
    static bool isWellFormed(const QJsonObject& object);

    static QString j_msg;
    static QString j_kwargs;
    static QString j_err;

    QString message_;
    QJsonObject kwargs_;
    QString error_;
};

#endif // NETWORK_MESSAGE_H
