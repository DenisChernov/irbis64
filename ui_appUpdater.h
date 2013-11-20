/********************************************************************************
** Form generated from reading UI file 'appUpdater.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPUPDATER_H
#define UI_APPUPDATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appUpdater
{
public:
    QWidget *centralwidget;
    QGroupBox *gbStatusDownloading;
    QProgressBar *pbDownload;
    QLabel *lblCurrentFile;

    void setupUi(QMainWindow *appUpdater)
    {
        if (appUpdater->objectName().isEmpty())
            appUpdater->setObjectName(QStringLiteral("appUpdater"));
        appUpdater->resize(557, 93);
        centralwidget = new QWidget(appUpdater);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gbStatusDownloading = new QGroupBox(centralwidget);
        gbStatusDownloading->setObjectName(QStringLiteral("gbStatusDownloading"));
        gbStatusDownloading->setGeometry(QRect(10, 10, 531, 71));
        gbStatusDownloading->setAlignment(Qt::AlignCenter);
        gbStatusDownloading->setFlat(true);
        gbStatusDownloading->setCheckable(false);
        pbDownload = new QProgressBar(gbStatusDownloading);
        pbDownload->setObjectName(QStringLiteral("pbDownload"));
        pbDownload->setGeometry(QRect(20, 34, 491, 23));
        pbDownload->setValue(24);
        pbDownload->setTextVisible(false);
        lblCurrentFile = new QLabel(gbStatusDownloading);
        lblCurrentFile->setObjectName(QStringLiteral("lblCurrentFile"));
        lblCurrentFile->setGeometry(QRect(30, 34, 471, 21));
        lblCurrentFile->setAlignment(Qt::AlignCenter);
        appUpdater->setCentralWidget(centralwidget);

        retranslateUi(appUpdater);

        QMetaObject::connectSlotsByName(appUpdater);
    } // setupUi

    void retranslateUi(QMainWindow *appUpdater)
    {
        appUpdater->setWindowTitle(QApplication::translate("appUpdater", "appUpdater", 0));
        gbStatusDownloading->setTitle(QApplication::translate("appUpdater", "Status", 0));
        lblCurrentFile->setText(QApplication::translate("appUpdater", "file downloaded", 0));
    } // retranslateUi

};

namespace Ui {
    class appUpdater: public Ui_appUpdater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPUPDATER_H
