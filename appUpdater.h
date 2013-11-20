/* 
 * File:   appUpdater.h
 * Author: demiin
 *
 * Created on August 14, 2013, 10:21 AM
 */

#ifndef APPUPDATER_H
#define	APPUPDATER_H

#include "ui_appUpdater.h"

#include <ace/INET_Addr.h>
#include <ace/SOCK_Acceptor.h>
#include <ace/SOCK_Connector.h>
#include <ace/SOCK_Stream.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <boost/filesystem.hpp>
#include <QtWidgets/QMessageBox>

using namespace std;
using namespace boost::filesystem;

class appUpdater : public QMainWindow {
    Q_OBJECT
public:
    appUpdater(string currentAppFile);
    virtual ~appUpdater();
private:
    Ui::appUpdater widget;
    
    /*
     *  адрес помещается в myip;
     */
    void myIP();
    
    /*
     *  проверка и получение обновления
     */
    bool checkFilesAndUpdate();
    
    /*
     *   перезапуск приложения после обновления
     */
    void restartApp();

    
    string myip;
    string appPath;
};

#endif	/* APPUPDATER_H */
