/*
 * File:   form_UserRegistration.cpp
 * Author: f10-kafedra
 *
 * 
 * 
 * Created on 20 Сентябрь 2011 г., 13:18
 * 
 * 
 * 
 * 
 */

//#include <QtSql/qsqlquery.h>
//#include <QtSql/qsqlerror.h>

#include "form_UserRegistration.h"
#include "structs.h"
//#include "mainForm.h"
//#include "form_Information.h"
#include "passports.h"
//#include "form_UserReRg.h"
#include "parser.h"
#include "engine.h"


form_UserRegistration::form_UserRegistration(QStringList filialList, QString ip) {
    form_UserReg.setupUi(this);
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/reguser.png"), QSize(), QIcon::Normal, QIcon::Off);
    this->setWindowIcon(icon);
    
    form_UserReg.pbSendToServer->setEnabled(true);
    
    irbis64 = new engine(APM_REGUSER, "f10", "f10");
            
    isOVD = true;
    
    
/*  запрос пароля
 *  если сохранен в таблице - то автовход
 * 
 *  form_Login.myIP = ip;
    form_Login.setModal(true);
    QStringList account = form_Login.bd.checkAccountAvailable(ip);
    if (account.count() == 0)
        form_Login.show();
    else
    {
        irbis64->login = account.at(0).toStdString();
        irbis64->pass = account.at(1).toStdString();
    }
*/  
    
    maxWorkAge = 55;
    dt = new datetime();
    form_UserReg.leBirthYear_21->setText(QString::number(dt->year().toInt() - 8));

    form_UserReg.cbFilial->addItems(filialList);
    filialName = form_UserReg.cbFilial->currentText();
    
    // начальная обработка года рождения
    slotOnBirthYearChange("");
    
    form_UserReg.leBirthYear_21->connect(form_UserReg.leBirthYear_21, SIGNAL(textChanged(QString)), this, SLOT(slotOnBirthYearChange(QString)));
//    form_UserReg.leFam_10->connect(form_UserReg.leFam_10, SIGNAL(textChanged(QString)), this, SLOT(slotOnFamChange(QString)));
    
    connect(form_UserReg.leFam_10, SIGNAL(textEdited(QString)), this, SLOT(slotCheckUserExists(QString)));
    connect(form_UserReg.leName_11, SIGNAL(textEdited(QString)), this, SLOT(slotCheckUserExists(QString)));
    connect(form_UserReg.leSurname_12, SIGNAL(textEdited(QString)), this, SLOT(slotCheckUserExists(QString)));
    connect(form_UserReg.leBirthYear_21, SIGNAL(textEdited(QString)), this, SLOT(slotCheckUserExists(QString)));

    form_UserReg.cbAddressRegistration->connect(form_UserReg.cbAddressRegistration, SIGNAL(clicked()), this, SLOT(slotOnAdditionalAddress()));
    
    form_UserReg.pbSendToServer->connect(form_UserReg.pbSendToServer, SIGNAL(clicked()), this, SLOT(slotRegUser()));
    form_UserReg.pbClearForm->connect(form_UserReg.pbClearForm, SIGNAL(clicked()), this, SLOT(slotClearForm()));
    
    QList< QLineEdit* > list;
    list = form_UserReg.gbNewUserReg->findChildren<QLineEdit *>();
    for (int i = 0; i < list.size(); i++)
    {
        connect(list.at(i), SIGNAL(returnPressed()), this, SLOT(slotKeyPressed()));
    }
    
    loadConfFile();
    loadCfgFile();
    
    connect(form_UserReg.cbStreet_13, SIGNAL(editTextChanged(QString)), this, SLOT(slotStreetChanged(QString)));
    slotStreetChanged(form_UserReg.cbStreet_13->currentText());
    
    connect(form_UserReg.cbStreet_14, SIGNAL(editTextChanged(QString)), this, SLOT(slotStreetChanged(QString)));
    connect(form_UserReg.leSerial_14, SIGNAL(textEdited(QString)), this, SLOT(slotSetOVD_OUFMS_Year(QString)));
}

