/* 
 * File:   form_UserRegistration.h
 * Author: f10-kafedra
 *
 * Created on 20 Сентябрь 2011 г., 13:18
 */

#ifndef _FORM_USERREGISTRATION_H
#define	_FORM_USERREGISTRATION_H

#include "ui_form_UserRegistration.h"
#include <iostream>
#ifdef WIN32
    #include <QtCore/QRegExp>
    #include <QtCore/QTextCodec>
    #include <QtCore/QTimer>
    #include <QtCore/QFile>
    #include <QtCore/QTextStream>
    #include <QtWidgets/QMessageBox>
#else
    #include <QRegExp>
    #include <QTextCodec>
    #include <QTimer>
    #include <QFile>
    #include <QTextStream>
    #include <QMessageBox>
#endif
#include "datetime.h"
#include "formLogin.h"
#include "engine.h"

const int maxHeightForm = 720;
const int middleHeightForm = 620;
const int minHeightForm = 501;

using namespace std;

class form_UserRegistration : public QDialog {
    Q_OBJECT
public:
    form_UserRegistration(QStringList filialList, QString ip);
    virtual ~form_UserRegistration();

    formLogin form_Login;
    
    QString filialName;
    QStringList filials;
    passportsData len_ovd;
    passportsData len_oufms;
    passportsData okt_ovd;
    passportsData okt_oufms;
    passportsData perv_ovd;
    passportsData perv_oufms;
    
    
private:
    Ui::form_UserRegistration form_UserReg;
    datetime* dt;
    char UserGender;
    QRegExp re;
    int maxWorkAge;
    QTimer* timerCheckUsers;
    bool isOVD;
    engine* irbis64;
    catalogs catalog;
    int indexMurmansk;
    
    /*
     *  Загрузка справочников
     */
    void loadConfFile();
    
    /*
     *  Загрузка соотношений мест регистраций и улиц
     */
    void loadCfgFile();
    void setIndexPlaceOfIssue(QString);
    QString removeLastsSpaces(QString);
    
    /*
     *  Очистка полей данных о читателе
     */
    void clearFields();
    
private slots:
    void slotOnBirthYearChange(QString);
    void slotOnFamChange(QString);
    void slotOnAdditionalAddress();
    void slotRegUser();
    void slotClearForm();
    void slotKeyPressed();
    void slotStreetChanged(QString);
    /*
     *  проверяет - есть ли пользователь в базе
     */
    void slotCheckUserExists(QString);
    
    /*
     * 
     */
    void slotSetOVD_OUFMS_Year(QString);
};

#endif	/* _FORM_USERREGISTRATION_H */

