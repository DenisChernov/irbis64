/* 
 * File:   form_DownloadBooks.h
 * Author: f10-kafedra
 *
 * Created on 8 Апрель 2012 г., 11:48
 */

#ifndef _FORM_DOWNLOADBOOKS_H
#define	_FORM_DOWNLOADBOOKS_H

#include "ui_form_DownloadBooks.h"
#include "engine.h"
#include "filework.h"
#include "boost/thread.hpp"

class form_DownloadBooks : public QDialog {
    Q_OBJECT
public:
    form_DownloadBooks();
    virtual ~form_DownloadBooks();
    
    
    
private:
    Ui::form_DownloadBooks frmDownloadBooks;
    
    engine* irbis64;
    void downloadBooks();
    void uploadBooks();
    void prepareBooks();
    boost::thread Thread;
    
private slots:    
    void slotGetBooks();
    void slotUploadBooks();
    void slotPrepareFiles();
    void slotChangeBD(QString bd);
    void slotlogin();
};

#endif	/* _FORM_DOWNLOADBOOKS_H */
