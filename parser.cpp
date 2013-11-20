/* 
 * File:   parser.cpp
 * Author: f10-kafedra
 * 
 * Created on 10 Сентябрь 2011 г., 18:29
 */


#include <vector>
#ifdef WIN32
    #include <QtCore/qlist.h>
    #include <QtCore/qlocale.h>
    //#include <QtGui/qmessagebox.h>
    #include <QtWidgets/QMessageBox>
    #include <QtGui/QIcon>
#else
    #include <qlist.h>
    #include <qlocale.h>
    //#include <QtGui/qmessagebox.h>
    #include <QMessageBox>
    #include <QIcon>
#include <boost/lexical_cast.hpp>
#endif
//#include <io.h>

#include "parser.h"
#include "datetime.h"

parser::parser() {
}



parser::~parser() {
}

QString parser::translateData(QString rawData)
{
    //cout << "parsing raw answer" << endl;
    int row = 1;
    QString tmp;
    
    for (int i = 0; i < rawData.count(); i++)
    {
        if (row == 11)
        {
            tmp.append(rawData.at(i));
        }
        if (rawData.at(i) == '\n')
            row++;
    }
    
    //cout << "end parsing" << endl;
    return tmp;
}

QString parser::parseUserData(QString rawData)
{
    cout << "parsing user raw data" << endl;
    
    vector <QString> clearedData;
    QString finalData;
    int amountFields = sizeof(fieldID) / sizeof(*fieldID);
    
    QStringList strList;
    strList = rawData.split("\n", QString::SkipEmptyParts);
    
    foreach (QString str, strList)
    {
        for (int i = 0; i < amountFields; i++)
        {
            reGlobal.setPattern("^" + fieldID[i] + "(.*)");
//            cout << "pattern: " << re.pattern().toLatin1().data() <<
//                 "\nstring: " << str.toLatin1().data() << endl;
            if (reGlobal.indexIn(str)!= -1)
            {
                // вставляем идентификатор следующего поля
                clearedData.push_back(fieldID[i]);
                clearedData.push_back(reGlobal.cap(1));
                break;
            }
        }
    }

    for (unsigned short int i = 0; i < clearedData.size(); i++)
    {
        if (clearedData.at(i) == "10#")
            finalData.append("<b>Фамилия:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "11#")
            finalData.append("<b>Имя:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "12#")
            finalData.append("<b>Отчество:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "21#")
            finalData.append("<b>Год Рождения:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "50#")
            finalData.append("<b>Категория:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "67#")
            finalData.append("<b>Доп. категория:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "20#")
            finalData.append("<b>Образование:</b> " + clearedData.at(++i) + "<br>");
        else
        if (clearedData.at(i) == "17#")
            finalData.append("<b>Телефон:</b> " + clearedData.at(++i) + "<br>");
        else
            finalData.append(clearedData.at(i) + "<br>");
        
        
    }
    
    
    cout << "end parsing" << endl;
    return finalData;
}

QString parser::parseServerVersion(QString rawData)
{
    
    cout << "server version: \n" << rawData.toLatin1().data() << endl;
    
    return "";
}

QString parser::parseLastID(QString rawData)
{
    QStringList strList;
    
    strList = rawData.split("\n", QString::SkipEmptyParts);
    
    cout << "MFN = " << strList.at(15).toInt() << '\n' << "LOG DEL = " << strList.at(10).toInt() << endl;
    //return QString::number(strList.at(15).toInt() - strList.at(10).toInt() + 3);
    cout << "returning: " << QString::number(strList.at(15).toInt() + 60).toLatin1().data() << endl;
    return QString::number(strList.at(15).toInt() + 60);
}

bool parser::parseExistUser(QString rawData)
{
//    cout << QObject::tr("Проверка существования пользователя").toLatin1().data() << endl;
    QStringList pars = rawData.split("\n", QString::SkipEmptyParts);
    
    if (pars.at(11).contains('0'))
        return false;
    else
        return true;
}

vector <info> parser::parseTargetInfo(string rawData)
{
    vector <info> inform;
    
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    
    QString element = QString::fromLatin1(QByteArray::fromHex("1F").data());
    QStringList fieldList;
    
    //cout << rawData.toLatin1().data() << endl;
    QStringList tmpData = QString::fromStdString(rawData).split('\n', QString::SkipEmptyParts);
//    cout << "amount: " << tmpData.at(11).toLatin1().data() << endl;
//    for (int i = 0; i <= 11; i++)
//        tmpData.pop_back();
    
    cout << "parsing" << endl;
    
    // 5е поле
    // \D5#(.*)6#(.*)7#(.*)8#
    // by ide
    // \D5\#(.*)\x1F6\#(.*)\x1F7\#(.*)\x1F8\#.*[\x1F7\#(.*)\x1F7\#]{1,}
    // вся строка включая повторения 7го поля. если 4я позиция совпадения не пустая, значит 7х полей несколько
    // \D5\#(.*)\x1F6\#(.*)\x1F7\#(.*)\x1F8\#(.*7\#.*&{5})*
    
//    reGlobal.setPattern("\\D4#(.*)" + element + "5#(.*)" + element + "6#(.*)" + element + "7#(.*)" + element + "8#(.*7#(.*)" + element + "&{5})*");
//    reField.setPattern("7#(.*)" + element);
    reGlobal.setPattern("target:(.*)\\$topic:(.*)\\$type:(.*)\\$source:(.*)\\$knowledge:(.*)");
    foreach (QString str, tmpData)
    {
        infos.source.clear();
        infos.knowledge = " ";
        
        if (reGlobal.indexIn(str) != -1)
        {
            infos.target = reGlobal.cap(1);
            infos.topic = reGlobal.cap(2);
            infos.typeInfo = reGlobal.cap(3);
            infos.source = reGlobal.cap(4);
            if (reGlobal.cap(5).length() > 1)
            {
                infos.knowledge = reGlobal.cap(5);
                inform.push_back(infos);
            }
/*            
            if (reGlobal.cap(5).length() > 1)
            {
                if (reField.indexIn(reGlobal.cap(5)) != -1)
                {
                    fieldList = reField.cap(1).split(QRegExp(element + "\\d#"), QString::SkipEmptyParts);
                
                    foreach (QString capture, fieldList)
                    {
                        cout << capture.toLatin1().data() << endl;
                        
                        infos.source << capture;
                    }
                }
            }*/
            
        }
        
        
    }
    cout << "after parsing: " << inform.size() << endl;
    return inform;
}

QStringList parser::parseUserGettedByID(string rawData)
{
    //cout << rawData.c_str() << endl;
    
    string patterns[] = {"(.*)#.*10#(.*)11#(.*)12#([А-Яа-я]*).*51#(.*)#",
                         "\\^[vV]([а-яА-Я*\\s0-9*]*|[а-яА-Я\\s0-9]\\s[а-яА-Я]*|[А-Яа-я]*)\\^[DFC]{0,1}",
                         "\\^[dD]([0-9]*)\\^[FfCcVv12]"
                        };
    
    reader.fam.clear();
    reader.mfn.clear();
    reader.name.clear();
    reader.sname.clear();
    //cout << "sizeof oldRecord before clear: " << reader.oldRecord.size() << endl;
    reader.oldRecord.clear();
    //cout << "sizeof oldRecord after clear: " << reader.oldRecord.size() << endl;
    /*
    reader.visits.date.clear();
    reader.visits.fil.clear();
*/    
    //memset(&reader, 0 , sizeof(reader));
    
    
    //cout << rawData.c_str() << endl;
    //cout << QTextCodec::codecForName("cp1251")->fromUnicode(QString::fromStdString(rawData)).data() << endl;
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QString element = QString::fromLatin1(QByteArray::fromHex("1F1E").data());
    
    QStringList tmpList = QString::fromStdString(rawData).split('\n', QString::SkipEmptyParts);
    QStringList result;

    //cout << "tmpList after creating: " << tmpList.count() << endl;
    //cout << "result after creating: " << result.count() << endl;

    //result.clear();
    //cout << "list count: " << tmpList.count() << endl;
    if (tmpList.count() <= 12)
    {
        result << "";
        
#ifdef DEBUG_OUTPUT
        cout << "count: " << result.count() << endl;
#endif        
        
        return result;
    }

    // выборка ФИО и MFN
    reGlobal.setPattern(patterns[0].c_str());
    if (reGlobal.indexIn(tmpList.at(12)) != -1)
    {
/*        cout << "mfn: " << reGlobal.cap(1).toLatin1().data() 
             << "\nFam: " << reGlobal.cap(2).toLatin1().data() 
             << "\nName: " << reGlobal.cap(3).toLatin1().data() 
             << "\nSurname: " << reGlobal.cap(4).toLatin1().data() 
             << "\nFils: " << reGlobal.cap(5).toLatin1().data() << endl;
*/        
        //if (QString::fromStdString(reGlobal(5).))
        result << reGlobal.cap(2) << reGlobal.cap(3) << reGlobal.cap(4) << reGlobal.cap(1) << reGlobal.cap(5);
        
        reader.mfn = reGlobal.cap(1).toStdString();
        reader.fam = reGlobal.cap(2).toStdString();
        reader.name = reGlobal.cap(3).toStdString(); 
        reader.sname = reGlobal.cap(4).toStdString();
        reader.filials = reGlobal.cap(5).toStdString();
    }
    
    //cout << "oldRecord after search FIO & MFN: " << reader.oldRecord.size() << endl;
    
    // удаляем ненужную информацию, и оставляем только посещения
    QString tmp = tmpList.at(12);
    string visits = tmp.remove(0, tmp.indexOf('/', 0) + 1).toStdString();
    tmp = "";
    
    // выборка филиала
    reGlobal.setPattern(patterns[1].c_str());
    int curPos = 0;
    vector <string> fil;
    
    while ((curPos = reGlobal.indexIn(QString::fromStdString(visits), curPos)) != -1)
    {
        fil.push_back(reGlobal.cap(1).toStdString());
        curPos += reGlobal.matchedLength();
    }
    
    // выборка посещений
    reGlobal.setPattern(patterns[2].c_str());
    vector <string> date;
    curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(visits), curPos)) != -1)
    {
        date.push_back(reGlobal.cap(1).toStdString());
        curPos += reGlobal.matchedLength();
    }

//    reader.visits.fil.assign(fil.begin(), fil.end());
//    reader.visits.date.assign(date.begin(), date.end());

#ifdef DEBUG_OUTPUT
    cout << "MFN: " << reader.mfn.c_str() << '\n' << 
            "F: " << reader.fam.c_str() << '\n' <<
            "N: " << reader.name.c_str() << '\n' <<
            "S: " << reader.sname.c_str() << '\n' <<
            "fils: " << reader.visits.fil.size() << '\n' <<
            "dates: " << reader.visits.date.size() << endl;

#endif
    //cout << QTextCodec::codecForName("cp1251")->fromUnicode(QString::fromStdString(visits)).data() << endl;
    
    //memset(&reader, 0 , sizeof(reader));
    return result;
}

QString parser::parseUserRecord(QString record)
{
    QString element1 = QString::fromLatin1(QByteArray::fromHex("0D").data());
    QString element2 = QString::fromLatin1(QByteArray::fromHex("1F1E").data());
  
    //cout << record.toLatin1().data() << endl;
    
    //cout << "userRecord delete shlak: " << record.size() << endl;
    
    // удаляем ненужный шлак
    record.remove(0, record.indexOf(QRegExp("\\D0\\D")) + 4);
    //record.remove(0, record.indexOf(QRegExp("\\0D\\0A")) + 4);
    int from = record.indexOf('#') + 1;
    record.insert(from, "64");
    record.replace(element1, "", Qt::CaseInsensitive);
    record.replace('\n', element2, Qt::CaseInsensitive);

    //cout << record.toLatin1().data() << endl;
    //cout << "userRecord after shlak: " << record.size() << endl;
#ifdef DEBUG_OUTPUT
    for (int i = 0; i < 50; i++)
        cout << record.at(i).toLatin1();
    cout << endl;
#endif
    
    return record;
}

int parser::getMsgLen(string data)
{
    QStringList tmpList = QString::fromStdString(data).split('\n', QString::SkipEmptyParts);
    return tmpList.at(3).toInt();
}

int parser::countVisits(string rawData)
{
    string patterns[] = {"52#(\\^D[0-9]*\\^C[а-яА-Я0-9]*)"};

    int count = 0;
//    QStringList tmpList = QString::fromStdString(rawData).split('\n', QString::SkipEmptyParts);
    
//    if (tmpList.count() < 12)
//    {
        
//        return -1;
//    }

    reGlobal.setPattern(patterns[0].c_str());
//    if (reGlobal.indexIn(tmpList.at(12)) != -1)
//    {
        
//    }
    int curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(rawData), curPos)) != -1)
    {
        curPos += reGlobal.matchedLength();
        count++;
    }
    
    
    return count;
}

