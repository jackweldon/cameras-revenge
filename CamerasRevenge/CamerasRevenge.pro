#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T10:35:26
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamerasRevenge
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    delayform.cpp \
    editingtools.cpp \
    smtp.cpp

HEADERS  += mainwindow.h \
    delayform.h \
    editingtools.h \
    smtp.h

FORMS    += mainwindow.ui \
    delayform.ui \
    smtp.ui

RESOURCES += \
    Resources.qrc
