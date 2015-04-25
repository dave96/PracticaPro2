TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    agenda.cpp \
    reloj.cpp \
    comanda.cpp \
    tarea.cpp \
    etiqueta.cpp \
    fecha.cpp \
    hora.cpp \
    dia.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    agenda.h \
    reloj.h \
    comanda.h \
    tarea.h \
    etiqueta.h \
    fecha.h \
    hora.h \
    dia.h

