/********************************************************************************
** Form generated from reading UI file 'ui_importing.ui'
**
** Created: Thu 10. Feb 18:17:41 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_IMPORTING_H
#define UI_UI_IMPORTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Importing
{
public:
    QLabel *lblCurNumber;
    QLCDNumber *lcdCurNumber;

    void setupUi(QDialog *Importing)
    {
        if (Importing->objectName().isEmpty())
            Importing->setObjectName(QString::fromUtf8("Importing"));
        Importing->setWindowModality(Qt::WindowModal);
        Importing->resize(222, 254);
        Importing->setContextMenuPolicy(Qt::NoContextMenu);
        Importing->setModal(true);
        lblCurNumber = new QLabel(Importing);
        lblCurNumber->setObjectName(QString::fromUtf8("lblCurNumber"));
        lblCurNumber->setGeometry(QRect(10, 17, 101, 16));
        lcdCurNumber = new QLCDNumber(Importing);
        lcdCurNumber->setObjectName(QString::fromUtf8("lcdCurNumber"));
        lcdCurNumber->setGeometry(QRect(110, 13, 101, 23));
        lcdCurNumber->setFrameShape(QFrame::Box);
        lcdCurNumber->setFrameShadow(QFrame::Raised);
        lcdCurNumber->setSmallDecimalPoint(false);
        lcdCurNumber->setNumDigits(6);
        lcdCurNumber->setSegmentStyle(QLCDNumber::Filled);

        retranslateUi(Importing);

        QMetaObject::connectSlotsByName(Importing);
    } // setupUi

    void retranslateUi(QDialog *Importing)
    {
        Importing->setWindowTitle(QApplication::translate("Importing", "\320\230\320\274\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        lblCurNumber->setText(QApplication::translate("Importing", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Importing: public Ui_Importing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_IMPORTING_H
