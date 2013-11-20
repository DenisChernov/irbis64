/*
 * File:   mainWnd.h
 * Author: F10-kafedra
 *
 * Created on 7 Февраль 2011 г., 18:01
 */

#ifndef _SEARCHBOOK_H
#define	_SEARCHBOOK_H

#include "ui_searchBook.h"

#include <QtGui/QKeyEvent>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include <QtGui/QResizeEvent>
#include <QtCore/QRegExp>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>

#include <QtGui/QStandardItemModel>

#include <boost/thread.hpp>
#include <boost/foreach.hpp>

#include "bdOper.h"
#include "consts.h"
//#include "fb2BookInfo.h"
#include "bookParsing.h"
//#include "importBooks.h"
#include "engine.h"
#include "form_BookBaseUpdater.h"

class searchBook : public QMainWindow {
    Q_OBJECT
public:
    searchBook();
    virtual ~searchBook();
    bdOper* bd;
//    fb2BookInfo* fb2BookViewer;
//    threadFilterSelect thread;
    QTimer* timer;
    bool needResearch;
    QRegExp re;
    QString wndTitle;
    parsing pars;
    engine* irbis64;
    form_BookBaseUpdater* frmBdUpdater;

    void test();

private:
    Ui::searchBook filterForm;
    void setup();
    void setFilials();
    int setHorizCenter(int width);
    void resizeTable();
    void createContextMenu();
    QStringList getItem(unsigned int row, QModelIndexList indexes);

    void getBooks(string filter, string filial, string method);

    void checkBdBooksCountChange();
    void fillBooksCount(string bdname);

    void updateBdBooksCount();

    vector <string> bdBooksCount;
    string searchMethod;
    boost::thread threadBookSearch;
    QStandardItemModel *model;
    QStandardItem *parentItem;
    int titleColWidth;
    int autorColWidth;
    int knowledgeSectionWidth;
    int yearColWidth;
    int vollumeColWidth;
    int topicColWidth;
    int seriesColWidth;
    int tvBaseHeightIndex;
    QMenu *contextMenu;
    QAction *actBookView;
    QAction *actRequestBook;
    bool baseUpdateNeeded;
    //QAction viewBookInfo;

    //importBooks importing;
    
    /*
     *  список филиалов. имя филиала, индекс, 
     */
    map <int, string> filialsList;
    
    /*
     *  Таймер проверки статуса подключения к базе данных
     */
    QTimer* timerBDConnectionStatus;
    
    
public slots:
    void slotFilterBookName();
    void slotChangeFilterBookName(QString filter);
    void slotSetFilterOnFilial(QString fil);
    void slotChangeSearch();
    void slotTableClicked(QModelIndex);
    void slotShowFullInfo();

private slots:
    void slotShowContextMenu(const QPoint &);
    void slotViewHelpInfo();

    void slotInfoTimerTimeout();
    
    /*
     *  Слот проверки подключения к базе
     */
    void slotCheckBDConnection();

protected:
   void resizeEvent(QResizeEvent *);  // virtual
   void keyPressEvent(QKeyEvent *);  // virtual
};

#endif	/* _SEARCHBOOK_H */