form_UserRegistration::~form_UserRegistration() {
    delete irbis64;
}

void form_UserRegistration::loadConfFile()
{
    irbis64->loginToBase();
    
    catalog.city = irbis64->srvPars.parseConfFile(irbis64->getConfFile("goroda.mnu"));
    for (unsigned short int i = 0; i < catalog.city.size(); i++)
    {
        form_UserReg.cbCity_13->addItem(QString::fromStdString(catalog.city.at(i)));
        form_UserReg.cbCity_14->addItem(QString::fromStdString(catalog.city.at(i)));
        if (form_UserReg.cbCity_13->itemText(i).compare("Мурманск") == 0)
            indexMurmansk = i;
    }
    
    form_UserReg.cbCity_13->setCurrentIndex(indexMurmansk);
    form_UserReg.cbCity_14->setCurrentIndex(indexMurmansk);

    catalog.streets = irbis64->srvPars.parseConfFile(irbis64->getConfFile("ulici.mnu"));
    for (unsigned short int i = 0; i < catalog.streets.size(); i++)
    {
        form_UserReg.cbStreet_13->addItem(QString::fromStdString(catalog.streets.at(i)));
        form_UserReg.cbStreet_14->addItem(QString::fromStdString(catalog.streets.at(i)));
    }
 
    catalog.study = irbis64->srvPars.parseConfFile(irbis64->getConfFile("uchebniezav.mnu"));
    for (unsigned short int i = 0; i < catalog.study.size(); i++)
        form_UserReg.cbTeachPlaceName_19->addItem(QString::fromStdString(catalog.study.at(i)));
    
    irbis64->unloginFromBase();
}

void form_UserRegistration::slotOnBirthYearChange(QString text)
{
    if (form_UserReg.leBirthYear_21->text().length() == 4)
    {
        if ((form_UserReg.leBirthYear_21->text().toInt() == (dt->year().toInt() - 14)) |
            (form_UserReg.leBirthYear_21->text().toInt() == (dt->year().toInt() - 20)) |
            (form_UserReg.leBirthYear_21->text().toInt() == (dt->year().toInt() - 45)))
                form_UserReg.leSerial_14->setText("47" + dt->getHalfYear());
        // TODO: узнать во сколько меняется паспорт
        
        if (form_UserReg.leBirthYear_21->text().toInt() >= (dt->year().toInt() - 13)) // дети до 14
        {
            form_UserReg.gbWorkPlace_15->setVisible(false);
            form_UserReg.gbPassport_14->setVisible(false);
            form_UserReg.cbDontHavePassport->setChecked(true);
            this->setGeometry(this->x()+8, this->y()+30, this->width(), minHeightForm);
            
            form_UserReg.gbNewUserReg->setGeometry(form_UserReg.gbNewUserReg->x(), form_UserReg.gbNewUserReg->y(), 
                                                   form_UserReg.gbNewUserReg->width(), minHeightForm-9);
        }
        else
        {
            form_UserReg.gbWorkPlace_15->setVisible(true);
            form_UserReg.gbPassport_14->setVisible(true);
            
            if (!form_UserReg.cbAddressRegistration->isChecked())
            {
                form_UserReg.gbNewUserReg->setGeometry(form_UserReg.gbNewUserReg->x(), form_UserReg.gbNewUserReg->y(), 
                                                       form_UserReg.gbNewUserReg->width(), middleHeightForm-9);
                form_UserReg.gbRegistrationAddress_14->setVisible(false);
                this->setGeometry(this->x()+8, this->y()+30, this->width(), middleHeightForm);
            }
            else
            {
                form_UserReg.gbRegistrationAddress_14->setVisible(true);
                form_UserReg.gbNewUserReg->setGeometry(form_UserReg.gbNewUserReg->x(), form_UserReg.gbNewUserReg->y(), 
                                                       form_UserReg.gbNewUserReg->width(), maxHeightForm-9);
                this->setGeometry(this->x()+8, this->y()+30, this->width(), maxHeightForm);
            }
        }
        
        if (form_UserReg.leBirthYear_21->text().toInt() >= (dt->year().toInt() - 14)) // дети до 14
        {
            form_UserReg.cbEducation_20->setCurrentIndex(0);
            form_UserReg.cbAdditionalCategory_67->setCurrentIndex(1);
            
            if (form_UserReg.leBirthYear_21->text().toInt() >= (dt->year().toInt() - 5))
                form_UserReg.cbCategory_50->setCurrentIndex(1);
            else
                form_UserReg.cbCategory_50->setCurrentIndex(11);
        }
        else
        if ((form_UserReg.leBirthYear_21->text().toInt() <= (dt->year().toInt() - 14)) && 
            (form_UserReg.leBirthYear_21->text().toInt() >= (dt->year().toInt() - 24))) // юношество
        {
            form_UserReg.cbAdditionalCategory_67->setCurrentIndex(6);
            
            if (form_UserReg.leBirthYear_21->text().toInt() <= (dt->year().toInt() - 16))
                form_UserReg.cbCategory_50->setCurrentIndex(12);
            
            if (form_UserReg.leBirthYear_21->text().toInt() <= (dt->year().toInt() - 14))  // старшекласники
            {
                form_UserReg.cbEducation_20->setCurrentIndex(1);
            }
        }
        else 
        if (form_UserReg.leBirthYear_21->text().toInt() <= (dt->year().toInt() - maxWorkAge)) // пенсионеры
        {
            form_UserReg.cbAdditionalCategory_67->setCurrentIndex(4);
            form_UserReg.cbCategory_50->setCurrentIndex(5);
        }
        else
        {
            form_UserReg.cbAdditionalCategory_67->setCurrentIndex(7);
            form_UserReg.cbCategory_50->setCurrentIndex(0);
        }
    }
}

