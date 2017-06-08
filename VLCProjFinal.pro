#-------------------------------------------------
#
# Project created by QtCreator 2017-06-08T13:59:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLCProjFinal
TEMPLATE = app


SOURCES += main.cpp\
        vlcproj.cpp \
    sem.cpp \
    Sync.cpp \
    Thread.cpp \
    Consumer.cpp \
    Error.cpp \
    Producer.cpp

HEADERS  += vlcproj.h \
    sem.h \
    Sync.h \
    Thread.h \
    Buffer.h \
    Consumer.h \
    Error.h \
    Producer.h

FORMS    += vlcproj.ui
