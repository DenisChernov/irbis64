/*
 * File:   formLogin.cpp
 * Author: f10-kafedra
 *
 * Created on 16 Октябрь 2011 г., 14:47
 */

#include "formLogin.h"

formLogin::formLogin() {
    form_Login.setupUi(this);
    connect(form_Login.pbLogin, SIGNAL(clicked()), this, SLOT(slotLogin()));
    
}

formLogin::~formLogin() {
}

void formLogin::slotLogin()
{
    if (form_Login.cbSaveAccount->isChecked() && form_Login.leLogin->text().length() > 0 && form_Login.lePassword->text().length() > 0)
    {
        bd.saveAccount(form_Login.leLogin->text(), form_Login.lePassword->text(), myIP);
        //client->login = form_Login.leLogin->text();
        //client->pass = form_Login.lePassword->text();
    }
    
    this->close();
}