void form_UserRegistration::slotOnFamChange(QString text)
{
    re.setPattern("(.)$");
    if (re.indexIn((form_UserReg.leFam_10->text())) != -1)
    {
        if ((re.cap(1) == "а") || (re.cap(1) == "я"))
            maxWorkAge = 55;
        else
            maxWorkAge = 60;
    }
}

void form_UserRegistration::slotOnAdditionalAddress()
{
    if (form_UserReg.cbAddressRegistration->isChecked())
    {
        disconnect(form_UserReg.cbStreet_13, SIGNAL(editTextChanged(QString)), this, SLOT(slotStreetChanged(QString)));
        if (form_UserReg.leBirthYear_21->text().toInt() >= (dt->year().toInt() - 13)) // без изменений
        {
        
        }
        else
        {
            form_UserReg.gbNewUserReg->setGeometry(form_UserReg.gbNewUserReg->x(), form_UserReg.gbNewUserReg->y(), 
                                                       form_UserReg.gbNewUserReg->width(), maxHeightForm-9);
                this->setGeometry(this->x()+8, this->y()+30, this->width(), maxHeightForm);
            
            form_UserReg.gbRegistrationAddress_14->setVisible(true);
        }
        slotStreetChanged(form_UserReg.cbStreet_14->currentText());
    }
    else
    {
        connect(form_UserReg.cbStreet_13, SIGNAL(editTextChanged(QString)), this, SLOT(slotStreetChanged(QString)));
        if (form_UserReg.leBirthYear_21->text().toInt() >= (dt->year().toInt() - 13)) // без изменений
        {
        
        }
        else
        {
            this->setGeometry(this->x()+8, this->y()+30, this->width(), middleHeightForm);
            form_UserReg.gbNewUserReg->setGeometry(form_UserReg.gbNewUserReg->x(), form_UserReg.gbNewUserReg->y(), form_UserReg.gbNewUserReg->width(), middleHeightForm - 8);
            form_UserReg.gbRegistrationAddress_14->setVisible(false);
        }
        slotStreetChanged(form_UserReg.cbStreet_13->currentText());
    }
}

