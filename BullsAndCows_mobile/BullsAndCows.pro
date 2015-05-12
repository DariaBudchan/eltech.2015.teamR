#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T10:00:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BullsAndCows
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    custompushbutton.cpp \
    customlabel.cpp \
    numpad.cpp \
    menu.cpp \
    numscore.cpp \
    secretnumber.cpp \
    stepresult.cpp \
    steps.cpp \
    game.cpp \
    scoreworker.cpp \
    endgamewindow.cpp \
    scorewindow.cpp \
    infowindow.cpp

HEADERS  += dialog.h \
    custompushbutton.h \
    customlabel.h \
    numpad.h \
    menu.h \
    numscore.h \
    secretnumber.h \
    stepresult.h \
    steps.h \
    game.h \
    scoreworker.h \
    endgamewindow.h \
    scorewindow.h \
    infowindow.h

RESOURCES += \
    resource.qrc
