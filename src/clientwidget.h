#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QLabel>

#include <QHBoxLayout>

#include "client.h"

class ClientWidget : public QWidget
{
        Q_OBJECT
    public:
        explicit ClientWidget(QWidget *parent = nullptr);

    signals:

    public slots:
        void onConnectButtonPress();

    private:
        void initLayout();

    private:
        QLineEdit *ip_edit_;
        QLineEdit *port_edit_;
        QPushButton *client_connect_button_;
        Client client_;
};

#endif // CLIENTWIDGET_H
