/*
 * File:   structs.h
 * Author: f10-kafedra
 *
 * Created on 10 Сентябрь 2011 г., 17:45
 */

#ifndef STRUCTS_H
#define	STRUCTS_H

#include <string>
#include <QtCore/QString>
#include <vector>

using namespace std;

enum apmType{
                APM_REGUSER,
                APM_REREG,
                APM_INFO,
                APM_BOOKSEARCH
            };

enum targetField{
                        TARGET_REQUEST,
                        TYPE_INFO
                };

enum oper {oper_IDLE,
           oper_CHECK_EXIST_USER

          };

enum curSearchStage{GetInitPage,
                    GetManyResults,
                    GetFullBookInfo,
                    GetAdditionalBookInfo,
                    Stopped
};



enum request {APP_START,
              IDLE,
              LOGIN,
              UNLOGIN,
              GETMAXMFN,
              SERVER_VERSION,
              GET_USER_BY_MFN,
              GET_USER_BY_FIO,
              GET_USER_BY_ID,
              CREATE_USER,
              GET_LOGIC_DEL,
              GET_FILE_CITY,
              GET_FILE_STREET,
              GET_FILE_STUDY,
              GET_FILE_OVD,
              CHECK_USER_EXISTS,
              GET_TARGET_INFO,
              GET_INFO_BY_FIELDS,
              SEND_INFOS,
              UPDATE_RECORD,
              GET_RECORD
                };

enum fields {VISITS,
             REREG

};

enum ACE_ERROR_SETUP {RETURN_OK = 0,
                      SET_PEER_ERROR = -1,
                      SET_CONNECTOR_ERROR = -2
};

struct info
{
    QString target;
    QString topic;
    QString typeInfo;
    QString source;
    QString knowledge;
};

/*
 *  структура записи посещения в филиал
 *  fil - название филиала
 *  date - дата посещения
 */
struct visit
{
    vector <string> fil;
    vector <string> date;
};

/*
 *  структура записи читателя
 *  fam, name, sname - ФИО
 *  visit visits - структура записи посещений
 */
struct customers
{
    string mfn;
    string fam;
    string name;
    string sname;
    string oldRecord;
    string filials;
    //visit visits;
};

struct bookUnit
{
    /*
     *  статус книги. 0 - в фонде, 1 - выдана
     */
    int bookStatus = -1;
    
    /*
     *  индекс книги
     */
    string index;
    
    /*
     *  место хранения
     */
    string filial;
};

/*
 *  данные о книге, полученные с книгохранилищ
 */
struct booksData
{
    string FIO;
    string bookName;
    int yearOfPublication = -1;
    int publishing = -1;
    int cityOfPublishing = -1;
    int pageCount = 0;
    int autorSign = -1;
    int sectionKnowledge = -1;
    string aboutBook;
    string indexUDK;
    string BBK;
    int series = -1;
    
    /*
     * роман, повесть
     */
    string additionalBookName; 
    
    /*
     * том, книга, часть
     */
    string bookType; 
    string bookVollume;
    
    /*
     *  название тома, части, книги из многотомника
     */
    string vollumeBookName; 
     
    /* 
     *  ISBN
     */
    string ISBN;
    
    /*
     *  Предметная рубрика
     */
    string subject;
    
    vector <bookUnit> bookHandler;
    
};

struct requests
{
    request lastRequest;
    bool inWork;
};

struct lastOperation
{
    request oper;
    int result;
};

struct operations
{
    oper operation;
    QString request;
};

struct pars
{
    QString codeCommand;
    QString numbCommand;
    int uniqueID;
    int returnCode;
    QString data;
};

struct confs
{
    bool filled;
    QString city;
    QString street;
    QString study;
    QString OVD;
};

struct catalogs
{
    vector <string> city;
    vector <string> streets;
    vector <string> study;
    vector <string> OVD;
};

struct queueRequests
{
  bool needReadAnswer;
  int id;
  QString req;
  request operation;
};

struct passportsData
{
    QString ovd;
    vector <QString> streets;
};


#endif	/* STRUCTS_H */

