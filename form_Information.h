/* 
 * File:   form_Information.h
 * Author: f10-kafedra
 *
 * Created on 26 Сентябрь 2011 г., 17:11
 */

#ifndef _FORM_INFORMATION_H
#define	_FORM_INFORMATION_H

#include "ui_form_Information.h"
#include <QtCore/QTimer>
#include <QtCore/QTextCodec>
#include <QtCore/QFile>
#include <QtCore/QProcess>
#include <boost/thread.hpp>
#include <QtCore/QLibrary>
#include "parser.h"
//#include "tcpSocket.h"
#include "engine.h"
#include "datetime.h"
#include "form_loadfile.h"
//#include "../lib/Updater/updater.h"

#define MSG_CREATEBD_X 10
#define MSG_CREATEBD_Y 10
#define MSG_CREATEBD_W 281
#define MSG_CREATEBD_H 111

#define FORM_CREATEBD_W 301
#define FORM_CREATEBD_H 131

#define FORM_W 499
#define FORM_H 656

#define fBD "infos.bd"

#define CGB_SBO "ЦГБ СБО"
#define CGB_SBO_TEL "телефон"

class form_Information : public QDialog {
    Q_OBJECT
public:
    form_Information(QString appName);
    virtual ~form_Information();
    bool checkBDFile();
    
    //form_loadfile wndLoadInfos;
    //tcpSocket* client;
    parser* parsing;
    
    QTimer* timerCreateBD;
    vector <info> infos;
    datetime dt;
    QString filialName;
    QString fromWho;
    QString appFullPath;
    //thread_LoadFile* tLoadFile;
    int from;
    int to;
    
private:
    Ui::form_Information form_Info;
    boost::thread Thread;
    engine* irbis64;
    QStringList tmpList;
    QTimer* timerFillTable;
    
    void fillAmountTypesInfo();
    void fillTable(QStringList parametrs);
    void clearTable();
    void flushBD();
    void loadFile();
    void fillFilials();
    void getInfosList();
    
private slots:    
    void slotGetInfosFromIrbis64ByParametrs();
    void slotAddToList();
    void slotRemoveFromList();
    void slotSendInfosToIrbis64();
    void slotFilialChanged(QString);
    //void slotLoadFileFinished();
    void slotRowFilled();
    
    void slotTimer_FillTable();
    
    void slotHideInfoStatus();
};

#endif	/* _FORM_INFORMATION_H */

