TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    agenda.cpp \
    reloj.cpp \
    comanda.cpp \
    tarea.cpp \
    fecha.cpp \
    token.cpp \
    menu.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    agenda.h \
    reloj.h \
    comanda.h \
    tarea.h \
    token.h \
    menu.h \
    fecha.h