void form_UserRegistration::slotClearForm()
{
    clearFields();
}

void form_UserRegistration::slotRegUser()
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    
    string elm = QByteArray::fromHex("1F1E").data();
        /*QString createRec = "RDR\n0\n1\n0#0" + elm + "0#0" + elm + 
                                     "10#Новый" + elm +                     // Фамилиия
                                     "11#Пользователь" + elm +              // имя
                                     "12#Системы" + elm +                   // Отчество
                                     "21#2011" + elm +                      // год рождения
                                     "50#Прочие" + elm +                    // Категория
                                     "67#Пенсионеры" + elm +                // доп. категория
                                     "51#^D20110915^Cф 10" + elm +          // дата записи
                                     "52#^D20110916^Cф 10" + elm +          // дата перерегистрации
                                     "17#319753" + elm +                    // домашний телефон
                                     "32#f10 (собака) murmanlib.ru" + elm + // мыло
                                     "13#^CГород^DУлица^EДом^HКвартира" + elm + 
                                     "14#^AНомер^BВыдан^SДатаВыдачи^CГород^DУлица^EНомерДома^HКвартира" + elm +
                                     "15#ИИЦ №10" + elm +                  // место работы
                                     "16#Системный АДминистратор" + elm +   // Должность
                                     "19#^AМестоУчебы^EКласс" + elm +       // Место учебы
                                     "20#Высшее проф." + elm +              // Образование
                                     "691#^DЕФ^F20110915^Eф 10" + elm +     // читатель ЕФ \ СПС
                                     "33#^A20110915^Bф 10" + elm +          // договор
                                     "31#^A20110915^BЧДА" + elm +           // регистратор записи
                                     "920#RDR" + elm;                      // Рабочий лист
         */
    string request = "RDR\n0\n1\n0#0" + elm + "920#RDR" + elm;
    
    if (form_UserReg.leFam_10->text().length() > 0)
        request.append("10#" + removeLastsSpaces(form_UserReg.leFam_10->text()).toStdString() + elm);
    
    if (form_UserReg.leName_11->text().length() > 0)
        request.append("11#" + removeLastsSpaces(form_UserReg.leName_11->text()).toStdString() + elm);
    
    if (form_UserReg.leSurname_12->text().length() > 0)
        request.append("12#" + removeLastsSpaces(form_UserReg.leSurname_12->text()).toStdString() + elm);
    
    if (form_UserReg.leBirthYear_21->text().length() > 0)
        request.append("21#" + form_UserReg.leBirthYear_21->text().toStdString() + elm);
    
    if (form_UserReg.cbCategory_50->currentText().length() > 0)
        request.append("50#" + form_UserReg.cbCategory_50->currentText().toStdString() + elm);
    
    if (form_UserReg.cbAdditionalCategory_67->currentText().length() > 0)
        request.append("67#" + form_UserReg.cbAdditionalCategory_67->currentText().toStdString() + elm);
    
    request.append("51#^D" + dt->fullDate().toStdString() + "^C" + filialName.toStdString() + elm);
            
    if (form_UserReg.leTelNumber_Home_17->text().length() > 0)
        request.append("17#" + form_UserReg.leTelNumber_Home_17->text().toStdString() + elm);
    
    if (form_UserReg.leTelNumber_Work_18->text().length() > 0)
        request.append("18#" + form_UserReg.leTelNumber_Work_18->text().toStdString() + elm);
    
