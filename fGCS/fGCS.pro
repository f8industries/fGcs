#-------------------------------------------------
#
# Project created by QtCreator 2015-04-11T14:34:42
#
#-------------------------------------------------

QT       += core gui

QT += widgets network webkit webkitwidgets

TARGET = fGCS
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    systemparameters.cpp \
    videodecoder.cpp \
    qcgaugewidget.cpp

HEADERS  += mainwidget.h \
    systemparameters.h \
    videodecoder.h \
    ffmpeg.h \
    qcgaugewidget.h


INCLUDEPATH += C:\ffmpeg\include
INCLUDEPATH += $$PWD/../../../../../ffmpeg/include
DEPENDPATH += $$PWD/../../../../../ffmpeg/include

QMAKE_CXXFLAGS += -D__STDC_CONSTANT_MACROS
LIBS += -LC:\ffmpeg\lib
LIBS += -lavdevice
LIBS += -lavfilter
LIBS += -lpostproc
LIBS += -lavformat
LIBS += -lavcodec
LIBS += -lC:\ffmpeg\lib\avformat
LIBS += -lswresample
LIBS += -lswscale


#win32: LIBS += -L$$PWD/../../../../../ffmpeg/lib/ -lavutil
#win32: LIBS += -L$$PWD/../../../../../ffmpeg/lib/ -lavformat


DEFINES += __STDC_CONSTANT_MACROS
