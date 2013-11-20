/*
 * File:   mainWnd.cpp
 * Author: F10-kafedra
 *
 * Created on 7 Февраль 2011 г., 18:01
 *
 * TODO:
 * 1. при выделении строки - авторасширять поле места хранения
 *
 */


#include "searchBook.h"
#include "filework.h"

#include "boost/thread/thread.hpp"
#include "boost/thread/xtime.hpp"

searchBook::searchBook() {
   this->setup();

}

searchBook::~searchBook() {
}

void searchBook::setup()
{
    filterForm.setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    bd = new bdOper();
#ifdef DEBUG_OUTPUT
    try
    {
        throw 1;
    }
    catch (...)
    {
        cout << "i: " << endl;
    }
#endif    
            
    searchMethod = "title";
    needResearch = false;
    titleColWidth = 390;
    autorColWidth = 150;
    vollumeColWidth = 60;
    yearColWidth = 42;
    topicColWidth = 220;
    seriesColWidth = 220;
    tvBaseHeightIndex = 174;
    filterForm.gbFullInfo->hide();

    connect(filterForm.tvBase, SIGNAL(clicked(QModelIndex)), this, SLOT(slotTableClicked(QModelIndex)));
    connect(filterForm.cbFullInfo, SIGNAL(clicked()), this, SLOT(slotShowFullInfo()));
    connect(filterForm.cbHelpNeed, SIGNAL(clicked()), this, SLOT(slotViewHelpInfo()));
//    connect(filterForm.cbFilial, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotSetFilterOnFilial(QString)));
    connect(filterForm.leFilter, SIGNAL(textChanged(QString)), this, SLOT(slotChangeFilterBookName(QString)));
    connect(filterForm.cbFilial, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChangeFilterBookName(QString)));
    connect(filterForm.rbAutor, SIGNAL(clicked()), this, SLOT(slotChangeSearch()));
    connect(filterForm.rbName, SIGNAL(clicked()), this, SLOT(slotChangeSearch()));
    connect(filterForm.rbID, SIGNAL(clicked()), this, SLOT(slotChangeSearch()));
    connect(filterForm.pbDoubleSearch, SIGNAL(clicked()), this, SLOT(slotChangeSearch()));
    connect(filterForm.tvBase, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slotShowContextMenu(const QPoint &)));

    filterForm.tvBase->setContextMenuPolicy(Qt::CustomContextMenu);
    filterForm.rbName->setChecked(true);
    
     

    
    createContextMenu();
    try
    {
//        cout << "получаю список филиалов" << endl;
        boost::thread thrSetFilials = boost::thread(boost::bind(&searchBook::setFilials, this));
    }
    catch (...)
    {
        cout << "ошибка получения списка филиалов" << endl;
    }
//    cout << "список филиалов получен" << endl;

//    thrSetFilials.timed_join(boost::get_system_time() + boost::posix_time::milliseconds(4000));
    
    filterForm.cbFilial->setCurrentIndex(filterForm.cbFilial->count());

    filterForm.pbProgress->setVisible(false);
    filterForm.lblProgress->setVisible(false);

    model = new QStandardItemModel(filterForm.tvBase);
    model->setColumnCount(14);
    //parentItem = model->invisibleRootItem();
    filterForm.tvBase->setModel(model);
//    thread.tv = &filterForm.tvBase;
    //model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Заголовок");
    model->setHeaderData(2, Qt::Horizontal, "Автор");
    //model->setHeaderData(3, Qt::Horizontal, "Доп. название");
    model->setHeaderData(5, Qt::Horizontal, "кн/ч");
