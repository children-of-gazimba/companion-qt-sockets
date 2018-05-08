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
    ~Server();

signals:

private slots:
    void newConnection();

public slots:

private:
    void initServer();

    QTcpServer *tcp_server_;
    int port_;
};

#endif // SERVER_HPP
