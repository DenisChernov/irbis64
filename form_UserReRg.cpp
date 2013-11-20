/*
 * File:   form_UserReRg.cpp
 * Author: f10-kafedra
 *
 * Created on 11 Октябрь 2011 г., 15:18
 */

#include <boost/lexical_cast.hpp>

#ifdef WIN32
    #include <QtWidgets\QMessageBox>
#else
    #include <QMessageBox>
#endif

#include "form_UserReRg.h"

form_UserReRg::form_UserReRg(/*QStringList filialList*/) 
{
	setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/visits.png"), QSize(), QIcon::Normal, QIcon::Off);
    this->setWindowIcon(icon);
    dbCustomer.erase(dbCustomer.begin(), dbCustomer.end());
    deleted.erase(deleted.begin(), deleted.end());
    form_UserReReg.setupUi(this);

    currentRecord = 0;

    Thread = boost::thread (boost::bind(&form_UserReRg::fillFilials, this));
    
    connect(form_UserReReg.pbUpdateRecord, SIGNAL(clicked()), this, SLOT(slotSendUpdatedRecords()));
    connect(form_UserReReg.cbDefenceFromDuplicate, SIGNAL(stateChanged(int)), this, SLOT(slot_DefenceFromDuplicate(int)));
    connect(form_UserReReg.dt, SIGNAL(dateChanged(QDate)), this, SLOT(slot_DateChanged(QDate)));
    connect(form_UserReReg.leFIO, SIGNAL(textEdited(QString)), this, SLOT(slot_fioChanged(QString)));
    
    connect(form_UserReReg.leFIO, SIGNAL(textChanged(QString)), this, SLOT(slot_EnableDisableSearchingMethods(QString)));
    connect(form_UserReReg.leID, SIGNAL(textChanged(QString)), this, SLOT(slot_EnableDisableSearchingMethods(QString)));
    
    //connect(form_UserReReg.pbGET, SIGNAL(clicked()), this, SLOT(slot_SendTestRequest()));
   
    form_UserReReg.twUserList->setContextMenuPolicy(Qt::CustomContextMenu);
    form_UserReReg.leID->connect(form_UserReReg.leID, SIGNAL(returnPressed()), this, SLOT(slotSearch()/*ByID()*/));
    form_UserReReg.pbSearch->connect(form_UserReReg.pbSearch, SIGNAL(clicked()), this, SLOT(slotSearch()));
    form_UserReReg.twUserList->connect(form_UserReReg.twUserList, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slotShowContextMenu(const QPoint &)));
   
    QStringList labels;
    labels << "ФИО" << "Посещение";
    form_UserReReg.twUserList->setColumnCount(2);
    form_UserReReg.twUserList->setHorizontalHeaderLabels(labels);
    form_UserReReg.twUserList->setColumnWidth(1, 70);
    form_UserReReg.twUserList->setColumnWidth(0, 340);
    
    QDate date(dt.year().toInt(), dt.month().toInt(), dt.day().toInt());
    form_UserReReg.dt->setDate(date);

    irbis64 = new engine(APM_REREG, "irbisoft", "9f9@7Nuq");
    
    form_UserReReg.pbFront->connect(form_UserReReg.pbFront, SIGNAL(clicked()), this, SLOT(slot_DebugViewFrontRecord()));
    form_UserReReg.pbBack->connect(form_UserReReg.pbBack, SIGNAL(clicked()), this, SLOT(slot_DebugViewBackRecord()));
    form_UserReReg.pbNext->connect(form_UserReReg.pbNext, SIGNAL(clicked()), this, SLOT(slot_DebugViewNextRecord()));
    form_UserReReg.pbBefore->connect(form_UserReReg.pbBefore, SIGNAL(clicked()), this, SLOT(slot_DebugViewPrevRecord()));
    
    timerSearchByFIO = new QTimer(this);
    timerSearchByFIO->connect(timerSearchByFIO, SIGNAL(timeout()), this, SLOT(slot_timerGO()));
    
    connect(form_UserReReg.twUserList->model(), SIGNAL(rowsInserted(const QModelIndex &, int, int)), form_UserReReg.twUserList, SLOT(scrollToBottom()));
    
    form_UserReReg.tbMessage->hide();
    
//    irbis64->silentMode = true;
//    for (int i = 0; i < 100; i++)
//    {
//        //irbis64->loginToBase();
//        irbis64->getMaxMFN("RDR");
//    
//    }
    
}

