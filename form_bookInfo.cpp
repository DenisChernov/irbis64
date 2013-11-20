/*
 * File:   form_bookInfo.cpp
 * Author: f10-kafedra
 *
 * Created on 26 Март 2012 г., 14:27
 */

#include "form_bookInfo.h"
#include "form_BookWork.h"

form_bookInfo::form_bookInfo() {
    frm_BookInfo.setupUi(this);
    connect(frm_BookInfo.pbGoLeft, SIGNAL(clicked()), this, SLOT(slot_prevBook()));
    connect(frm_BookInfo.pbGoRight, SIGNAL(clicked()), this, SLOT(slot_nextBook()));
}

form_bookInfo::~form_bookInfo() {
}

void form_bookInfo::loadBooks(vector <booksData>* loadedBooks)
{
    books = loadedBooks;
    
    setBook(1);
    this->setModal(true);
    this->show();
}

void form_bookInfo::setBook(int number)
{
    number--;
    frm_BookInfo.gbMultiVollume->setChecked(false);
    frm_BookInfo.leVollumeName->clear();
    
    frm_BookInfo.leCurNumber->setText(QString::number(number+1));
    frm_BookInfo.leMaxNumber->setText(QString::number(books->size()));
    frm_BookInfo.leAutor->setText(QString::fromStdString(books->at(number).FIO));
    frm_BookInfo.leAutorSign->setText(QString::fromStdString(books->at(number).autorSign));
    frm_BookInfo.leBookName->setText(QString::fromStdString(books->at(number).bookName));
    frm_BookInfo.cbCityOfPublishing->clear();
    frm_BookInfo.cbCityOfPublishing->addItem(QString::fromStdString(books->at(number).cityOfPublishing));
    frm_BookInfo.cbCityOfPublishing->setCurrentIndex(0);
    frm_BookInfo.cbPublishing->clear();
    frm_BookInfo.cbPublishing->addItem(QString::fromStdString(books->at(number).publishing));
    frm_BookInfo.cbPublishing->setCurrentIndex(0);
    frm_BookInfo.cbBBK->clear();
    frm_BookInfo.cbBBK->addItem(QString::fromStdString(books->at(number).BBK));
    frm_BookInfo.cbBBK->setCurrentIndex(0);
    frm_BookInfo.cbIndexUDK->clear();
    frm_BookInfo.cbIndexUDK->addItem(QString::fromStdString(books->at(number).indexUDK));
    frm_BookInfo.cbIndexUDK->setCurrentIndex(0);
    //frm_BookInfo.cbBBK->addItem(QString::fromStdString(books->at(number).BBK));
    //frm_BookInfo.cbBBK->setCurrentIndex(0);
    frm_BookInfo.sbCountPages->setValue(books->at(number).pageCount);
    frm_BookInfo.sbYearOfPublihsing->setValue(QString::fromStdString(books->at(number).yearOfPublication).toInt());
    frm_BookInfo.teAboutBook->setText(QString::fromStdString(books->at(number).aboutBook));
    frm_BookInfo.leSeries->setText(QString::fromStdString(books->at(number).series));
    frm_BookInfo.leAdditionalBookName->setText(QString::fromStdString(books->at(number).additionalBookName));
    if (books->at(number).bookVollume.length() > 0)
    {
        frm_BookInfo.gbMultiVollume->setChecked(true);
        frm_BookInfo.spVollumeNumber->setValue(QString::fromStdString(books->at(number).bookVollume).toInt());
        frm_BookInfo.leVollumeName->setText(QString::fromStdString(books->at(number).vollumeBookName));
    }
    else
    {
        frm_BookInfo.gbMultiVollume->setChecked(false);
        frm_BookInfo.leVollumeName->clear();
        frm_BookInfo.spVollumeNumber->setValue(0);
    }
}

void form_bookInfo::slot_nextBook()
{
    if (frm_BookInfo.leCurNumber->text().toInt() < frm_BookInfo.leMaxNumber->text().toInt())
    {
        setBook(frm_BookInfo.leCurNumber->text().toInt() + 1);
        
    }
    
    if (frm_BookInfo.leCurNumber->text().toInt() == frm_BookInfo.leMaxNumber->text().toInt())
        frm_BookInfo.pbGoRight->setEnabled(false);
    
    frm_BookInfo.pbGoLeft->setEnabled(true);
}

void form_bookInfo::slot_prevBook()
{
    if (frm_BookInfo.leCurNumber->text().toInt() > 1)
    {
        setBook(frm_BookInfo.leCurNumber->text().toInt() -1);
    }
    
    if (frm_BookInfo.leCurNumber->text().toInt() == 1)
        frm_BookInfo.pbGoLeft->setEnabled(false);
    
    frm_BookInfo.pbGoRight->setEnabled(true);
}