//    model->setHeaderData(5, Qt::Horizontal, "Т./кн./ч.");
    model->setHeaderData(10, Qt::Horizontal, "Год");
	model->setHeaderData(11, Qt::Horizontal, "Тема");
	model->setHeaderData(12, Qt::Horizontal, "Серия");
    filterForm.tvBase->hideColumn(0); // isbn
    filterForm.tvBase->hideColumn(3); // доп. название
    filterForm.tvBase->hideColumn(4); // доп. заглавие
    filterForm.tvBase->hideColumn(6); // город издательства
    filterForm.tvBase->hideColumn(7); // издательство
    filterForm.tvBase->hideColumn(8); // раздел знаний
    filterForm.tvBase->hideColumn(9); // авторский знак
    filterForm.tvBase->hideColumn(13);  // ID
    filterForm.tvBase->hideColumn(14);  // ID

    if (!bd->isConnected())
         bd->connectToBD("apm", "apm", "bookbase");    
    
    boost::thread thr = boost::thread(boost::bind(&searchBook::checkBdBooksCountChange, this));
    thr.timed_join(boost::get_system_time() + boost::posix_time::milliseconds(4000));

    QTimer* timerInfo = new QTimer(this);
    timerInfo->singleShot(5000, this, SLOT(slotInfoTimerTimeout()));
    
    timerBDConnectionStatus = new QTimer(this);
    connect(timerBDConnectionStatus, SIGNAL(timeout()), this, SLOT(slotCheckBDConnection()));    
    timerBDConnectionStatus->start(200);
    
    if (baseUpdateNeeded)
        filterForm.lblInfoAboutUpdateBases->setText("<font color = \"red\">Требуется обновление базы!</font>");
    else
        filterForm.lblInfoAboutUpdateBases->setText("<font color = \"green\">Базы актуальны</font>");
    

}

void searchBook::slotCheckBDConnection()
{
    cout << "bd status: " << bd->bdConnStatus() << endl;
    //filterForm.lblInfoAboutUpdateBases->setText(QString::fromStdString("статус подключения: " + bd->bdConnStatus()));
}

void searchBook::slotFilterBookName()
{
    /*
    if (thread.isFinished())
    {
       //filterForm.tvBase->setModel(thread.model);
       //filterForm.tvBase->setModel(thread.modelAll);
       filterForm.tvBase->hideColumn(0);
       filterForm.tvBase->horizontalHeader()->resizeSection(1, nameColWidth);
       filterForm.tvBase->horizontalHeader()->resizeSection(2, autorColWidth);
       filterForm.tvBase->horizontalHeader()->resizeSection(4, knowledgeSectionWidth);
       filterForm.tvBase->hideColumn(6);

       filterForm.pbProgress->setValue(100);
       filterForm.lblProgress->setText("Запрос выполнен");

//       setWindowTitle(wndTitle + QString::number(thread.model->rowCount()) + "/" + QString::number(bd->getAmountRecords("bookbase")));

       resizeTable();
       //cout << "фильтр потока: " << thread.model->filter().toAscii().data() << endl;
       switch (thread.choseSearch)
       {
           case 0:
           case 1:
           case 2:
           {
               re.setPattern("UPPER\\(\'%(.*)%\'\\) AND");
               //re.indexIn(thread.model->filter());
               //resizeTable();
               if (QString::compare(re.cap(1), filterForm.leFilter->text()) != 0)
               {
                    emit slotChangeFilterBookName(filterForm.leFilter->text());
               }


               break;
           }
           case 3:
           {
               if (filterForm.leFilter->text().contains(" % "))
               {
               //    фильтр потока: UPPER(name) like UPPER('%тарас%') AND UPPER(autor) like UPPER('%гоголь%') AND fil like '%%'
                    re.setPattern("UPPER\\(\'%(.*)%\'\\) AND UPPER\\(autor\\) like UPPER\\(\'%(.*)%\'\\)");
//               cout << "найденно: " << re.cap(2).toAscii().data() << " & " << re.cap(1).toAscii().data() << endl;
                //    re.indexIn(thread.model->filter());
                    if (QString::compare(re.cap(2) + " % " + re.cap(1), filterForm.leFilter->text()) != 0)
                    {
                 //  resizeTable();
                        emit slotChangeFilterBookName(filterForm.leFilter->text());
                    }
               }
               break;

           }

       }
//       re.indexIn(thread.model->filter());
//       resizeTable();
//       cout << "фильтр отобранный: " << re.cap(1).toAscii().data() << endl;
//       cout << "фильтр пользователя: " << filterForm.leFilter->text().toAscii().data() << endl;
//       if (QString::compare(re.cap(1), filterForm.leFilter->text()) != 0)
//       {
//           cout << "фильтр модели: " << re.cap(1).toAscii().data() << endl;
//           cout << "потоковый фильтр: " << thread.model->filter().toAscii().data() << "\nфильтр пользователя: " << filterForm.leFilter->text().toAscii().data() << endl;
//           emit slotChangeFilterBookName(filterForm.leFilter->text());
//       }
    }
    else if (filterForm.leFilter->text().length() > 1)
    {
        if (filterForm.pbProgress->value() < 100)
            filterForm.pbProgress->setValue(filterForm.pbProgress->value() + 1);
        else
            filterForm.pbProgress->setValue(0);
    }*/
}