form_UserReRg::~form_UserReRg() {
    // останавливаем двигло и удаляем сокет
//    client->terminate();
//    delete engine;
    delete irbis64;
}

void form_UserReRg::fillFilials()
{
    QStringList filialList;
    bdOper* bd = new bdOper();

//	filialList = bd->getFilialNames(bd->getFilialsID());
	
    form_UserReReg.cbFilials->addItems(filialList);
    form_UserReReg.cbFilials->currentText();

    //Thread.join();
}

void form_UserReRg::addUserInList(QStringList userData)
{
    QTableWidgetItem* user = new QTableWidgetItem(userData.at(0));
    QTableWidgetItem* mfn = new QTableWidgetItem(form_UserReReg.dt->text());
    
    if (!checkAlreadyInList(userData.at(0)))
    {
        form_UserReReg.twUserList->setRowCount(form_UserReReg.twUserList->rowCount() + 1);
        form_UserReReg.twUserList->setRowHeight(form_UserReReg.twUserList->rowCount()-1, 18);
        form_UserReReg.twUserList->setItem(form_UserReReg.twUserList->rowCount()-1, 1, mfn);
        form_UserReReg.twUserList->setItem(form_UserReReg.twUserList->rowCount()-1, 0, user);
        form_UserReReg.leID->clear();
        form_UserReReg.leFIO->clear();
        
        // проверяем есть ли у пользователя регистрация / перерегистрация в текущем году и добавляем ее
        //irbis64->srvPars.addReg_ReReg(form_UserReReg.cbFilials->currentText().toStdString(), form_UserReReg.dt->text().toStdString());
        
        dbCustomer.push_back(irbis64->srvPars.reader);
        
        form_UserReReg.gbRecordDebug->setTitle("Record Debug : " + QString::number(dbCustomer.size()));
    }
    else
    {
        
    }
    
    form_UserReReg.leReaderSize->setText(QString::number(irbis64->srvPars.reader.oldRecord.length()));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    
    //cout << "db size: " << dbCustomer.size() << endl;
}

void form_UserReRg::slotSearchByID()
{
    if (form_UserReReg.leID->text().length() > 0)
    {
//        cout << "check ID. getting FIO" << endl;
        irbis64->silentMode = true;
        irbis64->loginToBase();
        
        QStringList answer = irbis64->getUserByID(form_UserReReg.leID->text().toStdString(), 
                                                  (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? form_UserReReg.cbFilials->currentText().toStdString() : ""),
                                                  (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? dt.year().toStdString() : ""));
        
        QString userRecord = QString::fromStdString(irbis64->getUserRecord(irbis64->srvPars.reader.mfn));
        
        //cout << "oldRecord before parsing: " << irbis64->srvPars.reader.oldRecord.size() << endl; 
        //cout << "userRecord before parsing: " << userRecord.size() << endl;
        irbis64->srvPars.reader.oldRecord = irbis64->srvPars.parseUserRecord(userRecord).toStdString();
        //cout << "oldRecord after parsing: " << irbis64->srvPars.reader.oldRecord.size() << endl; 
        
        if (form_UserReReg.cbDefenceFromDuplicate->isChecked())
        {
            if (irbis64->srvPars.wasToday(irbis64->srvPars.reader.oldRecord, dt.fullDate().toStdString(), form_UserReReg.cbFilials->currentText().toStdString()))
                {
                cout << "already in list" << endl;
                form_UserReReg.leID->clear();
                }
            else
                {
                    if (answer.count() == 2)
                    addUserInList(answer);
        //cout << irbis64->srvPars.reader.oldRecord.c_str() << endl;
                }
        }
        else
        {
            if (answer.count() == 2)
                addUserInList(answer);
        
        }
        
        irbis64->unloginFromBase();
        

    }
    
    
    
}

