#############################################################################
# Makefile for building: crossIrbis
# Generated by qmake (2.01a) (Qt 4.7.3) on: ?? 6. ??? 10:22:57 2011
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: c:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/bin/qmake.exe -spec ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/win32-g++ VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc.exe
CXX           = g++.exe
DEFINES       = -DUNICODE -DQT_LARGEFILE_SUPPORT -DQT_DLL -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_HAVE_MMX -DQT_HAVE_3DNOW -DQT_HAVE_SSE -DQT_HAVE_MMXEXT -DQT_HAVE_SSE2 -DQT_THREAD_SUPPORT -DQT_NEEDS_QMAIN
CFLAGS        = -g -Wall $(DEFINES)
CXXFLAGS      = -g -frtti -fexceptions -mthreads -Wall $(DEFINES)
INCPATH       = -I'../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/include/QtCore' -I'../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/include/QtNetwork' -I'../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/include/QtGui' -I'../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/include' -I'../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/include/ActiveQt' -I'.' -I'.' -I'nbproject' -I'.' -I'../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/win32-g++'
LINK        =        g++
LFLAGS        =        -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc -mthreads -Wl -Wl,-subsystem,windows
LIBS        =        -L'c:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/lib' -lmingw32 -lqtmaind build/Debug/MinGW_Qt4.7.3-Windows/crossIrbis_resource_res.o -lQtNetworkd4 -lQtGuid4 -lQtNetworkd4 -lQtCored4 -LC:\OpenSSL-Win32_full\lib 
QMAKE         = c:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/bin/qmake.exe
IDC           = c:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/binidc.exe
IDL           = midl
ZIP           = zip -r -9
DEF_FILE      = 
RES_FILE      = build/Debug/MinGW_Qt4.7.3-Windows/crossIrbis_resource_res.o
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
DEL_FILE      = rm
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir
INSTALL_FILE    = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR     = $(COPY_DIR)

####### Output directory

OBJECTS_DIR   = build/Debug/MinGW_Qt4.7.3-Windows/

####### Files

SOURCES       = main.cpp \
		mainForm.cpp moc_mainForm.cpp
OBJECTS       = build/Debug/MinGW_Qt4.7.3-Windows/main.o \
		build/Debug/MinGW_Qt4.7.3-Windows/mainForm.o \
		build/Debug/MinGW_Qt4.7.3-Windows/moc_mainForm.o
DIST          = 
QMAKE_TARGET  = crossIrbis
DESTDIR        = dist/Debug/MinGW_Qt4.7.3-Windows/ #avoid trailing-slash linebreak
TARGET         = crossIrbis.exe
DESTDIR_TARGET = dist/Debug/MinGW_Qt4.7.3-Windows/crossIrbis.exe

####### Implicit rules

.SUFFIXES: .cpp .cc .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

first: all
all: qttmp-Debug.mk  $(DESTDIR_TARGET)

$(DESTDIR_TARGET): ui_mainForm.h $(OBJECTS) build/Debug/MinGW_Qt4.7.3-Windows/crossIrbis_resource_res.o
	$(LINK) $(LFLAGS) -o $(DESTDIR_TARGET) $(OBJECTS)  $(LIBS)


build/Debug/MinGW_Qt4.7.3-Windows/crossIrbis_resource_res.o: crossIrbis_resource.rc
	windres -i crossIrbis_resource.rc -o build/Debug/MinGW_Qt4.7.3-Windows/crossIrbis_resource_res.o --include-dir=. $(DEFINES)

qttmp-Debug.mk: nbproject/qt-Debug.pro  ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/qconfig.pri \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/modules/qt_webkit_version.pri \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt_functions.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt_config.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/exclusive_builds.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/default_pre.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/default_pre.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/debug.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/default_post.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/default_post.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/rtti.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/exceptions.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/stl.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/shared.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/warn_on.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/thread.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/moc.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/windows.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/resources.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/uic.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/yacc.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/lex.prf \
		../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/include_source_dir.prf \
		c:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/lib/qtmaind.prl
	$(QMAKE) -spec ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/win32-g++ VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/qconfig.pri:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/modules/qt_webkit_version.pri:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt_functions.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt_config.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/exclusive_builds.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/default_pre.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/default_pre.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/debug.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/default_post.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/default_post.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/rtti.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/exceptions.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/stl.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/shared.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/warn_on.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/thread.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/moc.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/windows.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/resources.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/uic.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/yacc.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/lex.prf:
../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/include_source_dir.prf:
c:\Qt\4.7.3\Desktop\Qt\4.7.3\mingw\lib\qtmaind.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/win32-g++ VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist:
	$(ZIP) crossIrbis.zip $(SOURCES) $(DIST) nbproject/nbproject/qt-Debug.pro ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/qconfig.pri ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/modules/qt_webkit_version.pri ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt_functions.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt_config.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/exclusive_builds.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/default_pre.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/default_pre.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/debug.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/default_post.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/default_post.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/rtti.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/exceptions.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/stl.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/shared.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/warn_on.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/qt.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/thread.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/moc.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/win32/windows.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/resources.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/uic.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/yacc.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/lex.prf ../../../Qt/4.7.3/Desktop/Qt/4.7.3/mingw/mkspecs/features/include_source_dir.prf c:\Qt\4.7.3\Desktop\Qt\4.7.3\mingw\lib\qtmaind.prl  HEADERS RESOURCES IMAGES SOURCES OBJECTIVE_SOURCES FORMS YACCSOURCES YACCSOURCES LEXSOURCES 

clean: compiler_clean 
	-$(DEL_FILE) build/Debug/MinGW_Qt4.7.3-Windows/main.o build/Debug/MinGW_Qt4.7.3-Windows/mainForm.o build/Debug/MinGW_Qt4.7.3-Windows/moc_mainForm.o
	-$(DEL_FILE) build/Debug/MinGW_Qt4.7.3-Windows/crossIrbis_resource_res.o

distclean: clean
	-$(DEL_FILE) $(DESTDIR_TARGET)
	-$(DEL_FILE) qttmp-Debug.mk

check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainForm.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainForm.cpp
moc_mainForm.cpp: ui_mainForm.h \
		mainForm.h
	C:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/binmoc.exe $(DEFINES) $(INCPATH) -D__GNUC__ -DWIN32 mainForm.h -o moc_mainForm.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainForm.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainForm.h
ui_mainForm.h: mainForm.ui
	c:/Qt/4.7.3/Desktop/Qt/4.7.3/mingw/binuic.exe mainForm.ui -o ui_mainForm.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 



####### Compile

build/Debug/MinGW_Qt4.7.3-Windows/main.o: main.cpp mainForm.h \
		ui_mainForm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/MinGW_Qt4.7.3-Windows/main.o main.cpp

build/Debug/MinGW_Qt4.7.3-Windows/mainForm.o: mainForm.cpp mainForm.h \
		ui_mainForm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/MinGW_Qt4.7.3-Windows/mainForm.o mainForm.cpp

build/Debug/MinGW_Qt4.7.3-Windows/moc_mainForm.o: moc_mainForm.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/MinGW_Qt4.7.3-Windows/moc_mainForm.o moc_mainForm.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
