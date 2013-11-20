/********************************************************************************
** Form generated from reading UI file 'form_DownloadBooks.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_DOWNLOADBOOKS_H
#define UI_FORM_DOWNLOADBOOKS_H

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

QT_BEGIN_NAMESPACE

class Ui_form_DownloadBooks
{
public:
    QComboBox *cbBase;
    QLabel *label;
    QPushButton *pbGetBooks;
    QGroupBox *gbAboutCurrentBase;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *leAmountRecordInBase;
    QLabel *label_4;
    QLineEdit *leGetCount;
    QLineEdit *leRemain;
    QPushButton *pbLogin;
    QPushButton *pbFillBooks;
    QPushButton *pbPrepareBooks;
    QComboBox *cbPreparedFile;
    QLabel *label_5;

    void setupUi(QDialog *form_DownloadBooks)
    {
        if (form_DownloadBooks->objectName().isEmpty())
            form_DownloadBooks->setObjectName(QStringLiteral("form_DownloadBooks"));
        form_DownloadBooks->resize(432, 175);
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
        form_DownloadBooks->setPalette(palette);
        cbBase = new QComboBox(form_DownloadBooks);
        cbBase->setObjectName(QStringLiteral("cbBase"));
        cbBase->setGeometry(QRect(50, 7, 181, 20));
        label = new QLabel(form_DownloadBooks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 41, 16));
        pbGetBooks = new QPushButton(form_DownloadBooks);
        pbGetBooks->setObjectName(QStringLiteral("pbGetBooks"));
        pbGetBooks->setGeometry(QRect(240, 7, 81, 20));
        gbAboutCurrentBase = new QGroupBox(form_DownloadBooks);
        gbAboutCurrentBase->setObjectName(QStringLiteral("gbAboutCurrentBase"));
        gbAboutCurrentBase->setGeometry(QRect(20, 54, 391, 111));
        label_2 = new QLabel(gbAboutCurrentBase);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 24, 81, 16));
        label_3 = new QLabel(gbAboutCurrentBase);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 71, 16));
        leAmountRecordInBase = new QLineEdit(gbAboutCurrentBase);
        leAmountRecordInBase->setObjectName(QStringLiteral("leAmountRecordInBase"));
        leAmountRecordInBase->setEnabled(false);
        leAmountRecordInBase->setGeometry(QRect(100, 22, 131, 18));
        leAmountRecordInBase->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leAmountRecordInBase->setAlignment(Qt::AlignCenter);
        leAmountRecordInBase->setReadOnly(true);
        label_4 = new QLabel(gbAboutCurrentBase);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 80, 71, 16));
        leGetCount = new QLineEdit(gbAboutCurrentBase);
        leGetCount->setObjectName(QStringLiteral("leGetCount"));
        leGetCount->setEnabled(false);
        leGetCount->setGeometry(QRect(100, 50, 131, 18));
        leGetCount->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leGetCount->setAlignment(Qt::AlignCenter);
        leGetCount->setReadOnly(true);
        leRemain = new QLineEdit(gbAboutCurrentBase);
        leRemain->setObjectName(QStringLiteral("leRemain"));
        leRemain->setEnabled(false);
        leRemain->setGeometry(QRect(100, 79, 131, 18));
        leRemain->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leRemain->setAlignment(Qt::AlignCenter);
        leRemain->setReadOnly(true);
        pbLogin = new QPushButton(gbAboutCurrentBase);
        pbLogin->setObjectName(QStringLiteral("pbLogin"));
        pbLogin->setEnabled(true);
        pbLogin->setGeometry(QRect(280, 40, 75, 23));
        pbFillBooks = new QPushButton(form_DownloadBooks);
        pbFillBooks->setObjectName(QStringLiteral("pbFillBooks"));
        pbFillBooks->setGeometry(QRect(240, 30, 81, 20));
        pbPrepareBooks = new QPushButton(form_DownloadBooks);
        pbPrepareBooks->setObjectName(QStringLiteral("pbPrepareBooks"));
        pbPrepareBooks->setGeometry(QRect(330, 8, 81, 41));
        cbPreparedFile = new QComboBox(form_DownloadBooks);
        cbPreparedFile->setObjectName(QStringLiteral("cbPreparedFile"));
        cbPreparedFile->setGeometry(QRect(50, 30, 181, 20));
        label_5 = new QLabel(form_DownloadBooks);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 33, 41, 16));

        retranslateUi(form_DownloadBooks);

        QMetaObject::connectSlotsByName(form_DownloadBooks);
    } // setupUi

    void retranslateUi(QDialog *form_DownloadBooks)
    {
        form_DownloadBooks->setWindowTitle(QApplication::translate("form_DownloadBooks", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265 \320\261\320\260\320\267", 0));
        cbBase->clear();
        cbBase->insertItems(0, QStringList()
         << QApplication::translate("form_DownloadBooks", "EKNEW", 0)
         << QApplication::translate("form_DownloadBooks", "EKOLD", 0)
         << QApplication::translate("form_DownloadBooks", "RETRO", 0)
        );
        label->setText(QApplication::translate("form_DownloadBooks", "\320\221\320\260\320\267\320\260", 0));
        pbGetBooks->setText(QApplication::translate("form_DownloadBooks", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0));
        gbAboutCurrentBase->setTitle(QApplication::translate("form_DownloadBooks", "\320\241\320\262\320\276\320\264\320\272\320\260 \320\276 \320\261\320\260\320\267\320\265", 0));
        label_2->setText(QApplication::translate("form_DownloadBooks", "\320\222\321\201\320\265\320\263\320\276 \320\267\320\260\320\277\320\270\321\201\320\265\320\271:", 0));
        label_3->setText(QApplication::translate("form_DownloadBooks", "\320\241\320\263\321\200\320\260\320\261\320\273\320\265\320\275\320\276:", 0));
        label_4->setText(QApplication::translate("form_DownloadBooks", "\320\236\321\201\321\202\320\260\320\273\320\276\321\201\321\214:", 0));
        pbLogin->setText(QApplication::translate("form_DownloadBooks", "login", 0));
        pbFillBooks->setText(QApplication::translate("form_DownloadBooks", "\320\236\321\202\320\264\320\260\321\202\321\214", 0));
        pbPrepareBooks->setText(QApplication::translate("form_DownloadBooks", "\320\237\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\270\321\202\321\214", 0));
        cbPreparedFile->clear();
        cbPreparedFile->insertItems(0, QStringList()
         << QApplication::translate("form_DownloadBooks", "EKNEW_prepared", 0)
         << QApplication::translate("form_DownloadBooks", "EKOLD_prepared", 0)
         << QApplication::translate("form_DownloadBooks", "RETRO_prepared", 0)
        );
        label_5->setText(QApplication::translate("form_DownloadBooks", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class form_DownloadBooks: public Ui_form_DownloadBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_DOWNLOADBOOKS_H
