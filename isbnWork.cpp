/* 
 * File:   isbnWork.cpp
 * Author: f10-kafedra
 * 
 * Created on 16 Ноябрь 2011 г., 15:58
 * 
 * 
 * ip.dst == 213.247.202.66 || ip.src == 213.247.202.66
 * ip.dst == 79.174.73.73 || ip.src == 79.174.73.73
 * 
 * __LASTFOCUS=&__EVENTTARGET=ctl00%24cphMain%24grvPublications&__EVENTARGUMENT=Select%24###&__VIEWSTATE=.......
 * 
 * 
 * k=%D8%EC%E8%E4%F2
 * 
 */


//#include <curl/curl.h>

#include "isbnWork.h"
#include "form_BookWork.h"
//#include "threads.h"
#include "datetime.h"

isbnWork::isbnWork() 
{
    srvPars.prepareUrlTable();
    //loadPage(ISBN_SOURCE_BD_RFBookChamber);

}

isbnWork::~isbnWork() 
{
    
}


void isbnWork::loadInitPage_MGOUNB()
{
#ifdef DEBUG_OUTPUT
    cout << "getting page secrets" << endl;
#endif
    
    QFile f("cookie.txt");
    if (f.exists())
        f.remove();
                
    if (f.open(QIODevice::Text | QIODevice::WriteOnly))
    {
        f.close();
    }    
/*    
    curl = curl_easy_init();
    
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://opac.mgounb.ru/cgiopac/opacg/opac.exe");
        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        //указываем функцию обратного вызова для записи получаемых данных
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writedata);
        //указываем куда записывать принимаемые данные
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
        curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
        curl_easy_setopt(curl, CURLOPT_REFERER, "Referer: http://opac.mgounb.ru/opacg/inter1.htm");
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 44);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "arg0=GUES2&arg1=GUESTE2&TypeAccess=PayAccess");
    
        result = curl_easy_perform(curl);
        cout << "result: " << result << '\n' << buffer << endl;
        //this->page->setHtml(QString::fromStdString(buffer), QUrl("http://rbip.bookchamber.ru/PublicationsView.aspx"));
    }
    curl_easy_cleanup(curl);*/
}

void isbnWork::getShortBookInfo_MGOUNB()
{
#ifdef DEBUG_OUTPUT
    cout << "getting short book info" << endl;
#endif
    buffer.clear();
    /*
    curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://opac.mgounb.ru/cgiopac/opacg/direct.exe");
        //curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        //указываем функцию обратного вызова для записи получаемых данных
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writedata);
        //указываем куда записывать принимаемые данные
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
//        curl_easy_setopt(curl, CURLOPT_REFERER, "Referer: http://opac.mgounb.ru/opacg/html/hidden_query_frame/index.html");
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, true);
        //curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, postdata.toLatin1().length());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; rv:9.0) Gecko/20100101 Firefox/9.0");
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip, deflate");
        
        static string str = "_errorXsl=%2Fopacg%2Fhtml%2Fcommon%2Fxsl%2Ferror.xsl&_wait=6M&_xsl=%2Fopacg%2Fhtml%2Fsearch%2Fxsl%2Fsearch_results.xsl&_version=2.0.0&_service=STORAGE%3Aopacfindd%3AFindView&outform=FULLFORM&length=15&query%2Fbody=%28SB+";
        //str.append(isbn_c);
        str.append("%29&query%2Fopen=%7BNC%3A%3Cspan+class%3D%27red_text%27%3E%7D&query%2Fclose=%7BNC%3A%3C%2Fspan%3E%7D&userId=GUES2&session=201576&iddb=1&level%5B0%5D=Full&level%5B1%5D=Retro&level%5B2%5D=Unfinished&level%5B3%5D=Unknown&level%5B4%5D=Identify");
    
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(str.c_str()));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, str.c_str());
        
        
        result = curl_easy_perform(curl);
        cout << "result: " << result << '\n' << buffer << endl;
        //this->page->setHtml(QString::fromStdString(buffer), QUrl("http://rbip.bookchamber.ru/PublicationsView.aspx"));
    }
    curl_easy_cleanup(curl);    
    */
}