void form_UserReRg::slotSearch()
{
    QStringList answer;
    
    if (form_UserReReg.leID->text().length() > 0)
    {
        irbis64->silentMode = true;
        irbis64->loginToBase();

        answer = irbis64->getUserByID(form_UserReReg.leID->text().toStdString(), 
                                      (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? form_UserReReg.cbFilials->currentText().toStdString() : ""),
                                      (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? dt.year().toStdString() : ""));
        
    }
    else
    if (form_UserReReg.leFIO->text().length() > 0)
    {
        irbis64->silentMode = true;
        irbis64->loginToBase();
        
        answer = irbis64->getUserByFIO(form_UserReReg.leFIO->text().toStdString(), (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? form_UserReReg.cbFilials->currentText().toStdString() : ""));
    }
    
    if (answer.count() > 0)
    {
        QString userRecord = QString::fromStdString(irbis64->getUserRecord(irbis64->srvPars.reader.mfn));
        
        irbis64->srvPars.reader.oldRecord = irbis64->srvPars.parseUserRecord(userRecord).toStdString();
        
        
        if (form_UserReReg.cbDefenceFromDuplicate->isChecked())
        {
            if (irbis64->srvPars.wasToday(irbis64->srvPars.reader.oldRecord, dt.fullDate().toStdString(), form_UserReReg.cbFilials->currentText().toStdString()))
                {
                    cout << "already in list" << endl;
                    form_UserReReg.leID->clear();
                    form_UserReReg.leFIO->clear();
                }
            else
                {
                    if (answer.count() == 2)
                      addUserInList(answer);
                }
        }
        else
        {
            if (answer.count() == 2)
                addUserInList(answer);
        
        }
        
        irbis64->unloginFromBase();
    }
    else
    {
        //this->setEnabled(false);
        form_UserReReg.tbMessage->show();
        timerRaiseMsg = new QTimer(this);
        timerRaiseMsg->singleShot(1000, this, SLOT(slot_timerHideMsg()));
    
    }
}

bool form_UserReRg::checkAlreadyInList(QString item)
{
    for (int i = 0; i < form_UserReReg.twUserList->rowCount(); i++)
    {
        if (QString::compare(form_UserReReg.twUserList->item(i, 0)->text(), item) == 0)
        {
            return true;
        }
    }
    return false;
}

void form_UserReRg::slotShowContextMenu(const QPoint&)
{
    if (form_UserReReg.twUserList->rowCount() != 0)
    {
        QMenu contextMenu;
        QIcon icon;
        icon.addFile("images/DeleteRed.png");
        QAction* actDeleteItem = new QAction(icon, "Delete", this);
        actDeleteItem->connect(actDeleteItem, SIGNAL(triggered()), this, SLOT(slotDeleteItem()));
        contextMenu.addAction(actDeleteItem);
        contextMenu.exec(QCursor::pos());
    }
}

void form_UserReRg::slotDeleteItem()
{
    for (unsigned int i = 0; i < dbCustomer.size(); i++)
    {
        string fio;
        fio = dbCustomer.at(i).fam + ' ' + dbCustomer.at(i).name + ' ' + dbCustomer.at(i).sname;
        
        if (form_UserReReg.twUserList->item(form_UserReReg.twUserList->currentRow(), 0)->text().compare(QString::fromStdString(fio)) == 0)
        {
            deleted.push_back(dbCustomer.at(i).mfn);
            break;
        }
    }
    form_UserReReg.twUserList->removeRow(form_UserReReg.twUserList->currentRow());
    
}

void form_UserReRg::slotSendUpdatedRecords()
{
    cout << "begin updates records" << endl;
    
    Thread = boost::thread(boost::bind(&form_UserReRg::updateRecords, this));
}

void form_UserReRg::updateRecords()
{
    irbis64->silentMode = true;
    irbis64->loginToBase();
    
    string newVisit;
    string date;
    string visit = QString::fromUtf8("(Посещение)").toStdString();
    string filial = form_UserReReg.cbFilials->currentText().toStdString();
    int curRow = form_UserReReg.twUserList->rowCount() - 1;
    
    while (dbCustomer.size() > 0)
    {
        //cout << "mfn: " << dbCustomer.back().mfn.c_str() << endl;
        bool foundDeleted = false;
        for (unsigned int i = 0; i < deleted.size(); i++)
        {
            if (deleted.at(i).compare(dbCustomer.back().mfn) == 0)
            {
                foundDeleted = true;
                break;
            }
        }    
        
        if (!foundDeleted)
        {
        //date = form_UserReReg.dt->text().remove('.').toStdString();
            date = form_UserReReg.twUserList->item(curRow--, 1)->text().remove('.').toStdString();
            newVisit = "40#^F" + date + "^D" + date + "^C" + visit + "^V" + filial;
            irbis64->updateRecord(dbCustomer.back().oldRecord, newVisit);
            
            form_UserReReg.twUserList->removeRow(form_UserReReg.twUserList->rowCount() - 1);
        }
        
        dbCustomer.pop_back();
    }
    
    irbis64->unloginFromBase();

    Thread.join();
}

