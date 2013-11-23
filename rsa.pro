#-------------------------------------------------
#
# Project created by QtCreator 2013-10-30T04:00:10
#
#-------------------------------------------------

QT       += core gui

TARGET = rsa
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \


FORMS    += mainwindow.ui
INCLUDEPATH += $$PWD/bigint
DEPENDPATH += $$PWD/bigint
LIBS += $$PWD/bigint/debug/bigint.lib



