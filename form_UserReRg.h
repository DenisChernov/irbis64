/* 
 * File:   form_UserReRg.h
 * Author: f10-kafedra
 *
 * Created on 11 Октябрь 2011 г., 15:18
 */

#ifndef _FORM_USERRERG_H
#define	_FORM_USERRERG_H

#include "ui_form_UserReRg.h"

#include <iostream>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtCore/QTextCodec>
#include <QtCore/QStringListModel>
#include <QtWidgets/QCompleter>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>


#include <boost/thread.hpp>
#include <stdlib.h>
#include <time.h>
#include "bdOper.h"
#include "parser.h"
#include "datetime.h"
#include "engine.h"
//#include "structs.h"

//using namespace std;

class form_UserReRg : public QDialog {
    Q_OBJECT
public:
    form_UserReRg();
    virtual ~form_UserReRg();
    
    vector <QString> record;
    datetime dt;
    datetime lastDT;
    
private:
    Ui::form_UserReRg form_UserReReg;
    parser pars;
    engine* irbis64;
    vector <customers> dbCustomer;
    vector <string> deleted;
    boost::thread Thread;
    
    void fillFilials();
    void addUserInList(QStringList);
    bool checkAlreadyInList(QString);
    unsigned int currentRecord;
    QTimer* timerSearchByFIO;
    QTimer* timerRaiseMsg;
    void updateRecords();
    
    // Создание автопосещений
    void makeAutoVisits(int countVisits);
    
private slots:
    void slotSearchByID();
    void slotSearch();
    void slotShowContextMenu(const QPoint &);
    void slotDeleteItem();
    void slotSendUpdatedRecords();
    void slot_DefenceFromDuplicate(int);
    void slot_DateChanged(QDate);
    void slot_fioChanged(QString);
    
    void slot_DebugViewFrontRecord();
    void slot_DebugViewBackRecord();
    void slot_DebugViewNextRecord();
    void slot_DebugViewPrevRecord();
    
    //void slot_SendTestRequest();
    void slot_timerGO();
    
    void slot_timerHideMsg();
    /*
     *  включаем / выключаем не используемые методы поиска
     */
    void slot_EnableDisableSearchingMethods(QString txt);
    
protected:    
    void keyPressEvent(QKeyEvent *event);
};

#endif	/* _FORM_USERRERG_H */

