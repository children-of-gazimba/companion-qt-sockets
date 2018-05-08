#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , server_(41736, this)
{
   client_widget_ = new ClientWidget(this);
   setCentralWidget(client_widget_);
}

MainWindow::~MainWindow()
{}

