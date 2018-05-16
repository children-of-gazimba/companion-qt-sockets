#-------------------------------------------------
#
# Project created by QtCreator 2018-05-08T17:32:05
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = tcp-server
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    server.cpp \
    client.cpp \
    client_widget.cpp \
    main_window.cpp \
    network_message.cpp \
    udp_broadcast_client.cpp \
    udp_broadcast_server.cpp


HEADERS += \
    server.h \
    client.h \
    server.h \
    client_widget.h \
    main_window.h \
    network_message.h \
    udp_broadcast_client.h \
    udp_broadcast_server.h
