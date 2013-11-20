/********************************************************************************
** Form generated from reading UI file 'searchbook.ui'
**
** Created: Sat 6. Oct 18:51:37 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBOOK_H
#define UI_SEARCHBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchBook
{
public:
    QWidget *centralwidget;
    QTableView *tvBase;
    QLineEdit *leFilter;
    QLabel *lblFilter;
    QLabel *lblTableFilter;
    QProgressBar *pbProgress;
    QLabel *lblProgress;
    QComboBox *cbFilial;
    QRadioButton *rbName;
    QRadioButton *rbAutor;
    QRadioButton *rbID;
    QCheckBox *cbHelpNeed;
    QGroupBox *gbFullInfo;
    QLineEdit *leID;
    QLabel *lblFil;
    QLineEdit *leFil;
    QLineEdit *leKnowledgeSection;
    QLabel *lblYear;
    QLineEdit *leAutor;
    QLabel *lblKnowledgeSection;
    QLabel *lblID;
    QLineEdit *leYear;
    QLabel *lblAutor;
    QLineEdit *leName;
    QLabel *lblName;
    QPushButton *pbDoubleSearch;
    QLabel *lblHelp;
    QCheckBox *cbFullInfo;
    QLabel *lblInfoAboutUpdateBases;

    void setupUi(QMainWindow *searchBook)
    {
        if (searchBook->objectName().isEmpty())
            searchBook->setObjectName(QString::fromUtf8("searchBook"));
        searchBook->resize(791, 686);
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
        searchBook->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("app.gif"), QSize(), QIcon::Normal, QIcon::Off);
        searchBook->setWindowIcon(icon);
        centralwidget = new QWidget(searchBook);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tvBase = new QTableView(centralwidget);
        tvBase->setObjectName(QString::fromUtf8("tvBase"));
        tvBase->setGeometry(QRect(10, 110, 771, 301));
        tvBase->setStyleSheet(QString::fromUtf8("QTableView {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leFilter = new QLineEdit(centralwidget);
        leFilter->setObjectName(QString::fromUtf8("leFilter"));
        leFilter->setGeometry(QRect(110, 30, 571, 20));
        QFont font;
        font.setItalic(false);
        leFilter->setFont(font);
        leFilter->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        lblFilter = new QLabel(centralwidget);
        lblFilter->setObjectName(QString::fromUtf8("lblFilter"));
        lblFilter->setGeometry(QRect(343, -6, 71, 41));
        QFont font1;
        font1.setPointSize(14);
        lblFilter->setFont(font1);
        lblTableFilter = new QLabel(centralwidget);
        lblTableFilter->setObjectName(QString::fromUtf8("lblTableFilter"));
        lblTableFilter->setGeometry(QRect(320, 80, 121, 21));
        lblTableFilter->setFont(font1);
        pbProgress = new QProgressBar(centralwidget);
        pbProgress->setObjectName(QString::fromUtf8("pbProgress"));
        pbProgress->setGeometry(QRect(17, 620, 791, 21));
        pbProgress->setAutoFillBackground(false);
        pbProgress->setValue(24);
        pbProgress->setOrientation(Qt::Horizontal);
        pbProgress->setInvertedAppearance(false);
        pbProgress->setTextDirection(QProgressBar::TopToBottom);
        lblProgress = new QLabel(centralwidget);
        lblProgress->setObjectName(QString::fromUtf8("lblProgress"));
        lblProgress->setGeometry(QRect(310, 640, 171, 31));
        lblProgress->setFont(font1);
        cbFilial = new QComboBox(centralwidget);
        cbFilial->setObjectName(QString::fromUtf8("cbFilial"));
        cbFilial->setGeometry(QRect(700, 29, 81, 22));
        rbName = new QRadioButton(centralwidget);
        rbName->setObjectName(QString::fromUtf8("rbName"));
        rbName->setGeometry(QRect(140, 56, 101, 17));
        rbAutor = new QRadioButton(centralwidget);
        rbAutor->setObjectName(QString::fromUtf8("rbAutor"));
        rbAutor->setGeometry(QRect(340, 56, 82, 17));
        rbID = new QRadioButton(centralwidget);
        rbID->setObjectName(QString::fromUtf8("rbID"));
        rbID->setGeometry(QRect(530, 56, 101, 17));
        cbHelpNeed = new QCheckBox(centralwidget);
        cbHelpNeed->setObjectName(QString::fromUtf8("cbHelpNeed"));
        cbHelpNeed->setGeometry(QRect(413, 6, 121, 20));
        cbHelpNeed->setChecked(true);
        gbFullInfo = new QGroupBox(centralwidget);
        gbFullInfo->setObjectName(QString::fromUtf8("gbFullInfo"));
        gbFullInfo->setGeometry(QRect(10, 420, 771, 121));
        leID = new QLineEdit(gbFullInfo);
        leID->setObjectName(QString::fromUtf8("leID"));
        leID->setGeometry(QRect(170, 70, 591, 16));
        leID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leID->setReadOnly(true);
        lblFil = new QLabel(gbFullInfo);
        lblFil->setObjectName(QString::fromUtf8("lblFil"));
        lblFil->setGeometry(QRect(20, 85, 121, 16));
        leFil = new QLineEdit(gbFullInfo);
        leFil->setObjectName(QString::fromUtf8("leFil"));
        leFil->setGeometry(QRect(10, 100, 751, 16));
        leFil->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leFil->setReadOnly(true);
        leKnowledgeSection = new QLineEdit(gbFullInfo);
        leKnowledgeSection->setObjectName(QString::fromUtf8("leKnowledgeSection"));
        leKnowledgeSection->setGeometry(QRect(10, 70, 151, 16));
        leKnowledgeSection->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leKnowledgeSection->setReadOnly(true);
        lblYear = new QLabel(gbFullInfo);
        lblYear->setObjectName(QString::fromUtf8("lblYear"));
        lblYear->setGeometry(QRect(690, 20, 81, 16));
        leAutor = new QLineEdit(gbFullInfo);
        leAutor->setObjectName(QString::fromUtf8("leAutor"));
        leAutor->setGeometry(QRect(510, 40, 171, 16));
        leAutor->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leAutor->setReadOnly(true);
        lblKnowledgeSection = new QLabel(gbFullInfo);
        lblKnowledgeSection->setObjectName(QString::fromUtf8("lblKnowledgeSection"));
        lblKnowledgeSection->setGeometry(QRect(20, 56, 81, 16));
        lblID = new QLabel(gbFullInfo);
        lblID->setObjectName(QString::fromUtf8("lblID"));
        lblID->setGeometry(QRect(190, 55, 121, 16));
        leYear = new QLineEdit(gbFullInfo);
        leYear->setObjectName(QString::fromUtf8("leYear"));
        leYear->setGeometry(QRect(690, 40, 71, 16));
        leYear->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leYear->setReadOnly(true);
        lblAutor = new QLabel(gbFullInfo);
        lblAutor->setObjectName(QString::fromUtf8("lblAutor"));
        lblAutor->setGeometry(QRect(510, 20, 81, 16));
        leName = new QLineEdit(gbFullInfo);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setGeometry(QRect(10, 40, 491, 16));
        leName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leName->setReadOnly(true);
        lblName = new QLabel(gbFullInfo);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(10, 20, 81, 16));
        pbDoubleSearch = new QPushButton(centralwidget);
        pbDoubleSearch->setObjectName(QString::fromUtf8("pbDoubleSearch"));
        pbDoubleSearch->setGeometry(QRect(297, 53, 31, 23));
        pbDoubleSearch->setCheckable(true);
        pbDoubleSearch->setChecked(false);
        lblHelp = new QLabel(centralwidget);
        lblHelp->setObjectName(QString::fromUtf8("lblHelp"));
        lblHelp->setGeometry(QRect(20, 544, 741, 61));
        QFont font2;
        font2.setPointSize(9);
        lblHelp->setFont(font2);
        lblHelp->setTextFormat(Qt::RichText);
        lblHelp->setWordWrap(true);
        cbFullInfo = new QCheckBox(centralwidget);
        cbFullInfo->setObjectName(QString::fromUtf8("cbFullInfo"));
        cbFullInfo->setGeometry(QRect(649, 60, 121, 20));
        lblInfoAboutUpdateBases = new QLabel(centralwidget);
        lblInfoAboutUpdateBases->setObjectName(QString::fromUtf8("lblInfoAboutUpdateBases"));
        lblInfoAboutUpdateBases->setGeometry(QRect(19, 5, 271, 21));
        searchBook->setCentralWidget(centralwidget);

        retranslateUi(searchBook);

        QMetaObject::connectSlotsByName(searchBook);
    } // setupUi

    void retranslateUi(QMainWindow *searchBook)
    {
        searchBook->setWindowTitle(QApplication::translate("searchBook", "mainWnd", 0, QApplication::UnicodeUTF8));
        leFilter->setText(QString());
        leFilter->setPlaceholderText(QApplication::translate("searchBook", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\260\320\263\320\273\320\260\320\262\320\270\320\265 \320\270\320\273\320\270 \320\260\320\262\321\202\320\276\321\200\320\260 \320\272\320\275\320\270\320\263\320\270 \320\270\320\273\320\270 \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 (\321\200\320\265\320\263\320\270\321\201\321\202\321\200 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\275\320\265 \320\270\320\274\320\265\320\265\321\202)", 0, QApplication::UnicodeUTF8));
        lblFilter->setText(QApplication::translate("searchBook", "\320\227\320\260\320\277\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        lblTableFilter->setText(QApplication::translate("searchBook", "\320\236\320\272\320\275\320\276 \320\277\320\276\320\270\321\201\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pbProgress->setFormat(QString());
        lblProgress->setText(QApplication::translate("searchBook", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", 0, QApplication::UnicodeUTF8));
        rbName->setText(QApplication::translate("searchBook", "\320\237\320\276 \320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\272\321\203", 0, QApplication::UnicodeUTF8));
        rbAutor->setText(QApplication::translate("searchBook", "\320\237\320\276 \320\220\320\262\321\202\320\276\321\200\321\203", 0, QApplication::UnicodeUTF8));
        rbID->setText(QApplication::translate("searchBook", "\320\237\320\276 \320\230\320\275\320\262. \320\275\320\276\320\274\320\265\321\200\321\203", 0, QApplication::UnicodeUTF8));
        cbHelpNeed->setText(QApplication::translate("searchBook", "\320\235\321\203\320\266\320\275\320\260 \320\277\320\276\320\274\320\276\321\211\321\214?", 0, QApplication::UnicodeUTF8));
        gbFullInfo->setTitle(QApplication::translate("searchBook", "\320\237\320\276\320\273\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        lblFil->setText(QApplication::translate("searchBook", "\320\234\320\265\321\201\321\202\320\276 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        lblYear->setText(QApplication::translate("searchBook", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        lblKnowledgeSection->setText(QApplication::translate("searchBook", "\320\240\320\260\320\267\320\264\320\265\320\273:", 0, QApplication::UnicodeUTF8));
        lblID->setText(QApplication::translate("searchBook", "\320\230\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:", 0, QApplication::UnicodeUTF8));
        lblAutor->setText(QApplication::translate("searchBook", "\320\220\320\262\321\202\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        lblName->setText(QApplication::translate("searchBook", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        pbDoubleSearch->setText(QApplication::translate("searchBook", "+", 0, QApplication::UnicodeUTF8));
        lblHelp->setText(QApplication::translate("searchBook", "<html><head/><body><p>\320\224\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \320\272\320\275\320\270\320\263 \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\320\265, \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \320\275\320\260\320\271\321\202\320\270 \320\272\320\275\320\270\320\263\321\203 (\320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272, \320\260\320\262\321\202\320\276\321\200, \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200).<br/>\320\224\320\273\321\217 \321\203\321\202\320\276\321\207\320\275\320\265\320\275\320\270\321\217 \320\267\320\260\320\277\321\200\320\276\321\201\320\260 - \320\274\320\276\320\266\320\275\320\276 \320\262\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\270\320\273\320\270\320\260\320"
                        "\273 \320\270\320\267 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260.<br/>\320\224\320\273\321\217 \320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\263\320\276 \320\277\320\276\320\270\321\201\320\272\320\260 \320\277\320\276 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\321\203 \320\270 \320\260\320\262\321\202\320\276\321\200\321\203 - \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 + (\320\277\320\273\321\216\321\201) \320\270 \320\262\320\262\320\276\320\264\320\270\321\202\320\265 \320\277\320\276\320\270\321\201\320\272 \320\262 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\274 \321\204\320\276\321\200\320\274\320\260\321\202\320\265: <span style=\" font-weight:600;\">\320\244\320\260\320\274\320\270\320\273\320\270\321\217_\320\220\320\262\321\202\320"
                        "\276\321\200\320\260 % \321\207\320\260\321\201\321\202\321\214_\320\267\320\260\320\263\320\273\320\260\320\262\320\270\321\217_\320\272\320\275\320\270\320\263\320\270</span>. \320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: <span style=\" font-weight:600;\">\320\277\321\203\321\210 % \320\265\321\201\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cbFullInfo->setText(QApplication::translate("searchBook", "\320\237\320\276\320\273\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        lblInfoAboutUpdateBases->setText(QApplication::translate("searchBook", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\260\320\272\321\202\321\203\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270 \320\261\320\260\320\267\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchBook: public Ui_searchBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBOOK_H
