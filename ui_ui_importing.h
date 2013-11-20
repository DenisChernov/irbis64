/********************************************************************************
** Form generated from reading UI file 'ui_importing.ui'
**
** Created: Thu 4. Oct 13:46:25 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_IMPORTING_H
#define UI_UI_IMPORTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_Importing
{
public:
    QLabel *lblCurNumber;
    QLCDNumber *lcdCurNumber;
    QLabel *lblAmountNumber;
    QLCDNumber *lcdAmountNumber;
    QProgressBar *pbProgress;
    QLabel *lblPassDescription;

    void setupUi(QDialog *Importing)
    {
        if (Importing->objectName().isEmpty())
            Importing->setObjectName(QString::fromUtf8("Importing"));
        Importing->setWindowModality(Qt::WindowModal);
        Importing->resize(222, 124);
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
        lcdCurNumber->setDigitCount(6);
        lcdCurNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdCurNumber->setProperty("intValue", QVariant(0));
        lblAmountNumber = new QLabel(Importing);
        lblAmountNumber->setObjectName(QString::fromUtf8("lblAmountNumber"));
        lblAmountNumber->setGeometry(QRect(10, 54, 101, 16));
        lcdAmountNumber = new QLCDNumber(Importing);
        lcdAmountNumber->setObjectName(QString::fromUtf8("lcdAmountNumber"));
        lcdAmountNumber->setGeometry(QRect(110, 50, 101, 23));
        lcdAmountNumber->setFrameShape(QFrame::Box);
        lcdAmountNumber->setFrameShadow(QFrame::Raised);
        lcdAmountNumber->setSmallDecimalPoint(false);
        lcdAmountNumber->setDigitCount(6);
        lcdAmountNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdAmountNumber->setProperty("intValue", QVariant(0));
        pbProgress = new QProgressBar(Importing);
        pbProgress->setObjectName(QString::fromUtf8("pbProgress"));
        pbProgress->setGeometry(QRect(10, 100, 211, 16));
        pbProgress->setValue(24);
        lblPassDescription = new QLabel(Importing);
        lblPassDescription->setObjectName(QString::fromUtf8("lblPassDescription"));
        lblPassDescription->setGeometry(QRect(20, 80, 181, 16));
        lblPassDescription->setAlignment(Qt::AlignCenter);

        retranslateUi(Importing);

        QMetaObject::connectSlotsByName(Importing);
    } // setupUi

    void retranslateUi(QDialog *Importing)
    {
        Importing->setWindowTitle(QApplication::translate("Importing", "\320\230\320\274\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        lblCurNumber->setText(QApplication::translate("Importing", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217:", 0));
        lblAmountNumber->setText(QApplication::translate("Importing", "\320\222\321\201\320\265\320\263\320\276 \320\262 \320\261\320\260\320\267\320\265:", 0));
        lblPassDescription->setText(QApplication::translate("Importing", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\277\321\200\320\276\321\205\320\276\320\264\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Importing: public Ui_Importing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_IMPORTING_H
