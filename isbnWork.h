/* 
 * File:   isbnWork.h
 * Author: f10-kafedra
 *
 * Created on 16 Ноябрь 2011 г., 15:58
 */

#ifndef ISBNWORK_H
#define	ISBNWORK_H

//#include <QtWebKit/QWebView>

#include <ace/INET_Addr.h>
#include <ace/SOCK_Connector.h>
#include <ace/SOCK_Stream.h>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/shared_ptr.hpp>
#include <QtCore/QFile>
#include <iostream>
#include <curl/curl.h>
//#include <QThread>
#include <string>
#include <map>
#include "parser.h"
#include "structs.h"

using namespace std;

const size_t RECV_BUFFER_SIZE = 1514;
/*
 *  URL Российской Книжной палаты
 */
#define ISBN_SOURCE_BD_RFBookChamber "http://rbip.bookchamber.ru/SearchPublications.aspx"
#define ISBN_SOURCE_BD_RFBookChamber_View "http://rbip.bookchamber.ru/PublicationsView.aspx"

/*
 *  URL Мурманской Научной библиотеки
 */
#define ISBN_SOURCE_BD_MGOUNB "http://opac.mgounb.ru/cgiopac/opacg/opac.exe"

/*
 *  URL Сайта определения авторского знака
 */
#define AUTOR_SIGN "http://lit100.ru/znak.php"

class isbnWork{
public:
    isbnWork();
    virtual ~isbnWork();
    void prepareRequest();
    void getAutorSign();
    void loadPage(string url);
    
    void run(string url);
   
    ACE_SOCK_Connector connector;
    ACE_SOCK_Stream peer;
    ACE_INET_Addr peer_addr;
    char buf[BUFSIZ];
    
    
    curSearchStage curStage;
    parser srvPars;
    bool bookInfoGetted;
    CURL* curl;
    CURLcode result;
    string buffer;
    QString viewstate;
    QString eventvalidation;
    QString autor;
    QString numsean;

    
    string isbn;
    vector <booksData> books;
    
    /*
     *  Количество найденных книг
     */
    int countResults;
    
private:
    string lastAnswer;
    vector <string> secrets;
    boost::thread Thread;
    
    bool sendRequest(const iovec iov[], unsigned short size);
    string reciveAnswer();
    
    /*
     *  Инициализация ACE Wrappers.
     *  На входе: URL сервера
     */
    ACE_ERROR_SETUP initACE(string server_url);
    void deinitACE();
    
    /*
     *  Получить заглавную страницу поисковика книжной палаты РФ
     */
    void get_InitRFBookChamberPage();
    
    /*
     *  Получить данные о книгах из поисковика книжной палаты РФ
     */
    void get_Book_RFBookChamber();
    
    /*
     *  Получить авторский знак по фамилии
     */
    string get_AutorSign(string autor);
    
    
    void loadInitPage();
    void loadInitPage_MGOUNB();
    void getShortBookInfo_MGOUNB();
    
    
    
public slots:

    
};

#endif	/* ISBNWORK_H */

