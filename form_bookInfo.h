/* 
 * File:   form_bookInfo.h
 * Author: f10-kafedra
 *
 * Created on 26 Март 2012 г., 14:27
 */

#ifndef _FORM_BOOKINFO_H
#define	_FORM_BOOKINFO_H

#include "ui_form_bookInfo.h"
#include "structs.h"
#include <boost/thread.hpp>

class form_bookInfo : public QDialog {
    Q_OBJECT
public:
    form_bookInfo();
    virtual ~form_bookInfo();
    
    void loadBooks(vector<booksData>* loadedBooks);
    
private:
    Ui::form_bookInfo frm_BookInfo;
    vector<booksData>* books;
    
    void setBook(int number);

private slots:
    void slot_nextBook();
    void slot_prevBook();
    
};

#endif	/* _FORM_BOOKINFO_H */
