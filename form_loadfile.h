/* 
 * File:   form_loadfile.h
 * Author: f10-kafedra
 *
 * Created on 18 Январь 2012 г., 17:41
 */

#ifndef _FORM_LOADFILE_H
#define	_FORM_LOADFILE_H

#include "ui_form_loadfile.h"

class form_loadfile : public QDialog {
    Q_OBJECT
public:
    form_loadfile();
    void setCount(int count);
    virtual ~form_loadfile();
private:
    Ui::form_loadfile formLoadInfos;
};

#endif	/* _FORM_LOADFILE_H */
