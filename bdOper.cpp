/*
 * File:   bdOper.cpp
 * Author: f10-kafedra
 *
 * Created on 16 Октябрь 2011 г., 11:43
 */

#include <QtWidgets/QMessageBox>

#include "bdOper.h"

bdOper::bdOper() {
/*    QList<QHostAddress> myIpAddresses = QNetworkInterface::allAddresses();

    QRegExp re;
    re.setPattern("\\d{3}.\\d{3}.9.(.*)");
    for (int i = 0; i< myIpAddresses.count(); i++)
    {
        if (re.indexIn(myIpAddresses.at(i).toString()) != -1)
        {
    //        return re.cap(0);
            myIp = re.cap(0);
            break;
        }
    }*/
    
    string ip;
    ACE_INET_Addr inet_addr;


#ifdef linux
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, (char*)"eth0");

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    ioctl(s, SIOCGIFADDR, &ifr);
    close(s);

    struct sockaddr_in *sa = (struct sockaddr_in*)&ifr.ifr_addr;

    ip = inet_ntoa(sa->sin_addr);
    if (ip.length() > 0)
    {
        myIp = QString::fromStdString(ip);
        cout << "ip: " << myIp.toStdString() << endl;
    }
#endif

#ifdef _WIN32
    int result = inet_addr.set((unsigned short)0, inet_addr.get_host_name());
    if (result != 0)
        cout << "error setting peer_addr" << endl;
    else
    {
        ip = inet_addr.get_host_addr();
        myIp = QString::fromStdString(ip);
    }
#endif
}

bdOper::~bdOper() {
}

bool bdOper::isConnected()
{
    if (PQstatus(db) == CONNECTION_OK)
    {
        return true;
    }
    else
        return false;
}

bool bdOper::connectToBD(string login, string pass, string dbname)
{

    //string connStr = boost::str(format("user=%s password=%s dbname=%s hostaddr=%s") % DBLOGIN_BOOKBASE % DBPASS_BOOKBASE % DBNAME_BOOKBASE % HOSTBD);
    string connStr = boost::str(format("user=%s password=%s dbname=%s hostaddr=%s") % login % pass % dbname % HOSTBD);
    db = PQconnectdb(connStr.c_str());

    if (PQstatus(db) == CONNECTION_BAD)
    {
        cout << "Unable connect to DB: " << dbname << endl;
        //QMessageBox m;
        //m.setText(db.lastError().text());
        //m.exec();
        return false;
    }
    else
    {
        cout << "connected to " << HOSTBD << " % " << dbname << endl;
        return true;
    }
}


vector<string> bdOper::getFilialsID()
{
    vector<string> list;


//    if (connectToBD(DBLOGIN_IPLIST, DBPASS_IPLIST, DBNAME_IPLIST) == true)
    if (isConnected())
    {

        string query("SELECT \"filialID\" FROM \"ipList\" WHERE \"ip\" = '" + myIp.toLatin1() + "'");
        cout << query << endl;
        PGresult* result = PQexec(db, query.c_str());

        getResult(&result, 1, &list);

//        disconnect();
    }

    return list;
}

vector<string> bdOper::getFilials()
{
    vector<string> list;
    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
    {
//        foreach (QString id, ids)
//        {
            string query = "SELECT \"filial\" FROM \"filials\"";
            PGresult* result = PQexec(db, query.c_str());

            getResult(&result, 1, &list);
//        }

        disconnect();
    }

    return list;
}

vector<string> bdOper::getFilialNames(QStringList ids)
{
    vector<string> list;
//    if (connectToBD(DBLOGIN_IPLIST, DBPASS_IPLIST, DBNAME_IPLIST) == true)
    if (isConnected())
    {
        foreach (QString id, ids)
        {
            string query = "SELECT \"filial\" FROM \"filials\" WHERE \"id\" = '" + id.toStdString() + "'";
            cout << query << endl;
            PGresult* result = PQexec(db, query.c_str());

            getResult(&result, 1, &list);
        }

//        disconnect();
    }

    return list;
}

void bdOper::disconnect()
{
    PQfinish(db);
}

void bdOper::queryError(PGresult* result)
{
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    cerr << PQresultErrorMessage(result) << endl;
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
}

void bdOper::saveAccount(QString login, QString pass, QString ip)
{
    if (connectToBD(DBLOGIN_IPLIST, DBPASS_IPLIST, DBNAME_IPLIST))
    {
        string query = "INSERT INTO \"accounts\" VALUES ((SELECT COUNT(*) FROM \"accounts\"), '" + ip.toStdString() + "', '" + login.toStdString() + "', '" + pass.toStdString() + "');";
        PGresult* result = PQexec(db, query.c_str());

        if (PQresultStatus(result) != PGRES_COMMAND_OK)
        {
            queryError(result);
        }
        else
        {
            cout << "account saved\n" << "ip: " << ip.toLatin1().data() << "\nlogin: "
                                                << login.toLatin1().data() << "\npass: "
                                                << pass.toLatin1().data() << endl;
        }

        disconnect();
    }
}

