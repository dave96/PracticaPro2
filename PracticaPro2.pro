TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    agenda.cc \
    comanda.cc \
    fecha.cc \
    main.cc \
    menu.cc \
    reloj.cc \
    tarea.cc \
    token.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    agenda.hh \
    comanda.hh \
    fecha.hh \
    menu.hh \
    tarea.hh \
    reloj.hh \
    token.hh

