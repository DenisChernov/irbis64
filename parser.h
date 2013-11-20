/* 
 * File:   parser.h
 * Author: f10-kafedra
 *
 * Created on 10 Сентябрь 2011 г., 18:29
 */

#ifndef PARSER_H
#define	PARSER_H

#include <iostream>

#include <QtCore/QString>
#include <QtCore/QRegExp>
//#include <QTemporaryFile>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include <QtWidgets/QMessageBox>
#include <map>
#include <stdio.h>
#include <boost/regex.hpp>

#include "structs.h"

using namespace std;

const QString fieldID[] = {"10#", // фамилия
                           "11#", // имя
                           "12#", // отчество
                           "21#", // г.р.
                           "50#", // категория
                           "67#", // доп. категория
//                           "14#", // паспортные данные
//                           "13#", // место проживания
                           "20#", // образование
//                           "40#", // посещение
//                           "51#", // дата записи
//                           "52#", // дата перерегистрации
                           "17#", // телефон
//                           "691#", // СПС\ЕФ
//                           "33#", // наличие договора
//                           "910#", // фото
                          };

//#define DEBUG = 1

class parser {
public:
    parser();
    virtual ~parser();
    
    
    
    info infos;
    pars parseData;
    QRegExp reGlobal;
    QRegExp reField;
    QString visits;
    customers reader;
    map <unsigned char, string> url_table;

    /*
     *  список городов
     */
   map <int, string> cities;
    
    /*
     *  список издательств
     */
    map <int, string> publishes;
    
    /*
     *  список авторских знаков
     */
    map <int, string> autorSignes;
    
    /*
     *  список годов издания
     */
    map <int, string> yearsOfPublish;

    /*
     *  список разделов знания
     */
    map <int, string> sectionKnowledge;

    /*
     *  список серий книг
     */
    map <int, string> series;
    
    
    
    vector <booksData> books;
    /*
     *  Разпарсинг книг. Книги хранятся в векторе books.
     */
    void parseBookRecord(string line);
    
    int countVisits(string rawData);
    
    QString translateData(QString rawData);
    QString parseUserData(QString rawData);
    bool wasToday(string rawdata, string data, string fil);
    QString parseServerVersion(QString rawData);
    QString parseLastID(QString rawData);
    bool parseExistUser(QString rawData);
    vector <info> parseTargetInfo(string rawData);
    QStringList parseUserGettedByID(string rawData);
    QString parseUserRecord(QString record);
    int getMsgLen(string data);
    QStringList parseFIO(string fio);
    QStringList parseListFIOResult(string rawData);
    void addReg_ReReg(string filial, string curYear);
    
    /*
     *  Создаем справочник из файла справочника на сервере ирбиса
     */
    vector <string> parseConfFile(string rawData);
    
    /*
     *  Проверка ответа на истинность
     */
    bool ifExistUser(string rawData);
    
    /*
     *  Получить количество записей
     */
    string getCount(string rawData);
    
    string getLine(string rawData, int shift);
    
    
    /*
     *  Вычленить чистый адрес сервера
     */
    string cleanURL(string url);
    /*
     *  Вычленить страницу обработчик запросов
     */
    string cleanEngine(string url);
    /*
     *  Получить VIEWSTATE EVENTVALIDATION COOKIE параметры
     */
    vector<string> get_vewstate_eventvalidation(string rawData);
    /*
     *  Получить кукисы
     */
    string getCookie(string rawData);
    /*
     *  Определить перенаправление на страницу
     */
    string whereMoved(string rawData);
    /*
     *  Высчитываем количество результатов по запросу в isbn
     */
    int countResults(string rawData);
    /*
     *  Получение данных о книге с полученной страницы
     */
    booksData bookInfo(string rawData);
    /*
     *  Кодирование строки в Uri
     */
    string urlencode(string str);
    void prepareUrlTable();
    
    /*
     *  Получение авторского знака
     */
    string getAutorSign(string rawData);
    
    /*
     *  Получить MFN 
     */
    string mfn(string rawData);
    
    /*
     *  Замена MFN на нуль, для подготовки к аплоаду в БД
     */
    string replaceMFN(string line);
    
private:
    
    
};

#endif	/* PARSER_H */

