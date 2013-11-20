/*
 * File:   engine.cpp
 * Author: f10-kafedra
 *
 * Created on 29 Январь 2012 г., 15:24
 */

#include "engine.h"
#include "formLogin.h"
#include "form_UserReRg.h"

engine::engine(apmType apm, string login, string pass)
{
    code = 31337;

    _login = login;
    _pass = pass;
    reqCounter = 1;

    switch (apm)
    {
        case APM_REGUSER:
        {
            break;
        }

        case APM_REREG:
        {
#ifdef DEBUG_OUTPUT

#endif
            run();
            break;
        }

        case APM_INFO:
        {


            break;
        }

        default:
        {
#ifdef DEBUG_OUTPUT
            ACE_OS::printf("nothing to do\n");
#endif
            break;
        }
    }
}

engine::~engine() {
}

void engine::run()
{
//        loginToBase();
//        cout << reciveAnswer().c_str() << endl;
        //tmp = reciveAnswer();
        //cout << "len: " << srvPars.getMsgLen(tmp) << endl;
        //cout << tmp.c_str() << endl;
//        unloginFromBase();
        //disconnectFromBase();

}

bool engine::sendData(string data)
{
    //cout << data.c_str() << endl;

    if (connectToHostBase(HOST, PORT) == 0)
    {
        ssize_t lenTrans = 0;
        lenTrans = peer.send_n(data.c_str(), ACE_OS::strlen(data.c_str()), 0);
        data.clear();
        if (lenTrans > 0)
                return true;
        else
                return false;
    }

    data.clear();

    return false;
}

string engine::reciveAnswer()
{


	QMessageBox mesg;
	

    ACE_Time_Value timeout(10);
    //char buf[RECV_BUFFER_SIZE];
    char* buf = (char*)malloc(RECV_BUFFER_SIZE);
    memset(buf, 0, RECV_BUFFER_SIZE);
    ssize_t lenRecv = 0;
    ssize_t amount = 0;
    ssize_t lenMsg = 0;
    string msg;
    //cout << "msg len on create: " << msg.size() << endl;

    msg.clear();

	
    lenRecv = peer.recv(buf, RECV_BUFFER_SIZE, &timeout);
	//mesg.setText(QString::fromStdString(boost::lexical_cast<string>(lenRecv)));
	
//    amount += lenRecv;
    //buf[lenRecv] = '\0';
	
//	mesg.setText(QString::fromStdString(boost::lexical_cast<string>(strlen(buf))));
	//mesg.exec();

    msg.append(buf);

    //lenMsg = srvPars.getMsgLen(msg);

#ifndef DEBUG_OUTPUT
//    cout << "lenMsg: " << lenMsg << endl;
#endif
    //cout << "msg len before reciving data: " << msg.size() << endl;
    //string last = buf;

    while (peer.recv(buf, RECV_BUFFER_SIZE, &timeout) > 0)
    {
		//mesg.setText(QString::fromStdString(boost::lexical_cast<string>(lenRecv)));
        //if (lenRecv >= 0)
        //{
                amount += lenRecv;
                //buf[lenRecv] = '\0';
                msg.append(buf);
				//mesg.setText("i recv: " + QString::fromStdString(msg));
				//mesg.exec();


//                cout << "lenRecv: " << lenRecv << endl;
//                cout << "msg len: " << msg.size() << endl;
//                cout << "buf len: " << strlen(buf) << endl;
        //}
                    memset(buf, 0, RECV_BUFFER_SIZE);

    }
    //this->lastBuffer = QString::fromStdString(str);

    //cout << "i recv: " << amount << endl;//'\n' << msg.c_str() << endl;
	//mesg.setText("i recv: " + QString::fromStdString(boost::lexical_cast<string>(amount)));
	//mesg.exec();
    //cout << "i recv msg len: " << msg.size() << endl;
    //cout << msg << endl;
    disconnectFromBase();
    return msg;
}

void engine::loginToBase()
{

//    if (connectToHostBase(HOST, PORT) != -1)
    //reqCounter = 0;
    sendData(loginRequest("A", "C"));

    if (silentMode == true)
        reciveAnswer();

}

void engine::unloginFromBase()
{
    sendData(unLoginRequest("B", "C"));
    reciveAnswer();
//    if (silentMode == true)
//        reciveAnswer();
//    ACE_OS::printf("%s", reciveAnswer().c_str());
    disconnectFromBase();
}