/*QStringList bdOper::checkAccountAvailable(QString ip)
{
    QStringList accountData;
    cout << "checikng account" << endl;

    if (connectToBD(DBLOGIN_IPLIST, DBPASS_IPLIST, DBNAME_IPLIST) == true)
    {
        string query = "SELECT login, pass FROM \"accounts\" WHERE \"ip\" = '" + ip.toStdString() + "';";
        PGresult* result = PQexec(db, query.c_str());

        if (PQresultStatus(result) != PGRES_TUPLES_OK)
        {
            queryError(result);
        }
        else
        {
            for (int i = 0; i < PQntuples(result); i++)
            {
                accountData << QString::fromLatin1(PQgetvalue(result, i, 0));
                accountData << QString::fromLatin1(PQgetvalue(result, i, 1));
            }
        }

        getResult(&result, 2, &accountData);

        disconnect();
    }

    return accountData;
}*/

void bdOper::getResult(PGresult** result, unsigned short int items, vector<string>* container)
{
    if (PQresultStatus(*result) != PGRES_TUPLES_OK)
    {
        queryError(*result);
    }
    else
    {
        for (unsigned short int i = 0; i < PQntuples(*result); i++)
        {
            for (unsigned short int j = 0; j < items; j++)
    			(*container).push_back(boost::lexical_cast<string>(PQgetvalue(*result, i, j)));
        }
    }
}


// добавляем в базу данные о книгах имеющихся в системе
void bdOper::insertToBase(int id, QString name, QString fil, QString autor, QString KnowledgeSection, QString strID, QString strYear)
{
//    QSqlQuery query("INSERT INTO bookbase VALUES (" + QString::number(id) + ", '" + name + "', '"  + fil +
//                                                "', '" + autor + "', '" + KnowledgeSection + "', '" + strID + "', '" + strYear + "');");

//    /*if (!*/query.exec();/*)*/
/*    {
        cout << query.lastQuery().toLatin1().data() << '\n' <<  query.lastError().text().toLatin1().data() << endl;
    }
*/
}

void bdOper::ClearTable(string table)
{
    string query = boost::str(format("TRUNCATE TABLE %s") % table);

    sendQuery(&query);
}

void bdOper::resetAllCounters()
{
    string query = "ALTER SEQUENCE \"autorsigns_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"bookSeries_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"yearOfPublication_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"booksunits_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"autorsigns_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"city_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"knowledgesect_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"publishing_id_seq\" RESTART WITH 1;"
                   "ALTER SEQUENCE \"bookbase_id_seq\" RESTART WITH 1;";

    sendQuery(&query);
}

void bdOper::insertToBaseQuery(int id, QString name, QString fil, QString autor, QString KnowledgeSection)
{
    //query.append("INSERT INTO bookbase VALUES (" + QString::number(id) + ", '" + name + "', '"  + fil +
//                                                "', '" + autor + "', '" + KnowledgeSection + "');");
}

string bdOper::checkLastVersionBD()
{
    string list;
    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
    {

        string query = "SELECT \"dateBD\" FROM \"bdVersion\"";
        PGresult* result = PQexec(db, query.c_str());
        if (PQresultStatus(result) != PGRES_TUPLES_OK)
        {
            queryError(result);
        }
        else
            list = PQgetvalue(result, 0, 0);

        disconnect();
     }

    return list;

}

string bdOper::lastVersionApp()
{
    string list;
    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
    {

        string query = "SELECT \"appVersion\" FROM \"bdVersion\"";
        PGresult* result = PQexec(db, query.c_str());
        if (PQresultStatus(result) != PGRES_TUPLES_OK)
        {
            queryError(result);
        }
        else
            list = PQgetvalue(result, 0, 0);

        disconnect();
     }

    return list;
}

void bdOper::updateLastVersionApp()
{


}

void bdOper::updateLastVersionBD()
{
    string query = boost::str(format("UPDATE \"bdVersion\" SET \"dateBD\" = '%s'") % QDateTime::currentDateTime().date().toString("yyyyMMdd").toStdString());
    
    sendQuery(&query);
}

