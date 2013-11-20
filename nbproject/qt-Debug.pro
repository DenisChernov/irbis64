# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = debug
TARGET = crossIrbis
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui network
SOURCES += datetime.cpp bdOper.cpp threads.cpp main.cpp isbnWork.cpp form_BookWork.cpp mainForm.cpp parser.cpp form_UserRegistration.cpp form_UserReRg.cpp tcpSocket.cpp form_Information.cpp formLogin.cpp
HEADERS += isbnWork.h mainForm.h form_Information.h structs.h form_UserRegistration.h parser.h datetime.h bdOper.h form_UserReRg.h threads.h tcpSocket.h form_BookWork.h formLogin.h passports.h
FORMS += form_UserRegistration.ui formLogin.ui form_UserReRg.ui form_Information.ui form_BookWork.ui mainForm.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/MinGW_Qt4.7.3-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc.exe
QMAKE_CXX = g++.exe
DEFINES += 
INCLUDEPATH += 
LIBS += -lQtNetworkd4  
