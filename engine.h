/*
 * File:   engine.h
 * Author: f10-kafedra
 *
 *
 *
 *
 *
 *
 * Created on 29 Январь 2012 г., 15:24
 */

#ifndef ENGINE_H
#define	ENGINE_H

//#define DEBUG_OUTPUT

#include <ace/INET_Addr.h>
#include <ace/SOCK_Connector.h>
#include <ace/SOCK_Stream.h>
#include <QtWidgets/QMessageBox>

#include <boost/lexical_cast.hpp>
#include <vector>
#include "structs.h"
#include "parser.h"

#include <iostream>

#define MAGIC_USER_ID 31337
//#define HOST "192.168.9.246"
//#define HOST "192.168.9.219"
//#define HOST "192.168.9.18"
#define HOST "192.168.9.20"
//#define HOST "127.0.0.1"
#define PORT 6666

const size_t RECV_BUFFER_SIZE = 1460;

using namespace std;

class engine {
public:
    int code;


    bool silentMode;
    parser srvPars;
    string login;
    string pass;

    engine(apmType apm = APM_REGUSER, string login = "irbisoft", string pass = "9f9@7Nuq");
    virtual ~engine();

    /*
     * Подключение к базе.
     */
    void loginToBase();

    /*
     * Отключение от базы
     */
    void unloginFromBase();

    /*
     * Получить пользователя по его идентификатору из ирбиса.
     */
    QStringList getUserByID(string id, string filial, string date);
    QStringList getUserByFIO(string fio, string filial);

    QStringList getuserByFAM(QStringList FAM);
    string getUserRecord(string MFN);
    void updateRecord(string record, string visit);

    /*
     *  Проверка вхождения ФИО в БД.
     *  На входе - строка ФИО.
     *  Возвращает список найденных вхождений.
     */
    QStringList checkUsersExists(string fio);

    /*
     *  Проверка на регистрацию пользователя в БД
     *  На входе - строка ФИО и год рождения
     *  Возвращает результат поиска
     */
    bool checkUserExist(vector <string> userData);

    /*
     *  Получить файл справочника
     */
    string getConfFile(string file);

    /*
     *  Регистрация нового пользователя
     */
    void regNewUser(string userData);

    /*
     *  Получить книги из диапозона
     */
    string getBooks(string base, int from, int to);

    /*
     *  Получить максимальный MFN
     */
    string getMaxMFN(string base);

    /*
     *  Получить справки
     */
    string getInfos(int from, int to);


    void sendInfos(QStringList info);

    void uploadBook(string bookRecord);

private:
    ACE_SOCK_Connector connector;
    ACE_SOCK_Stream peer;
    ACE_INET_Addr peer_addr;
    char buf[BUFSIZ];

    apmType currentAPM;
    string _login;
    string _pass;
    int reqCounter;
    queueRequests request;


    /*
     *  Запуск движка
     */
    void run();

    /*
     * Подключение к хосту.
     * host -> адрес PC, где находится ирбис
     * port -> порт, который случаешь ирбис.
     * Возвращает
     */
    int connectToHostBase(const char* host, const int port);

    /*
     * отключение от хоста
     */
    void disconnectFromBase();

    /*
     * Отправление данных.
     * Возвращает TRUE в случае успеха
     */
    bool sendData(string data);

    /*
     * Получаем отосланные данные. В идеале - вызов сразу после sendData(string).
     * Возвращает - полученный ответ от ирбиса.
     */
    string reciveAnswer();


    /*
     * Формирование запроса подключения к базе.
     * codeCommand -> код команды: A - административная
     *
     * codeAPM -> код арма:
     *  A - администратор
     *  C - каталогизатор
     *  M - комплектатор
     *  R - читатель
     *  B - книговыдача
     */
    string loginRequest(string codeCommand, string codeAPM);

    /*
     * Формирование запроса отключения от базе.
     * codeCommand -> код команды: A - административная
     *
     * codeAPM -> код арма:
     *  A - администратор
     *  C - каталогизатор
     *  M - комплектатор
     *  R - читатель
     *  B - книговыдача
     */
    string unLoginRequest(string codeCommand, string codeAPM);



    string generalRequest(string codeCommand, string codeAPM, string parameters);
    string generalRequestEditEnabled(string codeCommand, string codeAPM, string parameters);



};

#endif	/* ENGINE_H */

