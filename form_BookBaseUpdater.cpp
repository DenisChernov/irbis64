/*
 * File:   form_BookBaseUpdater.cpp
 * Author: f10-kafedra
 *
 * Created on October 6, 2012, 6:21 PM
 */

#include "form_BookBaseUpdater.h"
#include "bdOper.h"

#include <QMessageBox>
#include <boost/foreach.hpp>

form_BookBaseUpdater::form_BookBaseUpdater() {
    frmBookBaseUpdater.setupUi(this);

}

form_BookBaseUpdater::~form_BookBaseUpdater() {
}

void form_BookBaseUpdater::runUpdate()
{
    irbis64 = new engine(APM_BOOKSEARCH, "irbisoft", "9f9@7Nuq");
    bdOper* bd = new bdOper();
    if (!bd->isConnected())
        bd->connectToBD("apm", "apm", "bookbase");
    vector <string> lstFilial = bd->getFilials();
    for (unsigned int i = 1; i < lstFilial.size() - 1; i++)
        filials[lstFilial.at(i)] = i;
    
/*    threadRecv = boost::thread(boost::bind(&form_BookBaseUpdater::recvBooks, this));
    while (!threadRecv.timed_join(boost::get_system_time() + boost::posix_time::milliseconds(1000)))
    {
        
    }
   parseBooks();  
   sendBooks();
   bd->updateLastVersionBD();*/
}

void form_BookBaseUpdater::recvBooks()
{
	QMessageBox msg;

	

    frmBookBaseUpdater.leCurBaseName->setText(QString::fromStdString(bases[1]));
	frmBookBaseUpdater.leBooksCountAfterUpdate->setText(QString::fromStdString(irbis64->getMaxMFN(bases[1])));
    
    QTemporaryFile tmpFile;
	fstream out;
    
    for (unsigned int bd = 0; bd < (sizeof(bases) / sizeof(*bases)); bd++)
    {
        out.open("/tmp/" + bases[bd] + ".txt", fstream::out);
    //tmpFile.setEncodingFunction()

        tmpFile.setAutoRemove(false);
        tmpFile.setFileName(bases[bd].c_str());

    
        if (tmpFile.open())
        {
            cout << "try to recive books from " << bases[bd] << endl;
            string maxMFN = irbis64->getMaxMFN(bases[bd]);
            cout << maxMFN << endl;
        //QTextStream out(&tmpFile);
		//QTextStream out(&file);
            tmpFile.setTextModeEnabled(true);
        //out.setCodec("UTF-8");
            string sss;
            irbis64->silentMode = true;
            irbis64->loginToBase();
            irbis64->silentMode = false;
            for (int i = 0; i < boost::lexical_cast<int>(maxMFN); i++)
            {
//                cout << "i: " << i << endl;
                sss.append(irbis64->getBooks(bases[bd], i, i + 500));
                frmBookBaseUpdater.leBooksRemaining->setText(QString::number(boost::lexical_cast<int>(maxMFN) - i));

//            buffer += sss;
                out << sss << '\n';
                i += 500;
                cout << i << endl;
                sss.clear();
            }

            irbis64->unloginFromBase();
		
        }
        out.close();
        tmpFile.close();
    }
	
}

void form_BookBaseUpdater::parseBooks()
{
    fstream in;
    char* line = (char*)malloc(20480);
    
    for (unsigned int bd = 0; bd < (sizeof(bases) / sizeof(*bases)); bd++)
    {    
        int bookCount = 0;
        in.open("/tmp/" + bases[bd] + ".txt", fstream::in);
        cout << "parsing :" << bases[bd] << endl;
        if (in.is_open())
        {
            for (int i = 1; i < 12; i++)
                in.getline(line, 20480);
        //for (int i = 1; i < 100; i++)
            while (!in.eof())
            {
                memset(line, 0, 20480);
//                    cout << "\n>>>>>>>>>>>>>>>>\n" << endl;
                in.getline(line, 20480);
//                    cout << line << "\n<<<<<< " << strlen(line) << " <<<<<<<<<<\n" << endl;
                parsBook.parseBookRecord(line);
                bookCount++;
            }
        }
        cout << "parsing " << bases[bd] << " done\ntotal books: " << bookCount <<  endl;
        
        in.close();
    }
}

void form_BookBaseUpdater::sendBooks()
{
    bdOper* bd = new bdOper();
    cout << "total books to send: " << parsBook.books.size() << endl;
    truncateAllTables();
    int bookCounter = 1;
    
    if (bd->connectToBD("apm", "apm", "bookbase"))
    {    
        for (unsigned int i = 0; i < parsBook.cities.size(); i++)
            bd->insertOneFieldToTable("city", parsBook.cities[i]);
    
        for (unsigned int i = 0; i < parsBook.autorSignes.size(); i++)
            bd->insertOneFieldToTable("autorsigns", parsBook.autorSignes[i]);
    
        for (unsigned int i = 0; i < parsBook.publishes.size(); i++)
            bd->insertOneFieldToTable("publishing", parsBook.publishes[i]);

        for (unsigned int i = 0; i < parsBook.sectionKnowledge.size(); i++)
            bd->insertOneFieldToTable("knowledgesect", parsBook.sectionKnowledge[i]);
    
        for (unsigned int i = 0; i < parsBook.series.size(); i++)
            bd->insertOneFieldToTable("bookseries", parsBook.series[i]);
    
        for (unsigned int i = 0; i < parsBook.yearsOfPublish.size(); i++)
            bd->insertOneFieldToTable("yearofpublication", parsBook.yearsOfPublish[i]);

    
        BOOST_FOREACH(booksData book, parsBook.books)
        {
            
            bd->sendNewBookToBase(book.ISBN, book.bookName, book.FIO, book.vollumeBookName, book.additionalBookName, book.bookVollume, book.pageCount, book.cityOfPublishing, book.publishing, book.yearOfPublication, book.subject, 1, 1, 1, book.series);
//            cout << "экземпляров: " << book.bookHandler.size() << endl;

            BOOST_FOREACH(bookUnit bu, book.bookHandler)
            {
                
                bd->sendBookUnits(bu.index, filials[bu.filial], boost::lexical_cast<string>(bu.bookStatus), bookCounter);
            }
            bookCounter++;
        }
        bd->disconnect();
    }
    
    cout << "sending books done" << endl;
    
    exit(0);
}

void form_BookBaseUpdater::truncateAllTables()
{
    bdOper* bd = new bdOper();
    if (bd->connectToBD("apm", "apm", "bookbase"))
    {
        bd->ClearTable("bookbase");
        bd->ClearTable("city");
        bd->ClearTable("bookseries");
        bd->ClearTable("publishing");
        bd->ClearTable("yearofpublication");
        bd->ClearTable("booksunits");
        bd->ClearTable("autorsigns");
        bd->ClearTable("knowledgesect");
    
        bd->resetAllCounters();
     
        bd->disconnect();
    }
}