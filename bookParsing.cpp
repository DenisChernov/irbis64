/*
 * File:   parsing.cpp
 * Author: demiin
 *
 * Created on 5 Февраль 2011 г., 19:37
 */

#include <QtCore/qtextcodec.h>
#include <QtCore/qregexp.h>

#include <boost/math/special_functions/round.hpp>

#include "bookParsing.h"
#include "bdOper.h"

parsing::parsing() {
    QDir dir("bases/");
    QStringList tmp;
    if (dir.exists())
    {
        tmp = dir.entryList();
        foreach(QString filename, tmp)
        {
            if (!filename.contains("_prepared"))
            {
                filesListBases.append(filename);
                filesListPrepared << /*"bases/" + */filename.remove(".txt") + "_prepared.txt";
            }
        }
    }
}

parsing::~parsing() {
}

QString parsing::openFile(QString filename, char openMode)
{
    switch (openMode)
    {
        case 'r':
        {
            fileID_read.setFileName(filename);
            if (fileID_read.open(QIODevice::ReadOnly | QIODevice::Text))
            {

                return "File " + filename + " Found. Opening successful!\n";
            }
            else
            {
                return "Error while opening file...\n";
            }
            break;
        }
        case 'w':
        {
            fileID_write.setFileName(filename);

            if (fileID_write.open(QIODevice::WriteOnly | QIODevice::Text))
            {

                return "File " + filename + " Found. Preparing for write successful!\n";
            }
            else
            {
                return "Error while preparing file for writing...\n";
            }
            break;
        }
    }
    return "";
}

int parsing::amount(QString what)
{
    QString line;
    int counter = 0;

    QTextStream readFile (&fileID_read);
    // пока не конец файла, ищем метку искомого поля и увеличиваем счетчик
    while (!readFile.atEnd())
    {
      line = readFile.readLine();
      if (line.contains(what, Qt::CaseInsensitive))
         counter++;
    }
    return counter;
}

unsigned int parsing::amountBooks()
{
    unsigned int amountBook = 0;
//    int amountBases = sizeof(bases) / sizeof(*bases);
    // подсчитываем количество книг
    for (int i = 2; i < filesListPrepared.count(); i++)
    {
        this->openFile(filesListPrepared.at(i), 'r');
        amountBook += this->amount(fields[0]);
    }
    fileID_read.close();
    return amountBook;
}

