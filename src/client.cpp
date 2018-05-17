#include "client.h"

Client::Client(QObject *parent)
    : QObject(parent)
    , tcp_socket_(0)
    , timer_(0)
    , read_frequency_(500)
{
    init();
}

Client::Client(int read_frequency, QObject *parent)
    : QObject(parent)
    , tcp_socket_(0)
    , timer_(0)
    , read_frequency_(read_frequency)
{
    init();
}

Client::~Client()
{
    if(tcp_socket_ && tcp_socket_->isOpen())
        tcp_socket_->close();
}

void Client::connectToHost(QString host, int port)
{
    if(!tcp_socket_)
        tcp_socket_ = new QTcpSocket(this);
    tcp_socket_->connectToHost(host, port);

    if(tcp_socket_->waitForConnected(5000))
    {
        qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
        qDebug() << "  > " << "Success: connected to" << host << ":" << port;
    } else {
        qDebug().nospace() << Q_FUNC_INFO << " @ line " << __LINE__;
        qDebug() << "  > " << "Failure: couldn't connect to" << host << ":" << port;
    }
}

void Client::setReadFrequency(int ms)
{
    read_frequency_ = ms;
    if(ms <= 0)
        timer_->stop();
    else
        timer_->start(read_frequency_);
}

int Client::getReadFrequency() const
{
    return read_frequency_;
}

bool Client::sendToHost(const QByteArray &msg, int wait_written)
{
    if(!tcp_socket_ || !tcp_socket_->isOpen())
        return false;
    tcp_socket_->write(msg);
    if(wait_written > 0 && !tcp_socket_->waitForBytesWritten(wait_written))
        return false;
    return true;
}

void Client::checkMessage()
{
    if(tcp_socket_ && tcp_socket_->bytesAvailable())
        emit messageReceived(tcp_socket_->readAll());
}

void Client::init()
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout,
            this, &Client::checkMessage);
    timer_->start(read_frequency_);
}