//    if (form_UserReg.cbAddressRegistration->isChecked())
//    {
        if ((form_UserReg.cbCity_13->currentText().length() > 0) | (form_UserReg.cbStreet_13->currentText().length() > 0) |
             (form_UserReg.leHouseNumber_13->text().length() > 0) | (form_UserReg.leAppNumber_13->text().length() > 0))
        {
            request.append("13#");
            if (form_UserReg.cbCity_13->currentText().length() > 0) 
                request.append("^C" + form_UserReg.cbCity_13->currentText().toStdString());
            if (form_UserReg.cbStreet_13->currentText().length() > 0)
                request.append("^D" + form_UserReg.cbStreet_13->currentText().toStdString());
            if (form_UserReg.leHouseNumber_13->text().length() > 0)
                request.append("^E" + form_UserReg.leHouseNumber_13->text().toStdString());
            if (form_UserReg.leAppNumber_13->text().length())
                request.append("^H" + form_UserReg.leAppNumber_13->text().toStdString());
            request.append(elm);
        }
//    }
    
    if (!form_UserReg.cbDontHavePassport->isChecked())
    {
        if ((form_UserReg.leSerial_14->text().length() > 0) | (form_UserReg.leNumber_14->text().length() > 0) |
             (form_UserReg.cbPlaceOfIssue_14->currentText().length() > 0) |
             ((form_UserReg.cbCity_14->currentText().length() > 0) & (form_UserReg.cbAddressRegistration->isChecked())) | 
             ((form_UserReg.cbStreet_14->currentText().length() > 0) & (form_UserReg.cbAddressRegistration->isChecked())) | 
             ((form_UserReg.leHouseNumber_14->text().length() > 0) & (form_UserReg.cbAddressRegistration->isChecked())) | 
             ((form_UserReg.leAppNumber_14->text().length() > 0) & (form_UserReg.cbAddressRegistration->isChecked())))
        {
            request.append("14#");
            if (form_UserReg.leSerial_14->text().length() > 0) 
            {
                request.append("^A" + form_UserReg.leSerial_14->text().toStdString());
                if (form_UserReg.leNumber_14->text().length() > 0)
                    request.append(" " + form_UserReg.leNumber_14->text().toStdString());
            }
            if (form_UserReg.cbPlaceOfIssue_14->currentText().length() > 0)
            {
                string OVD = form_UserReg.cbPlaceOfIssue_14->currentText().toStdString();
                
                if (OVD.compare("ОУФМС РОССИИ ПО МО В ЛЕНИНСКОМ АО ГОРОДА МУРМАНСКА") == 0)
                    OVD = "ОТДЕЛОМ УФМС РОССИИ ПО МУРМАНСКОЙ ОБЛАСТИ В ЛЕНИНСКОМ АО ГОРОДА МУРМАНСКА";
                else
                if (OVD.compare("ОУФМС РОССИИ ПО МО В ОКТЯБРЬСКОМ АО ГОРОДА МУРМАНСКА") == 0)
                    OVD = "ОТДЕЛОМ УФМС РОССИИ ПО МУРМАНСКОЙ ОБЛАСТИ В ОКТЯБРЬСКОМ АО ГОРОДА МУРМАНСКА";
                else
                if (OVD.compare("ОУФМС РОССИИ ПО МО В ПЕРВОМАЙСКОМ АО ГОРОДА МУРМАНСКА") == 0)
                    OVD = "ОТДЕЛОМ УФМС РОССИИ ПО МУРМАНСКОЙ ОБЛАСТИ В ПЕРВОМАЙСКОМ АО ГОРОДА МУРМАНСКА";
                
                request.append("^B" + OVD);
            }
            if (form_UserReg.deDateOfIssue_14->text().length())
                request.append("^S" + form_UserReg.deDateOfIssue_14->text().toStdString());
            
            if (form_UserReg.cbAddressRegistration->isChecked())
            {        
                if (form_UserReg.cbCity_14->currentText().length() > 0) 
                    request.append("^C" + form_UserReg.cbCity_14->currentText().toStdString());
                if (form_UserReg.cbStreet_14->currentText().length() > 0)
                    request.append("^D" + form_UserReg.cbStreet_14->currentText().toStdString());

                if (form_UserReg.leHouseNumber_14->text().length() > 0)
                    request.append("^E" + form_UserReg.leHouseNumber_14->text().toStdString());
                if (form_UserReg.leAppNumber_14->text().length())
                    request.append("^H" + form_UserReg.leAppNumber_14->text().toStdString());
            }
            request.append(elm);         
        }
    }
    if (form_UserReg.leWorkPlaceName_15->text().length() > 0)
        request.append("15#" + form_UserReg.leWorkPlaceName_15->text().toStdString() + elm);
    
    if (form_UserReg.leJob_16->text().length() > 0)
        request.append("16#" + form_UserReg.leJob_16->text().toStdString() + elm);

    if ((form_UserReg.cbTeachPlaceName_19->currentText().length() > 0) | (form_UserReg.cbStudy_19->currentText().length() > 0) |
        (form_UserReg.leClass_19->text().length() > 0))
    {
        request.append("19#");
        if (form_UserReg.cbTeachPlaceName_19->currentText().length() > 0)
            request.append("^A" + form_UserReg.cbTeachPlaceName_19->currentText().toStdString());
        if (form_UserReg.cbStudy_19->currentText().length())
            request.append("^B" + form_UserReg.cbStudy_19->currentText().toStdString());
        if (form_UserReg.leClass_19->text().length() > 0)
            request.append("^E" + form_UserReg.leClass_19->text().toStdString());
        request.append(elm);
    }

    if (form_UserReg.cbContract->isChecked())
        request.append("33#^A" + dt->fullDate().toStdString() + "^B" + filialName.toStdString() + elm);

    request.append("20#" + form_UserReg.cbEducation_20->currentText().toStdString() + elm);
    
    request.append("40#^F" + dt->fullDate().toStdString() + "^D" + dt->fullDate().toStdString() + "^C(Посещение)^V" + filialName.toStdString() + elm);
    
    if (form_UserReg.cbEF_691->isChecked())
        request.append("691#^DЕФ^F" + dt->fullDate().toStdString() + "^E" + filialName.toStdString() + elm);
    if (form_UserReg.cbSPS_691->isChecked())
        request.append("691#^DСПС^F" + dt->fullDate().toStdString() + "^E" + filialName.toStdString() + elm);
    if (form_UserReg.cbMBA_691->isChecked())
        request.append("691#^DМБА^F" + dt->fullDate().toStdString() + "^E" + filialName.toStdString() + elm);
    
    //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(request)).data() << endl;
    
    irbis64->regNewUser(request);
    
    clearFields();
}

