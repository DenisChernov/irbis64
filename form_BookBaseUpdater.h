/*
 * File:   form_BookBaseUpdater.h
 * Author: f10-kafedra
 *
 * Created on October 6, 2012, 6:21 PM
 */

#ifndef _FORM_BOOKBASEUPDATER_H
#define	_FORM_BOOKBASEUPDATER_H

#include "ui_form_BookBaseUpdater.h"
#include "engine.h"
#include "consts.h"
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <QtCore/QTemporaryFile>
#include <QtCore/QTextStream>
#include <iostream>
#include <fstream>

using namespace std;

class form_BookBaseUpdater : public QDialog {
    Q_OBJECT
public:
    form_BookBaseUpdater();
    virtual ~form_BookBaseUpdater();

    void runUpdate();
    void recvBooks();
    void parseBooks();
    
    /*
     *  очистить все таблицы
     */
    void truncateAllTables();
    
    /*
     *  записать книги в базу
     */
    void sendBooks();
    
private:
    Ui::form_BookBaseUpdater frmBookBaseUpdater;

    engine* irbis64;
    boost::thread threadRecv;
    boost::thread threadParse;

    parser parsBook;
    string buffer;
    
    /*
     *  список филиалов. имя филиала, индекс, 
     */
    map <string, int> filials;
};

#endif	/* _FORM_BOOKBASEUPDATER_H */
