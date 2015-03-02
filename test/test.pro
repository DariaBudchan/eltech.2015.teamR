#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T16:53:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        startwindow.cpp \
    menuwindow.cpp \
    magicwindow.cpp \
    ruleswindow.cpp \
    scorewindow.cpp \
    playwindow.cpp \
    numpad.cpp \
    numscreen.cpp \
    game.cpp \
    secretnumber.cpp \
    stepresult.cpp \
    gamewidget.cpp

HEADERS  += startwindow.h \
    menuwindow.h \
    magicwindow.h \
    ruleswindow.h \
    scorewindow.h \
    playwindow.h \
    numpad.h \
    numscreen.h \
    game.h \
    secretnumber.h \
    stepresult.h \
    gamewidget.h

RESOURCES += \
    res.qrc
