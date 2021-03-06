/*
 * File:   bdOper.h
 * Author: f10-kafedra
 *
 * Created on 16 Октябрь 2011 г., 11:43
 */

#ifndef BDOPER_H
#define	BDOPER_H

#include <ace/INET_Addr.h>
#include <ace/SOCK_Acceptor.h>
#include <ace/SOCK_Connector.h>
#include <ace/SOCK_Stream.h>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtCore/QTextCodec>
#include <QtCore/QDateTime>
#include <stdlib.h>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include "structs.h"
#include "consts.h"
#include "crypto.h"

#ifdef WIN32
    #include <psql/9.1/libpq-fe.h>
#else
    #include </usr/include/postgresql/libpq-fe.h>
#endif

using namespace std;
using boost::format;

#define HOSTBD "127.0.0.1"
//#define HOSTBD "192.168.9.254"
//#define HOSTBD "192.168.9.250"

#define DBNAME_IPLIST "OurIP"
#define DBLOGIN_IPLIST "apm"
#define DBPASS_IPLIST "apm"

/*
 * db: bookbase
 */
const string DBNAME_BOOKBASE = "bookbase";

/*
 *  table books
 */
const string TABLE_NAME_BOOKS = "books";
/*
 *  table books units
 */
const string TABLE_NAME_BOOK_UNITS = "booksunits";

/*
 * login: irbis64Soft
 */
const string DBLOGIN_BOOKBASE = "irbis64soft";
/*
 * pass: apm
 */
const string DBPASS_BOOKBASE = "apm";

const string PSQL_ROOT_LOGIN = "postgres";
const string PSQL_ROOT_PASSWD = "123";

class bdOper {
public:
    bdOper();
    ~bdOper();

    vector<string> getFilials();
    vector<string> getFilialsID();
    vector<string> getFilialNames(QStringList);
    void saveAccount(QString login, QString pass, QString ip);
    //QStringList checkAccountAvailable(QString ip);

    string checkLastVersionBD();
    void updateLastVersionBD();
    string lastVersionApp();
    void updateLastVersionApp();

    void insertToBase(int id, QString name, QString fil, QString autor, QString KnowledgeSection, QString strID, QString strYear);
    void insertToBaseQuery(int id, QString name, QString fil, QString autor, QString KnowledgeSection);

    /*
     *  Проверка подключения к базе
     */
    bool isConnected();

    /*
     *  Статус подключения к БД
     */
    string bdConnStatus();
    
    /*
     *  очистка таблицы
     */
    void ClearTable(string table);

    /*
     *  сброс счетчиков во всех таблицах
     */
    void resetAllCounters();
    
    /*
     *  Получить количество записей в базе
     *  table - имя базы
     */
    int getAmountRecords(string table);

    void setPrintUsedIP();

    vector<QStringList> getBooks(string condition);

    /*
     *  Узнать количество книг в базах
     */
    void getBooksInBasesCount(vector <string>* booksCount);

    /*
     *  Изменить количество книг в базе
     */
    void updateMaxBookInBases(vector <string> booksCount);

//    QStringList getFilialsID();
//    QStringList getFilialNames(QStringList);
//    void saveAccount(QString login, QString pass, QString ip);
//    QStringList checkAccountAvailable(QString ip);

    //QSqlDatabase db;
    PGconn* db;
    QString myIp;
    QString query;

    vector<string> getField(string table, string field, int condition);
    vector<string> getField(QString table, QString field, QString condition);

    
    /*
     *  Занести в базу новую книгу
     *  ISBN (char var), заглавие (char var), автор (char var), заглавие многотомника (char var)б
     *    доп.сведения о заглавии (char var), номер тома/книги (char var), объем - int,
     *    город int, издательство int, год int, тематика (char var), BBK int, 
     *    раздел знаний int, авторский знак int, серия int
     */
    void sendNewBookToBase(string isbn, string title, string autor, string multiTitle, string addTitle, \
                             string vollume, int pageCount, int city, int publish, int year, string subj, \
                             int BBK, int knowledgeSection, int autorSign, int series);
    
    /*
     *  Занести в базу сведения об экземплярности книги
     *  ИД экземпляра (char var), номер филиала из таблицы filials (int), статус книги (char var), ИД книги (int)
     */
    void sendBookUnits(string index, int filial, string status, unsigned int bookID);
    
    /*
     *  Получить список экземпляров книг, по id книги в базе
     */
    vector <bookUnit> recvBookUnits(string bookID);
    
    /*
     *  Занести в таблицу одно поле
     */
    void insertOneFieldToTable(string table, string field);
    
    bool connectToBD(string login, string pass, string db);
    void disconnect();

    /*
     *  Подготовить базуданных в СУБД
     */
    void prepareBD();
    
private:
    cryptographic crypt;
    
//    bool connectToBD(string db, string login, string pass);
//    void disconnect();
    void queryError(PGresult* result);
    void getResult(PGresult** result, unsigned short int items, vector<string>* container);
/*    bool connectToBD();
    void disconnect();
    void queryError(QSqlQuery query); */

    /*
     *  послать запрос в базу и получить ответ
     */
    bool sendQuery(string* query);
    
    /*
     *  Подключение к СУБД с правами владельца
     */
    bool connectROOTtoBD();
    
    /*
     * Создание базы книг ->
     * CREATE DATABASE bookbase
     * (
     * 
     * );
     * 
     * CREATE UNIQUE index
     */
    void prepareBookBase();
    
    /*
     *  Создание ролей для доступа к БД
     *  CREATE ROLE oa LOGIN NOSUPERUSER NOINHERIT CREATEDB NOCREATEROLE REPLICATION;
     */
    void prepareRoles();
    
    /*
     *  Сброс активных подключений к базе данных
     *  SELECT pid as procpid FROM pg_catalog.pg_stat_activity WHERE datname = 'testbd';
     *  SELECT pg_terminate_backend(procpid) FROM pg_stat_activity WHERE datname = 'testbd';
     */
    void dropConnectionsToBD();
    
    void dropTable(string table);
    
    void prepareReadersBase();
};

#endif	/* BDOPER_H */