void parsing::getBookName()
{
    //int amountBases = sizeof(bases) / sizeof(*bases);
    QString line;
    QString strName;
    QString strAutor;
    QString strFil;
    QString strID;
    QString strKnowledgeSection;
    QString strYear;
    QString curRec;
    double lastPercentage = 0;

    this->curRecord = 0;
    bdOper* bd = new bdOper;
//    bd->connectBD();
    bd->ClearTable("bookbase");
    bd->query.clear();
    if (isConsole)
        cout << "Процесс добавления записей в базу..." << endl;

    for (int i = 2; i < filesListPrepared.count(); i++)
    {
        this->openFile("bases/" + filesListPrepared.at(i), 'r');
        QTextStream readFile (&fileID_read);
        readFile.setCodec("UTF-8");

        while (!readFile.atEnd())
        {
            strFil.clear();
            strAutor.clear();
            strName.clear();
            strFil.clear();
            strID.clear();
            strKnowledgeSection.clear();
            strYear.clear();
            line = readFile.readLine();

            // пока не признак конца записи
            while (QString::compare("*****", line)) // начинаем выполнение пока не закончится запись
            {
                if ((line.contains(fields[8], Qt::CaseInsensitive))) // поле раздела знаний
                {
/*                    if (i == 0)
                        strKnowledgeSection = parseKS_EK(line, 8);
                    else
                    if ((i == 1) | (i == 2))
                        strKnowledgeSection = parseKS_EKNEW_RETRO(line, 8);
 */
                    strKnowledgeSection = parseFilialData(line, patterns[2]);
                    //cout << strKnowledgeSection.toLatin1().data() << endl;
                }
                else
                if ((line.contains(fields[2], Qt::CaseInsensitive))) // поле филиала
                {
//                    QString tmp = parseName(line, 4);
                    // если это не метка искомого поля
//                    if ((!tmp.contains(fields[2])) && (!strFil.contains(tmp)))
//                       strFil.append(tmp + ", ");
                    // TODO: проверить на правильность фильтра проверки вхождения филиала

                    //cout << parseFilialData(line).toLatin1().data() << endl;
                    //strID = parseFilialData(line, patterns[0]);
                    QString strIDtmp = parseFilialData(line, patterns[0]);
                    if (strIDtmp.length() == 0)
                        strIDtmp = parseFilialData(line, patterns[6]);
                    if (!strID.contains(strIDtmp))
                    {
                        strID.append(strIDtmp + ", ");
                    }

//                    cout << strID.toLatin1().data() << endl;
//                    re.setPattern("(\\s.*)");

                    //strID.remove(re);
//                    cout << "до ремува: " << strID.toLatin1().data() << "\nосле: " << strID.remove(re).toLatin1().data() << endl;

                    QString strFilTmp = parseFilialData(line, patterns[1]);
                    if (!strFil.contains(strFilTmp))
                    {
                       strFil.append(strFilTmp + ", ");
                    }

                    //cout << strID.toLatin1().data() << endl;
                    //cout << strFil.toLatin1().data() << endl;
                }
                else
                if ((line.contains(fields[5], Qt::CaseInsensitive))) // поле автора
                {
                    strAutor = parseName(line, 6) + " " + parseName(line, 7); // аккумулируем ФИО автора

                 //   cout << parseFilialData(line, patterns[3]).toLatin1().data() << " " << parseFilialData(line, patterns[4]).toLatin1().data() << endl;
                 //   cout << strAutor.toLatin1().data() << endl;
                }
                else
                if ((line.contains(fields[13], Qt::CaseInsensitive))) // поле автора
                {
//                    if (strAutor.length() == 0)
                      strAutor = parseName(line, 6) + " " + parseName(line, 7);
                 //   cout << parseFilialData(line, patterns[3]).toLatin1().data() << " " << parseFilialData(line, patterns[4]).toLatin1().data() << endl;
                 //   cout << strAutor.toLatin1().data() << endl;
                }
                else
                if ((line.contains(fields[0], Qt::CaseInsensitive))) // поле заглавия
                {
                    strName = parseName(line, 1);
                    if (strName.contains("200:"))
                        strName = parseName(line, 12);
//                    strName = parseFilialData(line, patterns[])
//                    cout << strName.toLatin1().data() << endl;
                }
                else
                if ((line.contains(fields[9], Qt::CaseInsensitive))) // поле заглавия многотомника
                {
//                    strName = parseName(line, 10)
//                    strName.append('(' + parseName(line, 11) + ')');
                     strName.prepend(parseName(line, 10) + " (" + parseName(line, 11) + ") - ");
//                    strName = parseFilialData(line, patterns[])
//                    cout << strName.toLatin1().data() << endl;
                }
                else
                if ((line.contains(fields[14], Qt::CaseInsensitive)))
                {
                    re.setPattern(patterns[7]) ;
                    re.indexIn(line);
                    if (re.cap(1).length() == 4)
                        strYear = re.cap(1);
                }
//                cout << line.toLatin1().data() << endl;
                line = readFile.readLine();
            }

            strFil.remove(strFil.length() - 2, 2);
            strID.remove(strID.length() - 2, 2);

/*            if (strName.contains("Налоги и налогообложение"))

            cout << "****** общий результат:\n"
                    << strName.toLatin1().data() << "\n"
                    << strFil.toLatin1().data() << "\n"
                    << strAutor.toLatin1().data() << "\n"
                    << strKnowledgeSection.toLatin1().data() << "\n"
                    << strID.toLatin1().data() << "\n"
                    << "длина записи: " << strID.length()
                    << "******"
                    << endl;
*/
            bd->insertToBase(this->curRecord++, strName, strFil, strAutor, strKnowledgeSection, strID, strYear);
//            bd->insertToBaseQuery(this->curRecord++, strName, strFil, strAutor, strKnowledgeSection);
            if (isConsole)
            {
                curRec.clear();
				lastPercentage = boost::math::round((double)curRecord/amountRecord * 100);
                if (lastPercentage < boost::math::round((double)curRecord/amountRecord * 100))
                {
                    curRec.append("Обработано %f%").arg(boost::math::round((double)curRecord/amountRecord * 100));
                    cout << curRec.toLatin1().data() << endl;
                }
            }
//            cout << "Добавлена запись №" << this->curRecord << endl;

//            cout << bd->query.length()toLatin1().data() << endl;
//            cout << strName.toLatin1().data() << endl;
//            cout << strAutor.toLatin1().data() << endl;
//            cout << strFil.toLatin1().data() << endl;
//            cout << strKnowledgeSection.toLatin1().data() << endl;
//            cout << "***************" << endl;


        }
        cout << filesListPrepared.at(i).toLatin1().data() << ": success" << endl;
    }
    bd->updateLastVersionBD();

//    bd->db.close();
    fileID_read.close();
}

