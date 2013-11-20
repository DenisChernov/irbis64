/* 
 * File:   form_BookWork.h
 * Author: f10-kafedra
 *
 * Created on 16 Ноябрь 2011 г., 15:33
 */

#ifndef _FORM_BOOKWORK_H
#define	_FORM_BOOKWORK_H

#include "ui_form_BookWork.h"
#include "isbnWork.h"
#include "form_bookInfo.h"
#include <QtCore/QTimer>
//#include <QMessageBox>
//#include <QString>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class form_BookWork : public QDialog {
    Q_OBJECT
public:
    form_BookWork();
    virtual ~form_BookWork();
    
    
private:
    Ui::form_BookWork formBookSearch;
    isbnWork* isbn;
    form_bookInfo formManyBooks;
    boost::thread Thread;   
    QTimer* timer;
    
    void checkSearchStage();
    
private slots:
    void slotSearchByISBN();
    void slotViewBooks();
    
};

#endif	/* _FORM_BOOKWORK_H */