void form_UserRegistration::slotKeyPressed()
{
    QWidget* wgt = qobject_cast < QWidget* > (sender());
    if (QString::compare(wgt->metaObject()->className(), "QLineEdit") == 0)
        wgt->nextInFocusChain()->setFocus();
//    cout << wgt->objectName().toAscii().data() << endl;
//    cout << wgt->metaObject()->className() << endl;

}

void form_UserRegistration::slotStreetChanged(QString street)
{
    for (uint i = 0; i < len_ovd.streets.size(); i++)
    {
        if (QString::compare(street, len_ovd.streets.at(i)) == 0)
        {
            if (isOVD)
                setIndexPlaceOfIssue(len_ovd.ovd);
            else
                setIndexPlaceOfIssue(len_oufms.ovd);
            
            //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(street).data() << endl;
            //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(len_ovd.streets.at(i)).data() << endl;
            break;
        }
    }
    for (uint i = 0; i < okt_ovd.streets.size(); i++)
    {
        if (QString::compare(street, okt_ovd.streets.at(i)) == 0)
        {
            if (isOVD)
                setIndexPlaceOfIssue(okt_ovd.ovd);
            else
                setIndexPlaceOfIssue(okt_oufms.ovd);
            //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(street).data() << endl;
            //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(okt_ovd.streets.at(i)).data() << endl;
            
            break;
        }
    }
    for (uint i = 0; i < perv_ovd.streets.size(); i++)
    {
        if (QString::compare(street, perv_ovd.streets.at(i)) == 0)
        {
            if (isOVD)
                setIndexPlaceOfIssue(perv_ovd.ovd);
            else
                setIndexPlaceOfIssue(perv_oufms.ovd);
            
            //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(street).data() << endl;
            //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(perv_ovd.streets.at(i)).data() << endl;

            break;
        }
    }

}

