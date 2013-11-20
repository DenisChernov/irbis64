/*
 * File:   form_Information.cpp
 * Author: f10-kafedra
 *
 * Created on 26 Сентябрь 2011 г., 17:11
 */

#include <QtCore/qtextstream.h>
#include "form_Information.h"
//#include "tcpSocket.h"
#include "formLogin.h"
//#include "threads.h"

form_Information::form_Information(QString appName) {
    form_Info.setupUi(this);

    irbis64 = new engine(APM_REREG, "f10", "f10");
    
    //irbis64->silentMode = true;
    //for (int i = 0; i < 38; i++)
    //{
//        irbis64->loginToBase();
//        irbis64->getMaxMFN("RDR");
    
//    }
    
    
    //updater* updateApp = new updater("infos");
    
    appFullPath = appName;
    
    from = 50000;
    to = 51000;
    
    QStringList labels;
    labels << "";
    form_Info.twInfosChosed->setColumnCount(1);
    form_Info.twInfosChosed->setColumnWidth(0, 450);
    form_Info.twInfosChosed->setHorizontalHeaderLabels(labels);

    labels.clear();
    labels << "Справка" << "";
    form_Info.twInfosInIrbis64->setColumnCount(2);
    form_Info.twInfosInIrbis64->setColumnWidth(0, 404);
    form_Info.twInfosInIrbis64->setColumnWidth(1, 16);
    form_Info.twInfosInIrbis64->setHorizontalHeaderLabels(labels);
    form_Info.twInfosInIrbis64->setUpdatesEnabled(true);
    
    form_Info.pbProgress->setValue(0);
    form_Info.gbInSearching->setVisible(false);

    timerFillTable = new QTimer(this);
    timerFillTable->setInterval(300);
    timerFillTable->connect(timerFillTable, SIGNAL(timeout()), this, SLOT(slotTimer_FillTable()));
    
    form_Info.pbSearch->setEnabled(false);
    
    Thread = boost::thread (boost::bind(&form_Information::fillFilials, this));
    
    form_Info.pbSearch->connect(form_Info.pbSearch, SIGNAL(clicked()), this, SLOT(slotGetInfosFromIrbis64ByParametrs()));
    form_Info.pbAdd->connect(form_Info.pbAdd, SIGNAL(clicked()), this, SLOT(slotAddToList()));
    form_Info.pbRemove->connect(form_Info.pbRemove, SIGNAL(clicked()), this, SLOT(slotRemoveFromList()));
    form_Info.pbSendInfosToIrbis64->connect(form_Info.pbSendInfosToIrbis64, SIGNAL(clicked()), this, SLOT(slotSendInfosToIrbis64()));
    form_Info.cbFilial->connect(form_Info.cbFilial, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotFilialChanged(QString)));
    
    clearTable();
    //irbis64 = new engine(APM_REREG, "f10", "f10");
    
    if (!checkBDFile())
    {
        // создаем список
        cout << "file not exists. creating bd" << endl;
        Thread = boost::thread(boost::bind(&form_Information::getInfosList, this));
        
    }
    else
    {
        // читаем список 
        cout << "file exists" << endl;
        Thread = boost::thread(boost::bind(&form_Information::loadFile, this));
    }
    
    QTimer* timerHideInfoStatus = new QTimer(this);
    timerHideInfoStatus->singleShot(6000, this, SLOT(slotHideInfoStatus()));
}

form_Information::~form_Information() {
    
}

void form_Information::fillFilials()
{
    QStringList filialList;
    bdOper bd;
    
//    filialList = bd.getFilialNames(bd.getFilialsID());
    
    for (int i = 0; i < filialList.count(); i++)
        form_Info.cbFilial->addItem(QTextCodec::codecForName("UTF-8")->toUnicode(filialList.at(i).toLatin1()));
    
    form_Info.cbFilial->setCurrentIndex(0);
    
    form_Info.cbFilial->currentText();
    filialName = form_Info.cbFilial->currentText();

    if (QString::compare(CGB_SBO, form_Info.cbFilial->currentText()) == 0)
        fromWho = CGB_SBO_TEL;
    else
        fromWho = filialName;
    
    Thread.join();
}