bool parser::wasToday(string rawdata, string data, string fil)
{
    reGlobal.setPattern("40#\\^[fF]" + QString::fromStdString(data) + "\\^[dD](" + QString::fromStdString(data) + ")\\^[cC]\\(.*\\)\\^[vV](" + QString::fromStdString(fil) + ")");
    if (reGlobal.indexIn(QString::fromStdString(rawdata)) != -1)
    {
        cout << reGlobal.cap(0).toLatin1().data() << endl;
        cout << reGlobal.cap(1).toLatin1().data() << endl;
        cout << reGlobal.cap(2).toLatin1().data() << endl;
        return true;
    }
    return false;
}

QStringList parser::parseFIO(string fio)
{
    QStringList listFIO;
    
    reGlobal.setPattern("([а-яА-Я]*)\\s{0,}([а-яА-Я]*)\\s{0,}([а-яА-Я]*)");
    if (reGlobal.indexIn(QString::fromStdString(fio)) != -1)
    {
        for (int i = 1; i < reGlobal.capturedTexts().count(); i++)
        {
            if (reGlobal.cap(i).length() > 0)
                listFIO << reGlobal.cap(i);
        }
    }
    return listFIO;
}

QStringList parser::parseListFIOResult(string rawData)
{
    QStringList customers;
    QString e = QString::fromLatin1(QByteArray::fromHex("1E").data());
    
    reGlobal.setPattern("1#(\\d{1,6})#301#1#2" + e + "RI=([А-Яа-я\\s]*)" + e + "(\\d{0,6})");
    
    int curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(rawData), curPos)) != -1)
    {
        customers << reGlobal.cap(2);// + " # " + reGlobal.cap(1);
        
//        cout << reGlobal.cap(1).toLatin1().data() << endl;
//        cout << reGlobal.cap(2).toLatin1().data() << endl;
        
        curPos += reGlobal.matchedLength();
    }
    
    return customers;
}

