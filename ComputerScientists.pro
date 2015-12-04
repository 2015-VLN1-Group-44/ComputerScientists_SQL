QT += core
QT -= gui

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

