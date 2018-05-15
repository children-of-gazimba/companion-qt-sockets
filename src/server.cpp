#include "server.h"

Server::Server(int port, QObject *parent)
    : QObject(parent)
    , tcp_server_(Q_NULLPTR)
    , clients_()
    , refresh_read_(0)
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

    sendToClient("Hello client\r\n", socket);

    clients_.push_back(socket);

    connect(socket, &QTcpSocket::disconnected,
            [=]()
        {
            qDebug() << "client disconnected";
            socket->close();
            clients_.removeAll(socket);
        }
    );
}

void Server::checkMessages()
{
    foreach(auto client, clients_) {
        if(client->bytesAvailable()) {
            NetworkMessage msg = NetworkMessage::fromByteArray(client->readAll());
            if(msg.isValid())
                processClientMessage(msg, client);
        }
    }
}

void Server::sendToClient(const QByteArray &data, QTcpSocket *client)
{
    client->write(data);
    client->flush();
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

    refresh_read_ = new QTimer(this);
    connect(refresh_read_, &QTimer::timeout,
            this, &Server::checkMessages);
    refresh_read_->start(1000);
}

void Server::processClientMessage(const NetworkMessage &msg, QTcpSocket *client)
{
    Q_UNUSED(client);
    qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
    qDebug() << "  > " << msg.toByteArray();
}