void isbnWork::loadPage(string url)
{
    switch (initACE(url))
    {
        case SET_PEER_ERROR:
        {
            cout << "error peer set" << endl;
            break;
        }
        case SET_CONNECTOR_ERROR:
        {
            cout << "error connect" << endl;
            break;
        }
        case RETURN_OK:
        {
            cout << "setting alright" << endl;
            break;
        }
    }
    
    get_InitRFBookChamberPage();
    secrets = srvPars.get_vewstate_eventvalidation(lastAnswer);

    deinitACE();
    
    
    switch (initACE(url))
    {
        case SET_PEER_ERROR:
        {
            cout << "error peer set" << endl;
            break;
        }
        case SET_CONNECTOR_ERROR:
        {
            cout << "error connect" << endl;
            break;
        }
        case RETURN_OK:
        {
            cout << "setting alright" << endl;
            break;
        }
    }
    get_Book_RFBookChamber();
//    cout << lastAnswer.c_str() << endl;
    //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(lastAnswer)).data() << endl;
    
    deinitACE();
}

ACE_ERROR_SETUP isbnWork::initACE(string server_url)
{
    
    if (peer_addr.set(80, srvPars.cleanURL(server_url).c_str()) == -1)
    {
        return SET_PEER_ERROR;
    }
    else
    if (connector.connect(peer, peer_addr) == -1)
    {
        return SET_CONNECTOR_ERROR;
    }
    
    return RETURN_OK;
}

void isbnWork::deinitACE()
{
    connector.complete(peer, 0, &ACE_Time_Value::zero);
    peer.close();
}

bool isbnWork::sendRequest(const iovec iov[], unsigned short size)
{
    ssize_t lenSend = 0;
    lenSend = peer.sendv_n(iov, size);
    cout << "sended: " << lenSend << endl;
    if (lenSend > 0)
        return true;
    else
        return false;
}

string isbnWork::reciveAnswer()
{
    ACE_Time_Value timeout(10);
    char buf[RECV_BUFFER_SIZE];
    ssize_t lenRecv = 0;    
    ssize_t amount = 0;
    string msg;
    
//    lenRecv = peer.recv(buf, RECV_BUFFER_SIZE, &timeout);
//    cout << buf << endl;
    
    while (lenRecv = peer.recv(buf, RECV_BUFFER_SIZE, &timeout))
    {
        if (lenRecv >= 0)
        {
//                cout << "lenRecv: " << lenRecv << endl;
                amount += lenRecv;
//                cout << "amount: " << amount << endl;
                buf[lenRecv] = '\0';
                msg.append(buf);
                if (QString::fromLatin1(buf).contains("</html>"))
                    break;
        }
    }
    
    cout << "i recv: " << amount << endl;
    return msg;
}


void isbnWork::get_InitRFBookChamberPage()
{
    curStage = GetInitPage;
    
    iovec iov[11];
    iov[0].iov_base = "GET ";
    iov[0].iov_len = 4;
    iov[1].iov_base = (char*)srvPars.cleanEngine(ISBN_SOURCE_BD_RFBookChamber).c_str();
    iov[1].iov_len = strlen(iov[1].iov_base);
    iov[2].iov_base = " HTTP/1.1\r\n";
    iov[2].iov_len = strlen(iov[2].iov_base);
    
    iov[3].iov_base = "Host: rbip.bookchamber.ru\r\n";
    iov[3].iov_len = strlen(iov[3].iov_base);
    iov[4].iov_base = "User-Agent: Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
    iov[4].iov_len = strlen(iov[4].iov_base);
    iov[5].iov_base = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
    iov[5].iov_len = strlen(iov[5].iov_base);
    iov[6].iov_base = "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
    iov[6].iov_len = strlen(iov[6].iov_base);
    iov[7].iov_base = "Accept-Encoding: gzip, deflate\r\n";
    iov[7].iov_len = strlen(iov[7].iov_base);
    iov[8].iov_base = "DNT: 1\r\n";
    iov[8].iov_len = strlen(iov[8].iov_base);
    iov[9].iov_base = "Connection: keep-alive\r\n";
    iov[9].iov_len = strlen(iov[9].iov_base);
    iov[10].iov_base = "Cache-Control: max-age=0\r\n\r\n";
    iov[10].iov_len = strlen(iov[10].iov_base);
    
    if (sendRequest(iov, 11) == true)
    {
//        cout << "send successful" << endl;
        lastAnswer = reciveAnswer();
    }
    else
        cout << "error send" << endl;
}

