#-------------------------------------------------
#
# Project created by QtCreator 2015-08-05T22:36:51
#
#-------------------------------------------------

QT       += core gui

TARGET = tanks_v_1_3
TEMPLATE = app


SOURCES += main.cpp\
        mediator.cpp \
    map.cpp \
    tank.cpp \
    bullet.cpp \
    gamePlaying.cpp \
    mainmenu.cpp \
    about.cpp \
    score.cpp \
    bonus.cpp \
    dialog.cpp \
    endgame.cpp \
    bomber.cpp

HEADERS  += mediator.h \
    map.h \
    header.h \
    tank.h \
    bullet.h \
    gamePlaying.h \
    mainmenu.h \
    about.h \
    score.h \
    bonus.h \
    dialog.h \
    endgame.h \
    bomber.h

FORMS    += mediator.ui \
    mainmenu.ui \
    about.ui \
    dialog.ui \
    endgame.ui
