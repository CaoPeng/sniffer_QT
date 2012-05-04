# -------------------------------------------------
# Project created by QtCreator 2011-12-01T18:42:15
# -------------------------------------------------
TARGET = window
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    startdialog.cpp \
    highlighter.cpp
HEADERS += mainwindow.h \
    startdialog.h \
    highlighter.h
FORMS += mainwindow.ui \
    startdialog.ui
RESOURCES = mainwindow.qrc
#RC_FILE = mainwindow.rc
LIBS += -L/usr/local/lib \
    -lpcap
#QT += xml
