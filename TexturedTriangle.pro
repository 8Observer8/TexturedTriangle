#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T10:23:23
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TexturedTriangle
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp \
    Triangle.cpp \
    glFunctions.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Triangle.h \
    glFunctions.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc \
    Textures.qrc