void form_Information::fillAmountTypesInfo()
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("KOI8-R"));
  
    for (unsigned int i = 0; i < infos.size(); i++)
    {
        if (QString::compare(infos.at(i).target, form_Info.lblStudy_4->text()) == 0)
            form_Info.leStudy_4->setText(QString::number(form_Info.leStudy_4->text().toInt() + 1));
//        cout << infos.at(i).target.toLatin1().data() << "\n" << form_Info.lblStudy_4->text().toLatin1().data() << endl;
        //cout << QTextCodec::codecForName("cp1251")->fromUnicode(infos.at(i).topic).data() << endl;
        //cout << QTextCodec::codecForName("cp1251")->fromUnicode(form_Info.lblStudy_4->text()).data() << endl;
        //else
        if (QString::compare(infos.at(i).target, form_Info.lblSpecial_4->text()) == 0)
            form_Info.leSpecial_4->setText(QString::number(form_Info.leSpecial_4->text().toInt() + 1));
        else
        if (QString::compare(infos.at(i).target, form_Info.lblDosug_4->text()) == 0)
            form_Info.leDosug_4->setText(QString::number(form_Info.leDosug_4->text().toInt() + 1));
        else
        if (QString::compare(infos.at(i).target, form_Info.lblSelfStudy_4->text()) == 0)
            form_Info.leSelfStudy_4->setText(QString::number(form_Info.leSelfStudy_4->text().toInt() + 1));
     
        if (QString::compare(infos.at(i).typeInfo, form_Info.lblTemat_6->text()) == 0)
            form_Info.leTemat_6->setText(QString::number(form_Info.leStudy_4->text().toInt() + 1));
        else
        if (QString::compare(infos.at(i).typeInfo, form_Info.lblYtochn_6->text()) == 0)
            form_Info.leYtochn_6->setText(QString::number(form_Info.leYtochn_6->text().toInt() + 1));            
        else
        if (QString::compare(infos.at(i).typeInfo, form_Info.lblFactograf_6->text()) == 0)
            form_Info.leFactograf_6->setText(QString::number(form_Info.leFactograf_6->text().toInt() + 1));            
        else
        if (QString::compare(infos.at(i).typeInfo, form_Info.lblAdressBiblio_6->text()) == 0)
            form_Info.leAddresBiblio_6->setText(QString::number(form_Info.leAddresBiblio_6->text().toInt() + 1));            
        else
        if (QString::compare(infos.at(i).typeInfo, form_Info.lblSocio_6->text()) == 0)
            form_Info.leSocio_6->setText(QString::number(form_Info.leSocio_6->text().toInt() + 1));            
    }
}

void form_Information::slotGetInfosFromIrbis64ByParametrs()
{
    //Thread = boost::thread(boost::bind(&form_Information::raiseWaitingInfo, this));
    //Thread = boost::thread(boost::bind(&form_Info.gbInSearching::setVisible, this, true));
    form_Info.gbInSearching->setVisible(true);
    
    tmpList.clear();
    tmpList << form_Info.cbTarget_4->currentText() << form_Info.cbType_6->currentText();
    
    QList<QCheckBox* > listCheckBox;
    
    listCheckBox = form_Info.gbSource->findChildren<QCheckBox *>();
    for (int i = 0; i < listCheckBox.size(); i++)
    {
        if (listCheckBox.at(i)->isChecked())
            tmpList << listCheckBox.at(i)->text();
    }


    timerFillTable->start();

}

void form_Information::slotTimer_FillTable()
{
    timerFillTable->stop();
    fillTable(tmpList);
    form_Info.gbInSearching->setVisible(false);
    
}

void form_Information::fillTable(QStringList parametrs)
{
    //form_Info.twInfosInIrbis64->clear();
    clearTable();
    form_Info.twInfosInIrbis64->hide();
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    
    
    for (unsigned int i = 0; i < infos.size(); i++)
    {
        bool fullMatch = true;
        
        if ((QString::compare(infos.at(i).target, parametrs.at(0)) == 0) &
            (QString::compare(infos.at(i).typeInfo, parametrs.at(1)) == 0))
        {
            for (int j = 2; j < parametrs.count(); j++)
            {
                if (!infos.at(i).source.contains(parametrs.at(j)))
                {
                    fullMatch = false;
                    break;
                }
            }
            if (fullMatch)
            {
                QTableWidgetItem* itemText = new QTableWidgetItem(infos.at(i).target + "~ " + infos.at(i).typeInfo + "~ " + infos.at(i).topic);
                form_Info.twInfosInIrbis64->setRowCount(form_Info.twInfosInIrbis64->rowCount() + 1);
                form_Info.twInfosInIrbis64->setRowHeight(form_Info.twInfosInIrbis64->rowCount()-1, 18);
                form_Info.twInfosInIrbis64->setItem(form_Info.twInfosInIrbis64->rowCount()-1, 0, itemText);
                form_Info.twInfosInIrbis64->setCellWidget(form_Info.twInfosInIrbis64->rowCount()-1, 1, new QCheckBox(this));
            }
        }
    }
    
    form_Info.twInfosInIrbis64->show();
    //tLoadFile->amount = form_Info.twInfosInIrbis64->rowCount();
    //tLoadFile->start();
}