string engine::loginRequest(string codeCommand, string codeAPM)
{
    //code++;

    string request = codeCommand + '\n' + codeAPM + '\n' + codeCommand + '\n'
                        + QString::number(MAGIC_USER_ID + code).toStdString() + '\n' + QString::number(reqCounter++).toStdString() + '\n'
                        + _login.c_str() + '\n' + _pass.c_str() + "\n\n\n\n"
                        + _login.c_str() + '\n' + _pass.c_str();
    request.insert(0, QString::number(request.length()).toStdString() + '\n');

    return request;
}

string engine::unLoginRequest(string codeCommand, string codeAPM)
{
    string request = codeCommand + '\n' + codeAPM + '\n' + codeCommand + '\n'
                        + QString::number(MAGIC_USER_ID + code).toStdString() + '\n' + QString::number(reqCounter++).toStdString() + '\n'
                        + _login.c_str() + '\n' + _pass.c_str() + "\n\n\n\n"
                        + _login.c_str();
    request.insert(0, QString::number(request.length()).toStdString() + '\n');

    return request;
}

int engine::connectToHostBase(const char* host, const int port)
{
    if (peer_addr.set(PORT, HOST) == -1)
    {
#ifdef DEBUG_OUTPUT
        cout << "ACE: error setting host:port" << endl;
#endif
        return -1;
    }
    else
    if (connector.connect(peer, peer_addr) == -1)
    {
#ifdef DEBUG_OUTPUT
        cout << "ACE: connect unsuccessul" << endl;
#endif
        return -1;
    }
#ifdef DEBUG_OUTPUT
    cout << "ACE: setting beginning cons complete" << endl;
#endif
    return 0;
}

void engine::disconnectFromBase()
{
    connector.complete(peer, 0, &ACE_Time_Value::zero);
    peer.close();
}

QStringList engine::getUserByID(string id, string filial, string date)
{
    sendData(generalRequestEditEnabled("K", "C", "RDR\n\"RI=" + id + "\"\n45\n1\nmpl,'&&&&&','10#',v10,'11#',v11,'12#',v12,'/','51#',v51^d,v51^c|#|,'/'v40"));

    string answerVisits = reciveAnswer();
    //cout << answerVisits.c_str() << endl;


    QStringList userData = srvPars.parseUserGettedByID(answerVisits);
    if (userData.count() > 0)
        {
            
            QStringList sendData;
            sendData.clear();

            cout << filial.length() << " : " << filial << endl;
            
            if ((filial.length() == 0) && userData.count() == 5)
            {
               sendData << userData.at(0) + ' ' + userData.at(1) + ' ' + userData.at(2) << userData.at(3);
               return sendData;
            }
            
            if ((( userData.count() == 5 && userData.at(4).contains(QRegExp("2012\\d{4}" + QString::fromStdString(filial))) && filial.compare("") != 0) || userData.count() == 5))
            {
               sendData << userData.at(0) + ' ' + userData.at(1) + ' ' + userData.at(2) << userData.at(3);
               return sendData;
            }
            
 
            return sendData;
        }

    userData.clear();
    answerVisits.clear();
    return userData;
}

QStringList engine::getUserByFIO(string fio, string filial)
{
    sendData(generalRequestEditEnabled("K", "C", "RDR\n\"RI=" + fio + "\"\n21\n1\nmpl,'&&&&&','10#',v10,'11#',v11,'12#',v12,'/',v40"));
    string answerVisits = reciveAnswer();
    //cout << answerVisits.c_str() << endl;

    QStringList userData = srvPars.parseUserGettedByID(answerVisits);
    if (userData.count() > 0)
       {
         QStringList sendData;
         sendData << userData.at(0) + ' ' + userData.at(1) + ' ' + userData.at(2) << userData.at(3);
         return sendData;
       }

    userData.clear();
    answerVisits.clear();
    return userData;
}

QStringList engine::getuserByFAM(QStringList FAM)
{
    QStringList lst;
    string requestString;

    switch (FAM.count())
    {
        case 1:
        {
            requestString = "RDR\nRI=" + FAM.at(0).toStdString() + "\n30\nv21";
            break;
        }
        case 2:
        {
            requestString = "RDR\nRI=" + FAM.at(0).toStdString() + ' ' + FAM.at(1).toStdString() + "\n15\nv21";
            break;
        }
        case 3:
        {
            requestString = "RDR\nRI=" + FAM.at(0).toStdString() + ' ' + FAM.at(1).toStdString() + ' ' + FAM.at(2).toStdString() + "\n6\nv21";
            break;
        }
    }

    //requestString = "RDR\nRI=Чернов Денис\n20\nv30";
    //sendData(generalRequestEditEnabled("K", "C", "RDR\n\n21\n1\nmpl,'&&&&&','10#',v10,'11#',v11,'12#',v12,'/',v30\n23000\n24000\n!(if V10 : 'Андрианова' then '1' else '0' fi)"));//   ,'&&&&&','10#',v10,'11#',v11,'12#',v12,'/',v"));
    sendData(generalRequestEditEnabled("H", "C", requestString));

    return srvPars.parseListFIOResult(reciveAnswer());
}

