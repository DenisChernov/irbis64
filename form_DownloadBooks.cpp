/*
 * File:   form_DownloadBooks.cpp
 * Author: f10-kafedra
 *
 * Created on 8 Апрель 2012 г., 11:48
 */

#include "form_DownloadBooks.h"

form_DownloadBooks::form_DownloadBooks() {
    frmDownloadBooks.setupUi(this);

    connect(frmDownloadBooks.pbGetBooks, SIGNAL(clicked()), this, SLOT(slotGetBooks()));
    connect(frmDownloadBooks.pbFillBooks, SIGNAL(clicked()), this, SLOT(slotUploadBooks()));
    connect(frmDownloadBooks.pbPrepareBooks, SIGNAL(clicked()), this, SLOT(slotPrepareFiles()));

    connect(frmDownloadBooks.pbLogin, SIGNAL(clicked()), this, SLOT(slotlogin()));
    connect(frmDownloadBooks.cbBase, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeBD(QString)));

    //emit slotChangeBD(frmDownloadBooks.cbBase->currentText());

    irbis64 = new engine(APM_REREG, "f10", "f10");
    irbis64->silentMode = true;


}

form_DownloadBooks::~form_DownloadBooks() {
}

void form_DownloadBooks::downloadBooks()
{
    string base = frmDownloadBooks.cbBase->currentText().toStdString();

    filework f("bases\\" + base + ".txt", fWrite);
    int maxMFN = frmDownloadBooks.leAmountRecordInBase->text().toInt();
    int to = 0;
    for (int i = 1; i < maxMFN; i += 1000)
    {
        if ((to + 1000) > maxMFN)
            to = maxMFN;
        else
            to += 1000;

        f.write(irbis64->getBooks(base, i , to));

        frmDownloadBooks.leGetCount->setText(QString::number(to));
    }
    f.close();
    //Thread.join();
}

void form_DownloadBooks::slotGetBooks()
{
    Thread = boost::thread (boost::bind(&form_DownloadBooks::downloadBooks, this));
}

void form_DownloadBooks::slotChangeBD(QString bd)
{
    string mfn = irbis64->getMaxMFN(bd.toStdString());
    frmDownloadBooks.leAmountRecordInBase->setText(QString::number(QString::fromStdString(mfn).toInt() - 1));
}

void form_DownloadBooks::slotUploadBooks()
{
    Thread = boost::thread (boost::bind(&form_DownloadBooks::uploadBooks, this));
}

void form_DownloadBooks::uploadBooks()
{
    irbis64->silentMode = true;
    irbis64->loginToBase();
    irbis64->silentMode = false;

    int amount = 0;
    filework f("bases\\" + frmDownloadBooks.cbPreparedFile->currentText().toStdString() + ".txt", fOpen);
    while (!f.eof())
    {
        irbis64->uploadBook(f.readline());
        frmDownloadBooks.leAmountRecordInBase->setText(QString::number(++amount));
    }

    f.close();

    irbis64->unloginFromBase();
    Thread.join();
}

void form_DownloadBooks::slotPrepareFiles()
{
    Thread = boost::thread (boost::bind(&form_DownloadBooks::prepareBooks, this));
}

void form_DownloadBooks::prepareBooks()
{

    filework fRead("bases\\" + frmDownloadBooks.cbBase->currentText().toStdString() + ".txt", fOpen);
    filework fWrit("bases\\" + frmDownloadBooks.cbBase->currentText().toStdString() + "_prepared.txt", fWrite);
    while (!fRead.eof())
    {
        string line = fRead.readline();
        if (line.length() > 6)
        {
            //cout << line.c_str() << endl;
            string tmpLine = irbis64->srvPars.replaceMFN(line);
            if (tmpLine != "#")
            {

                tmpLine[tmpLine.length() - 1] = '\n';
                fWrit.write(tmpLine);
            }
            //break;
        }
    }

    fRead.close();
    fWrit.close();

 //   Thread.join();
}

void form_DownloadBooks::slotlogin()
{
    for (int i = 1; i <= 150; i++)
        irbis64->loginToBase();
}