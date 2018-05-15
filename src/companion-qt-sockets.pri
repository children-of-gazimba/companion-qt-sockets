INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui widgets network

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    DEFINES += SUPERVERBOSE
}

HEADERS += $$PWD/client.h \
           $$PWD/server.h \
           $$PWD/network_message.h
           
SOURCES += $$PWD/client.cpp \
           $$PWD/server.cpp \
           $$PWD/network_message.cpp 