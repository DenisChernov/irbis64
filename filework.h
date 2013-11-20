/* 
 * File:   filework.h
 * Author: f10-kafedra
 *
 * Created on 8 Апрель 2012 г., 12:36
 */

#ifndef FILEWORK_H
#define	FILEWORK_H

#include <string>
#include <fstream>

enum fileMode 
{
    fOpen,
    fWrite,
    fAppend
};

using namespace std;

class filework {
public:
    filework(string filename, fileMode mode);
    void write(string data);
    string readline();
    bool eof();
    
    void close();
    virtual ~filework();
    
private:
    string filename;
    ofstream wFile;
    ifstream rFile;
    
};

#endif	/* FILEWORK_H */