void parser::addReg_ReReg(string filial, string date)
{
    bool regFound = false;
    bool reregFound = false;
    int countReg = 0;
    int countRegInCurYear = 0;
    int countReReg = 0;
    string curYear = date.substr(0, 4);
    string firstVisit;
    
    // определяем самое первое посещение в текущем году
    reGlobal.setPattern("\\^[fF](" + QString::fromStdString(curYear) + "\\d*)\\^[dD]");
    reGlobal.indexIn(QString::fromStdString(reader.oldRecord));
    {
        firstVisit = reGlobal.cap(1).toStdString();
    }

    if (strlen(firstVisit.c_str()) == 0)
        firstVisit = date;
    
    reGlobal.setPattern("51#\\^[Dd](\\d*)\\^[Cc]([а-яА-я0-9\\s]*)\x1F\x1E");
    int curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(reader.oldRecord), curPos)) != -1)
    {
        // сравниваем совпадение филиала
        if (strcmp(filial.c_str(), reGlobal.cap(2).toLatin1().data()) == 0)
        {
            cout << reGlobal.cap(1).toLatin1().data() << ' ' << reGlobal.cap(2).toLatin1().data() << endl;
            countReg++;
            
            // сравниваем год регистрации
            if (reGlobal.cap(1).toStdString().substr(0, 4).compare(curYear) == 0)
            {
                regFound = true;
                countRegInCurYear++;
            }
        }
        
        curPos += reGlobal.matchedLength();
    }

    reGlobal.setPattern("52#\\^[Dd](\\d*)\\^[Cc]([а-яА-я0-9\\s]*)\x1F\x1E");
    curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(reader.oldRecord), curPos)) != -1)
    {
        if (strcmp(filial.c_str() ,reGlobal.cap(2).toLatin1().data()) == 0)
        {
          cout << reGlobal.cap(1).toLatin1().data() << ' ' << reGlobal.cap(2).toLatin1().data() << endl;
        
          // сравниваем год перерегистрации
          if (reGlobal.cap(1).toStdString().substr(0, 4).compare(curYear) == 0)
          {
             reregFound = true;
             countReReg++;
          }
          
        }
        curPos += reGlobal.matchedLength();
    }    

    QMessageBox msg;
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/visits.png"), QSize(), QIcon::Normal, QIcon::Off);
    msg.setWindowIcon(icon);
    
    if (regFound)
    {
        cout << "regFound" << endl;
        if (countRegInCurYear > 1)
        {
            msg.setText("Регистраций за " + QString::fromStdString(curYear) + " - " + QString::number(countReg) + " штук!!!");
            msg.exec();
        }
    }
    if (reregFound)    
    {
        cout << "reregFound" << endl;
        if (countReReg > 1)
        {
            msg.setText("Перерегистраций за " + QString::fromStdString(curYear) + " - " + QString::number(countReReg) + " штук!!!");
            msg.exec();        
        }
    }
    
    string elm = QByteArray::fromHex("1F1E").data();
    if (!reregFound && countRegInCurYear == 0)
    {
        
        reader.oldRecord.append(elm + "52#^D" + QString::fromStdString(firstVisit).remove('.').toStdString() + "^C" + filial + elm);
    }
}

