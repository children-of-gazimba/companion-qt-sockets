#include "udp_broadcast_client.h"

#include <QUdpSocket>

UdpBroadcastClient::UdpBroadcastClient(QObject *parent)
    : QObject(parent)
    , socket_()
    , port_(45454)
{
    initSocket();
}

UdpBroadcastClient::UdpBroadcastClient(unsigned port, QObject *parent)
    : QObject(parent)
    , socket_()
    , port_(port)
{
    initSocket();
}

void UdpBroadcastClient::processPendingDatagrams()
{
    QByteArray datagram;
    QHostAddress sender;
    quint16 sender_port;
    while (socket_->hasPendingDatagrams()) {
        datagram.resize(socket_->pendingDatagramSize());
        socket_->readDatagram(datagram.data(), datagram.size(), &sender, &sender_port);
        emit messageReceived(datagram, sender, sender_port);
    }
}

void UdpBroadcastClient::initSocket()
{
    socket_ = new QUdpSocket(this);
    socket_->bind(QHostAddress::Broadcast, port_, QUdpSocket::ShareAddress);
    connect(socket_, &QUdpSocket::readyRead,
            this, &UdpBroadcastClient::processPendingDatagrams);
}
