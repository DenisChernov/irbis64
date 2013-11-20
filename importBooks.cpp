/*
 * File:   importBooks.cpp
 * Author: F10-kafedra
 *
 * Created on 13 Февраль 2011 г., 15:47
 */

#include "importBooks.h"

importBooks::importBooks() {
    imports.setupUi(this);
//    imports.pbProgress->setValue(0);
//    timer = new QTimer(this);
//    timer->setInterval(10);
//    timer->connect(timer, SIGNAL(timeout()), this, SLOT(slotReadCurBook()));
    this->setModal(true);
    irbis64 = new engine(APM_REREG, "f10", "f10");
    irbis64->silentMode = true;

}

importBooks::~importBooks() {
}

void importBooks::run()
{
    Thread = boost::thread (boost::bind(&importBooks::startDownload, this));

}

void importBooks::startDownload()
{
    cout << "MFN: " << irbis64->getMaxMFN("RDR") << endl;

/*    thread.pass = 0;
    if (isConsole)
        thread.isConsole = true;
    else
        thread.isConsole = false;
    timer->start();
    thread.start();
 */
    /*
    cout << "size: " << sizeof(bases) / sizeof(*bases) << endl;
    for (int curbase = 0; curbase < sizeof(bases) / sizeof(*bases); curbase++)
    {
        imports.lblPassDescription->setText("Получение списка книг из " + QString::fromStdString(bases[curbase]));
        string mfn = irbis64->getMaxMFN(bases[curbase]);
        imports.lcdAmountNumber->display(QString::fromStdString(mfn).toInt());
        filework f(bases[curbase] + ".txt", fWrite);
        int maxMFN = QString::fromStdString(mfn).toInt();
        int to = 0;
        for (int i = 1; i < maxMFN; i += 1000)
        {
            if ((to + 1000) > maxMFN)
                to = maxMFN;
            else
                to += 1000;

            f.write(irbis64->getBooks(bases[curbase], i , to));

            imports.lcdCurNumber->display(to);
        }
        f.close();
    }
     */
    //Thread.join();
}

void importBooks::slotReadCurBook()
{
/*    imports.lcdCurNumber->display(thread.parsingBooks.curRecord);
    switch (thread.pass)
    {
        case 1:
        {
            imports.lblPassDescription->setText("Сбор описания книг");
            break;
        }
        default:
        {
            imports.pbProgress->setValue(round((double)thread.parsingBooks.curRecord/thread.parsingBooks.amountRecord * 100));
            break;
        }
    }
    if ((thread.isFinished()) && (thread.pass < 2))
    {
        thread.pass++;
        imports.lcdAmountNumber->display(thread.parsingBooks.amountRecord);
        imports.lblPassDescription->setText("Добавление в базу");
        thread.start();
    }*/
}