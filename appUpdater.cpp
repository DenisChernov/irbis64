/*
 * File:   appUpdater.cpp
 * Author: demiin
 *
 * Created on August 14, 2013, 10:21 AM
 */

#include "appUpdater.h"



appUpdater::appUpdater(string currentAppFile) {
    widget.setupUi(this);
    
    appPath = currentAppFile;
    
    myIP();
    
    checkFilesAndUpdate();
}

appUpdater::~appUpdater() {
}

void appUpdater::myIP()
{
    string ip;
    ACE_INET_Addr inet_addr;

#ifdef __linux
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, (char*)"eth0");

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    ioctl(s, SIOCGIFADDR, &ifr);
    ::close(s);

    struct sockaddr_in *sa = (struct sockaddr_in*)&ifr.ifr_addr;

    ip = inet_ntoa(sa->sin_addr);
    if (ip.length() > 0)
         myip = ip;
#endif

#ifdef _WIN32
    int result = inet_addr.set((unsigned short)0, inet_addr.get_host_name());
    if (result != 0)
        cout << "error setting peer_addr" << endl;
    else
    {
        ip = inet_addr.get_host_addr();
        myip = ip;
    }
#endif

}

bool appUpdater::checkFilesAndUpdate()
{
#ifdef __linux
    int result = ::system("/usr/bin/rsync -e=\"ssh -p 4828\" -z 192.168.9.250:softForIrbis/crossIrbis /tmp/crossIrbis");
#endif
    path pathToLocal(appPath);
    int flocalAppSize = file_size(pathToLocal);
    int fServerAppSize = 0;
    
    path pathToServer("/tmp/crossIrbis");
    if (exists(pathToServer))
    {
        if (is_regular_file(pathToServer))
             fServerAppSize = file_size(pathToServer);
        
        if (flocalAppSize != fServerAppSize)
            if (!QMessageBox::question(this, tr("Обновление завершено"), tr("Обновление завершено!\nНеобходимо перезапустить приложение"), tr("&Согласен"), QString::null, 0, 1 ) )
                restartApp();
    }
    
    return false;
}

void appUpdater::restartApp()
{
#ifdef __linux
    string copyCmd = "/usr/bin/rsync /tmp/crossIrbis " + appPath;
    ::system(copyCmd.c_str());
    ::system("killall -HUP crossIrbis");
#endif
}
