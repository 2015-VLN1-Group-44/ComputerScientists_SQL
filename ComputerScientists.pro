QT += core
QT -= gui

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    scientist.cpp \
    database.cpp

HEADERS += \
    scientist.h \
    database.h

DISTFILES += \
    listofCS.txt

