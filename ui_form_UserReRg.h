/********************************************************************************
** Form generated from reading UI file 'form_UserReRg.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_USERRERG_H
#define UI_FORM_USERRERG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_form_UserReRg
{
public:
    QGroupBox *gbUserAccount;
    QGroupBox *gbSearchByID;
    QLineEdit *leID;
    QGroupBox *gbSearchByFIO;
    QLineEdit *leFIO;
    QPushButton *pbSearch;
    QGroupBox *gbUserList;
    QTableWidget *twUserList;
    QPushButton *pbUpdateRecord;
    QDateEdit *dt;
    QComboBox *cbFilials;
    QCheckBox *cbDefenceFromDuplicate;
    QCheckBox *cbSearchOnFilialOnly;
    QGroupBox *gbRecordDebug;
    QLineEdit *leMFN;
    QLineEdit *leFAM;
    QLineEdit *leNAME;
    QLineEdit *leSURNAME;
    QTextEdit *teVisits;
    QTextEdit *teOldRecord;
    QPushButton *pbBefore;
    QPushButton *pbNext;
    QPushButton *pbFront;
    QPushButton *pbBack;
    QLineEdit *leReaderSize;
    QPushButton *pbGET;
    QTextBrowser *tbMessage;

    void setupUi(QDialog *form_UserReRg)
    {
        if (form_UserReRg->objectName().isEmpty())
            form_UserReRg->setObjectName(QStringLiteral("form_UserReRg"));
        form_UserReRg->setEnabled(true);
        form_UserReRg->resize(470, 560);
        form_UserReRg->setMaximumSize(QSize(470, 560));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 253, 215, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        form_UserReRg->setPalette(palette);
        gbUserAccount = new QGroupBox(form_UserReRg);
        gbUserAccount->setObjectName(QStringLiteral("gbUserAccount"));
        gbUserAccount->setGeometry(QRect(10, 0, 451, 128));
        gbSearchByID = new QGroupBox(gbUserAccount);
        gbSearchByID->setObjectName(QStringLiteral("gbSearchByID"));
        gbSearchByID->setGeometry(QRect(10, 20, 431, 48));
        leID = new QLineEdit(gbSearchByID);
        leID->setObjectName(QStringLiteral("leID"));
        leID->setGeometry(QRect(10, 20, 411, 18));
        leID->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leID->setMaxLength(32767);
        gbSearchByFIO = new QGroupBox(gbUserAccount);
        gbSearchByFIO->setObjectName(QStringLiteral("gbSearchByFIO"));
        gbSearchByFIO->setGeometry(QRect(10, 70, 431, 48));
        leFIO = new QLineEdit(gbSearchByFIO);
        leFIO->setObjectName(QStringLiteral("leFIO"));
        leFIO->setGeometry(QRect(10, 20, 411, 18));
        leFIO->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        pbSearch = new QPushButton(gbUserAccount);
        pbSearch->setObjectName(QStringLiteral("pbSearch"));
        pbSearch->setGeometry(QRect(190, 60, 75, 23));
        gbUserList = new QGroupBox(form_UserReRg);
        gbUserList->setObjectName(QStringLiteral("gbUserList"));
        gbUserList->setGeometry(QRect(10, 140, 451, 411));
        twUserList = new QTableWidget(gbUserList);
        twUserList->setObjectName(QStringLiteral("twUserList"));
        twUserList->setGeometry(QRect(10, 20, 431, 331));
        twUserList->setStyleSheet(QLatin1String("QTableWidget\n"
"{\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pbUpdateRecord = new QPushButton(gbUserList);
        pbUpdateRecord->setObjectName(QStringLiteral("pbUpdateRecord"));
        pbUpdateRecord->setGeometry(QRect(80, 380, 151, 23));
        dt = new QDateEdit(gbUserList);
        dt->setObjectName(QStringLiteral("dt"));
        dt->setGeometry(QRect(240, 380, 91, 22));
        dt->setAlignment(Qt::AlignCenter);
        dt->setReadOnly(true);
        dt->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dt->setTime(QTime(0, 0, 0));
        dt->setCalendarPopup(true);
        cbFilials = new QComboBox(gbUserList);
        cbFilials->setObjectName(QStringLiteral("cbFilials"));
        cbFilials->setGeometry(QRect(340, 380, 91, 22));
        cbFilials->setEditable(false);
        cbDefenceFromDuplicate = new QCheckBox(gbUserList);
        cbDefenceFromDuplicate->setObjectName(QStringLiteral("cbDefenceFromDuplicate"));
        cbDefenceFromDuplicate->setGeometry(QRect(270, 354, 171, 21));
        cbDefenceFromDuplicate->setChecked(true);
        cbSearchOnFilialOnly = new QCheckBox(gbUserList);
        cbSearchOnFilialOnly->setObjectName(QStringLiteral("cbSearchOnFilialOnly"));
        cbSearchOnFilialOnly->setGeometry(QRect(30, 354, 161, 20));
        cbSearchOnFilialOnly->setChecked(true);
        gbRecordDebug = new QGroupBox(form_UserReRg);
        gbRecordDebug->setObjectName(QStringLiteral("gbRecordDebug"));
        gbRecordDebug->setGeometry(QRect(470, 0, 391, 521));
        leMFN = new QLineEdit(gbRecordDebug);
        leMFN->setObjectName(QStringLiteral("leMFN"));
        leMFN->setGeometry(QRect(10, 40, 61, 20));
        leFAM = new QLineEdit(gbRecordDebug);
        leFAM->setObjectName(QStringLiteral("leFAM"));
        leFAM->setGeometry(QRect(80, 40, 81, 20));
        leNAME = new QLineEdit(gbRecordDebug);
        leNAME->setObjectName(QStringLiteral("leNAME"));
        leNAME->setGeometry(QRect(160, 40, 71, 20));
        leSURNAME = new QLineEdit(gbRecordDebug);
        leSURNAME->setObjectName(QStringLiteral("leSURNAME"));
        leSURNAME->setGeometry(QRect(230, 40, 131, 20));
        teVisits = new QTextEdit(gbRecordDebug);
        teVisits->setObjectName(QStringLiteral("teVisits"));
        teVisits->setGeometry(QRect(10, 80, 371, 211));
        teOldRecord = new QTextEdit(gbRecordDebug);
        teOldRecord->setObjectName(QStringLiteral("teOldRecord"));
        teOldRecord->setGeometry(QRect(10, 300, 371, 211));
        pbBefore = new QPushButton(gbRecordDebug);
        pbBefore->setObjectName(QStringLiteral("pbBefore"));
        pbBefore->setGeometry(QRect(140, 10, 41, 23));
        pbNext = new QPushButton(gbRecordDebug);
        pbNext->setObjectName(QStringLiteral("pbNext"));
        pbNext->setGeometry(QRect(180, 10, 41, 23));
        pbFront = new QPushButton(gbRecordDebug);
        pbFront->setObjectName(QStringLiteral("pbFront"));
        pbFront->setGeometry(QRect(90, 10, 41, 23));
        pbBack = new QPushButton(gbRecordDebug);
        pbBack->setObjectName(QStringLiteral("pbBack"));
        pbBack->setGeometry(QRect(230, 10, 41, 23));
        leReaderSize = new QLineEdit(gbRecordDebug);
        leReaderSize->setObjectName(QStringLiteral("leReaderSize"));
        leReaderSize->setGeometry(QRect(307, 12, 71, 20));
        pbGET = new QPushButton(gbRecordDebug);
        pbGET->setObjectName(QStringLiteral("pbGET"));
        pbGET->setGeometry(QRect(170, 50, 75, 23));
        tbMessage = new QTextBrowser(form_UserReRg);
        tbMessage->setObjectName(QStringLiteral("tbMessage"));
        tbMessage->setEnabled(true);
        tbMessage->setGeometry(QRect(90, 100, 291, 91));

        retranslateUi(form_UserReRg);

        QMetaObject::connectSlotsByName(form_UserReRg);
    } // setupUi

    void retranslateUi(QDialog *form_UserReRg)
    {
        form_UserReRg->setWindowTitle(QApplication::translate("form_UserReRg", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217", 0));
        gbUserAccount->setTitle(QApplication::translate("form_UserReRg", "\320\243\321\207\320\265\321\202\320\272\320\260 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        gbSearchByID->setTitle(QApplication::translate("form_UserReRg", "\320\222\320\262\320\276\320\264 \320\277\320\276 \320\270\320\275\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200\321\203", 0));
        leID->setInputMask(QString());
        gbSearchByFIO->setTitle(QApplication::translate("form_UserReRg", "\320\222\320\262\320\276\320\264 \320\277\320\276 \321\204\320\270\320\276", 0));
        pbSearch->setText(QApplication::translate("form_UserReRg", "\320\230\321\201\320\272\320\260\321\202\321\214", 0));
        gbUserList->setTitle(QApplication::translate("form_UserReRg", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271 \320\275\320\260 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217 / \320\277\320\265\321\200\320\265\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\216", 0));
        pbUpdateRecord->setText(QApplication::translate("form_UserReRg", "\320\237\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\320\265 \320\275\320\260", 0));
        dt->setDisplayFormat(QApplication::translate("form_UserReRg", "yyyy.MM.dd", 0));
        cbDefenceFromDuplicate->setText(QApplication::translate("form_UserReRg", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\277\320\276\320\262\321\202\320\276\321\200\320\275\320\276\320\263\320\276 \320\262\320\262\320\276\320\264\320\260", 0));
        cbSearchOnFilialOnly->setText(QApplication::translate("form_UserReRg", "\320\230\321\201\320\272\320\260\321\202\321\214 \320\277\320\276 \321\204\320\270\320\273\320\270\320\260\320\273\321\203", 0));
        gbRecordDebug->setTitle(QApplication::translate("form_UserReRg", "Record Debug", 0));
        pbBefore->setText(QApplication::translate("form_UserReRg", "<", 0));
        pbNext->setText(QApplication::translate("form_UserReRg", ">", 0));
        pbFront->setText(QApplication::translate("form_UserReRg", "Front", 0));
        pbBack->setText(QApplication::translate("form_UserReRg", "Back", 0));
        pbGET->setText(QApplication::translate("form_UserReRg", "GET", 0));
        tbMessage->setHtml(QApplication::translate("form_UserReRg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:16pt; color:#ff0000;\">\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 \320\275\320\265 \320\267\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275 \320\262 \320\262\320\260\321\210\320\265\320\274 \321\204\320\270\320\273\320\270\320\260\320\273\320\265!</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class form_UserReRg: public Ui_form_UserReRg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_USERRERG_H
