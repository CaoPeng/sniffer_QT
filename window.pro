# -------------------------------------------------
# Project created by QtCreator 2011-12-01T18:42:15
# -------------------------------------------------
TARGET = window
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    startdialog.cpp \
    domitem.cpp \
    dommodel.cpp
HEADERS += mainwindow.h \
    startdialog.h \
    domitem.h \
    dommodel.h
FORMS += mainwindow.ui \
    startdialog.ui
RESOURCES = mainwindow.qrc
LIBS += -L/usr/local/lib \
    -lpcap
QT += xml