void form_Information::clearTable()
{
    form_Info.twInfosInIrbis64->setRowCount(0);

}

void form_Information::slotAddToList()
{
    QList<QCheckBox* > listCheckBox;
    listCheckBox = form_Info.twInfosInIrbis64->findChildren<QCheckBox *>();
    
    for (int i = 0; i < listCheckBox.count(); i++)
    {
        if (listCheckBox.at(i)->isChecked())
        {
            QString item;
            QList<QCheckBox* > list;
            list = form_Info.gbSource->findChildren<QCheckBox *>();
            for (int j = 0; j < list.size(); j++)
            {
                if (list.at(j)->isChecked())
                    item.append(list.at(j)->text() + ". ");
            }
                QTableWidgetItem* itemText = new QTableWidgetItem(form_Info.twInfosInIrbis64->item(i, 0)->text() + "/ " + item);
                form_Info.twInfosChosed->setRowCount(form_Info.twInfosChosed->rowCount() + 1);
                form_Info.twInfosChosed->setRowHeight(form_Info.twInfosChosed->rowCount()-1, 18);
                form_Info.twInfosChosed->setItem(form_Info.twInfosChosed->rowCount()-1, 0, itemText);
        }
    }
}

void form_Information::slotRemoveFromList()
{
    form_Info.twInfosChosed->removeRow(form_Info.twInfosChosed->currentRow());
}

void form_Information::slotSendInfosToIrbis64()
{
    QStringList info;
    //info
    QStringList tmpList;
    QRegExp re;

    //client->loginToBase();
    
    for (int i=0; i < form_Info.twInfosChosed->rowCount(); i++)
    {
        info.clear();
        info << dt.fullDate() << fromWho; // дата справки, филиал
        re.setPattern("(.*)~\\s{0,}([^\\s].*)~\\s{0,}([^\\s].*)/ ");
        re.indexIn(form_Info.twInfosChosed->item(i, 0)->data(Qt::DisplayRole).toString());
        {
            info << re.cap(1) << re.cap(3) << re.cap(2); // цель запроса, название справки, тип
            //cout << re.cap(1).toLatin1().data() << '\n' << re.cap(2).toLatin1().data() << '\n' << re.cap(3).toLatin1().data() << endl;
        }
        
        re.setPattern("/ (.*)");
        re.indexIn(form_Info.twInfosChosed->item(i, 0)->data(Qt::DisplayRole).toString());
        tmpList = re.cap(1).split(". ", QString::SkipEmptyParts);
        info << QString::number(tmpList.count()); // количество источников выполнения
        foreach (QString str, tmpList)
        {
            info << str; // источники выполнения
        }
        
        info << filialName; // филиал
        
        for (unsigned int j = 0; j<infos.size(); j++)
        {
            if (QString::compare(infos.at(j).topic, info.at(3)) == 0)
            {
                if (QString::compare(infos.at(j).knowledge, " ") != 0)
                    info << infos.at(j).knowledge;

                break;
            }
        }
    
        if (form_Info.twInfosChosed->item(i, 0)->isSelected())
            info << "+";
        else
            info << " ";
        foreach (QString str, info)
        {
            cout << QTextCodec::codecForName("CP-1251")->fromUnicode(str).data() << endl;
        }    
        irbis64->sendInfos(info);
    }
    form_Info.twInfosChosed->setRowCount(0);
    
    //client->unloginFromBase();
}