int bdOper::getAmountRecords(string table)
{
    string count = "0";
    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
    {
        string query = "SELECT COUNT(*) FROM " + table;
        PGresult* result = PQexec(db, query.c_str());
        if (PQresultStatus(result) != PGRES_TUPLES_OK)
        {
            queryError(result);
        }
        else
            count = PQgetvalue(result, 0, 0);
            //count = "0";

        disconnect();
     }

    return QString::fromStdString(count).toInt();
}


void bdOper::setPrintUsedIP()
{
//    QList<QHostAddress> myIpAddresses = QNetworkInterface::allAddresses();
//    bool ipExists = false;

//    QSqlQuery query;
//    if (!query.exec("SELECT * from \"clientIP\""))
//    {
   //     log->logError(query.lastError().text());
//    }
//    else
//    {
//        while (query.next()) // проводим поиск по уже имеющимся IP адресам
//        {
//            if (QString::compare(query.value(1).toString(), myIpAddresses.at(0).toString()) == 0) // если IP уже есть в списке
//            {
//                ipExists = true;
//                break;
//            }
//        }
//        if (!ipExists) // если IP нет в списке
//                if (!query.exec("INSERT INTO \"clientIP\" VALUES(" + QString::number(getAmountRecords("\"clientIP\"") + 1) + ",'"+ myIpAddresses.at(0).toString() + "')"))
//                        {
     //                           log->logError(query.lastError().text());
//                        }
//    }
}

vector<string> bdOper::getField(string table, string field, int condition)
{
/*    QSqlQuery query;
    QStringList fields;

    if (!query.exec("SELECT \"" + field + "\" FROM \"" + table + "\""))
    {
  //      log->logError(query.lastError().text());
    }
    else
    {
        while (query.next())
                fields << query.value(0).toString();
    }

    return fields;
 */
    vector<string> list;
//    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
//    {
//        foreach (QString id, ids)
//        {
            string query = boost::str(format("SELECT \"%s\" FROM \"%s\" WHERE id = %d") % table % field % condition);
            PGresult* result = PQexec(db, query.c_str());

            getResult(&result, 1, &list);
//        }

//        disconnect();
//    }

    return list;
}

vector<string> bdOper::getField(QString table, QString field, QString condition)
{
//    QSqlQuery query;
    vector<string> fields;

//    if (!query.exec("SELECT \"" + field + "\" FROM \"" + table + "\" WHERE " + condition))
//    {

     //   log->logError(query.lastError().text());
//    }
//    else
//    {
//        log->logOK(query.lastQuery());
//        while (query.next())
//        {
//            for (int i = 0; query.isNull(i) == false; i++)
//                fields << query.value(i).toString();
//        }
//    }

    return fields;
}

vector <QStringList> bdOper::getBooks(string condition)
{
    vector <QStringList> books;

    string query = "SELECT DISTINCT bookbase.isbn, bookbase.title, bookbase.autor, bookbase.\"multiTitle\", bookbase.\"addTitle\", bookbase.vollume, city.city, publishing.publishing, knowledgesect.section, autorsigns.autorsign, yearofpublication.year, bookbase.subj, bookseries.series, bookbase.id FROM \"bookbase\" \
                    LEFT JOIN city ON bookbase.city = city.id \
                    LEFT JOIN publishing ON bookbase.publish = publishing.id \
                    LEFT JOIN yearofpublication ON bookbase.year = yearofpublication.id \
                    LEFT JOIN knowledgesect ON bookbase.\"knowledgeSection\" = knowledgesect.id \
                    LEFT JOIN autorsigns ON bookbase.\"autorSign\" = autorsigns.id \
                    LEFT JOIN bookseries ON bookbase.series = bookseries.id \
                    left join booksunits on booksunits.\"bookID\" = bookbase.id \
                    left join filials on filials.\"ID\" = booksunits.filial \
                    WHERE " + condition;
        
        cout << query << endl;

    PGresult *result = PQexec(db, query.c_str());

    if (PQresultStatus(result) != PGRES_TUPLES_OK)
    {
        queryError(result);
    }
    else
    {
        QStringList container;
        for (unsigned short int i = 0; i < PQntuples(result); i++)
        {
            container.clear();

            for (unsigned short int j = 0; j < 14; j++)
                container << QString::fromLatin1(PQgetvalue(result, i, j));

            books.push_back(container);
        }
    }
    return books;
}

void bdOper::updateMaxBookInBases(vector<string> booksCount)
{
    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
    {
        string query = boost::str(format("UPDATE \"bdBooksCount\" SET \"oldek\" = %s, \"retro\"= %s") % booksCount.at(0)
                                                                                                      % booksCount.at(1));
        PGresult *result = PQexec(db, query.c_str());
        if (PQresultStatus(result) != PGRES_TUPLES_OK)
        {
            queryError(result);
        }
        else
        {
            cout << "Count books in BD is successfuly updated!" << endl;
        }
        disconnect();
    }
}

