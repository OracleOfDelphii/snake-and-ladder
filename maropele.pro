TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT -= gui
QT+= core
SOURCES += main.cpp \
    algorithm.cpp \
    functions.cpp
LIBS +=  -lSDL2main -lSDL2 -lSDL2_mixer -lncurses
HEADERS += \
    algorithm.h \
    header.h

DISTFILES += \
    sound/roll.wav \
    ../build-maropele-Desktop_Qt_5_10_0_GCC_64bit-Debug/sound/main.mp3