void form_UserRegistration::setIndexPlaceOfIssue(QString ovd)
{
    //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(ovd).data() << endl;
    
    for (int index = 0; index < form_UserReg.cbPlaceOfIssue_14->count(); index++)
        {
            if (QString::compare(ovd, form_UserReg.cbPlaceOfIssue_14->itemText(index)) == 0)
               {
                 //   cout << len_ovd.ovd.toAscii().data() << '\n' << form_UserReg.cbPlaceOfIssue_14->itemText(index).toAscii().data() << endl;
                    form_UserReg.cbPlaceOfIssue_14->setCurrentIndex(index);
                    form_UserReg.cbPlaceOfIssue_14->lineEdit()->setCursorPosition(0);
                    break;
               }
        }
}

void form_UserRegistration::loadCfgFile()
{
    QFile cfgFile;
    QTextStream rStream(&cfgFile);
    QString line;
    vector <QString> str;
    
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    
    cfgFile.setFileName("ovd.cfg");
    cfgFile.open(QIODevice::ReadOnly | QIODevice::Text);
    
    do // загружаем названия частоиспользуемых ОВД
    {
        line = rStream.readLine();
        if (line.contains("len_ovd"))
        {
            len_ovd.ovd = line.remove(QRegExp("(.*=)"));
//            cout << len_ovd.toAscii().data() << endl;
        }
        else
        if (line.contains("okt_ovd"))
        {
            okt_ovd.ovd = line.remove(QRegExp("(.*=)"));
//            cout << okt_ovd.toAscii().data() << endl;
        }
        else
        if (line.contains("perv_ovd"))
        {
            perv_ovd.ovd = line.remove(QRegExp("(.*=)"));
//            cout << perv_ovd.toAscii().data() << endl;   
        }
        else
        if (line.contains("len_oufms"))
        {
            len_oufms.ovd = line.remove(QRegExp("(.*=)"));
//            cout << len_oufms.toAscii().data() << endl;   
        }                
        else
        if (line.contains("okt_oufms"))
        {
            okt_oufms.ovd = line.remove(QRegExp("(.*=)"));
//            cout << okt_oufms.toAscii().data() << endl;   
        }                
        else
        if (line.contains("perv_oufms"))
        {
            perv_oufms.ovd = line.remove(QRegExp("(.*=)"));
//            cout << perv_oufms.toAscii().data() << endl;   
        }                
    }
    while (!line.isNull());
    cfgFile.close();
    
    cfgFile.setFileName("streets.cfg");
    cfgFile.open(QIODevice::ReadOnly | QIODevice::Text);
     
    do // загружаем списки улиц и распределяем их по овд
    { // так в лень было переписывать все в одну функцию... поэтому пока что так =)
        str.clear();
        line = rStream.readLine();
        if (line.contains("len_ovd="))
        {
            int amount = line.remove(QRegExp("(.*=)")).toInt() - 1;
            for (int i = 0; i <= amount; i++) // пока не указанное количество улиц 
            {
                line = rStream.readLine();
                str.push_back(line);
            }
            len_ovd.streets = str;
        }
        else
        if (line.contains("okt_ovd="))
        {
            int amount = line.remove(QRegExp("(.*=)")).toInt() - 1;
            for (int i = 0; i <= amount; i++) // пока не указанное количество улиц 
            {
                line = rStream.readLine();
                str.push_back(line);
            }
            okt_ovd.streets = str; 
        }
        else
        if (line.contains("perv_ovd="))
        {
            int amount = line.remove(QRegExp("(.*=)")).toInt() - 1;
            for (int i = 0; i <= amount; i++) // пока не указанное количество улиц 
            {
                line = rStream.readLine();
                str.push_back(line);
            }
            perv_ovd.streets = str; 
        }
            
    } while (!line.isNull()); 
    
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
}