void searchBook::slotChangeFilterBookName(QString filter)
{
    /*
        if (filterForm.leFilter->text().length() > 1)
        {
            if (filterForm.pbDoubleSearch->isChecked())
            {
                thread.choseSearch = 3;
                thread.lastFilter = filterForm.leFilter->text();
                thread.filter = filterForm.leFilter->text();
            }
            else
            {
                thread.filter = filterForm.leFilter->text();
            }
            thread.filial = filterForm.cbFilial->currentText();
            //filterForm.lblProgress->setText(progress[1]);
            filterForm.lblProgress->setText("Обработка запроса");
            thread.start();
        }
  */

#ifdef Q_OS_WIN32
    cout << "in slot win32 % " << filter.toStdString().c_str() << endl;
#endif
#ifdef Q_OS_LINUX
    cout << "in slot linux" << endl;
#endif

    if (filterForm.leFilter->text().length() > 2)
    {
        try 
        {
            cout << "прерываю поток поиска" << endl;
            threadBookSearch.interrupt();
            threadBookSearch.join();
            cout << "запускаю новый поток поиска" << endl;
            threadBookSearch = boost::thread(&searchBook::getBooks, this, filterForm.leFilter->text().toStdString(), filterForm.cbFilial->currentText().toStdString(), searchMethod);
        }
        catch (...)
        {
            cout << "ошибка в потоке запроса книг" << endl;
        }
    }
}

