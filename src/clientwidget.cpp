#include "clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) : QWidget(parent)
{
    initLayout();

    connect(client_connect_button_, &QPushButton::clicked,
            this, &ClientWidget::onConnectButtonPress);
}

void ClientWidget::initLayout() {
   ip_edit_ = new QLineEdit(this);
   ip_edit_->setPlaceholderText("IP-Address");

   port_edit_ = new QLineEdit("41736", this);
   port_edit_->setPlaceholderText("Port");

   client_connect_button_ = new QPushButton("Connect", this);

   QHBoxLayout *outter = new QHBoxLayout;
   outter->addWidget(ip_edit_, 6);
   outter->addWidget(port_edit_, 2);
   outter->addWidget(client_connect_button_, 2);

   setLayout(outter);
}


void ClientWidget::onConnectButtonPress() {
    QString ip = ip_edit_->text();
    int port = port_edit_->text().toInt();

    client_.connect(ip, port);
}
