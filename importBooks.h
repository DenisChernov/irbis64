/* 
 * File:   importBooks.h
 * Author: F10-kafedra
 *
 * Created on 13 Февраль 2011 г., 15:47
 */

#ifndef IMPORTBOOKS_H
#define	IMPORTBOOKS_H

#include "ui_ui_importing.h"
#include <QtCore/QTimer>

//#include "parsing.h"
#include "engine.h"
#include "filework.h"
#include "boost/thread.hpp"

//#include "threads.h"
#include "consts.h"


class importBooks : public QDialog
{
    Q_OBJECT
public:
    //threadImportBooks thread;
    engine* irbis64;
    bool isConsole;
    
    importBooks();
    virtual ~importBooks();

    void run();
    
private:
    Ui::Importing imports;
    
    boost::thread Thread;
//    parser parsingBooks;
    int curRecord;
    int amountRecord;
    
    
    void startDownload();

protected:
    QTimer* timer;

public slots:
    void slotReadCurBook();

};

#endif	/* IMPORTBOOKS_H */

