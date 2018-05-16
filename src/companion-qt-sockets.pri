INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui widgets network

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    DEFINES += SUPERVERBOSE
}

HEADERS += $$PWD/client.h \
           $$PWD/server.h \
           $$PWD/udp_broadcast_server.h \
           $$PWD/udp_broadcast_client.h \
           $$PWD/network_message.h
           
SOURCES += $$PWD/client.cpp \
           $$PWD/server.cpp \
           $$PWD/udp_broadcast_server.cpp \
           $$PWD/udp_broadcast_client.cpp \
           $$PWD/network_message.cpp 