/* 
 * File:   formLogin.h
 * Author: f10-kafedra
 *
 * Created on 16 Октябрь 2011 г., 14:47
 */

#ifndef _FORMLOGIN_H
#define	_FORMLOGIN_H

//#include <QString>
#include "ui_formLogin.h"
#include "bdOper.h"
//#include "tcpSocket.h"

class formLogin : public QDialog {
    Q_OBJECT
public:
    formLogin();
    virtual ~formLogin();
    
    bdOper bd;
    QString myIP;
    //tcpSocket* client;
    
private:
    Ui::formLogin form_Login;
    
private slots:
    void slotLogin();
    
};

#endif	/* _FORMLOGIN_H */