string engine::generalRequest(string codeCommand, string codeAPM, string parameters)
{
    string request = codeCommand + '\n' + codeAPM + '\n' + codeCommand + '\n'
                        + QString::number(MAGIC_USER_ID + code).toStdString() + '\n' + QString::number(reqCounter++).toStdString()
                        + '\n' + "\n\n\n\n\n" + parameters.c_str();
    request.insert(0, QString::number(request.length()).toStdString() + '\n');

    return request;
}

string engine::generalRequestEditEnabled(string codeCommand, string codeAPM, string parameters)
{
    string request = codeCommand + '\n' + codeAPM + '\n' + codeCommand + '\n'
                        + QString::number(MAGIC_USER_ID + code).toStdString() + '\n' + QString::number(reqCounter++).toStdString() + '\n'
                        + _login.c_str() + '\n' + _pass.c_str() + '\n' + "\n\n\n" + parameters.c_str();

    request.insert(0, QString::number(request.length()).toStdString() + '\n');

    return request;
}

string engine::getUserRecord(string MFN)
{
    sendData(generalRequest("C", "C", "RDR\n" + MFN + "\n0\n\n"));
    silentMode = false;
    return reciveAnswer();
}

void engine::updateRecord(string record, string visit)
{
    QString element = QString::fromLatin1(QByteArray::fromHex("1F1E").data());
    QString NL = QString::fromLatin1(QByteArray::fromHex("0A").data());

    string request =  generalRequestEditEnabled("D", "C",
                            "RDR" + NL.toStdString() + "0" + NL.toStdString() + "1" + NL.toStdString() +
                            //srvPars.parseUserRecord(QString::fromStdString(record)).toStdString() +
                            record + visit + element.toStdString());

    //cout << request.c_str() << endl;

    sendData(request);

//    sendData(generalRequest("D", "C",
//                            "RDR" + NL.toStdString() + "0" + NL.toStdString() + "1" + NL.toStdString() +
//                            srvPars.parseUserRecord(QString::fromStdString(record)).toStdString() +
//                            visit + element.toStdString()));

    if (silentMode == true)
        reciveAnswer();
    else
        cout << reciveAnswer().c_str() << endl;

    record.clear();
}

QStringList engine::checkUsersExists(string fio)
{
    QStringList listFIO = srvPars.parseFIO(fio);

    QStringList result = getuserByFAM(listFIO);

    return result;
}

string engine::getConfFile(string file)
{
    string confs;
    //silentMode = true;
    //loginToBase();
    //silentMode = false;
    sendData(generalRequest("L", "C", "10.RDR." + file));
    confs = reciveAnswer();
    //unloginFromBase();
    return confs;
}

bool engine::checkUserExist(vector <string> userData)
{
    string elm = QByteArray::fromHex("1F1E").data();

    string request;
    request = "RDR\n!if val(ref(l('!'v21,v10,v11.6,v12.6),mfn))=val(mfn) then '0' else '1' fi/,\n-2\n0#0" + elm + "0#0" + elm + "920#RDR"
                                                    + elm + "10#" + userData.at(0)
                                                    + elm + "11#" + userData.at(1)
                                                    + elm + "12#" + userData.at(2)
                                                    + elm + "21#" + userData.at(3) + elm;

    sendData(generalRequestEditEnabled("G", "C", request));
    return srvPars.ifExistUser(reciveAnswer());
}

