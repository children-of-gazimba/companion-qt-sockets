#include "mainwindow.hpp"
#include <QApplication>

#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Client c(this);

    return a.exec();
}