QString form_UserRegistration::removeLastsSpaces(QString str)
{
    return str.remove(QRegExp("((\\s | \\S)*)\\s*$"));
}

void form_UserRegistration::slotCheckUserExists(QString text)
{
    if (form_UserReg.leFam_10->text().length() > 0 && 
        form_UserReg.leName_11->text().length() > 0 && 
        form_UserReg.leSurname_12->text().length() > 0 &&
        form_UserReg.leBirthYear_21->text().length() == 4)
    {
        vector <string> userData;
        userData.push_back(form_UserReg.leFam_10->text().toStdString());
        userData.push_back(form_UserReg.leName_11->text().toStdString());
        userData.push_back(form_UserReg.leSurname_12->text().toStdString());
        userData.push_back(form_UserReg.leBirthYear_21->text().toStdString());
        
        irbis64->silentMode = true;
        irbis64->loginToBase();
        irbis64->silentMode = false;
        
        if (irbis64->checkUserExist(userData) == true)
        {
            QMessageBox msg;
            msg.setText("<b>Данный читатель уже существует!</b>");
            msg.setWindowTitle("Дублетный читатель");
            msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msg.setDefaultButton(QMessageBox::No);
            msg.setInformativeText("Продолжить с данным читателем?");
            msg.setIcon(QMessageBox::Critical);
            int answer = msg.exec();
            
            switch (answer)
            {
                case QMessageBox::Yes: // продолжать с читателем
                {
                    
                
                    break;
                }
                
                case QMessageBox::No: // очистить поля 
                {
                    clearFields();
                    break;
                }
            }
        }
        
        irbis64->unloginFromBase();
    }
}

void form_UserRegistration::clearFields()
{
    QList<QLineEdit*> list;
    list = form_UserReg.gbNewUserReg->findChildren<QLineEdit *>();
    for (int i = 0; i < list.size(); i++)
        list.at(i)->clear();
    
    form_UserReg.leBirthYear_21->setText("2004");
    form_UserReg.cbCity_13->setCurrentIndex(indexMurmansk);
    form_UserReg.cbCity_14->setCurrentIndex(indexMurmansk);
    form_UserReg.cbStreet_13->setCurrentIndex(0);
    form_UserReg.cbStreet_14->setCurrentIndex(0);
}

void form_UserRegistration::slotSetOVD_OUFMS_Year(QString str)
{
    if (str.length() == 4)
    {
        if (form_UserReg.leSerial_14->text().toInt() >= 4706 && 
            form_UserReg.leSerial_14->text().toInt() <= 4700 + dt->year().remove(0, 2).toInt())
        {
            isOVD = false;
        }
        else
        {
            isOVD = true;
        }
    
    /*
     * если две последних цифры в серии больше двух последних цифр в идентификации текущего года, то
     * выставляется в дате выдаче - год равный 19 + две последних цифры в серии паспорта,
     * иначе 20 + две последниц цифры в паспорте
     */ 
        QString serial = str.remove(0, 2);
        QString year = dt->year().remove(0, 2);
        QDate calDate = form_UserReg.deDateOfIssue_14->date();
        //cout << "before change: " << calDate.toString("yyyyMMdd").toAscii().data() << endl;
        if (serial.toInt() <= year.toInt()) // 20+
            calDate.setDate(2000 + serial.toInt(), calDate.toString("MM").toInt(), calDate.toString("dd").toInt());
        else                                // 19+
            calDate.setDate(1900 + serial.toInt(), calDate.toString("MM").toInt(), calDate.toString("dd").toInt());
        
        //cout << "change date: " << calDate.toString("yyyyMMdd").toAscii().data() << endl;
        form_UserReg.deDateOfIssue_14->setDate(calDate);
        
        slotStreetChanged(form_UserReg.cbStreet_14->currentText());
    }
}