vector <string> parser::parseConfFile(string rawData)
{
    vector <string> catalog;
    
    string tmpData = QTextCodec::codecForName("Windows-1251")->toUnicode(rawData.c_str()).toStdString();
    
    //reGlobal.setPattern("([а-яА-Я-\\d\\s]*)\x1F\x1E([а-яА-Я-\\d\\s]*)\x1F\x1E");
    reGlobal.setPattern("([а-яА-Я-\\d\\s\\(\\)]*)\x1F\x1E([а-яА-Я-\\d\\s\\(\\)]*)\x1F\x1E");
    
    int curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(tmpData), curPos)) != -1)
    {
//        QByteArray ba = QTextCodec::codecForName("Windows-1251")->fromUnicode(reGlobal.cap(2));
//        cout << "cap: " << ba.data() << endl;
        
        //catalog.push_back(QTextCodec::codecForName("Windows-1251")->fromUnicode(reGlobal.cap(2)).data());
        catalog.push_back(reGlobal.cap(2).toStdString());
        curPos += reGlobal.matchedLength();
    }    

    //cout << catalog.size() << endl;
    
    return catalog;
}

bool parser::ifExistUser(string rawData)
{
    string answer = QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts).at(11).toLatin1().data();
    if (answer[0] == '0')
        return false;
    else
        return true;
}

