/*
 * File:   main.cpp
 * Author: f10-kafedra
 *
 * Created on 6 Сентябрь 2011 г., 10:12
 */

#if defined(_WIN32) && !defined(WIN32)
#define WIN32
#endif

//#define NO_LOCALNET

//#define DEBUG_MAIN
//#define DEBUG_REG
//#define DEBUG_INFO
//#define DEBUG_REREG
//#define DEBUG_ISBN
//#define DEBUG_DOWNLOADBOOKS
#define DEBUG_UPDATER
#define DEBUG_BOOKSEARCH
//#define DEBUG_BOOKBASEUPDATER


#define DEBUG_OUTPUT

#ifdef WIN32
    #include <QtWidgets\QApplication>
    #include <QtCore\QTextCodec>
    #include <QtWidgets\QDesktopWidget>
    #include <QtWidgets\QMessageBox>
    #include <QtCore\QRegExp>
#else
    #include <QtWidgets/QApplication>
    #include <QtCore/QTextCodec>
    #include <QtWidgets/QDesktopWidget>
    #include <QtWidgets/QMessageBox>
    #include <QtCore/QRegExp>
#endif


//#ifdef DEBUG_MAIN
//#include "mainForm.h"
//#endif
#ifdef DEBUG_REG
#include "form_UserRegistration.h"
#endif
#ifdef DEBUG_REREG
#include "form_UserReRg.h"
#endif
#ifdef DEBUG_INFO
#include "form_Information.h"
#endif
#ifdef DEBUG_ISBN
#include "form_BookWork.h"
#endif
#ifdef DEBUG_BOOKSEARCH
#include "searchBook.h"
//#include "importBooks.h"
#endif
#ifdef DEBUG_DOWNLOADBOOKS
#include "form_DownloadBooks.h"
#endif
#ifdef DEBUG_BOOKBASEUPDATER
#include "form_BookBaseUpdater.h"
#endif
#ifdef DEBUG_UPDATER
#include "appUpdater.h"
#endif

#include "bdOper.h"
#include <string>

#define REGUSER_VER "1.0"
#define REREGUSER_VER "1.0"
#define INFO_VER "0.7"
#define DOWNLOADBOOKS_VER "0.1"
const string BOOKSEARCH_VER = "0.4.2";

std::string appPath;

#ifdef __linux
/*
 *  автоперезапуск программы
 */
void sighup_handler(int signum)
{
    int pid = fork();
    if (pid == 0)
    {
        execl(appPath.c_str(), NULL); 
    }
    else
        ::kill(getpid(), SIGTERM);
}
#endif


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    ::signal(SIGHUP, sighup_handler);
    
    QApplication app(argc, argv);
    //app.addLibraryPath(qApp->applicationDirPath() + "/plugins");
//    foreach (QString str, app.libraryPaths())
//    {
//        cout << str.toAscii().data() << endl;
//    }

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec *codecTr = QTextCodec::codecForName("Windows-1251");

    QTextCodec *codecLocale = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codecTr);
    QTextCodec *codecStr = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForCStrings(codecStr);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));

    //getMyIp();

    QDesktopWidget *d = QApplication::desktop();
    int cur_x = d->width();
    int cur_y = d->height();

#ifndef DEBUG_ISBN
//#ifndef DEBUG_REREG
//    mainForm mainDebug;
    //mainDebug.started = false;
//#endif
#endif


#ifdef DEBUG_MAIN
    //mainDebug.show();
#endif
#ifdef DEBUG_INFO
    //mainDebug.apm = APM_INFO;
    form_Information formInfo(QString("%1").arg(argv[0])/*.remove(QRegExp("(.*\\\\)"))*/);
    formInfo.setWindowTitle(formInfo.windowTitle() + " [v." + INFO_VER + "]");
    formInfo.show();
#endif
#ifdef DEBUG_REG
    //mainDebug.apm = APM_REGUSER;
    form_UserRegistration formUsrReg(bd.getFilialNames(bd.getFilialsID()), bd.myIp);
    formUsrReg.setWindowTitle(formUsrReg.windowTitle());
    formUsrReg.move(cur_x / 2 - formUsrReg.width() / 2, 140);

//    formUsrReg.client = mainDebug.client;
    formUsrReg.show();
//    form_UserReRg formReReg;
//    formReReg.show();
#endif
#ifdef DEBUG_REREG
    //mainDebug.apm = APM_REREG;
    //mainDebug.client->apm = APM_REREG;

#ifdef NO_LOCALNET
    QStringList listFilials;
    listFilials << "ф. 10";
    form_UserReRg formUsrReReg(mainDebug.client, listFilials);
    formUsrReReg.show();
#else
    form_UserReRg formUsrReReg;//(bd.getFilialNames(bd.getFilialsID()));
    formUsrReReg.show();
#endif // NO_LOCALNET
#endif // DEBUG_REREG

#ifdef DEBUG_ISBN
    form_BookWork formBookSearch;
    formBookSearch.move(cur_x / 2 - formBookSearch.width() / 2, 140);
    formBookSearch.show();

#endif

#ifdef DEBUG_DOWNLOADBOOKS
    form_DownloadBooks formDownBooks;
    formDownBooks.move(cur_x / 2 - formDownBooks.width() / 2, 140);
    formDownBooks.show();
#endif

#ifdef DEBUG_BOOKBASEUPDATER
	form_BookBaseUpdater formBookBaseUpdater;
	formBookBaseUpdater.move(cur_x / 2 - formBookBaseUpdater.width() / 2, 140);
    formBookBaseUpdater.show();
	formBookBaseUpdater.runUpdate();
#endif

#ifdef DEBUG_BOOKSEARCH

    string bdVer;
    string appVer;
    QDesktopWidget *desktop = qApp->desktop();

    searchBook* searchBookWnd = new searchBook();
    searchBookWnd->setGeometry (0, 0, 1143, 811);
    searchBookWnd->move(((desktop->width() / 2) - (searchBookWnd->width() / 2)),
                       ((desktop->height() / 2) - (searchBookWnd->height() / 2)));

    appVer = searchBookWnd->bd->lastVersionApp();
    bdVer = searchBookWnd->bd->checkLastVersionBD();

    cout << "app: " << appVer << "\nbdVer: " << bdVer << endl;
    
        if (appVer.compare(BOOKSEARCH_VER) != 0)
        {
            string infoMsg = "Ваша версия " + BOOKSEARCH_VER + " приложения устарела\nНеобходимо обновить до " + appVer;
            if (!QMessageBox::information(searchBookWnd, "Новая версия", QString::fromStdString(infoMsg), "&Обновить", "О&тмена", QString::null))
            {
            
#ifdef DEBUG_UPDATER
                appPath = argv[0];
                appUpdater* update = new appUpdater(argv[0]);
                QDesktopWidget *desktop = qApp->desktop();
        
                update->move(((desktop->width() / 2) - (update->width() / 2)),
                               ((desktop->height() / 2) - (update->height() / 2)));
                
                update->show();
#endif                    
            }
        }
        else
        {
            searchBookWnd->wndTitle = "Поиск книг по базам OLDEK, RETRO. По состоянию на " + QString::fromStdString(bdVer) + ". Записей ";
            searchBookWnd->setWindowTitle(searchBookWnd->wndTitle + "(0/" + QString::number(searchBookWnd->bd->getAmountRecords("bookbase")) + ")");

            searchBookWnd->show();
        }
#endif


        
    return app.exec();
}