void form_Information::flushBD()
{
    QFile fileBD(fBD);
    if (fileBD.open(QIODevice::Text | QIODevice::Append))
    {
        QTextStream out(&fileBD);
        foreach(info inform, infos)
        {
            out << /*"target:"*/ 1 << ':' << inform.target << '\n'
                << /*"type:"*/ 2 << ':' << inform.typeInfo << '\n'
                << /*"topic:"*/ 3 << ':' << inform.topic << '\n'
                << /*"source:"*/ 4 << ':' << inform.source;
            //if (inform.knowledge.length() > 1)
                out << /*"\nknowledge:"*/ '\n' << 5 << ':' << inform.knowledge.remove(inform.knowledge.length()-1, 1) << '\n';
//            else
//                out << '\n';
            out << 0 << ":\n";
            out.flush();
        }
        fileBD.close();
    }
}

bool form_Information::checkBDFile()
{
    QFile fileBD(fBD);
    if (!fileBD.exists())
    {
        this->setGeometry(100, 100, FORM_CREATEBD_W, FORM_CREATEBD_H);
        form_Info.gbParametrs->setVisible(false);
        form_Info.gbCreateBDMsg->setGeometry(MSG_CREATEBD_X, MSG_CREATEBD_Y, MSG_CREATEBD_W, MSG_CREATEBD_H);
        form_Info.gbCreateBDMsg->setVisible(true);
        form_Info.lblFilial->setVisible(false);
        form_Info.cbFilial->setVisible(false);
        return false;
    }
    else
    {
        this->setGeometry(100, 100, FORM_W, FORM_H);
        form_Info.gbCreateBDMsg->setVisible(false);
        return true;
    }
    
}

void form_Information::loadFile()
{
    
//    wndLoadInfos.show();
    cout << "reading bd file" << endl;
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    
    info inform;
    QString line;
    QRegExp re;
    re.setPattern("(\\d):(.*)");
    QFile fileBD(fBD);
    if (fileBD.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        QTextStream in(&fileBD);
        while (!in.atEnd())
        {
            line = in.readLine();
            //cout << line.toLatin1().data() << endl;
            if (re.indexIn(line) != -1)
            {
                switch (re.cap(1).toInt())
                {
                    case 1:
                    {
                        inform.target = re.cap(2);
                        break;
                    }
                    case 2:
                    {
                        inform.typeInfo = re.cap(2);
                        break;
                    }                
                    case 3:
                    {
                        inform.topic = re.cap(2);
                        break;
                    }
                    case 4:
                    {
                        inform.source = re.cap(2);
                        break;
                    }
                    case 5:
                    {
                        inform.knowledge = re.cap(2);
                        break;
                    }
                    case 0:
                    {
                        infos.push_back(inform);
                        inform.knowledge.clear();
                        inform.source.clear();
                        inform.topic.clear();
                        break;
                    }
                }
            }
        }
        cout << "infos size: " << infos.size() << endl;
        fileBD.close();
    }
     
    form_Info.lblInfoStatus->setText("Всего справок: " + QString::number(infos.size()));
    form_Info.pbSearch->setEnabled(true);

    //fillAmountTypesInfo();
    Thread.join();
    //wndLoadInfos.close();
}

void form_Information::slotFilialChanged(QString filial)
{
    filialName = form_Info.cbFilial->currentText();
    if (QString::compare(CGB_SBO, form_Info.cbFilial->currentText()) == 0)
        fromWho = CGB_SBO_TEL;
    else
        fromWho = filialName;
}

void form_Information::slotRowFilled()
{
    cout << "filled" << endl;
}

void form_Information::getInfosList()
{
    int maxMFN = QString::fromStdString(irbis64->getMaxMFN("UCHETSPR")).toInt() - 1;

    irbis64->silentMode = true;
    irbis64->loginToBase();
    irbis64->silentMode = false;
    
    while (from <= maxMFN)
    {
        infos = irbis64->srvPars.parseTargetInfo(irbis64->getInfos(from, to));
        flushBD();
        
        form_Info.lblAmountInfo->setText(QString::number(to-50000));
        from = to + 1;
        to = to + 1000;
        //form_Info.pbProgress->setValue((to-50000) / 1000);
    }
    irbis64->unloginFromBase();
    
    QProcess process;
    process.startDetached(appFullPath);
    this->close();
    
    Thread.join();
}

void form_Information::slotHideInfoStatus()
{
    form_Info.lblInfoStatus->hide();
}