QString parsing::parseName(QString str, int field)
{
    // первая позиция искомого поля
    int beginPosName;
    int endPosName;

    beginPosName = str.indexOf(fields[field], fields[field-1].length(), Qt::CaseInsensitive);
    // последняя позиция искомого поля
    if (field == 12)
        endPosName = str.length();
    else
        endPosName = str.indexOf("^", beginPosName + 1, Qt::CaseInsensitive) - beginPosName - 2;
    return str.mid(beginPosName+2, endPosName);
}

QString parsing::parseKS_EK(QString str, int field)
{
    int beginPosNameField = str.indexOf(fields[field], 0, Qt::CaseInsensitive);
    int beginPosName = str.indexOf("^", beginPosNameField, Qt::CaseInsensitive);
    int endPosName = str.indexOf("^", beginPosName+1, Qt::CaseInsensitive);
    return str.mid(beginPosName+2, endPosName-beginPosName-2);
}

QString parsing::parseKS_EKNEW_RETRO(QString str, int field)
{
    int beginPosName = str.indexOf(" ", fields[field].length(), Qt::CaseInsensitive);
    int endPosName = str.indexOf("\n", beginPosName+1, Qt::CaseInsensitive);
    return str.mid(beginPosName+1, endPosName-beginPosName-2);
}

void parsing::prepareFileBooks()
{
    cout << "Присутствуют базы" << endl;
    for (int i = 2; i < filesListBases.count(); i++)
        cout << filesListBases.at(i).toLatin1().data() << endl;

    QString line;
    this->curRecord = 0;

//    for (int i = 0; i < amountBases; i++)
    for (int i = 2; i < filesListBases.count(); i++)
    {
      cout << this->openFile("bases/" + filesListBases.at(i), 'r').toLatin1().data();
      cout << this->openFile("bases/" + filesListPrepared.at(i), 'w').toLatin1().data();
      QTextStream readFile (&fileID_read);
      QTextStream writeFile (&fileID_write);
      readFile.setCodec("UTF-8");
      writeFile.setCodec("UTF-8");
      while (!readFile.atEnd())
      {
        line = readFile.readLine(); // читаем очередную строку
        while (QString::compare("*****", line))
        {
            if (line.contains(fields[2]))
            {
                //cout << prepareFilialName(line).toLatin1().data() << endl;
                writeFile << prepareFilialName(line) << endl;
            }
            else
            if ((line.contains(fields[0])) || (line.contains(fields[5]))
                 || (line.contains(fields[8])) || (line.contains(fields[9]))
                 || (line.contains(fields[13])) || (line.contains(fields[14])))
            {
                writeFile << line << endl;
            }
            line = readFile.readLine(); // читаем очередную строку
        }
        writeFile << "*****" << endl;
        curRecord++;
//        cout << "Запись №" << this->curRecord++ << endl;
      }
      cout << "\n------- " << filesListBases.at(i).toLatin1().data() << " finished! Next! -------" << endl;
      fileID_read.close();
      fileID_write.close();
    }
    this->amountRecord = this->curRecord;
}

void parsing::test()
{

}

