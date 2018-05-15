#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

/**
 * Implements a client socket in a tcp connection.
 * Offers a timer based update interface to receive bytes from the host
 * and can send bytes to the host.
*/
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    explicit Client(int read_frequency, QObject *parent = nullptr);

    virtual ~Client();

    /**
     * Connects to service identified by given host ip and port.
    */
    virtual void connectToHost(QString host, int port);

    /**
    * Sets the checkMessage update frequency in milliseconds.
    * If value is <= 0 automatic update will be disabled.
    */
    void setReadFrequency(int ms);

    /**
    * Gets the checkMessage update frequency in milliseconds.
    * If value is <= 0 automatic update is disabled.
    */
    int getReadFrequency() const;

    /**
     * Sends given QByteArray to the connected remote host.
     * A wait time can be specified, to wait for the acknowledgement
     * of sent package. Per default the class doesn't block for delivery.
     * Returns success of operation.
    */
    bool sendToHost(const QByteArray& msg, int wait_written = -1);

signals:
    void messageReceived(const QByteArray&);

public slots:
    /**
     * Tests if message can be received from host,
     * reads all bytes if available
     * and signals messageReceived if bytes read.
    */
    virtual void checkMessage();

protected:
    /**
     * called in constructor to initialize client setup.
    */
    virtual void init();

    QTcpSocket *tcp_socket_;
    QTimer* timer_;
    int read_frequency_;
};

#endif // CLIENT_H
