/********************************************************************************
** Form generated from reading UI file 'form_bookInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_BOOKINFO_H
#define UI_FORM_BOOKINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_form_bookInfo
{
public:
    QGroupBox *gbCurrentBookNumber;
    QLabel *lbl;
    QPushButton *pbGoLeft;
    QPushButton *pbGoRight;
    QLineEdit *leCurNumber;
    QLineEdit *leMaxNumber;
    QGroupBox *gbBookInfo;
    QLabel *lblAutor;
    QLineEdit *leAutor;
    QLineEdit *leBookName;
    QLabel *lblBookName;
    QGroupBox *gbMultiVollume;
    QLabel *label;
    QSpinBox *spVollumeNumber;
    QLineEdit *leVollumeName;
    QLabel *lblPublishing;
    QComboBox *cbPublishing;
    QComboBox *cbCityOfPublishing;
    QLabel *lblCityOfPublishing;
    QLineEdit *leCity;
    QGroupBox *gbAutorSign;
    QLineEdit *leAutorSign;
    QLabel *lblYearOfPublishing;
    QSpinBox *sbYearOfPublihsing;
    QLabel *lblCountPages;
    QSpinBox *sbCountPages;
    QLabel *lblIndexUDK;
    QComboBox *cbIndexUDK;
    QLabel *lblBBK;
    QComboBox *cbBBK;
    QLabel *lblSectionOfKnowlidge;
    QComboBox *cbSectionOfKnowlidge;
    QGroupBox *gbAboutBook;
    QTextEdit *teAboutBook;
    QLineEdit *leAdditionalBookName;
    QLabel *lblAdditionalBookName;
    QLineEdit *leSeries;
    QLabel *lblSeries;

    void setupUi(QDialog *form_bookInfo)
    {
        if (form_bookInfo->objectName().isEmpty())
            form_bookInfo->setObjectName(QStringLiteral("form_bookInfo"));
        form_bookInfo->resize(776, 522);
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
        form_bookInfo->setPalette(palette);
        form_bookInfo->setStyleSheet(QStringLiteral(""));
        gbCurrentBookNumber = new QGroupBox(form_bookInfo);
        gbCurrentBookNumber->setObjectName(QStringLiteral("gbCurrentBookNumber"));
        gbCurrentBookNumber->setGeometry(QRect(590, 10, 161, 76));
        lbl = new QLabel(gbCurrentBookNumber);
        lbl->setObjectName(QStringLiteral("lbl"));
        lbl->setGeometry(QRect(77, 20, 16, 16));
        pbGoLeft = new QPushButton(gbCurrentBookNumber);
        pbGoLeft->setObjectName(QStringLiteral("pbGoLeft"));
        pbGoLeft->setEnabled(false);
        pbGoLeft->setGeometry(QRect(20, 40, 61, 23));
        pbGoLeft->setIconSize(QSize(16, 16));
        pbGoRight = new QPushButton(gbCurrentBookNumber);
        pbGoRight->setObjectName(QStringLiteral("pbGoRight"));
        pbGoRight->setGeometry(QRect(84, 40, 61, 23));
        leCurNumber = new QLineEdit(gbCurrentBookNumber);
        leCurNumber->setObjectName(QStringLiteral("leCurNumber"));
        leCurNumber->setGeometry(QRect(20, 18, 41, 20));
        leCurNumber->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leMaxNumber = new QLineEdit(gbCurrentBookNumber);
        leMaxNumber->setObjectName(QStringLiteral("leMaxNumber"));
        leMaxNumber->setGeometry(QRect(104, 18, 41, 20));
        leMaxNumber->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbBookInfo = new QGroupBox(form_bookInfo);
        gbBookInfo->setObjectName(QStringLiteral("gbBookInfo"));
        gbBookInfo->setGeometry(QRect(10, 10, 571, 501));
        lblAutor = new QLabel(gbBookInfo);
        lblAutor->setObjectName(QStringLiteral("lblAutor"));
        lblAutor->setGeometry(QRect(20, 20, 41, 21));
        leAutor = new QLineEdit(gbBookInfo);
        leAutor->setObjectName(QStringLiteral("leAutor"));
        leAutor->setGeometry(QRect(100, 20, 211, 20));
        leAutor->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leBookName = new QLineEdit(gbBookInfo);
        leBookName->setObjectName(QStringLiteral("leBookName"));
        leBookName->setGeometry(QRect(100, 50, 451, 20));
        leBookName->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        lblBookName = new QLabel(gbBookInfo);
        lblBookName->setObjectName(QStringLiteral("lblBookName"));
        lblBookName->setGeometry(QRect(20, 50, 61, 21));
        gbMultiVollume = new QGroupBox(gbBookInfo);
        gbMultiVollume->setObjectName(QStringLiteral("gbMultiVollume"));
        gbMultiVollume->setGeometry(QRect(20, 173, 541, 61));
        gbMultiVollume->setCheckable(true);
        gbMultiVollume->setChecked(false);
        label = new QLabel(gbMultiVollume);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 27, 16, 16));
        spVollumeNumber = new QSpinBox(gbMultiVollume);
        spVollumeNumber->setObjectName(QStringLiteral("spVollumeNumber"));
        spVollumeNumber->setGeometry(QRect(20, 24, 41, 20));
        spVollumeNumber->setStyleSheet(QLatin1String("QSpinBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        spVollumeNumber->setMinimum(1);
        leVollumeName = new QLineEdit(gbMultiVollume);
        leVollumeName->setObjectName(QStringLiteral("leVollumeName"));
        leVollumeName->setGeometry(QRect(80, 24, 451, 20));
        leVollumeName->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        lblPublishing = new QLabel(gbBookInfo);
        lblPublishing->setObjectName(QStringLiteral("lblPublishing"));
        lblPublishing->setGeometry(QRect(20, 243, 81, 21));
        cbPublishing = new QComboBox(gbBookInfo);
        cbPublishing->setObjectName(QStringLiteral("cbPublishing"));
        cbPublishing->setGeometry(QRect(100, 245, 291, 20));
        cbPublishing->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbPublishing->setEditable(true);
        cbCityOfPublishing = new QComboBox(gbBookInfo);
        cbCityOfPublishing->setObjectName(QStringLiteral("cbCityOfPublishing"));
        cbCityOfPublishing->setGeometry(QRect(100, 273, 201, 20));
        cbCityOfPublishing->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbCityOfPublishing->setEditable(false);
        lblCityOfPublishing = new QLabel(gbBookInfo);
        lblCityOfPublishing->setObjectName(QStringLiteral("lblCityOfPublishing"));
        lblCityOfPublishing->setGeometry(QRect(20, 273, 41, 21));
        leCity = new QLineEdit(gbBookInfo);
        leCity->setObjectName(QStringLiteral("leCity"));
        leCity->setEnabled(false);
        leCity->setGeometry(QRect(340, 273, 31, 20));
        gbAutorSign = new QGroupBox(gbBookInfo);
        gbAutorSign->setObjectName(QStringLiteral("gbAutorSign"));
        gbAutorSign->setGeometry(QRect(330, 0, 91, 61));
        leAutorSign = new QLineEdit(gbAutorSign);
        leAutorSign->setObjectName(QStringLiteral("leAutorSign"));
        leAutorSign->setEnabled(false);
        leAutorSign->setGeometry(QRect(20, 20, 51, 20));
        lblYearOfPublishing = new QLabel(gbBookInfo);
        lblYearOfPublishing->setObjectName(QStringLiteral("lblYearOfPublishing"));
        lblYearOfPublishing->setGeometry(QRect(410, 246, 31, 16));
        sbYearOfPublihsing = new QSpinBox(gbBookInfo);
        sbYearOfPublihsing->setObjectName(QStringLiteral("sbYearOfPublihsing"));
        sbYearOfPublihsing->setGeometry(QRect(440, 243, 51, 20));
        sbYearOfPublihsing->setMaximum(2012);
        sbYearOfPublihsing->setValue(2012);
        lblCountPages = new QLabel(gbBookInfo);
        lblCountPages->setObjectName(QStringLiteral("lblCountPages"));
        lblCountPages->setGeometry(QRect(20, 303, 46, 13));
        sbCountPages = new QSpinBox(gbBookInfo);
        sbCountPages->setObjectName(QStringLiteral("sbCountPages"));
        sbCountPages->setGeometry(QRect(100, 299, 61, 20));
        sbCountPages->setMaximum(2000);
        lblIndexUDK = new QLabel(gbBookInfo);
        lblIndexUDK->setObjectName(QStringLiteral("lblIndexUDK"));
        lblIndexUDK->setGeometry(QRect(20, 343, 71, 16));
        cbIndexUDK = new QComboBox(gbBookInfo);
        cbIndexUDK->setObjectName(QStringLiteral("cbIndexUDK"));
        cbIndexUDK->setGeometry(QRect(100, 340, 111, 20));
        cbIndexUDK->setEditable(true);
        lblBBK = new QLabel(gbBookInfo);
        lblBBK->setObjectName(QStringLiteral("lblBBK"));
        lblBBK->setGeometry(QRect(220, 343, 31, 16));
        cbBBK = new QComboBox(gbBookInfo);
        cbBBK->setObjectName(QStringLiteral("cbBBK"));
        cbBBK->setGeometry(QRect(250, 340, 111, 20));
        cbBBK->setEditable(true);
        lblSectionOfKnowlidge = new QLabel(gbBookInfo);
        lblSectionOfKnowlidge->setObjectName(QStringLiteral("lblSectionOfKnowlidge"));
        lblSectionOfKnowlidge->setGeometry(QRect(370, 343, 81, 16));
        cbSectionOfKnowlidge = new QComboBox(gbBookInfo);
        cbSectionOfKnowlidge->setObjectName(QStringLiteral("cbSectionOfKnowlidge"));
        cbSectionOfKnowlidge->setGeometry(QRect(460, 340, 51, 20));
        cbSectionOfKnowlidge->setEditable(true);
        gbAboutBook = new QGroupBox(gbBookInfo);
        gbAboutBook->setObjectName(QStringLiteral("gbAboutBook"));
        gbAboutBook->setGeometry(QRect(10, 370, 551, 131));
        teAboutBook = new QTextEdit(gbAboutBook);
        teAboutBook->setObjectName(QStringLiteral("teAboutBook"));
        teAboutBook->setGeometry(QRect(10, 20, 531, 101));
        leAdditionalBookName = new QLineEdit(gbBookInfo);
        leAdditionalBookName->setObjectName(QStringLiteral("leAdditionalBookName"));
        leAdditionalBookName->setGeometry(QRect(100, 80, 451, 20));
        leAdditionalBookName->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        lblAdditionalBookName = new QLabel(gbBookInfo);
        lblAdditionalBookName->setObjectName(QStringLiteral("lblAdditionalBookName"));
        lblAdditionalBookName->setGeometry(QRect(20, 80, 61, 21));
        leSeries = new QLineEdit(gbBookInfo);
        leSeries->setObjectName(QStringLiteral("leSeries"));
        leSeries->setGeometry(QRect(100, 110, 451, 20));
        leSeries->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        lblSeries = new QLabel(gbBookInfo);
        lblSeries->setObjectName(QStringLiteral("lblSeries"));
        lblSeries->setGeometry(QRect(20, 110, 61, 21));
        lblAutor->raise();
        leAutor->raise();
        lblBookName->raise();
        gbMultiVollume->raise();
        lblPublishing->raise();
        cbPublishing->raise();
        cbCityOfPublishing->raise();
        lblCityOfPublishing->raise();
        leCity->raise();
        gbAutorSign->raise();
        leBookName->raise();
        lblYearOfPublishing->raise();
        sbYearOfPublihsing->raise();
        lblCountPages->raise();
        sbCountPages->raise();
        lblIndexUDK->raise();
        cbIndexUDK->raise();
        lblBBK->raise();
        cbBBK->raise();
        lblSectionOfKnowlidge->raise();
        cbSectionOfKnowlidge->raise();
        gbAboutBook->raise();
        leAdditionalBookName->raise();
        lblAdditionalBookName->raise();
        leSeries->raise();
        lblSeries->raise();
        gbBookInfo->raise();
        gbCurrentBookNumber->raise();

        retranslateUi(form_bookInfo);

        QMetaObject::connectSlotsByName(form_bookInfo);
    } // setupUi

    void retranslateUi(QDialog *form_bookInfo)
    {
        form_bookInfo->setWindowTitle(QApplication::translate("form_bookInfo", "\320\241\321\213\321\200\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        gbCurrentBookNumber->setTitle(QApplication::translate("form_bookInfo", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", 0));
        lbl->setText(QApplication::translate("form_bookInfo", "\320\270\320\267", 0));
        pbGoLeft->setText(QApplication::translate("form_bookInfo", "<<", 0));
        pbGoRight->setText(QApplication::translate("form_bookInfo", ">>", 0));
        gbBookInfo->setTitle(QApplication::translate("form_bookInfo", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \320\272\320\275\320\270\320\263\320\265", 0));
        lblAutor->setText(QApplication::translate("form_bookInfo", "\320\220\320\262\321\202\320\276\321\200:", 0));
        lblBookName->setText(QApplication::translate("form_bookInfo", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265:", 0));
        gbMultiVollume->setTitle(QApplication::translate("form_bookInfo", "\320\234\320\275\320\276\320\263\320\276\321\202\320\276\320\274\320\275\320\270\320\272?", 0));
        label->setText(QApplication::translate("form_bookInfo", "#", 0));
        lblPublishing->setText(QApplication::translate("form_bookInfo", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276:", 0));
        lblCityOfPublishing->setText(QApplication::translate("form_bookInfo", "\320\223\320\276\321\200\320\276\320\264:", 0));
        gbAutorSign->setTitle(QApplication::translate("form_bookInfo", "\320\220\320\262\321\202. \320\267\320\275\320\260\320\272", 0));
        lblYearOfPublishing->setText(QApplication::translate("form_bookInfo", "\320\223\320\276\320\264:", 0));
        sbYearOfPublihsing->setSuffix(QString());
        sbYearOfPublihsing->setPrefix(QString());
        lblCountPages->setText(QApplication::translate("form_bookInfo", "\320\236\320\261\321\212\320\265\320\274:", 0));
        lblIndexUDK->setText(QApplication::translate("form_bookInfo", "\320\230\320\275\320\264\320\265\320\272\321\201 \320\243\320\224\320\232:", 0));
        lblBBK->setText(QApplication::translate("form_bookInfo", "\320\221\320\221\320\232:", 0));
        lblSectionOfKnowlidge->setText(QApplication::translate("form_bookInfo", "\320\240\320\260\320\267\320\264\320\265\320\273 \320\267\320\275\320\260\320\275\320\270\320\271:", 0));
        gbAboutBook->setTitle(QApplication::translate("form_bookInfo", "\320\220\320\275\320\275\320\276\321\202\320\260\321\206\320\270\321\217", 0));
        lblAdditionalBookName->setText(QApplication::translate("form_bookInfo", "\320\243\321\202\320\276\321\207\320\275\320\265\320\275\320\270\320\265:", 0));
        lblSeries->setText(QApplication::translate("form_bookInfo", "\320\241\320\265\321\200\320\270\321\217:", 0));
    } // retranslateUi

};

namespace Ui {
    class form_bookInfo: public Ui_form_bookInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_BOOKINFO_H