void isbnWork::get_Book_RFBookChamber()
{
    books.clear();
    curStage = GetManyResults;
    
    string request = "__LASTFOCUS=&__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=" + secrets.at(0) + 
                                                           "&__EVENTVALIDATION=" + secrets.at(1) + 
                                                           "&eeF010a=" + isbn + "&ctl00%24cphMain%24ePageSize=100&ctl00%24cphMain%24btnDoSearch2=%D0%92%D1%8B%D0%BF%D0%BE%D0%BB%D0%BD%D0%B8%D1%82%D1%8C+%D0%BF%D0%BE%D0%B8%D1%81%D0%BA";
    
    iovec iov[31];
    iov[0].iov_base = "POST ";
    iov[0].iov_len = strlen(iov[0].iov_base);
    iov[1].iov_base = "/SearchPublications.aspx";//(char*)srvPars.cleanEngine(ISBN_SOURCE_BD_RFBookChamber).c_str();
    iov[1].iov_len = strlen(iov[1].iov_base);
    iov[2].iov_base = " HTTP/1.1\r\n";
    iov[2].iov_len = strlen(iov[2].iov_base);
    iov[3].iov_base = "Host: ";
    iov[3].iov_len = strlen(iov[3].iov_base);
    iov[4].iov_base = "rbip.bookchamber.ru\r\n";
    iov[4].iov_len = strlen(iov[4].iov_base);
    iov[5].iov_base = "User-Agent: ";
    iov[5].iov_len = strlen(iov[5].iov_base);
    iov[6].iov_base = "Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
    iov[6].iov_len = strlen(iov[6].iov_base);
    iov[7].iov_base = "Accept: ";
    iov[7].iov_len = strlen(iov[7].iov_base);
    iov[8].iov_base = "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
    iov[8].iov_len = strlen(iov[8].iov_base);
    iov[9].iov_base = "Accept-Language: ";
    iov[9].iov_len = strlen(iov[9].iov_base);
    iov[10].iov_base = "ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
    iov[10].iov_len = strlen(iov[10].iov_base);
    iov[11].iov_base = "Accept-Encoding: ";
    iov[11].iov_len = strlen(iov[11].iov_base);
    iov[12].iov_base = "gzip, deflate\r\n";
    iov[12].iov_len = strlen(iov[12].iov_base);
    iov[13].iov_base = "Connection: ";
    iov[13].iov_len = strlen(iov[13].iov_base);
    iov[14].iov_base = "keep-alive\r\n";
    iov[14].iov_len = strlen(iov[14].iov_base);
    iov[15].iov_base = "Referer: ";
    iov[15].iov_len = strlen(iov[15].iov_base);
    iov[16].iov_base = ISBN_SOURCE_BD_RFBookChamber;
    iov[16].iov_len = strlen(iov[16].iov_base);
    iov[17].iov_base = "\r\nCookie: ";
    iov[17].iov_len = strlen(iov[17].iov_base);
    iov[18].iov_base = (char*)secrets.at(2).c_str();
    iov[18].iov_len = strlen(iov[18].iov_base);
    iov[19].iov_base = "\r\nContent-Type: ";
    iov[19].iov_len = strlen(iov[19].iov_base);
    iov[20].iov_base = "application/x-www-form-urlencoded\r\n";
    iov[20].iov_len = strlen(iov[20].iov_base);
    iov[21].iov_base = "Content-Length: ";
    iov[21].iov_len = strlen(iov[21].iov_base);
    iov[22].iov_base = QString::number(strlen(request.c_str())).toLatin1().data();
    iov[22].iov_len = strlen(iov[22].iov_base);
    iov[23].iov_base = "\r\n\r\n__LASTFOCUS=&__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=";
    iov[23].iov_len = strlen(iov[23].iov_base);
    iov[24].iov_base = (char*)secrets.at(0).c_str();
    iov[24].iov_len = strlen(iov[24].iov_base);
    iov[25].iov_base = "&__EVENTVALIDATION=";
    iov[25].iov_len = strlen(iov[25].iov_base);
    iov[26].iov_base = (char*)secrets.at(1).c_str();
    iov[26].iov_len = strlen(iov[26].iov_base);
    iov[27].iov_base = "&eeF010a=";
    iov[27].iov_len = strlen(iov[27].iov_base);
    iov[28].iov_base = (char*)isbn.c_str();//"978-5-9518-0362-7";
    iov[28].iov_len = strlen(iov[28].iov_base);
    iov[29].iov_base = "&ctl00%24cphMain%24ePageSize=100&ctl00%24cphMain%24btnDoSearch2=";
    iov[29].iov_len = strlen(iov[29].iov_base);
    iov[30].iov_base = "%D0%92%D1%8B%D0%BF%D0%BE%D0%BB%D0%BD%D0%B8%D1%82%D1%8C+%D0%BF%D0%BE%D0%B8%D1%81%D0%BA"; //"Выполнить+поиск";
    iov[30].iov_len = strlen(iov[30].iov_base);
 
    string pageToMove;
    
    if (sendRequest(iov, 31) == true)
    {
        pageToMove = srvPars.whereMoved(reciveAnswer());
    }
    else
        cout << "error send" << endl;    

    iov[0].iov_base = "GET ";
    iov[0].iov_len = 4;
    iov[1].iov_base = (char*)pageToMove.c_str();
    iov[1].iov_len = strlen(iov[1].iov_base);
    iov[2].iov_base = " HTTP/1.1\r\n";
    iov[2].iov_len = strlen(iov[2].iov_base);
    iov[3].iov_base = "Host: rbip.bookchamber.ru\r\n";
    iov[3].iov_len = strlen(iov[3].iov_base);
    iov[4].iov_base = "User-Agent: Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
    iov[4].iov_len = strlen(iov[4].iov_base);
    iov[5].iov_base = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
    iov[5].iov_len = strlen(iov[5].iov_base);
    iov[6].iov_base = "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
    iov[6].iov_len = strlen(iov[6].iov_base);
    iov[7].iov_base = "Accept-Encoding: gzip, deflate\r\n";
    iov[7].iov_len = strlen(iov[7].iov_base);
    iov[8].iov_base = "DNT: 1\r\n";
    iov[8].iov_len = strlen(iov[8].iov_base);
    iov[9].iov_base = "Cookie: ";
    iov[9].iov_len = strlen(iov[9].iov_base);
    iov[10].iov_base = (char*)secrets.at(2).c_str();
    iov[10].iov_len = strlen(iov[10].iov_base);
    iov[11].iov_base = "\r\nConnection: keep-alive\r\n";
    iov[11].iov_len = strlen(iov[11].iov_base);
    iov[12].iov_base = "Cache-Control: max-age=0\r\n\r\n";
    iov[12].iov_len = strlen(iov[12].iov_base);
    
    string cookie = secrets.at(2);
    
    if (sendRequest(iov, 13) == true)
    {
        lastAnswer = reciveAnswer();
    }
    else
        cout << "error send" << endl;

    deinitACE();

        switch (initACE(ISBN_SOURCE_BD_RFBookChamber_View))
        {
            case SET_PEER_ERROR:
            {
                cout << "error peer set" << endl;
                break;
            }
            case SET_CONNECTOR_ERROR:
            {
                cout << "error connect" << endl;
                break;
            }
            case RETURN_OK:
            {
                cout << "setting alright" << endl;
                break;
            }
        }    
    
    
    countResults = srvPars.countResults(lastAnswer);
    
    secrets = srvPars.get_vewstate_eventvalidation(lastAnswer);
    for (int i = 0; i < countResults; i++) // перебор всех результатов
    {
        cout << "#" << i << endl;
        
        curStage = GetFullBookInfo;
        
        request.clear();
        request = "__LASTFOCUS=&__EVENTTARGET=ctl00%24cphMain%24grvPublications&__EVENTARGUMENT=Select%24" + QString::number(i).toStdString() + "&__VIEWSTATE=" + secrets.at(0) + 
                                                                   "&__VIEWSTATEENCRYPTED=&__EVENTVALIDATION=" + secrets.at(1);

        deinitACE();

        switch (initACE(ISBN_SOURCE_BD_RFBookChamber_View))
        {
            case SET_PEER_ERROR:
            {
                cout << "error peer set" << endl;
                break;
            }
            case SET_CONNECTOR_ERROR:
            {
                cout << "error connect" << endl;
                break;
            }
            case RETURN_OK:
            {
                cout << "setting alright" << endl;
                break;
            }
        }        
        
        iov[0].iov_base = "POST ";
        iov[0].iov_len = 5;
        iov[1].iov_base = (char*)pageToMove.c_str();
        iov[1].iov_len = strlen(iov[1].iov_base);
        iov[2].iov_base = " HTTP/1.1\r\n";
        iov[2].iov_len = strlen(iov[2].iov_base);
        iov[3].iov_base = "Host: rbip.bookchamber.ru\r\n";
        iov[3].iov_len = strlen(iov[3].iov_base);
        iov[4].iov_base = "User-Agent: Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
        iov[4].iov_len = strlen(iov[4].iov_base);
        iov[5].iov_base = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
        iov[5].iov_len = strlen(iov[5].iov_base);
        iov[6].iov_base = "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
        iov[6].iov_len = strlen(iov[6].iov_base);
        iov[7].iov_base = "Accept-Encoding: gzip, deflate\r\n";
        iov[7].iov_len = strlen(iov[7].iov_base);
        iov[8].iov_base = "Connection: keep-alive\r\n";
        iov[8].iov_len = strlen(iov[8].iov_base);
        iov[9].iov_base = "Referer: ";
        iov[9].iov_len = strlen(iov[9].iov_base);
        iov[10].iov_base = ISBN_SOURCE_BD_RFBookChamber_View;
        iov[10].iov_len = strlen(iov[10].iov_base);
        iov[11].iov_base = "\r\nCookie: ";
        iov[11].iov_len = strlen(iov[11].iov_base);
        iov[12].iov_base = (char*)cookie.c_str();
        iov[12].iov_len = strlen(iov[12].iov_base);        
        iov[13].iov_base = "\r\nContent-Type: ";
        iov[13].iov_len = strlen(iov[13].iov_base);
        iov[14].iov_base = "application/x-www-form-urlencoded\r\n";
        iov[14].iov_len = strlen(iov[14].iov_base);
        iov[15].iov_base = "Content-Length: ";
        iov[15].iov_len = strlen(iov[15].iov_base);
        iov[16].iov_base = QString::number(strlen(request.c_str())).toLatin1().data();
        iov[16].iov_len = strlen(iov[16].iov_base);
        string req = "\r\n\r\n__LASTFOCUS=&__EVENTTARGET=ctl00%24cphMain%24grvPublications&__EVENTARGUMENT=Select%24" + QString::number(i).toStdString() + "&__VIEWSTATE=";
        iov[17].iov_base = (char*)req.c_str();
        iov[17].iov_len = strlen(iov[17].iov_base);
        iov[18].iov_base = (char*)secrets.at(0).c_str();
        iov[18].iov_len = strlen(iov[18].iov_base);
        iov[19].iov_base = "&__VIEWSTATEENCRYPTED=&__EVENTVALIDATION=";
        iov[19].iov_len = strlen(iov[19].iov_base);
        iov[20].iov_base = (char*)secrets.at(1).c_str();
        iov[20].iov_len = strlen(iov[20].iov_base);    
    
        if (sendRequest(iov, 21) == true)
        {
            cout << "get full book info part - successful" << endl;
            lastAnswer = reciveAnswer();
        }
        else
            cout << "error send" << endl;    
    
        string newPageToMove = srvPars.whereMoved(lastAnswer);

        deinitACE();

        switch (initACE(ISBN_SOURCE_BD_RFBookChamber_View))
        {
            case SET_PEER_ERROR:
            {
                cout << "error peer set" << endl;
                break;
            }
            case SET_CONNECTOR_ERROR:
            {
                cout << "error connect" << endl;
                break;
            }
            case RETURN_OK:
            {
                cout << "setting alright" << endl;
                break;
            }
        }            
            
            iov[0].iov_base = "GET ";
            iov[0].iov_len = 4;
            iov[1].iov_base = (char*)newPageToMove.c_str();
            iov[1].iov_len = strlen(iov[1].iov_base);
            iov[2].iov_base = " HTTP/1.1\r\n";
            iov[2].iov_len = strlen(iov[2].iov_base);
            iov[3].iov_base = "Host: rbip.bookchamber.ru\r\n";
            iov[3].iov_len = strlen(iov[3].iov_base);
            iov[4].iov_base = "User-Agent: Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
            iov[4].iov_len = strlen(iov[4].iov_base);
            iov[5].iov_base = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
            iov[5].iov_len = strlen(iov[5].iov_base);
            iov[6].iov_base = "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
            iov[6].iov_len = strlen(iov[6].iov_base);
            iov[7].iov_base = "Accept-Encoding: gzip, deflate\r\n";
            iov[7].iov_len = strlen(iov[7].iov_base);
            iov[8].iov_base = "DNT: 1\r\n";
            iov[8].iov_len = strlen(iov[8].iov_base);
            iov[9].iov_base = "Cookie: ";
            iov[9].iov_len = strlen(iov[9].iov_base);
            iov[10].iov_base = (char*)cookie.c_str();
            iov[10].iov_len = strlen(iov[10].iov_base);
            iov[11].iov_base = "\r\nConnection: keep-alive\r\n";
            iov[11].iov_len = strlen(iov[11].iov_base);
            iov[12].iov_base = "Cache-Control: max-age=0\r\n\r\n";
            iov[12].iov_len = strlen(iov[12].iov_base);
    
            if (sendRequest(iov, 13) == true)
            {
//        cout << "send successful" << endl;
                lastAnswer = reciveAnswer();
            }
            else
                cout << "error send" << endl;
        //}
    //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(lastAnswer)).data() << endl;
        
            booksData bookInfos;
            bookInfos = srvPars.bookInfo(lastAnswer);
        
            curStage = GetAdditionalBookInfo;
//            bookInfos.autorSign = get_AutorSign(bookInfos.FIO);
        
            books.push_back(bookInfos);
        //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(books.back().bookName)).data() << endl;
        
  //      cout << "###############" << endl;
    }
    
    countResults = books.size();
    
    deinitACE();
    
    curStage = Stopped;
    Thread.join();  
}
string isbnWork::get_AutorSign(string autor)
{

            string fio = QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(autor)).data();
            fio = srvPars.urlencode(fio.substr(0, fio.find_first_of(' ', 0)));
            
            deinitACE();
            
            switch (initACE(AUTOR_SIGN))
            {
                case SET_PEER_ERROR:
                {
                    cout << "error peer set" << endl;
                    break;
                }
                case SET_CONNECTOR_ERROR:
                {
                    cout << "error connect" << endl;
                    break;
                }
                case RETURN_OK:
                {
                    cout << "setting alright" << endl;
                    break;
                }
            }
            
            iovec iov[19];
            
            string request = "k=" + fio;
        iov[0].iov_base = "GET ";
        iov[0].iov_len = strlen(iov[0].iov_base);;
        iov[1].iov_base = "/znak.php";
        iov[1].iov_len = strlen(iov[1].iov_base);
        iov[2].iov_base = " HTTP/1.1\r\n";
        iov[2].iov_len = strlen(iov[2].iov_base);
        iov[3].iov_base = "Accept: text/html,application/xhtml+xml,*/*\r\n";
        iov[3].iov_len = strlen(iov[3].iov_base);
        iov[4].iov_base = "Accept-Language: ru-RU\r\n";
        iov[4].iov_len = strlen(iov[4].iov_base);
        iov[5].iov_base = "User-Agent: Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
        iov[5].iov_len = strlen(iov[5].iov_base);
        iov[6].iov_base = "Accept-Encoding: gzip, deflate\r\n";
        iov[6].iov_len = strlen(iov[6].iov_base);
        iov[7].iov_base = "Host: lit100.ru\r\n";
        iov[7].iov_len = strlen(iov[7].iov_base);
        iov[8].iov_base = "Connection: keep-alive\r\n\r\n";
        iov[8].iov_len = strlen(iov[8].iov_base);
            
        if (sendRequest(iov, 9) == true)
            {
//        cout << "send successful" << endl;
                lastAnswer = reciveAnswer();
            }
            else
                cout << "error send" << endl;                
        
        deinitACE();
        switch (initACE(AUTOR_SIGN))
            {
                case SET_PEER_ERROR:
                {
                    cout << "error peer set" << endl;
                    break;
                }
                case SET_CONNECTOR_ERROR:
                {
                    cout << "error connect" << endl;
                    break;
                }
                case RETURN_OK:
                {
                    cout << "setting alright" << endl;
                    break;
                }
            }
        
        string cookie = srvPars.getCookie(lastAnswer);
        
        
        iov[0].iov_base = "POST ";
        iov[0].iov_len = strlen(iov[0].iov_base);;
        iov[1].iov_base = "/znak.php";
        iov[1].iov_len = strlen(iov[1].iov_base);
        iov[2].iov_base = " HTTP/1.1\r\n";
        iov[2].iov_len = strlen(iov[2].iov_base);
        iov[3].iov_base = "Host: lit100.ru\r\n";
        iov[3].iov_len = strlen(iov[3].iov_base);
        iov[4].iov_base = "User-Agent: Mozilla/5.0 (Windows NT 6.1; rv:11.0) Gecko/20100101 Firefox/11.0\r\n";
        iov[4].iov_len = strlen(iov[4].iov_base);
        iov[5].iov_base = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
        iov[5].iov_len = strlen(iov[5].iov_base);
        iov[6].iov_base = "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
        iov[6].iov_len = strlen(iov[6].iov_base);
        iov[7].iov_base = "Accept-Encoding: gzip, deflate\r\n";
        iov[7].iov_len = strlen(iov[7].iov_base);
        iov[8].iov_base = "Connection: keep-alive\r\n";
        iov[8].iov_len = strlen(iov[8].iov_base);
        iov[9].iov_base = "Referer: ";
        iov[9].iov_len = strlen(iov[9].iov_base);
        iov[10].iov_base = AUTOR_SIGN;
        iov[10].iov_len = strlen(iov[10].iov_base);
        iov[11].iov_base = "\r\nCookie: Apache=";
        iov[11].iov_len = strlen(iov[11].iov_base);
        iov[12].iov_base = (char*)cookie.c_str();
        iov[12].iov_len = strlen(iov[12].iov_base);
        iov[13].iov_base = "\r\nContent-Type: ";
        iov[13].iov_len = strlen(iov[13].iov_base);
        iov[14].iov_base = "application/x-www-form-urlencoded\r\n";
        iov[14].iov_len = strlen(iov[14].iov_base);
        iov[15].iov_base = "Content-Length: ";
        iov[15].iov_len = strlen(iov[15].iov_base);
        iov[16].iov_base = QString::number(strlen(request.c_str())).toLatin1().data();
        iov[16].iov_len = strlen(iov[16].iov_base);            
        iov[17].iov_base = "\r\n\r\n";
        iov[17].iov_len = strlen(iov[17].iov_base);
        iov[18].iov_base = (char*)request.c_str();
        iov[18].iov_len = strlen(iov[18].iov_base);

        if (sendRequest(iov, 19) == true)
        {
			cout << "send successful" << endl;
            lastAnswer = reciveAnswer();
        }
        else
            cout << "error send" << endl;        
        
            
        deinitACE();
            
        return srvPars.getAutorSign(lastAnswer);

}

void isbnWork::run(string url)
{
//    assert(!this->Thread);
    curStage = GetInitPage;
    //Thread = boost::shared_ptr<boost::thread> ( new boost::thread(boost::bind(&isbnWork::loadPage, this, url)));
    Thread = boost::thread( boost::bind(&isbnWork::loadPage, this, url));
}

