#-------------------------------------------------
#
# Project created by QtCreator 2019-05-09T16:22:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kompsitor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        RtMidi.cpp \
        Synthesizer.cpp \
        clickinglabel.cpp \
        eigthnote.cpp \
        eigthpausenote.cpp \
        halfnote.cpp \
        main.cpp \
        kompsitor.cpp \
        note.cpp \
        quaternote.cpp \
        quaterpausenote.cpp \
        sheet.cpp

HEADERS += \
        RtMidi.h \
        Synthesizer.h \
        clickinglabel.h \
        eigthnote.h \
        eigthpausenote.h \
        halfnot.h \
        kompsitor.h \
        note.h \
        noteenums.h \
        quaternote.h \
        quaterpausenote.h \
        sheet.h

FORMS += \
        kompsitor.ui

LIBS += -lwinmm
DEFINES += __WINDOWS_MM__

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    graphics.qrc
