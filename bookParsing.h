/* 
 * File:   parsing.h
 * Author: demiin
 *
 * Created on 5 Февраль 2011 г., 19:37
 */


#ifndef PARSING_H
#define	PARSING_H

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QDir>
#include <iostream>
#include <math.h>
#include <QtCore/QRegExp>
#include <boost/regex.hpp>
#include <vector>
#include "consts.h"

using namespace std;


class parsing {
public:
    parsing();
    virtual ~parsing();
    
    QString openFile(QString filename, char openMode);
    void prepareFileBooks();
    int amount(QString what);
    unsigned int amountBooks();
    void getBookName();
    QString parseName(QString str, int field);  // общий парсер
    QString parseKS_EK(QString str, int field); // для базы EK
    QString parseKS_EKNEW_RETRO(QString str, int field); // для базы EKNEW и RETRO
    QString prepareFilialName(QString line); // приводим название филиала к единому виду Ф.##

    QString parseFilialData(QString line, QString pattern);
    void test();
    
    vector<string> getAutorAndName(string filter);
    
    int curRecord;
    int amountRecord;
    bool isConsole;
private:
    QFile fileID_read;
    QFile fileID_write;
    QStringList filesListBases;
    QStringList filesListPrepared;
    QRegExp re;
};

struct filials
{
    QString name;
    int pos;
};

#endif	/* PARSING_H */

