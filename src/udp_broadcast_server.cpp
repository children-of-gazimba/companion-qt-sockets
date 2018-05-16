#include "udp_broadcast_server.h"

UdpBroadcastServer::UdpBroadcastServer(QObject *parent)
    : QObject(parent)
    , socket_(0)
    , port_(45454)
    , timer_(0)
    , broadcast_frequency_(200)
{
    initSocket();
}

UdpBroadcastServer::UdpBroadcastServer(unsigned port, QObject *parent)
    : QObject(parent)
    , socket_(0)
    , port_(port)
    , timer_(0)
    , broadcast_frequency_(200)
{
    initSocket();
}

void UdpBroadcastServer::setBroadcastFrequency(int ms)
{
    broadcast_frequency_ = ms;
    if(broadcast_frequency_ < 0)
        timer_->stop();
    timer_->start(broadcast_frequency_);
}

int UdpBroadcastServer::getBroadcastFrequency() const
{
    return broadcast_frequency_;
}

void UdpBroadcastServer::broadcast()
{
    QByteArray data = "TEST BROADCAST";
    socket_->writeDatagram(data, QHostAddress::Broadcast, port_);
}

void UdpBroadcastServer::initSocket()
{
    socket_ = new QUdpSocket(this);
    timer_ = new QTimer(this);
    timer_->start(broadcast_frequency_);
    connect(timer_, &QTimer::timeout,
            this, &UdpBroadcastServer::broadcast);
}
