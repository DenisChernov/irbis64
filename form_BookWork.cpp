/*
 * File:   form_BookWork.cpp
 * Author: f10-kafedra
 *
 * Created on 16 Ноябрь 2011 г., 15:33
 */

//#include <QtWebKit/qwebframe.h>

#include "form_BookWork.h"
//#include "threads.h"

QString patterns[] = {
                        "\"FoundTextFrag\">([0-9,-]*)<",
                        "<b>(.*)</b>.*<b>(.*)</b>.*-\\s(.*):\\s(.*),\\s(\\d{4}).*-\\s(\\d{2,4})",
                        "<b>(.*)</b>.*<b>(.*)</b>.*:\\s(.*),\\s(\\d{4}).*-\\s(\\d{2,4})",
                        "<b>(.*)</b>.*\\[(.*)\\].*-\\s(.*):\\s(.*),\\s(\\d{4}).*-\\s(\\d{2,4})"
};

QString patterns_MGOUNB[] = {
                        "<entry>&lt;Авторский\\sзнак:&gt;\\s(.*)</entry>",
                        "<entry>&lt;Основное\\sзаглавие:&gt;\\s(.*)</entry>",
                        "<entry>&lt;Дата\\0sиздания:&gt;\\s(.*)</entry>",
                        "<entry>&lt;Объем:&gt;\\s(.*)\\sс.</entry>",
                        "<entry>&lt;Наименование\\sтемы\\sкак\\sпредмет&gt;:\\s(.*)</entry>",
                        "<entry>(.*)</entry>"
};

form_BookWork::form_BookWork() {
    formBookSearch.setupUi(this);
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/isbn.png"), QSize(), QIcon::Normal, QIcon::Off);
    this->setWindowIcon(icon);

    timer = new QTimer(this);
    timer->setInterval(200);
    
    isbn = new isbnWork();
    connect(formBookSearch.pbSearchByISBN, SIGNAL(clicked()), this, SLOT(slotSearchByISBN()));
    connect(timer, SIGNAL(timeout()), this, SLOT(slotViewBooks()));
    
    
}

form_BookWork::~form_BookWork() {
    delete isbn;
}

void form_BookWork::checkSearchStage()
{
    curSearchStage stage = Stopped;
    
        while (isbn->curStage != Stopped)
        {
            switch (isbn->curStage)
            {
                case GetInitPage:
                {
//                    if (isbn->curStage != stage)
//                    {
                        formBookSearch.lblCurrentStage->setText("Получение начальной страницы");
//                        formBookSearch.pbCurrentStage->setValue(formBookSearch.pbCurrentStage->value() + 25);
//                        stage = isbn->curStage;
//                    }
                    break;
                }
                case GetManyResults:
                {
//                    if (isbn->curStage != stage)
//                    {
                        formBookSearch.lblCurrentStage->setText("Получение результатов поиска");
//                        formBookSearch.pbCurrentStage->setValue(formBookSearch.pbCurrentStage->value() + 25);
//                        stage = isbn->curStage;
//                    }
                    break;
                }
                case GetFullBookInfo:
                {
                    //int valuePlus = 50 / isbn->books.size() * 2;
                    
                    formBookSearch.lblCurrentStage->setText("Получение книги");
                    //formBookSearch.pbCurrentStage->setValue(formBookSearch.pbCurrentStage->value() + 25);
                    break;
                }
                case GetAdditionalBookInfo:
                {
                    //int valuePlus = 50 / isbn->books.size() * 2;
                    formBookSearch.lblCurrentStage->setText("Получение авторского знака");
                    //formBookSearch.pbCurrentStage->setValue(formBookSearch.pbCurrentStage->value() +25);
                    break;
                }
            }
        }
        
        formBookSearch.lblCurrentStage->setText("Поиск выполнен");
        Thread.join();
}


void form_BookWork::slotSearchByISBN()
{
    // 978-5-9518-0362-7
    
    if (formBookSearch.leISBN->text().length() > 0)
    {
        formBookSearch.pbCurrentStage->setValue(0);
        timer->start();
        isbn->isbn = formBookSearch.leISBN->text().toStdString();
        isbn->run(ISBN_SOURCE_BD_RFBookChamber);
        
        Thread = boost::thread (boost::bind(&form_BookWork::checkSearchStage, this));
        
    }
    
}

void form_BookWork::slotViewBooks()
{
    if (isbn->curStage == Stopped)
    {
        timer->stop();
        if (isbn->books.size() > 0)
            formManyBooks.loadBooks(&isbn->books);
    }
}