void bdOper::getBooksInBasesCount(vector<string>* booksCount)
{
    if (connectToBD(DBLOGIN_BOOKBASE, DBPASS_BOOKBASE, DBNAME_BOOKBASE) == true)
    {
        string query = "SELECT * from \"bdBooksCount\"";

        PGresult *result = PQexec(db, query.c_str());
        if (PQresultStatus(result) != PGRES_TUPLES_OK)
        {
            queryError(result);
        }
        else
        {
            for (unsigned short int i = 0; i <= 2; i++)
            {

               (*booksCount).push_back(PQgetvalue(result, 0, i));

            }
        }

    }
}

void bdOper::sendNewBookToBase(string isbn, string title, string autor, string multiTitle, string addTitle, string vollume, int pageCount, int city, int publish, int year, string subj, int BBK, int knowledgeSection, int autorSign, int series)
{
//    string query = boost::str(format("UPDATE \"bdBooksCount\" SET \"ek\" = %s, \"oldek\" = %s, \"retro\"= %s") % booksCount.at(0)//.substr(0, booksCount.at(0).length() - 1)
//                                                                                                                   % booksCount.at(1)//.substr(0, booksCount.at(1).length() - 1)
//                                                                                                                   % booksCount.at(2));//.substr(0, booksCount.at(2).length() - 1));
    
    string query = boost::str(format("INSERT INTO bookbase VALUES ('%s', '%s', '%s', '%s', '%s', '%s', %d, %d, %d, %d, '%s', %d, %d, %d, %d)") % isbn % title % autor % multiTitle % addTitle % vollume % pageCount % city % publish % year % subj % BBK % knowledgeSection % autorSign % series);
    //cout << query << endl;
    
    sendQuery(&query);
}

void bdOper::sendBookUnits(string index, int filial, string status, unsigned int bookID)
{
    string query = boost::str(format("INSERT INTO booksunits VALUES ('%s', '%d', '%s', %d)") % index % filial % status % bookID);
    //cout << query << endl;
    
    sendQuery(&query);
}

void bdOper::sendQuery(string* query)
{
    PGresult *result = PQexec(db, (*query).c_str());
    if (PQresultStatus(result) != PGRES_COMMAND_OK)
    {
        queryError(result);
    }
    else
    {
        //cout << "...inserted!!" << endl;
    }   
}

void bdOper::insertOneFieldToTable(string table, string field)
{
    string query = boost::str(format("INSERT INTO %s VALUES ('%s')") % table % field);
    //cout << query << endl;
    
    sendQuery(&query);
}


vector <bookUnit> bdOper::recvBookUnits(string bookID)
{
    vector <bookUnit> units;
    string query = boost::str(format(" SELECT index, filial, status FROM booksunits WHERE \"bookID\" = %s") % bookID);

    PGresult *result = PQexec(db, query.c_str());
    if (PQresultStatus(result) != PGRES_TUPLES_OK)
    {
        queryError(result);
    }
    else
    {
        
        for (unsigned short int i = 0; i < PQntuples(result); i++)
        {
            bookUnit unit;
            for (unsigned short int j = 0; j < 3; j++)
            {
                
                switch (j)
                {
                    case 0:
                    {
                        unit.index = PQgetvalue(result, i, 0);
                        break;
                    }
                    case 1:
                    {
                        unit.filial = PQgetvalue(result, i, 1);
                        break;
                    }
                    case 2:
                    {
                        //unit.bookStatus = boost::lexical_cast<int>(PQgetvalue(result, i, 2));
                        break;
                    }
                
                }
                
            }
                
                
                // << QString::fromLatin1(PQgetvalue(result, i, j));
            units.push_back(unit);     
        }
            

    }

    return units;
}

string bdOper::bdConnStatus()
{
    switch (PQstatus(db))
    {
        case CONNECTION_AUTH_OK:
        {
            return "подключаюсь... жду аутентификации";
            break;
        }
        case CONNECTION_AWAITING_RESPONSE:
        {
            return "жду ответа";
            break;
        }
        case CONNECTION_BAD:
        {
            return "ошибка подключения";
            break;
        }
        case CONNECTION_MADE:
        {
            return "соединение установлено. жду отсылки данных";
            break;
        }
        case CONNECTION_NEEDED:
        {
            return "не подключен. необходим вызов подключения!";
            break;
        }
        case CONNECTION_OK:
        {
            return "соединение установленно";
            break;
        }
        case CONNECTION_STARTED:
        {
            return "подключаюсь...";
            break;
        }
        default:
        {
            return "не определено";
            break;
        }
    }
    return "@#$";
}