#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>

class UdpClient : public QObject
{
        Q_OBJECT
    public:
        explicit UdpClient(QObject *parent = nullptr);
        explicit UdpClient(unsigned port, QObject *parent = nullptr);
        explicit UdpClient(unsigned port, const QHostAddress &address, QObject *parent = nullptr);
        virtual ~UdpClient();

        bool hasPendingDatagrams();

    signals:
        void messageReceived(const QByteArray&, const QHostAddress&, unsigned);

    public slots:

    protected slots:
        virtual void processPendingDatagrams();

    protected:
        void initSocket();
        void initLocalSocket();

        QUdpSocket* socket_;

        QHostAddress ip_;
        unsigned port_;

};

#endif // UDP_CLIENT_H
