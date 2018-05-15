#ifndef SERVER_HPP
#define SERVER_HPP

#include <QtNetwork>
#include <QTcpServer>
#include <QNetworkSession>
#include <QList>

#include "network_message.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(int port = 41736, QObject *parent = nullptr);
    virtual ~Server();

signals:

protected slots:
    virtual void newConnection();
    virtual void checkMessages();

public slots:

protected:
    virtual void sendToClient(const QByteArray& data, QTcpSocket* client);
    virtual void initServer();
    virtual void processClientMessage(const NetworkMessage& msg, QTcpSocket* client);

    QTcpServer *tcp_server_;
    QList<QTcpSocket*> clients_;
    QTimer* refresh_read_;
    int port_;
};

#endif // SERVER_HPP
