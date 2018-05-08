#include "mainwindow.hpp"
#include <QApplication>

#include "server.hpp"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Server s(41736);
    Client c;
    c.connect("192.168.1.128", 41736);

    return a.exec();
}
