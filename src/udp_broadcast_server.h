#ifndef UDP_BROADCAST_SERVER_H
#define UDP_BROADCAST_SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class UdpBroadcastServer : public QObject
{
    Q_OBJECT
public:
    explicit UdpBroadcastServer(QObject *parent = nullptr);
    explicit UdpBroadcastServer(unsigned port, QObject *parent = nullptr);

    void setBroadcastFrequency(int ms);
    int getBroadcastFrequency() const;

signals:

public slots:

protected slots:
    virtual void broadcast();

protected:
    void initSocket();

    QUdpSocket* socket_;
    unsigned port_;
    QTimer* timer_;
    int broadcast_frequency_;
};

#endif // UDP_BROADCAST_SERVER_H
