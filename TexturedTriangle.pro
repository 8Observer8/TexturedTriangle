#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T10:23:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TexturedTriangle
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp \
    Triangle.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Triangle.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc \
    Textures.qrc
