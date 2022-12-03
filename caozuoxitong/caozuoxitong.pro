#-------------------------------------------------
#
# Project created by QtCreator 2022-05-20T19:25:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = caozuoxitong
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    fifo.cpp \
    lru.cpp \
    opt.cpp

HEADERS  += mainwindow.h \
    form.h \
    fifo.h \
    lru.h \
    opt.h

FORMS    += mainwindow.ui \
    form.ui \
    fifo.ui \
    lru.ui \
    opt.ui

RESOURCES +=
