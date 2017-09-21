#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T21:44:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    game.cpp \
    figure.cpp

HEADERS  += widget.h \
    game.h \
    figure.h
