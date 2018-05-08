#ifndef SERVER_HPP
#define SERVER_HPP

#include <QtNetwork>
#include <QTcpServer>
#include <QNetworkSession>
#include <QList>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(int port = 41736, QObject *parent = nullptr);
    virtual ~Server();

signals:

protected slots:
    virtual void newConnection();

public slots:

protected:
    virtual void initServer();

    QTcpServer *tcp_server_;
    QList<QTcpSocket*> clients_;
    QTimer* refresh_read_;
    int port_;
};

#endif // SERVER_HPP