string parser::getCount(string rawData)
{
    int lastField = QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts).count() - 1;
    return QString::number(QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts).at(lastField).toInt()).toStdString();
}

string parser::getLine(string rawData, int shift)
{
    int lastField = QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts).count() - shift;
    return QString::number(QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts).at(lastField).toInt()).toStdString();
}

string parser::cleanURL(string url)
{
    reGlobal.setPattern("http://([a-zA-Z\\.0-9\\/]*)\\/[a-zA-Z\\.]*");
    if (reGlobal.indexIn(QString::fromStdString(url)) != -1)
    {
//        cout << reGlobal.cap(1).toLatin1().data() << endl;
        
        return reGlobal.cap(1).toStdString();
    }
    else
        return " ";
}

string parser::cleanEngine(string url)
{
    reGlobal.setPattern("(/[a-zA-z\\.]*)$");
    if (reGlobal.indexIn(QString::fromStdString(url)) != -1)
    {
        //cout << reGlobal.cap(1).toLatin1().data() << endl;
        
        return reGlobal.cap(1).toStdString();
    }
    else
        return " ";    
}

vector <string> parser::get_vewstate_eventvalidation(string rawData)
{
    vector <string> viewstate_eventvalidation;
    reGlobal.setPattern("name=\"(__VIEWSTATE|__EVENTVALIDATION)\".*value=\"([0-9a-zA-Z\\/+=]*)\"");
    QStringList pageHtml = QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts);
    for (int i = 0; i < pageHtml.count(); i++)
    {
        if (reGlobal.indexIn(pageHtml.at(i)) != -1)
            viewstate_eventvalidation.push_back(QString::fromLatin1(reGlobal.cap(2).replace("$", "%24").replace("/", "%2F").replace("+", "%2B").replace("=", "%3D").toUtf8().data()).toStdString());
        
        if (viewstate_eventvalidation.size() == 2)
            break;
    }

    reGlobal.setPattern("(ASP.NET_SessionId=[a-zA-z0-9]*);");
    for (int i = 0; i < pageHtml.count(); i++)
    {
        if (reGlobal.indexIn(pageHtml.at(i)) != -1)
        {
            viewstate_eventvalidation.push_back(reGlobal.cap(1).toStdString());
            break;
        }
    }
    
    cout << "secrets getted" << endl;
    return viewstate_eventvalidation;
}

string parser::getCookie(string rawData)
{
    QStringList pageHtml = QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts);
    reGlobal.setPattern("(Apache=[a-zA-z0-9\\.]*);");
    for (int i = 0; i < pageHtml.count(); i++)
    {
        if (reGlobal.indexIn(pageHtml.at(i)) != -1)
        {
            return reGlobal.cap(1).toStdString();
            break;
        }
    }

    return " ";
}

string parser::whereMoved(string rawData)
{
    string moved;
    ///PublicationCard.aspx?product_no=1682000
    
    reGlobal.setPattern("Location: (\\/[a-zA-Z\\.0-9\\_\\?=]*)");
    if (reGlobal.indexIn(QString::fromStdString(rawData)) != -1)
        moved = reGlobal.cap(1).toStdString();
    
    return moved;
}

int parser::countResults(string rawData)
{
    int results = 0;
    reGlobal.setPattern("'(Select\\$\\d*)'");
    int curPos = 0;
    while ((curPos = reGlobal.indexIn(QString::fromStdString(rawData), curPos)) != -1)
    {
        results++;
        curPos += reGlobal.matchedLength();
    }    
    return results;
}

