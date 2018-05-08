#include "server.hpp"

Server::Server(int port, QObject *parent)
    : QObject(parent)
    , tcp_server_(Q_NULLPTR)
    , port_(port)
{
    initServer();
}

Server::~Server()
{}

void Server::newConnection()
{
    qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
    qDebug() << "  > " << "new incoming connection";
    // need to grab the socket
    QTcpSocket *socket = tcp_server_->nextPendingConnection();

    if(socket->bytesAvailable())
        qDebug() << "    > "  << "Client says:" << socket->readAll();

    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}

void Server::initServer()
{
    tcp_server_ = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(tcp_server_, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!tcp_server_->listen(QHostAddress::Any, port_))
    {
        qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
        qDebug() << "  > " << "Failure: Server couldn't start";
    }
    else
    {
        qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
        qDebug() << "  > " << "Success: Server started.";
    }
}
