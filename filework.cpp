/* 
 * File:   filework.cpp
 * Author: f10-kafedra
 * 
 * Created on 8 Апрель 2012 г., 12:36
 */

#include "filework.h"

filework::filework(string filename, fileMode mode)
{
    switch (mode)
    {
        case fOpen:
        {
            rFile.open(filename.c_str(), ios::in);
            if (!rFile)
                printf("error openning file");
            break;
        }
        case fWrite:
        {
            wFile.open(filename.c_str(), ios::out);
            if (!wFile)
                printf("error openning file");
            break;
        }
        case fAppend:
        {
            wFile.open(filename.c_str(), ios::app);
            if (!wFile)
                printf("error openning file");
            break;
        }
    }
}

filework::~filework() {
    close();
}

void filework::write(string data)
{
    wFile << data;
}

void filework::close()
{
    if (wFile.is_open())
        wFile.close();
    if (rFile.is_open())
        rFile.close();
}

string filework::readline()
{
    string line;
    getline(rFile, line);
    return line;
}

bool filework::eof()
{
    return rFile.eof();
}