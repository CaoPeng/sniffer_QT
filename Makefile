#############################################################################
# Makefile for building: window
# Generated by qmake (2.01a) (Qt 4.6.2) on: Sat May 5 13:39:42 2012
# Project:  window.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile window.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -L/usr/local/lib -lpcap -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		startdialog.cpp \
		highlighter.cpp \
		helpbrowser.cpp moc_mainwindow.cpp \
		moc_startdialog.cpp \
		moc_highlighter.cpp \
		moc_helpbrowser.cpp \
		qrc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		startdialog.o \
		highlighter.o \
		helpbrowser.o \
		moc_mainwindow.o \
		moc_startdialog.o \
		moc_highlighter.o \
		moc_helpbrowser.o \
		qrc_mainwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		window.pro
QMAKE_TARGET  = window
DESTDIR       = 
TARGET        = window

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_startdialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: window.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile window.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile window.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/window1.0.0 || $(MKDIR) .tmp/window1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/window1.0.0/ && $(COPY_FILE) --parents mainwindow.h startdialog.h highlighter.h helpbrowser.h .tmp/window1.0.0/ && $(COPY_FILE) --parents mainwindow.qrc .tmp/window1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp startdialog.cpp highlighter.cpp helpbrowser.cpp .tmp/window1.0.0/ && $(COPY_FILE) --parents mainwindow.ui startdialog.ui .tmp/window1.0.0/ && (cd `dirname .tmp/window1.0.0` && $(TAR) window1.0.0.tar window1.0.0 && $(COMPRESS) window1.0.0.tar) && $(MOVE) `dirname .tmp/window1.0.0`/window1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/window1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_startdialog.cpp moc_highlighter.cpp moc_helpbrowser.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_startdialog.cpp moc_highlighter.cpp moc_helpbrowser.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_startdialog.cpp: ui_startdialog.h \
		startdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) startdialog.h -o moc_startdialog.cpp

moc_highlighter.cpp: highlighter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) highlighter.h -o moc_highlighter.cpp

moc_helpbrowser.cpp: helpbrowser.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) helpbrowser.h -o moc_helpbrowser.cpp

compiler_rcc_make_all: qrc_mainwindow.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_mainwindow.cpp
qrc_mainwindow.cpp: mainwindow.qrc \
		images/new.png \
		images/find.png \
		images/splash.png \
		images/next.png \
		images/copy.png \
		images/cut.png \
		images/icon.png \
		images/save.png \
		images/paste.png \
		images/first.png \
		images/open.png \
		images/end.png \
		images/previous.png
	/usr/bin/rcc -name mainwindow mainwindow.qrc -o qrc_mainwindow.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_startdialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_startdialog.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_startdialog.h: startdialog.ui
	/usr/bin/uic-qt4 startdialog.ui -o ui_startdialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		startdialog.h \
		ui_startdialog.h \
		highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

startdialog.o: startdialog.cpp startdialog.h \
		ui_startdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o startdialog.o startdialog.cpp

highlighter.o: highlighter.cpp highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o highlighter.o highlighter.cpp

helpbrowser.o: helpbrowser.cpp helpbrowser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o helpbrowser.o helpbrowser.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_startdialog.o: moc_startdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_startdialog.o moc_startdialog.cpp

moc_highlighter.o: moc_highlighter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_highlighter.o moc_highlighter.cpp

moc_helpbrowser.o: moc_helpbrowser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_helpbrowser.o moc_helpbrowser.cpp

qrc_mainwindow.o: qrc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_mainwindow.o qrc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