void form_UserReRg::slot_DebugViewFrontRecord()
{
    if (dbCustomer.size() > 0)
    {
        form_UserReReg.leMFN->setText(QString::fromStdString(dbCustomer.front().mfn));
        form_UserReReg.leFAM->setText(QString::fromStdString(dbCustomer.front().fam));
        form_UserReReg.leNAME->setText(QString::fromStdString(dbCustomer.front().name));
        form_UserReReg.leSURNAME->setText(QString::fromStdString(dbCustomer.front().sname));
        //form_UserReReg.teVisits->setText(QString::fromStdString(dbCustomer.front().visits.date.));
        form_UserReReg.teOldRecord->setText(QString::fromStdString(dbCustomer.front().oldRecord));
        currentRecord = 0;
    }
}

void form_UserReRg::slot_DebugViewNextRecord()
{
    if (currentRecord + 1 < dbCustomer.size())
    {
        currentRecord++;
        form_UserReReg.leMFN->setText(QString::fromStdString(dbCustomer.at(currentRecord).mfn));
        form_UserReReg.leFAM->setText(QString::fromStdString(dbCustomer.at(currentRecord).fam));
        form_UserReReg.leNAME->setText(QString::fromStdString(dbCustomer.at(currentRecord).name));
        form_UserReReg.leSURNAME->setText(QString::fromStdString(dbCustomer.at(currentRecord).sname));
        //form_UserReReg.teVisits->setText(QString::fromStdString(dbCustomer.front().visits.date.));
        form_UserReReg.teOldRecord->setText(QString::fromStdString(dbCustomer.at(currentRecord).oldRecord));
    }
}

void form_UserReRg::slot_DebugViewBackRecord()
{
    if (dbCustomer.size() > 0)
    {
        form_UserReReg.leMFN->setText(QString::fromStdString(dbCustomer.back().mfn));
        form_UserReReg.leFAM->setText(QString::fromStdString(dbCustomer.back().fam));
        form_UserReReg.leNAME->setText(QString::fromStdString(dbCustomer.back().name));
        form_UserReReg.leSURNAME->setText(QString::fromStdString(dbCustomer.back().sname));
        //form_UserReReg.teVisits->setText(QString::fromStdString(dbCustomer.front().visits.date.));
        form_UserReReg.teOldRecord->setText(QString::fromStdString(dbCustomer.back().oldRecord));
        currentRecord = dbCustomer.size();
    }
}

void form_UserReRg::slot_DebugViewPrevRecord()
{
    if (currentRecord - 1 >= 0)
    {
        currentRecord--;
        form_UserReReg.leMFN->setText(QString::fromStdString(dbCustomer.at(currentRecord).mfn));
        form_UserReReg.leFAM->setText(QString::fromStdString(dbCustomer.at(currentRecord).fam));
        form_UserReReg.leNAME->setText(QString::fromStdString(dbCustomer.at(currentRecord).name));
        form_UserReReg.leSURNAME->setText(QString::fromStdString(dbCustomer.at(currentRecord).sname));
        //form_UserReReg.teVisits->setText(QString::fromStdString(dbCustomer.front().visits.date.));
        form_UserReReg.teOldRecord->setText(QString::fromStdString(dbCustomer.at(currentRecord).oldRecord));
    }
}

void form_UserReRg::slot_DefenceFromDuplicate(int state)
{
    if (state == false) // если галка не стоит
    {
        form_UserReReg.dt->setReadOnly(false);
        form_UserReReg.dt->setDate(lastDT.dtDateTime->date());
    }
    else
    {
        form_UserReReg.dt->setReadOnly(true);
        QDate date(dt.year().toInt(), dt.month().toInt(), dt.day().toInt());
        form_UserReReg.dt->setDate(date);
    }

}

void form_UserReRg::slot_DateChanged(QDate date)
{
    if (!form_UserReReg.dt->isReadOnly())
        lastDT.dtDateTime->setDate(date);
}

