#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QLabel>

#include "server.h"

#include "client_widget.h"
#include "udp_broadcast_client.h"

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        UdpBroadcastClient* client_;
};

#endif // MAINWINDOW_HPP
