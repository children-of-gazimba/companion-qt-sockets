#ifndef UDP_BROADCAST_CLIENT_H
#define UDP_BROADCAST_CLIENT_H

#include <QObject>

class QUdpSocket;
class QHostAddress;

class UdpBroadcastClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpBroadcastClient(QObject *parent = nullptr);
    explicit UdpBroadcastClient(unsigned port, QObject *parent = nullptr);

signals:
    void messageReceived(const QByteArray&, const QHostAddress&, unsigned);

public slots:

protected slots:
    virtual void processPendingDatagrams();

protected:
    void initSocket();

    QUdpSocket* socket_;
    unsigned port_;
};

#endif // UDP_BROADCAST_CLIENT_H