void form_UserReRg::slot_fioChanged(QString fio)
{
    if ((fio[fio.length() - 1] != ' ') && (fio.length() > 0))
    {
        if (timerSearchByFIO->isActive())
        {
                timerSearchByFIO->stop();
                timerSearchByFIO->start(300);
        }
        else
        {
                timerSearchByFIO->start(300);
        }
    }
}

void form_UserReRg::slot_timerGO()
{
    timerSearchByFIO->stop();
    
    irbis64->silentMode = true;
    irbis64->loginToBase();
    QStringList list = irbis64->checkUsersExists(form_UserReReg.leFIO->text().toStdString());
    irbis64->unloginFromBase();
    
    QCompleter* fioCompleter = new QCompleter();
    fioCompleter->setMaxVisibleItems(10);
    fioCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    
    QStringListModel* fioModel = new QStringListModel(list);
    form_UserReReg.leFIO->setCompleter(fioCompleter);
    fioCompleter->setModel(fioModel);
  
    emit fioCompleter->complete();
}

void form_UserReRg::slot_EnableDisableSearchingMethods(QString txt)
{
    if (txt.length() == 0)
    {
        form_UserReReg.leFIO->setEnabled(true);
        form_UserReReg.leID->setEnabled(true);
    }
    else
    if (form_UserReReg.leID->text().compare(txt) == 0)
        form_UserReReg.leFIO->setEnabled(false);
    else
    if (form_UserReReg.leFIO->text().compare(txt) == 0)
        form_UserReReg.leID->setEnabled(false);
}

void form_UserReRg::slot_timerHideMsg()
{
    //this->setDisabled(false);
    form_UserReReg.tbMessage->hide();
}

void form_UserReRg::makeAutoVisits(int countVisits)
{
    QStringList answer;
    
    string maxMFN = irbis64->getMaxMFN("RDR");
    
    srand(time(NULL));
    
    irbis64->silentMode = true;
    irbis64->loginToBase();

    int tryCount = 0;
    int makedVisits = 0;
    
    
    while (makedVisits < countVisits)
    {
        tryCount++;
        cout << "try # " << tryCount << endl;
        int ID = rand() % boost::lexical_cast<int>(maxMFN);
        //cout << "ID: " << ID << endl;
    
        answer = irbis64->getUserByID(boost::lexical_cast<string>(ID), 
                                      (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? form_UserReReg.cbFilials->currentText().toStdString() : ""),
                                      (form_UserReReg.cbSearchOnFilialOnly->isChecked() ? dt.year().toStdString() : ""));
        
        if (answer.count() > 0)
        {
            
            QString userRecord = QString::fromStdString(irbis64->getUserRecord(irbis64->srvPars.reader.mfn));
        
            irbis64->srvPars.reader.oldRecord = irbis64->srvPars.parseUserRecord(userRecord).toStdString();
        
        
            if (form_UserReReg.cbDefenceFromDuplicate->isChecked())
            {
                if (irbis64->srvPars.wasToday(irbis64->srvPars.reader.oldRecord, dt.fullDate().toStdString(), form_UserReReg.cbFilials->currentText().toStdString()))
                {
                    cout << "already in list" << endl;
//                    form_UserReReg.leID->clear();
//                    form_UserReReg.leFIO->clear();
                }
                else
                {
                    if (answer.count() == 2)
                    {
                      addUserInList(answer);
                      form_UserReReg.twUserList->setRowHeight(form_UserReReg.twUserList->rowCount() - 1, 20);
                    }
                    
                }
            }
            else
            {
                if (answer.count() == 2)
                {
                    addUserInList(answer);
                    form_UserReReg.twUserList->setRowHeight(form_UserReReg.twUserList->rowCount() - 1, 20);   
                }
        
            }            
        
            
            makedVisits++;
        }
        
    }
    
    cout << "try: " << tryCount << ", visits: " << makedVisits << endl;
    form_UserReReg.tbMessage->hide();
    
    irbis64->unloginFromBase();
}

void form_UserReRg::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::AltModifier && event->key() == Qt::Key_Pause)
    {
        form_UserReReg.tbMessage->setText("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"> \
                                           <html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\"> \
                                           p, li { white-space: pre-wrap; } \
                                           </style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\"> \
                                           <p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ff0000;\">Поиск <br>посетителей...</span></p></body></html>");
        form_UserReReg.tbMessage->show();
        
        boost::thread visits = boost::thread(boost::bind(&form_UserReRg::makeAutoVisits, this, 10));
    }
}