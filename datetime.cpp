/* 
 * File:   datetime.cpp
 * Author: f10-kafedra
 * 
 * Created on 20 Сентябрь 2011 г., 14:22
 */

#include "datetime.h"

datetime::datetime() {
    dtDateTime = new QDateTime(QDateTime::currentDateTime());
}

datetime::~datetime() {
}

QString datetime::year()
{
    return dtDateTime->toString("yyyy");
}

QString datetime::month()
{
    return dtDateTime->toString("MM");
}

QString datetime::day()
{
    return dtDateTime->toString("dd");
}

QString datetime::fullDate()
{
    return dtDateTime->toString("yyyyMMdd");
}

QString datetime::getHalfYear()
{
    return dtDateTime->toString("yy");
}

QString datetime::curTime()
{
    return dtDateTime->toString("hh:mm:ss");
}