booksData parser::bookInfo(string rawData)
{
    int curPos = 0;
    booksData bookInfos;
    
    reGlobal.setPattern("PublicationAttrLabelTd\">([а-яА-Яa-zA-Z0-9\\.\\s\\+:,&nbsp;]*)<\\/td><td class=\"PublicationAttrValueTd\">([а-яА-Яa-zA-Z0-9\\.\\s\\+:,\\-\\(\\)\\?]*)");
    
    while ((curPos = reGlobal.indexIn(QString::fromStdString(rawData), curPos)) != -1)
    {
        if (reGlobal.cap(1).compare("Основное&nbsp;заглавие публикации") == 0)
        {
//            string::const_iterator from = rawData.begin();
            bookInfos.bookName = reGlobal.cap(2).toStdString();
            //string search_str = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(bookInfos.bookName)).data();
            string search_str = bookInfos.bookName;
            string pattern = ".*(Т|Т\\s|Том|Кн|Кн\\s|Книга)\\.{0,1}\\s{0,}([\\d*])[\\s\\.]*(.*)";
            //cout << search_str.c_str() << endl;
            //pattern = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(pattern)).data();
            pattern = QTextCodec::codecForName("UTF-8")->toUnicode(pattern.c_str()).toStdString();
            //cout << pattern.c_str() << endl;
            boost::regex re(pattern);
            boost::smatch result;
            boost::regex_match(search_str, result, re);
            //cout << result[1] << '\n' << result[2] << '\n' << result[3] << '\n' << endl;
            bookInfos.bookType = result[1];
            bookInfos.bookVollume = result[2];
            bookInfos.vollumeBookName = result[3];
            //cout << bookInfos.vollumeBookName.c_str() << endl;
            cout << bookInfos.bookName.c_str() << endl;
            cout << search_str.c_str() << endl;
            cout << bookInfos.bookType.c_str() << endl;
            
            
            string s0 = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(search_str)).data();
            string s1 = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(bookInfos.bookName)).data();
            string s2 = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(bookInfos.bookType)).data();
       
            //s0.erase(iter, s0.end());

            cout << "string: " << s0.c_str() << endl;
            cout << "to find: " << s2.c_str() << endl;
            cout << "find first: " << s0.find_first_of(s2, 0) << endl;
            cout << "substr: " << s1.substr(0, s0.find_first_of(s2, 0)) << endl;
            //cout << result[1].second << endl;
            //bookInfos.bookName = bookInfos.bookName.substr(0, search_str.find_first_of(bookInfos.bookType, 0));
        }   
        
        if (reGlobal.cap(1).compare("Издательство") == 0)
            bookInfos.publishing = reGlobal.cap(2).toInt();
        if (reGlobal.cap(1).compare("Количество&nbsp;страниц") == 0)
            bookInfos.pageCount = reGlobal.cap(2).toInt();
        if (reGlobal.cap(1).compare("Первый&nbsp;автор публикации") == 0)
            bookInfos.FIO = reGlobal.cap(2).toStdString();
        if (reGlobal.cap(1).compare("Год&nbsp;издания") == 0)
            bookInfos.yearOfPublication = reGlobal.cap(2).toInt();
        if (reGlobal.cap(1).compare("Место&nbsp;издания") == 0)
            bookInfos.cityOfPublishing = reGlobal.cap(2).toInt();
        if (reGlobal.cap(1).compare("Аннотация") == 0)
            bookInfos.aboutBook = reGlobal.cap(2).toStdString();
        if (reGlobal.cap(1).compare("Авторы&nbsp;публикации") == 0)
            bookInfos.FIO = reGlobal.cap(2).toStdString();
        if (reGlobal.cap(1).compare("Индекс&nbsp;УДК") == 0)
            bookInfos.indexUDK = reGlobal.cap(2).toStdString();
        if (reGlobal.cap(1).compare("ББК") == 0)
            bookInfos.BBK = reGlobal.cap(2).toStdString();
        if (reGlobal.cap(1).compare("Серия") == 0)
            bookInfos.series = reGlobal.cap(2).toInt();
        if (reGlobal.cap(1).compare("Сведения,&nbsp;относящиеся к заглавию") == 0)
            bookInfos.additionalBookName = reGlobal.cap(2).toStdString();
        
        
        curPos += reGlobal.matchedLength();
    }

    return bookInfos;
}

string parser::urlencode(string str)
{
    string encodedString;
    //str = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString:
    //:fromStdString(str)).data();
    
    for (int i = 0; i < (int)str.length(); i++)
        encodedString += "%" + url_table[(unsigned char)(int)(str[i]-48 + '0')];
    
    return encodedString;
}

void parser::prepareUrlTable()
{
    /*
     * 176 - а
     * 207 - я
     * 144 - А
     * 175 - Я
     */
    
    for (unsigned short int ch = 192; ch <= 255; ch++)
    {
        unsigned char simb = (ch-48) + '0';
        char buf[3];
        sprintf(buf, "%X", ch);
        string str = buf;
        url_table[simb] = str;
    }
}

string parser::getAutorSign(string rawData)
{
    string autorSign;
    
    boost::regex re("<\\/h1><h1>(.*)&nbsp;&nbsp;&nbsp;.*<\\/h1><table");
    boost::smatch result;
    string::const_iterator from = rawData.begin();
    string::const_iterator to = rawData.end();
    
    while (boost::regex_search(from, to,  result, re))
    {
        cout << "result: " <<  result[1] << endl;
        from = result[2].second;
        
        autorSign = result[1];
        if (autorSign.length() > 0)
            break;
    }
    //QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(str)).data();
    //autorSign = QTextCodec::codecForName("KOI8-R")->toUnicode(QString::fromStdString(autorSign).toLatin1().data()).toStdString();
    //cout << "sign: " << autorSign.c_str() << endl;
    
    return autorSign;
}

string parser::mfn(string rawData)
{
    QStringList strList;
    strList = QString::fromStdString(rawData).split("\n", QString::SkipEmptyParts);
    
    return strList.at(10).toStdString();
}