void searchBook::getBooks(string filter, string filial, string whereSearch)
{

    vector <QStringList> result;
    string postfix;

    boost::this_thread::interruption_point();

    if (filial.length() > 0)
        postfix = " AND UPPER(filials.filial) LIKE UPPER('%" + filial + "%')";
    
/*    try
    {
        cout << "подключаюсь к БД, чтобы взять книги" << endl;
        bd->connectToBD("apm", "apm", "bookbase");
    }
    catch (...)
    {
        cout << "ошибка подключения" << endl;
    }
    cout << "подключился к БД" << endl;
  */  
//        boost::this_thread::sleep(boost::posix_time::milliseconds(500));
    if (whereSearch.compare("all") == 0)
    {
        vector<string> autor_name;
        boost::this_thread::interruption_point();
        cout << "парсинг @ autor_name" << endl;
        autor_name = pars.getAutorAndName(filter);
        boost::this_thread::interruption_point();
        if (autor_name.at(1).compare("") != 0)
        {
            cout << "получение книг после парсинга @ autor_name" << endl;
            if (bd->isConnected())
            {
                result = bd->getBooks("UPPER(autor) LIKE UPPER('%" + autor_name.at(0) + "%')" + "AND UPPER(title) LIKE UPPER('%" + autor_name.at(1) + "%') " + postfix);
            //cout << "UPPER(autor) LIKE UPPER('%" << autor_name.at(0) << "%')" << "AND UPPER(name) LIKE UPPER('%" << autor_name.at(1) << "%') " + postfix << endl;
            }
        }
        boost::this_thread::interruption_point();
    }
    else
    {
        //SELECT * FROM "bookbase" WHERE UPPER(name) LIKE UPPER('%дин%') AND UPPER(autor) LIKE UPPER('%ака%')
        cout << "получение книг без парсинга @ autor_name" <<endl;
        cout << "запрос: " << "UPPER(" + whereSearch + ") LIKE UPPER('%" + filter + "%')" + postfix << endl;
        if (bd->isConnected())
        {
            result = bd->getBooks("UPPER(" + whereSearch + ") LIKE UPPER('%" + filter + "%')" + postfix);
        }
    }
    boost::this_thread::interruption_point();
    cout << "запрос успешен" << endl;
    try
    {
        model->setRowCount(0);
        while (!result.empty())
        {
            boost::this_thread::interruption_point();

            QList <QStandardItem*> items;
            for (int j = 0; j < 14; j++)
            {
                items.push_back(new QStandardItem(QString::fromUtf8(result.back().at(j).toLatin1())));
            
                boost::this_thread::interruption_point();
            }
            result.pop_back();

            model->appendRow(items);
        }
    }
    catch (...)
    {
        cout << "exception" << endl;
    }
    
        
 //   bd->disconnect();
    filterForm.tvBase->horizontalHeader()->resizeSection(1, titleColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(2, autorColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(5, vollumeColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(10, yearColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(11, topicColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(12, seriesColWidth);
}

void searchBook::slotSetFilterOnFilial(QString fil)
{
    //thread.filial = fil;
}

void searchBook::setFilials()
{


    int index = 0;
    BOOST_FOREACH (string filial, bd->getFilials())
    {
        filterForm.cbFilial->addItem(QString::fromStdString(filial));
        filialsList[index++] = filial;
    }
}

void searchBook::slotChangeSearch()
{
    if (filterForm.pbDoubleSearch->isChecked())
    {
        filterForm.rbName->setEnabled(false);
        filterForm.rbAutor->setEnabled(false);
        filterForm.rbID->setEnabled(false);
        filterForm.rbName->setChecked(false);
        filterForm.rbAutor->setChecked(false);
        searchMethod = "all";
    }
    else if (!filterForm.pbDoubleSearch->isChecked())
    {
        filterForm.rbName->setEnabled(true);
        filterForm.rbAutor->setEnabled(true);
        filterForm.rbID->setEnabled(true);
        if (filterForm.rbName->isChecked())
        {
            searchMethod = "title";
        }
        else
        if (filterForm.rbAutor->isChecked())
        {
            searchMethod = "autor";
        }
        else
        if (filterForm.rbID->isChecked())
        {
            searchMethod = "\"index\"";
            filterForm.leFilter->clear();
        }
    }

    emit slotChangeFilterBookName(filterForm.leFilter->text());
}

void searchBook::resizeEvent(QResizeEvent* event)
{
    resizeTable();
}

void searchBook::resizeTable()
{
    // размер таблицы
    filterForm.tvBase->resize(this->width() - 20, this->height() - tvBaseHeightIndex);
    titleColWidth = filterForm.tvBase->width() - (filterForm.tvBase->columnWidth(2) + filterForm.tvBase->columnWidth(5) + filterForm.tvBase->columnWidth(10) + filterForm.tvBase->columnWidth(11) + filterForm.tvBase->columnWidth(12) + 28);
    // метка поля ввода запроса
    filterForm.lblFilter->move(setHorizCenter(filterForm.lblFilter->width()), filterForm.lblFilter->y());
    // модификатор вывода помощи о поиске
    filterForm.cbHelpNeed->move(filterForm.lblFilter->width() + filterForm.lblFilter->x() + 20, filterForm.cbHelpNeed->y());
    // поле фильтра
    filterForm.leFilter->move(setHorizCenter(filterForm.leFilter->width()), filterForm.leFilter->y());
    // список филиалов
    filterForm.cbFilial->move(filterForm.leFilter->width() + filterForm.leFilter->x() + 20, filterForm.cbFilial->y());
    // метка описания таблицы поиска
    filterForm.lblTableFilter->move(setHorizCenter(filterForm.lblTableFilter->width()), filterForm.lblTableFilter->y());
    // модификаторы фильтра поиска
    filterForm.rbName->move(filterForm.lblTableFilter->x() - filterForm.rbName->width() - 40, filterForm.rbName->y());
    filterForm.pbDoubleSearch->move(filterForm.rbName->x() + filterForm.rbName->width() + 6, filterForm.pbDoubleSearch->y());
    filterForm.rbID->move(filterForm.lblTableFilter->width() + filterForm.lblTableFilter->x() + 40, filterForm.rbID->y());
    filterForm.rbAutor->move(setHorizCenter(filterForm.rbAutor->width()), filterForm.rbAutor->y());
    // помошь по поиску
    filterForm.lblHelp->move(setHorizCenter(filterForm.lblHelp->width()), this->height() - 64);
    // дополнительная информация
    filterForm.cbFullInfo->move(filterForm.lblTableFilter->x() + filterForm.cbFullInfo->width() + 200, filterForm.cbFullInfo->y());
    filterForm.gbFullInfo->move(filterForm.gbFullInfo->x(), filterForm.tvBase->height() + 110);
    filterForm.gbFullInfo->resize(this->width() - 20, filterForm.gbFullInfo->height());
    filterForm.leName->resize(this->width() - 300, filterForm.leName->height());
    filterForm.leAutor->move(filterForm.leName->width() + 20, filterForm.leName->y());
    filterForm.leYear->move(filterForm.leAutor->width() + filterForm.leName->width() + 30, filterForm.leAutor->y());
    filterForm.leID->resize(filterForm.gbFullInfo->width() - filterForm.leKnowledgeSection->width() - 28, filterForm.leID->height());
    filterForm.leFil->resize(filterForm.gbFullInfo->width() - 18, filterForm.leFil->height());
    filterForm.lblAutor->move(filterForm.leAutor->x(), filterForm.lblAutor->y());
    filterForm.lblYear->move(filterForm.leYear->x(), filterForm.lblYear->y());

    filterForm.tvBase->horizontalHeader()->resizeSection(1, titleColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(2, autorColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(5, vollumeColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(10, yearColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(11, topicColWidth);
    filterForm.tvBase->horizontalHeader()->resizeSection(12, seriesColWidth);
    
}

int searchBook::setHorizCenter(int width)
{
    width = this->width() / 2 -  width / 2;
    return width;
}

void searchBook::test()
{


}

void searchBook::slotTableClicked(QModelIndex mi)
{
    QList< QLineEdit* > listLE;
    listLE = filterForm.gbFullInfo->findChildren<QLineEdit *>();
    for (int i = 0; i < listLE.size(); i++)
    {
        listLE.at(i)->clear();
    }
    
    QList< QTextEdit* > listTE;
    listTE = filterForm.gbFullInfo->findChildren<QTextEdit *>();
    for (int i = 0; i < listTE.size(); i++)
    {
        listTE.at(i)->clear();
    }
    
    filterForm.tvBase->selectRow(mi.row());
    QStringList strTmp = getItem(filterForm.tvBase->currentIndex().row(), filterForm.tvBase->selectionModel()->selection().indexes());
    filterForm.leName->setText(strTmp.at(1)); // установка заглавия
    filterForm.leAutor->setText(strTmp.at(2)); // установка Автора
    filterForm.leKnowledgeSection->setText(strTmp.at(8)); // установка раздела знаний
    filterForm.leYear->setText(strTmp.at(10)); // установка года издания
    filterForm.leBookPart->setText(strTmp.at(5)); // установка номера тома
    filterForm.leISBN->setText(strTmp.at(0)); // установка ISBN
    filterForm.leSeries->setText(strTmp.at(12)); // установка серии

    vector <bookUnit> units;
    
//    bd->connectToBD("apm", "apm", "bookbase");
    try
    {
//        cout << "получаю книги" << endl;
        units = bd->recvBookUnits(strTmp.at(13).toStdString());
//        cout << "получил книги" << endl;
    }
    catch (...)
    {
        cout << "exception" << endl;
    }
    
    
    
    if (units.size() > 0)
    {
//        cout << "заполняю список" << endl;
        string indexes;
        string filials;
        string curcolor;
///        cout << "всего: " << units.size() << endl;
        for (unsigned int i = 0; i < units.size(); i++)
        {
//            cout << "позиция: " << i << endl;
            if (i < sizeof(colors) / sizeof(*colors))
                curcolor = "<font color=\"#" + colors[i] + "\">";
            else
                curcolor = "<font color=\"#000000\">";
            indexes.append(curcolor + units.at(i).index + "</font>");
            filials.append(curcolor + filialsList[boost::lexical_cast<int>(units.at(i).filial)] + "</font>");
            if (i < units.size() - 1)
            {
                indexes.append(", ");
                filials.append(", ");
            }
        }
//        cout << "закончил заполнять список" << endl;
        filterForm.leID->setText(QString::fromStdString(indexes)); // установка инв. номера
        filterForm.leFil->setText(QString::fromStdString(filials)); // установка мест хранения
    }
//    bd->disconnect();
}

QStringList searchBook::getItem(unsigned int row, QModelIndexList indexes)
{
    QStringList strRow;
    // перебираем строку
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        for (int j = 0; j < 15; j++)
            strRow << index.sibling(row, j).data().toString();
    }
    return strRow;
}

void searchBook::slotShowFullInfo()
{
    if (filterForm.cbFullInfo->isChecked())
    {
        filterForm.gbFullInfo->show();
        if (filterForm.cbHelpNeed->isChecked())
            tvBaseHeightIndex = 340; // когда обе галки стоят
        else
            tvBaseHeightIndex = 280;
        resizeTable();
    }
    else
    {
        filterForm.gbFullInfo->hide();
        if (filterForm.cbHelpNeed->isChecked())
            tvBaseHeightIndex = 174;
        else
            tvBaseHeightIndex = 116; // когда обе галки сняты
        resizeTable();
    }
}

void searchBook::slotViewHelpInfo()
{
    if (filterForm.cbHelpNeed->isChecked())
    {
        filterForm.lblHelp->show();
        if (filterForm.cbFullInfo->isChecked())
            tvBaseHeightIndex = 340; // когда обе галки стоят
        else
            tvBaseHeightIndex = 174;
        resizeTable();
    }
    else
    {
        if (filterForm.cbFullInfo->isChecked())
            tvBaseHeightIndex = 280;
        else
            tvBaseHeightIndex = 116;
        filterForm.lblHelp->hide();
        resizeTable();
    }
}

void searchBook::slotShowContextMenu(const QPoint &point)
{
    contextMenu->exec(QCursor::pos());
}

void searchBook::createContextMenu()
{
    contextMenu = new QMenu(this);
    actBookView = new QAction(tr("Инфо о книге"), this);
    actRequestBook = new QAction(tr("Заказать книгу"), this);
    //connect(actBookView, SIGNAL(triggered()), this, SLOT(slotViewBookInfo()));
    contextMenu->addAction(actBookView);
    contextMenu->addAction(actRequestBook);
}

void searchBook::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::AltModifier && event->key() == Qt::Key_Pause)
    {
        cout << "secret combination" << endl;
        frmBdUpdater = new form_BookBaseUpdater();
        frmBdUpdater->show();
        frmBdUpdater->runUpdate();
    }
}

void searchBook::checkBdBooksCountChange()
{
    irbis64 = new engine(APM_BOOKSEARCH, "irbisoft", "9f9@7Nuq");
    boost::thread threadBooksCheck;

    for (int i = 0; i <= 1; i++)
    {
        threadBooksCheck = boost::thread(boost::bind(&searchBook::fillBooksCount, this, bases[i]));
        threadBooksCheck.timed_join(boost::get_system_time() + boost::posix_time::milliseconds(1000));
    }
/*	
    vector <string> bdBooksSize;
    bd->getBooksInBasesCount(&bdBooksSize);

    for (int i = 0; i <= 2; i++)
    {
        if (bdBooksCount.at(i).compare(bdBooksSize.at(i)) != 0)
        {
            baseUpdateNeeded = true;
            //threadBooksCheck = boost::thread(boost::bind(&searchBook::updateBdBooksCount, this));
            //threadBooksCheck.timed_join(boost::get_system_time() + boost::posix_time::milliseconds(1000));

            break;
        }
            baseUpdateNeeded = false;
    }*/
}

void searchBook::fillBooksCount(string bdname)
{
    bdBooksCount.push_back(irbis64->getMaxMFN(bdname));
}

void searchBook::updateBdBooksCount()
{
    bd->updateMaxBookInBases(bdBooksCount);
}

void searchBook::slotInfoTimerTimeout()
{
    filterForm.lblInfoAboutUpdateBases->hide();
}