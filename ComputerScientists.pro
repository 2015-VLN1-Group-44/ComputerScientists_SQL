QT += core
QT -= gui
QT += core sql

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    scientist.cpp \
    interface.cpp \
    service.cpp \
    repository.cpp

HEADERS += \
    scientist.h \
    interface.h \
    constants.h \
    service.h \
    repository.h

DISTFILES += \
    data.txt

@QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9@