void engine::regNewUser(string userData)
{
    silentMode = true;
    loginToBase();
    silentMode = false;

    // получаем последний ID
    sendData(generalRequestEditEnabled("0", "C", "RDR"));
    string mfn = srvPars.getLine(reciveAnswer(), 2);
    int count = 0;
    while (count <= 0)
    {
        sendData(generalRequest("C", "C", "RDR\n" + mfn + "\n0\nv30\n"));
        count = atoi(srvPars.getLine(reciveAnswer(), 1).c_str());
        if (count <= 0)
        {
            mfn = QString::number(QString::fromStdString(mfn).toInt() - 1).toStdString();
        }
        else
            break;
    }
    //cout << "sending save record" << endl;
    // сохраняем запись
    string elm = QByteArray::fromHex("1F1E").data();
    sendData(generalRequest("D", "C", userData + "30#" + QString::number(count+1).toStdString() + elm));
    reciveAnswer();
    //string send = generalRequest("D", "C", userData + "30#" + QString::number(count+1).toStdString() + elm);
    //cout << "sended" << endl;
    //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(send)).data() << endl;
    //cout << reciveAnswer().c_str() << endl;

    unloginFromBase();
}

string engine::getBooks(string base, int from, int to)
{
//    silentMode = true;
//    loginToBase();
//    silentMode = false;

    sendData(generalRequestEditEnabled("G", "C", base + "\nmpl,&UNIFOR('+0')''\n0\n" + QString::number(from).toStdString() + "\n" + QString::number(to).toStdString()));
    string answer = reciveAnswer();
#ifdef DEBUG_OUTPUT    
    cout << answer.length() << endl;
#endif
//    unloginFromBase();

    return answer;
}

string engine::getMaxMFN(string base)
{
    string MFN;
    silentMode = true;
    loginToBase();
    silentMode = false;
    sendData(generalRequestEditEnabled("O", "C", base));
    MFN = srvPars.mfn(reciveAnswer());
    unloginFromBase();
    return MFN.substr(0, MFN.length() - 1);
}

void engine::uploadBook(string bookRecord)
{
    QString e = QString::fromLatin1(QByteArray::fromHex("1F").data());
    QString element = QString::fromLatin1(QByteArray::fromHex("1E").data());
    //bookRecord = "1#01#00#9920#PAZK900#^B05102#RU101#rus919#^Arus^N02^KPSBO700#^AASD^BL.D.^91";
    bookRecord[bookRecord.length() - 1] = '\x1E';
//    silentMode = true;
//    loginToBase();
//    silentMode = false;
    //cout << generalRequestEditEnabled("D", "C", "TEST\n0\n1\n" + bookRecord).c_str() << endl;

    sendData(generalRequestEditEnabled("D", "C", "TEST\n0\n1\n" + bookRecord));
    reciveAnswer();
    //cout << QTextCodec::codecForName("Windows-1251")->fromUnicode(QString::fromStdString(reciveAnswer())).data() << endl;
//    unloginFromBase();
}

string engine::getInfos(int from, int to)
{
     sendData(generalRequestEditEnabled("G", "C",
                               "UCHETSPR\nmpl,&UNIFOR('+0')'&&&&&','target:'v4,'$','topic:',v5,'$','type:',v6,'$','source:',v7,'$','knowledge:',v11\n0\n"
                               + QString::number(from).toStdString() + "\n" + QString::number(to).toStdString()));
     return reciveAnswer();
}

void engine::sendInfos(QStringList info)
{

    QString element = QString::fromLatin1(QByteArray::fromHex("1F1E").data());
    QString reqs;

    reqs = "UCHETSPR\n0\n1\n0#0" + element + "0#0" + element + "920#UCHETSPR" + element +
            "2#" + info.at(0) + element +
            "3#" + info.at(1) + element +
            "4#" + info.at(2) + element +
            "5#" + info.at(3) + element +
            "6#" + info.at(4) + element;

    for (int i = 6; i < info.at(5).toInt() + 6; i++)
    {
        reqs.append("7#" + info.at(i) + element);
    }

    reqs.append("8#" + info.at(info.at(5).toInt() + 6) + element);

//    if (info.count() == info.at(5).toInt() + 8)
//    {
//        reqs.append("9#" + info.at(info.at(5).toInt() + 7) + element);
//    }

    reqs.append("11#" + info.at(info.at(5).toInt() + 7) + element);

    if (info.size() == info.at(5).toInt() + 9)
        reqs.append("9#" + info.at(info.at(5).toInt() + 8) + element);


    //cout << QTextCodec::codecForName("CP-1251")->fromUnicode(reqs).data() << endl;

    silentMode = true;
    loginToBase();


    sendData(generalRequestEditEnabled("D", "C", reqs.toStdString()));
    reciveAnswer();

    unloginFromBase();
    //request.req = generalRequestEditEnabled("D", "C", reqs);

    //                                          "11#" + info.at(info.at(5).toInt() + 8) + element);

    //cout << reqs.toLatin1().data() << endl;

//    cout << "*****" << endl;
//    query.push_back(request);
}