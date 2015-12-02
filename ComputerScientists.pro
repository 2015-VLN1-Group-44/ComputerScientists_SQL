QT += core
QT -= gui

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    scientist.cpp \
    database.cpp \
    interface.cpp

HEADERS += \
    scientist.h \
    database.h \
    interface.h

DISTFILES += \
    data.txt

