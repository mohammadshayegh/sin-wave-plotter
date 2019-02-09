#-------------------------------------------------
#
# Project created by QtCreator 2018-10-20T18:55:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SinPlotter
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp


HEADERS += \
        mainwindow.h \
    qcustomplot.h

FORMS += \
        mainwindow.ui
