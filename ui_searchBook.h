/********************************************************************************
** Form generated from reading UI file 'searchBook.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBOOK_H
#define UI_SEARCHBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

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
    QLabel *lblFil;
    QLineEdit *leKnowledgeSection;
    QLabel *lblYear;
    QLineEdit *leAutor;
    QLabel *lblKnowledgeSection;
    QLabel *lblID;
    QLineEdit *leYear;
    QLabel *lblAutor;
    QLineEdit *leName;
    QLabel *lblName;
    QLabel *lblSeries;
    QLineEdit *leSeries;
    QLineEdit *leBookPart;
    QLabel *lblBookPart;
    QLineEdit *leISBN;
    QLabel *lblISBN;
    QLabel *lblSysCode;
    QLineEdit *leSysCode;
    QTextEdit *leID;
    QTextEdit *leFil;
    QPushButton *pbDoubleSearch;
    QLabel *lblHelp;
    QCheckBox *cbFullInfo;
    QLabel *lblInfoAboutUpdateBases;

    void setupUi(QMainWindow *searchBook)
    {
        if (searchBook->objectName().isEmpty())
            searchBook->setObjectName(QStringLiteral("searchBook"));
        searchBook->resize(989, 733);
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
        icon.addFile(QStringLiteral("app.gif"), QSize(), QIcon::Normal, QIcon::Off);
        searchBook->setWindowIcon(icon);
        centralwidget = new QWidget(searchBook);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tvBase = new QTableView(centralwidget);
        tvBase->setObjectName(QStringLiteral("tvBase"));
        tvBase->setEnabled(true);
        tvBase->setGeometry(QRect(10, 110, 771, 301));
        tvBase->setStyleSheet(QLatin1String("QTableView {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leFilter = new QLineEdit(centralwidget);
        leFilter->setObjectName(QStringLiteral("leFilter"));
        leFilter->setGeometry(QRect(110, 30, 571, 20));
        QFont font;
        font.setItalic(false);
        leFilter->setFont(font);
        leFilter->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        lblFilter = new QLabel(centralwidget);
        lblFilter->setObjectName(QStringLiteral("lblFilter"));
        lblFilter->setGeometry(QRect(343, -6, 71, 41));
        QFont font1;
        font1.setPointSize(14);
        lblFilter->setFont(font1);
        lblTableFilter = new QLabel(centralwidget);
        lblTableFilter->setObjectName(QStringLiteral("lblTableFilter"));
        lblTableFilter->setGeometry(QRect(320, 80, 121, 21));
        lblTableFilter->setFont(font1);
        pbProgress = new QProgressBar(centralwidget);
        pbProgress->setObjectName(QStringLiteral("pbProgress"));
        pbProgress->setGeometry(QRect(17, 660, 791, 21));
        pbProgress->setAutoFillBackground(false);
        pbProgress->setValue(24);
        pbProgress->setOrientation(Qt::Horizontal);
        pbProgress->setInvertedAppearance(false);
        pbProgress->setTextDirection(QProgressBar::TopToBottom);
        lblProgress = new QLabel(centralwidget);
        lblProgress->setObjectName(QStringLiteral("lblProgress"));
        lblProgress->setGeometry(QRect(310, 680, 171, 31));
        lblProgress->setFont(font1);
        cbFilial = new QComboBox(centralwidget);
        cbFilial->setObjectName(QStringLiteral("cbFilial"));
        cbFilial->setGeometry(QRect(700, 29, 81, 22));
        rbName = new QRadioButton(centralwidget);
        rbName->setObjectName(QStringLiteral("rbName"));
        rbName->setGeometry(QRect(140, 56, 101, 17));
        rbAutor = new QRadioButton(centralwidget);
        rbAutor->setObjectName(QStringLiteral("rbAutor"));
        rbAutor->setGeometry(QRect(340, 56, 101, 17));
        rbID = new QRadioButton(centralwidget);
        rbID->setObjectName(QStringLiteral("rbID"));
        rbID->setGeometry(QRect(500, 56, 141, 17));
        cbHelpNeed = new QCheckBox(centralwidget);
        cbHelpNeed->setObjectName(QStringLiteral("cbHelpNeed"));
        cbHelpNeed->setGeometry(QRect(413, 6, 121, 20));
        cbHelpNeed->setChecked(true);
        gbFullInfo = new QGroupBox(centralwidget);
        gbFullInfo->setObjectName(QStringLiteral("gbFullInfo"));
        gbFullInfo->setGeometry(QRect(10, 420, 771, 171));
        lblFil = new QLabel(gbFullInfo);
        lblFil->setObjectName(QStringLiteral("lblFil"));
        lblFil->setGeometry(QRect(20, 96, 121, 16));
        leKnowledgeSection = new QLineEdit(gbFullInfo);
        leKnowledgeSection->setObjectName(QStringLiteral("leKnowledgeSection"));
        leKnowledgeSection->setGeometry(QRect(10, 76, 151, 20));
        leKnowledgeSection->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leKnowledgeSection->setReadOnly(true);
        lblYear = new QLabel(gbFullInfo);
        lblYear->setObjectName(QStringLiteral("lblYear"));
        lblYear->setGeometry(QRect(690, 20, 81, 16));
        leAutor = new QLineEdit(gbFullInfo);
        leAutor->setObjectName(QStringLiteral("leAutor"));
        leAutor->setGeometry(QRect(510, 40, 171, 20));
        leAutor->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leAutor->setReadOnly(true);
        lblKnowledgeSection = new QLabel(gbFullInfo);
        lblKnowledgeSection->setObjectName(QStringLiteral("lblKnowledgeSection"));
        lblKnowledgeSection->setGeometry(QRect(20, 60, 81, 16));
        lblID = new QLabel(gbFullInfo);
        lblID->setObjectName(QStringLiteral("lblID"));
        lblID->setGeometry(QRect(190, 60, 151, 16));
        leYear = new QLineEdit(gbFullInfo);
        leYear->setObjectName(QStringLiteral("leYear"));
        leYear->setGeometry(QRect(690, 40, 71, 20));
        leYear->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leYear->setReadOnly(true);
        lblAutor = new QLabel(gbFullInfo);
        lblAutor->setObjectName(QStringLiteral("lblAutor"));
        lblAutor->setGeometry(QRect(510, 20, 81, 16));
        leName = new QLineEdit(gbFullInfo);
        leName->setObjectName(QStringLiteral("leName"));
        leName->setGeometry(QRect(10, 40, 491, 20));
        leName->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leName->setReadOnly(true);
        lblName = new QLabel(gbFullInfo);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(10, 20, 81, 16));
        lblSeries = new QLabel(gbFullInfo);
        lblSeries->setObjectName(QStringLiteral("lblSeries"));
        lblSeries->setGeometry(QRect(20, 132, 121, 16));
        leSeries = new QLineEdit(gbFullInfo);
        leSeries->setObjectName(QStringLiteral("leSeries"));
        leSeries->setGeometry(QRect(10, 148, 211, 20));
        leSeries->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leSeries->setReadOnly(true);
        leBookPart = new QLineEdit(gbFullInfo);
        leBookPart->setObjectName(QStringLiteral("leBookPart"));
        leBookPart->setGeometry(QRect(230, 148, 101, 20));
        leBookPart->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leBookPart->setReadOnly(true);
        lblBookPart = new QLabel(gbFullInfo);
        lblBookPart->setObjectName(QStringLiteral("lblBookPart"));
        lblBookPart->setGeometry(QRect(240, 132, 111, 16));
        leISBN = new QLineEdit(gbFullInfo);
        leISBN->setObjectName(QStringLiteral("leISBN"));
        leISBN->setGeometry(QRect(340, 148, 161, 20));
        leISBN->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leISBN->setReadOnly(true);
        lblISBN = new QLabel(gbFullInfo);
        lblISBN->setObjectName(QStringLiteral("lblISBN"));
        lblISBN->setGeometry(QRect(350, 132, 81, 16));
        lblSysCode = new QLabel(gbFullInfo);
        lblSysCode->setObjectName(QStringLiteral("lblSysCode"));
        lblSysCode->setGeometry(QRect(520, 132, 101, 16));
        leSysCode = new QLineEdit(gbFullInfo);
        leSysCode->setObjectName(QStringLiteral("leSysCode"));
        leSysCode->setGeometry(QRect(510, 148, 251, 20));
        leSysCode->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leSysCode->setReadOnly(true);
        leID = new QTextEdit(gbFullInfo);
        leID->setObjectName(QStringLiteral("leID"));
        leID->setGeometry(QRect(170, 76, 591, 20));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leID->sizePolicy().hasHeightForWidth());
        leID->setSizePolicy(sizePolicy);
        leID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        leID->setMouseTracking(true);
        leID->setFocusPolicy(Qt::StrongFocus);
        leID->setStyleSheet(QLatin1String("QTextEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leID->setInputMethodHints(Qt::ImhNone);
        leID->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leID->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leID->setReadOnly(true);
        leFil = new QTextEdit(gbFullInfo);
        leFil->setObjectName(QStringLiteral("leFil"));
        leFil->setGeometry(QRect(10, 112, 751, 20));
        leFil->setStyleSheet(QLatin1String("QTextEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leFil->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leFil->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        leFil->setReadOnly(true);
        pbDoubleSearch = new QPushButton(centralwidget);
        pbDoubleSearch->setObjectName(QStringLiteral("pbDoubleSearch"));
        pbDoubleSearch->setGeometry(QRect(297, 53, 31, 23));
        pbDoubleSearch->setCheckable(true);
        pbDoubleSearch->setChecked(false);
        lblHelp = new QLabel(centralwidget);
        lblHelp->setObjectName(QStringLiteral("lblHelp"));
        lblHelp->setGeometry(QRect(20, 590, 741, 61));
        QFont font2;
        font2.setPointSize(9);
        lblHelp->setFont(font2);
        lblHelp->setTextFormat(Qt::RichText);
        lblHelp->setWordWrap(true);
        cbFullInfo = new QCheckBox(centralwidget);
        cbFullInfo->setObjectName(QStringLiteral("cbFullInfo"));
        cbFullInfo->setGeometry(QRect(649, 60, 121, 20));
        lblInfoAboutUpdateBases = new QLabel(centralwidget);
        lblInfoAboutUpdateBases->setObjectName(QStringLiteral("lblInfoAboutUpdateBases"));
        lblInfoAboutUpdateBases->setGeometry(QRect(19, 5, 271, 21));
        searchBook->setCentralWidget(centralwidget);

        retranslateUi(searchBook);

        QMetaObject::connectSlotsByName(searchBook);
    } // setupUi

    void retranslateUi(QMainWindow *searchBook)
    {
        searchBook->setWindowTitle(QApplication::translate("searchBook", "mainWnd", 0));
        leFilter->setText(QString());
        leFilter->setPlaceholderText(QApplication::translate("searchBook", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\260\320\263\320\273\320\260\320\262\320\270\320\265 \320\270\320\273\320\270 \320\260\320\262\321\202\320\276\321\200\320\260 \320\272\320\275\320\270\320\263\320\270 \320\270\320\273\320\270 \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 (\321\200\320\265\320\263\320\270\321\201\321\202\321\200 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\275\320\265 \320\270\320\274\320\265\320\265\321\202)", 0));
        lblFilter->setText(QApplication::translate("searchBook", "\320\227\320\260\320\277\321\200\320\276\321\201", 0));
        lblTableFilter->setText(QApplication::translate("searchBook", "\320\236\320\272\320\275\320\276 \320\277\320\276\320\270\321\201\320\272\320\260", 0));
        pbProgress->setFormat(QString());
        lblProgress->setText(QApplication::translate("searchBook", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", 0));
        rbName->setText(QApplication::translate("searchBook", "\320\237\320\276 \320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\272\321\203", 0));
        rbAutor->setText(QApplication::translate("searchBook", "\320\237\320\276 \320\220\320\262\321\202\320\276\321\200\321\203", 0));
        rbID->setText(QApplication::translate("searchBook", "\320\237\320\276 \320\230\320\275\320\262. \320\275\320\276\320\274\320\265\321\200\321\203", 0));
        cbHelpNeed->setText(QApplication::translate("searchBook", "\320\235\321\203\320\266\320\275\320\260 \320\277\320\276\320\274\320\276\321\211\321\214?", 0));
        gbFullInfo->setTitle(QApplication::translate("searchBook", "\320\237\320\276\320\273\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        lblFil->setText(QApplication::translate("searchBook", "\320\234\320\265\321\201\321\202\320\276 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217:", 0));
        lblYear->setText(QApplication::translate("searchBook", "\320\223\320\276\320\264:", 0));
        lblKnowledgeSection->setText(QApplication::translate("searchBook", "\320\240\320\260\320\267\320\264\320\265\320\273:", 0));
        lblID->setText(QApplication::translate("searchBook", "\320\230\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:", 0));
        lblAutor->setText(QApplication::translate("searchBook", "\320\220\320\262\321\202\320\276\321\200:", 0));
        lblName->setText(QApplication::translate("searchBook", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265:", 0));
        lblSeries->setText(QApplication::translate("searchBook", "\320\241\320\265\321\200\320\270\321\217:", 0));
        lblBookPart->setText(QApplication::translate("searchBook", "\320\232\320\275./\320\242\320\276\320\274/\321\207.:", 0));
        lblISBN->setText(QApplication::translate("searchBook", "ISBN:", 0));
        lblSysCode->setText(QApplication::translate("searchBook", "\320\241\320\270\321\201\321\202. \321\210\320\270\321\204\321\200:", 0));
        leID->setHtml(QApplication::translate("searchBook", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans Mono'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        pbDoubleSearch->setText(QApplication::translate("searchBook", "+", 0));
        lblHelp->setText(QApplication::translate("searchBook", "<html><head/><body><p>\320\224\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \320\272\320\275\320\270\320\263 \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\320\265, \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \320\275\320\260\320\271\321\202\320\270 \320\272\320\275\320\270\320\263\321\203 (\320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272, \320\260\320\262\321\202\320\276\321\200, \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200).<br/>\320\224\320\273\321\217 \321\203\321\202\320\276\321\207\320\275\320\265\320\275\320\270\321\217 \320\267\320\260\320\277\321\200\320\276\321\201\320\260 - \320\274\320\276\320\266\320\275\320\276 \320\262\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\270\320\273\320\270\320\260\320"
                        "\273 \320\270\320\267 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260.<br/>\320\224\320\273\321\217 \320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\263\320\276 \320\277\320\276\320\270\321\201\320\272\320\260 \320\277\320\276 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\321\203 \320\270 \320\260\320\262\321\202\320\276\321\200\321\203 - \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 + (\320\277\320\273\321\216\321\201) \320\270 \320\262\320\262\320\276\320\264\320\270\321\202\320\265 \320\277\320\276\320\270\321\201\320\272 \320\262 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\274 \321\204\320\276\321\200\320\274\320\260\321\202\320\265: <span style=\" font-weight:600;\">\320\244\320\260\320\274\320\270\320\273\320\270\321\217_\320\220\320\262\321\202\320"
                        "\276\321\200\320\260 % \321\207\320\260\321\201\321\202\321\214_\320\267\320\260\320\263\320\273\320\260\320\262\320\270\321\217_\320\272\320\275\320\270\320\263\320\270</span>. \320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: <span style=\" font-weight:600;\">\320\277\321\203\321\210 % \320\265\321\201\320\265</span></p></body></html>", 0));
        cbFullInfo->setText(QApplication::translate("searchBook", "\320\237\320\276\320\273\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        lblInfoAboutUpdateBases->setText(QApplication::translate("searchBook", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\260\320\272\321\202\321\203\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270 \320\261\320\260\320\267\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class searchBook: public Ui_searchBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBOOK_H
