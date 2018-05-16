#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , client_(0)
{
   client_ = new UdpBroadcastClient(this);
   connect(client_, &UdpBroadcastClient::messageReceived,
           this, [=](const QByteArray& arr) {
        qDebug() << arr;
   });
}

MainWindow::~MainWindow()
{}