string parser::replaceMFN(string line)
{
    string newLine;
    string formatStr("0$2");
    boost::regex re("([0-9]*)(.*)");
    boost::smatch result;
    boost::regex_match(line, result, re);
    if (result[1] != "")
    {
        newLine = boost::regex_replace(line, re, formatStr, boost::match_default | boost::format_perl);
    }
    else
        newLine = "#";
    //cout << newLine.c_str() << endl;
    return newLine;
}

void parser::parseBookRecord(string line)
{
    boost::smatch result;
    string delimiterUnits = "\x1f";
    booksData book;
    map<int, string> parsing;
    bookUnit bookHandler;
    
    string searchPattern = "[:йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ\\s\\d\\.\\,\\?\\!\\-\"\"]*";
    parsing[0] = "10#\\^[Aa]";
    parsing[1] = "215#\\^[Aa](\\d*)";
    parsing[2] = "606#\\^[Aa]";
    parsing[3] = "621#";
    parsing[4] = "906#";
    parsing[5] = "908#";
    parsing[6] = "210#" + searchPattern.replace(searchPattern.length() - 2, strlen("\\^a-zA-Z]*"), "\\^a-zA-Z]*") + "\\^[Aa]";
    parsing[7] = "210#" + searchPattern + "\\^[Сс]";
    parsing[8] = "210#" + searchPattern + "\\^[Dd]";
    parsing[9] = "200#" + searchPattern + "\\^[Aa]";
    parsing[10] = "700#" + searchPattern + "\\^[Aa]";
    parsing[11] = "701#" + searchPattern + "\\^[Aa]";
    parsing[12] = "961#" + searchPattern + "\\^[Aa]";
    parsing[13] = "225#" + searchPattern + "\\^[Aa]";
    parsing[14] = "46#" + searchPattern + "\\^[Aa]";
    parsing[15] = "461#" + searchPattern + "\\^[Cc]";
    parsing[16] = "461#" + searchPattern + "\\^[Ee]";
    parsing[17] = "200#" + searchPattern + "\\^[Vv]";
    
    parsing[18] = "910#" + searchPattern + "\\^[Aa](\\d*)";
    parsing[19] = "910#" + searchPattern + "\\^[Bb]";
    parsing[20] = "910#" + searchPattern + "\\^[Dd]";
    parsing[21] = "(910#[йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ\\s\\d\\.\\-\\^a-zA-Z]*)";
    
    
    searchPattern.replace(searchPattern.length() - strlen("\\^a-zA-Z]*"), strlen("\\^a-zA-Z]*"), "]*");
    //cout << searchPattern.replace(searchPattern.length() - strlen("\\^a-zA-Z]*"), strlen("\\^a-zA-Z]*"), "]*") << endl;
    
    for (unsigned int i = 0; i < parsing.size() - 4; i++) 
    {
        
        boost::regex re(".*" + delimiterUnits + parsing[i] + "(" + searchPattern + ").*");
        //cout << ".*" + delimiterUnits + parsing[i] + "(" + searchPattern + ").*" << endl;
        boost::regex_match(line, result, re);
        if (result[1] != "")
        switch (i)
        {
            case 0: // isbn
            {
#ifdef DEBUG
                cout << "ISBN:\t\t" << result[1] << endl;
#endif
                book.ISBN = result[1];
                break;
            }
            case 1: // количество страниц
            {
#ifdef DEBUG
                cout << "pages:\t\t" << result[1] << endl;
#endif
                book.pageCount = boost::lexical_cast<int>(result[1]);
                break;
            }
            case 2: // предметная рубрика
            {
#ifdef DEBUG                
                cout << "subj:\t\t" << result[1] << endl;
#endif                
                book.subject = result[1];
                break;
            }            
            case 3: // ББК
            {
#ifdef DEBUG                
                cout << "BBK:\t\t" << result[1] << endl;
#endif
                book.BBK = result[1];
                break;
            }              
            case 4: // Раздел знаний
            {
#ifdef DEBUG                
                cout << "Knowledge:\t" << result[1] << endl;
#endif                
                bool found = false;
                for (unsigned int i = 0; i < sectionKnowledge.size(); i++)
                {
                    if (sectionKnowledge[i].compare(result[1]) == 0)
                    {
                        book.sectionKnowledge = i;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    book.sectionKnowledge = sectionKnowledge.size();
                    sectionKnowledge[sectionKnowledge.size()] = result[1];
                }
                break;
            }
            case 5: // авторский знак
            {
#ifdef DEBUG                
                cout << "autor sign:\t" << result[1] << endl;
#endif                
                bool found = false;
                for (unsigned int i = 0; i < autorSignes.size(); i++)
                {
                    if (autorSignes[i].compare(result[1]) == 0)
                    {
                        book.autorSign = i;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    book.autorSign = autorSignes.size();
                    autorSignes[autorSignes.size()] = result[1];
                }
                break;
            }
            case 6: // город
            {
#ifdef DEBUG                
                cout << "city:\t\t" << result[1] << endl;
#endif                
                bool found = false;
                for (unsigned int i = 0; i < cities.size(); i++)
                {
                    if (cities[i].compare(result[1]) == 0)
                    {
                        book.cityOfPublishing = i;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    book.cityOfPublishing = cities.size();
                    cities[cities.size()] = result[1];
                }
                
                break;
            }
            case 7: // издательство
            {
#ifdef DEBUG                
                cout << "publish:\t" << result[1] << endl;
#endif                
                bool found = false;
                for (unsigned int i = 0; i < publishes.size(); i++)
                {
                    if (publishes[i].compare(result[1]) == 0)
                    {
                        book.publishing = i;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    book.publishing = publishes.size();
                    publishes[publishes.size()] = result[1];
                }
                break;
            }
            case 8: // год
            {
#ifdef DEBUG               
                cout << "year:\t\t" << result[1] << endl;
#endif
                bool found = false;
                for (unsigned int i = 0; i < yearsOfPublish.size(); i++)
                {
                    if (yearsOfPublish[i].compare(result[1]) == 0)
                    {
                        book.yearOfPublication = i;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    book.yearOfPublication = yearsOfPublish.size();
                    yearsOfPublish[yearsOfPublish.size()] = result[1];
                }
                break;
            }
            case 9: // заглавие
            {
#ifdef DEBUG                
                cout << "title:\t\t" << result[1] << endl;
#endif                
                book.bookName = result[1];
                break;
            }
            case 10: // автор
            case 11:
            case 12:
            {
#ifdef DEBUG                
                cout << "autor:\t\t" << result[1] << endl;
#endif                
                book.FIO = result[1];
                break;
            }
            case 13: // серия
            case 14:
            {
#ifdef DEBUG                
                cout << "series:\t\t" << result[1] << endl;
#endif
                bool found = false;
                for (unsigned int i = 0; i < series.size(); i++)
                {
                    if (series[i].compare(result[1]) == 0)
                    {
                        book.series = i;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    book.series = series.size();
                    series[series.size()] = result[1];
                }
                break;
            }
            case 15: // заглавие многотомника
            {
#ifdef DEBUG               
                cout << "multi title:\t" << result[1] << endl;
#endif
                book.bookName = result[1];
                break;
            }
            case 16: // доп. название
            {
#ifdef DEBUG                
                cout << "add. title:\t" << result[1] << endl;
#endif
                book.vollumeBookName = result[1];
                break;
            }
            case 17: // номер тома, книги
            {
#ifdef DEBUG                
                cout << "vollume:\t" << result[1] << endl;
#endif
                book.bookVollume = result[1];
                break;
            }
        }
    }
// теперь поиск по экземплярности
    
    //boost::regex re910(parsing[15]);
    boost::sregex_iterator Iterator(line.begin(), line.end(), boost::regex (parsing[21]));
    boost::sregex_iterator InvalidIterator;  
    while (Iterator != InvalidIterator)
    {
        //cout << *Iterator << endl;
        string sss = Iterator++->str();
        for (int i = 18; i < 21; i++)
        {
            boost::regex re(parsing[i] + "(" + searchPattern + ").*");
            boost::regex_match(sss, result, re);            

            if (result[1] != "")
            switch (i)
            {
                case 18:
                {
#ifdef DEBUG                    
                    cout << "status:\t\t" << result[1] << endl;
#endif
                    bookHandler.bookStatus = boost::lexical_cast<int>(result[1]);
                    if (bookHandler.bookStatus != -1 &&bookHandler.filial != "" && bookHandler.index != "")
                    {
                        book.bookHandler.push_back(bookHandler);
                        bookHandler.bookStatus = -1;
                        bookHandler.filial.clear();
                        bookHandler.index.clear();
                    }                    
                    break;
                }
                case 19:
                {
#ifdef DEBUG                    
                    cout << "id:\t\t" << result[1] << endl;
#endif
                    bookHandler.index = result[1];
                    if (bookHandler.bookStatus != -1 &&bookHandler.filial != "" && bookHandler.index != "")
                    {
                        book.bookHandler.push_back(bookHandler);
                        bookHandler.bookStatus = -1;
                        bookHandler.filial.clear();
                        bookHandler.index.clear();
                    }
                    break;
                }
                case 20:
                {
#ifdef DEBUG                    
                    cout << "filial:\t\t" << result[1] << endl;
#endif
                    bookHandler.filial = result[1];
                    if (bookHandler.bookStatus != -1 &&bookHandler.filial != "" && bookHandler.index != "")
                    {
                        book.bookHandler.push_back(bookHandler);
                        bookHandler.bookStatus = -1;
                        bookHandler.filial.clear();
                        bookHandler.index.clear();
                    }                
                    break;
                }                
            }
        }
    
    }

    
    
    books.push_back(book);
}