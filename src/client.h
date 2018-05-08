#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
        Q_OBJECT
    public:
        explicit Client(QObject *parent = nullptr);
        virtual ~Client();

        virtual void connect(QString host, int port);

    signals:

    public slots:

    protected:
        QTcpSocket *tcp_socket_;
};

#endif // CLIENT_H
