/* 
 * File:   datetime.h
 * Author: f10-kafedra
 *
 * Created on 20 Сентябрь 2011 г., 14:22
 */

#ifndef DATETIME_H
#define	DATETIME_H

#include <QtCore/QDateTime>

class datetime {
public:
    datetime();
    virtual ~datetime();
    
    QDateTime* dtDateTime;
    
    QString year();
    QString month();
    QString day();
    QString getHalfYear();
    QString fullDate();
    QString curTime();
    
private:

};

#endif	/* DATETIME_H */

