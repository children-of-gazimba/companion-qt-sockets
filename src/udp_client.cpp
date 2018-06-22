#include "udp_client.h"

UdpClient::UdpClient(QObject *parent)
    : QObject(parent)
    , socket_()
    , port_(45455)
{
    initSocket();
}

UdpClient::UdpClient(unsigned port, QObject *parent)
    : QObject(parent)
    , socket_()
    , ip_()
    , port_(port)
{
    initSocket();
}

UdpClient::UdpClient(unsigned port, const QHostAddress &address, QObject *parent)
    : QObject(parent)
    , socket_()
    , ip_(address)
    , port_(port)
{
    initSocket();
}

UdpClient::~UdpClient()
{
    if(socket_ && socket_->isOpen())
        socket_->close();
}

bool UdpClient::hasPendingDatagrams()
{
    return socket_->hasPendingDatagrams();
}

void UdpClient::processPendingDatagrams()
{
    QByteArray datagram;
    QHostAddress sender;
    quint16 sender_port;
    while (socket_->hasPendingDatagrams()) {
        datagram.resize(socket_->pendingDatagramSize());
        qint64 size = socket_->readDatagram(datagram.data(), datagram.size(), &sender, &sender_port);

        if(size == -1 ) {
            continue;
        }

        if(size != datagram.size())
            datagram.resize(size);

        emit messageReceived(datagram, sender, sender_port);
    }
}

void UdpClient::initSocket()
{
    socket_ = new QUdpSocket(this);

    if(ip_.isNull()) {
        socket_->bind(QHostAddress::LocalHost,port_ );
    } else {
        socket_->bind(ip_,port_ );
    }

    connect(socket_, &QUdpSocket::readyRead,
            this, &UdpClient::processPendingDatagrams);
}

