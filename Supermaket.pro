#-------------------------------------------------
#
# Project created by QtCreator 2023-05-23T23:37:15
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Supermaket
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    user_login.cpp \
    maketsql.cpp \
    dlg_addmak.cpp \
    picture.cpp

HEADERS += \
        mainwindow.h \
    user_login.h \
    maketsql.h \
    dlg_addmak.h \
    picture.h

FORMS += \
        mainwindow.ui \
    user_login.ui \
    dlg_addmak.ui \
    picture.ui

RESOURCES += \
    pos.qrc
