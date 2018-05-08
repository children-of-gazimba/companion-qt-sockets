INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui widgets network

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    DEFINES += SUPERVERBOSE
}

HEADERS += $$PWD/client.h \
           $$PWD/server.h 
           
SOURCES += $$PWD/client.cpp \
           $$PWD/server.cpp 