QString parsing::prepareFilialName(QString line)
{
    /*
     Говно решение, но пока выход в падлу искать
     */
    filials fils;
//    cout << "на входе: " << line.toLatin1().data() << endl;
    const char* filialName[] = {"ф 1", "ф1", "ф.1",
                                "ф 2", "ф2", "ф.2",
                                "ф 3", "ф3", "ф.3",
                                "ф 4", "ф4", "ф.4",
                                "ф 5", "ф5", "ф.5",
                                "ф 6", "ф6", "ф.6",
                                "ф 7", "ф7", "ф.7",
                                "ф 8", "ф8", "ф.8",
                                "ф 9", "ф9", "ф.9",
                                "ф 10", "ф10", "ф.10",
                                "ф 11", "ф11", "ф.11",
                                "ф 14", "ф14", "ф.14",
                                "ф 15", "ф15", "ф.15",
                                "ф 22", "ф22", "ф.22",
                                "ф 23", "ф23", "ф.23",
                                "ф 24", "ф24", "ф.24",
                                "ф 25", "ф25", "ф.25",
                                "ф 26", "ф26", "ф.26",
                               };

    int amountFilials = sizeof(filialName) / sizeof(*filialName);
    fils.name = parseFilialData(line, patterns[1]);//parseName(line, 3);
//    cout << "имя филиала: " << parseFilialData(line, patterns[1]).toLatin1().data() << endl;
//    cout << fils.name.toLatin1().data() << endl;
    for (int cell = 0; cell < amountFilials; cell++)
    {
        if (!QString::compare(fils.name, filialName[cell], Qt::CaseSensitive))
        {
//            cout << "filial = " << filialName[cell] << endl;
//            cout << "исходная строка: " << line.toLatin1().data() << endl;
//            cout << "есть вхождение!!" << endl;
            fils.pos = line.indexOf(fils.name, fields[2].length(), Qt::CaseInsensitive);
//            cout << "name = " << fils.name.toLatin1().data() << "\npos = " << fils.pos << endl;
            line.remove(fils.pos, strlen(filialName[cell]) - 1);
//            cout << "уданенный филиал: " << line.toLatin1().data() << endl;
            if (cell < 27)
            {
                    fils.name = "Ф.0" + QString::number(cell/3 + 1);
            }
            else
            if ((cell >= 27) & (cell < 33))
            {
                    fils.name = "Ф." + QString::number(cell/3 + 1);
            }
            else
            if ((cell >= 33) & (cell < 39))
            {
                switch (cell)
                {
                    case 33:
                    case 34:
                    case 35:
                    {
                        fils.name = "Ф.14";
                        break;
                    }
                    case 36:
                    case 37:
                    case 38:
                    {
                        fils.name = "Ф.15";
                        break;
                    }
                }
            }
            else
            if (cell >=39)
            {
                    fils.name = "Ф." + QString::number(cell/3 + 9);
            }

            line.insert(fils.pos, fils.name);
//            cout << "cell = " << cell << endl;
//            cout << "новая строка = " << line.toLatin1().data() << endl;

            break;
        }
    }

//    cout << "на выходе: " << line.toLatin1().data() << endl;
    return line;
}

QString parsing::parseFilialData(QString line, QString pattern)
{
    re.setPattern(pattern);
    re.indexIn(line);
//    cout << re.cap(1).toLatin1().data() << endl;
    if (re.cap(1).contains("^"))
    {
        re.setPattern(patterns[5]);
        return re.cap(1).remove(re);
    }
    else
    if (re.cap(1).contains(" ") && !re.cap(1).contains("ф"))
        {
            re.setPattern(patterns[4]);
            return re.cap(1).remove(re);
        }
    else
    if (re.cap(1).contains(" ") && re.cap(1).contains("ф "))
        {
            re.setPattern(patterns[1]);
            return re.cap(1).remove(re);
        }
    if (re.cap(1).contains(" ") && re.cap(1).contains("ф."))
        {
            re.setPattern(patterns[4]);
            return re.cap(1).remove(re);
        }
    else
    {
        return re.cap(1);
    }
}

vector <string> parsing::getAutorAndName(string filter)
{
    vector <string> autor_name;

    boost::regex re("(.*[^\\s])\\s{0,}\\%\\s{0,}(.*[^\\s])");
    boost::smatch result;
    boost::regex_match(filter, result, re);

    autor_name.push_back(result[1]);
//    cout << "strlen: " << autor_name.at(0).length() << endl;
    autor_name.push_back(result[2]);
//    cout << "strlen: " << autor_name.at(1).length() << endl;

    return autor_name;
}