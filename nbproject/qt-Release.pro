# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = .
TARGET = crossIrbis
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui
SOURCES += appUpdater.cpp bdOper.cpp bookParsing.cpp datetime.cpp engine.cpp filework.cpp formLogin.cpp form_BookBaseUpdater.cpp form_BookWork.cpp form_DownloadBooks.cpp form_Information.cpp form_UserReRg.cpp form_UserRegistration.cpp form_bookInfo.cpp form_loadfile.cpp importBooks.cpp isbnWork.cpp main.cpp parser.cpp searchBook.cpp
HEADERS += appUpdater.h bdOper.h bookParsing.h consts.h datetime.h engine.h filework.h formLogin.h form_BookBaseUpdater.h form_BookWork.h form_DownloadBooks.h form_Information.h form_UserReRg.h form_UserRegistration.h form_bookInfo.h form_loadfile.h importBooks.h isbnWork.h parser.h passports.h searchBook.h structs.h
FORMS += appUpdater.ui formLogin.ui form_BookBaseUpdater.ui form_BookWork.ui form_DownloadBooks.ui form_Information.ui form_UserReRg.ui form_UserRegistration.ui form_bookInfo.ui form_loadfile.ui searchBook.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += ../psql/9.0/lib/libpq.a ../../Qt/4.8.0/lib/libcurl.a -lcurl -lpq -lACE  
equals(QT_MAJOR_VERSION, 4) {
QMAKE_CXXFLAGS += -std=c++11
}
equals(QT_MAJOR_VERSION, 5) {
CONFIG += c++11
}
