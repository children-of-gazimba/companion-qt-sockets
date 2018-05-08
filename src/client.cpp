#include "client.h"

Client::Client(QObject *parent)
    : QObject(parent)
    , tcp_socket_(0)
{}

Client::~Client()
{}

void Client::connect(QString host, int port)
{
    if(tcp_socket_)
        tcp_socket_->deleteLater();

    tcp_socket_ = new QTcpSocket(this);

    tcp_socket_->connectToHost(host, port);

    if(tcp_socket_->waitForConnected(5000))
    {
        qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
        qDebug() << "  > " << "Success: connected to" << host << ":" << port;

        // send
        tcp_socket_->write("Hello server\r\n\r\n");
        tcp_socket_->waitForBytesWritten(1000);
        tcp_socket_->waitForReadyRead(3000);

        qDebug() << "Reading: " << tcp_socket_->bytesAvailable();

        // get the data
        qDebug() << tcp_socket_->readAll();

        // close the connection
        tcp_socket_->close();
    }
    else
    {
        qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
        qDebug() << "  > " << "Failure: couldn't connect to" << host << ":" << port;
    }
}
