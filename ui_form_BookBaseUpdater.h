/********************************************************************************
** Form generated from reading UI file 'form_BookBaseUpdater.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_BOOKBASEUPDATER_H
#define UI_FORM_BOOKBASEUPDATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_form_BookBaseUpdater
{
public:
    QGroupBox *gbInfo;
    QLabel *lblBooksCountBeforeUpdate;
    QLabel *lblBooksCountAfterUpdate;
    QLabel *lblBoksRemaining;
    QLabel *lblUpdateDate;
    QLineEdit *leBooksCountBeforeUpdate;
    QLineEdit *leBooksCountAfterUpdate;
    QLineEdit *leBooksRemaining;
    QDateEdit *dtUpdate;
    QFrame *line;
    QLabel *lblCurBase;
    QLineEdit *leCurBaseName;

    void setupUi(QDialog *form_BookBaseUpdater)
    {
        if (form_BookBaseUpdater->objectName().isEmpty())
            form_BookBaseUpdater->setObjectName(QStringLiteral("form_BookBaseUpdater"));
        form_BookBaseUpdater->resize(232, 176);
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
        form_BookBaseUpdater->setPalette(palette);
        gbInfo = new QGroupBox(form_BookBaseUpdater);
        gbInfo->setObjectName(QStringLiteral("gbInfo"));
        gbInfo->setGeometry(QRect(20, 40, 191, 121));
        lblBooksCountBeforeUpdate = new QLabel(gbInfo);
        lblBooksCountBeforeUpdate->setObjectName(QStringLiteral("lblBooksCountBeforeUpdate"));
        lblBooksCountBeforeUpdate->setGeometry(QRect(20, 20, 91, 16));
        lblBooksCountAfterUpdate = new QLabel(gbInfo);
        lblBooksCountAfterUpdate->setObjectName(QStringLiteral("lblBooksCountAfterUpdate"));
        lblBooksCountAfterUpdate->setGeometry(QRect(20, 40, 101, 16));
        lblBoksRemaining = new QLabel(gbInfo);
        lblBoksRemaining->setObjectName(QStringLiteral("lblBoksRemaining"));
        lblBoksRemaining->setGeometry(QRect(20, 60, 101, 16));
        lblUpdateDate = new QLabel(gbInfo);
        lblUpdateDate->setObjectName(QStringLiteral("lblUpdateDate"));
        lblUpdateDate->setGeometry(QRect(20, 94, 101, 16));
        leBooksCountBeforeUpdate = new QLineEdit(gbInfo);
        leBooksCountBeforeUpdate->setObjectName(QStringLiteral("leBooksCountBeforeUpdate"));
        leBooksCountBeforeUpdate->setEnabled(false);
        leBooksCountBeforeUpdate->setGeometry(QRect(123, 20, 61, 16));
        leBooksCountBeforeUpdate->setReadOnly(true);
        leBooksCountAfterUpdate = new QLineEdit(gbInfo);
        leBooksCountAfterUpdate->setObjectName(QStringLiteral("leBooksCountAfterUpdate"));
        leBooksCountAfterUpdate->setEnabled(false);
        leBooksCountAfterUpdate->setGeometry(QRect(123, 40, 61, 16));
        leBooksCountAfterUpdate->setReadOnly(true);
        leBooksRemaining = new QLineEdit(gbInfo);
        leBooksRemaining->setObjectName(QStringLiteral("leBooksRemaining"));
        leBooksRemaining->setEnabled(false);
        leBooksRemaining->setGeometry(QRect(123, 60, 61, 16));
        leBooksRemaining->setReadOnly(true);
        dtUpdate = new QDateEdit(gbInfo);
        dtUpdate->setObjectName(QStringLiteral("dtUpdate"));
        dtUpdate->setEnabled(false);
        dtUpdate->setGeometry(QRect(123, 94, 61, 16));
        dtUpdate->setAlignment(Qt::AlignCenter);
        dtUpdate->setReadOnly(true);
        dtUpdate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        line = new QFrame(gbInfo);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(4, 76, 184, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lblCurBase = new QLabel(form_BookBaseUpdater);
        lblCurBase->setObjectName(QStringLiteral("lblCurBase"));
        lblCurBase->setGeometry(QRect(30, 18, 81, 16));
        leCurBaseName = new QLineEdit(form_BookBaseUpdater);
        leCurBaseName->setObjectName(QStringLiteral("leCurBaseName"));
        leCurBaseName->setEnabled(false);
        leCurBaseName->setGeometry(QRect(120, 16, 81, 20));
        leCurBaseName->setReadOnly(true);

        retranslateUi(form_BookBaseUpdater);

        QMetaObject::connectSlotsByName(form_BookBaseUpdater);
    } // setupUi

    void retranslateUi(QDialog *form_BookBaseUpdater)
    {
        form_BookBaseUpdater->setWindowTitle(QApplication::translate("form_BookBaseUpdater", "form_BookBaseUpdater", 0));
        gbInfo->setTitle(QApplication::translate("form_BookBaseUpdater", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        lblBooksCountBeforeUpdate->setText(QApplication::translate("form_BookBaseUpdater", "\320\224\320\276 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217:", 0));
        lblBooksCountAfterUpdate->setText(QApplication::translate("form_BookBaseUpdater", "\320\237\320\276\321\201\320\273\320\265 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217:", 0));
        lblBoksRemaining->setText(QApplication::translate("form_BookBaseUpdater", "\320\236\321\201\321\202\320\260\320\273\320\276\321\201\321\214:", 0));
        lblUpdateDate->setText(QApplication::translate("form_BookBaseUpdater", "\320\224\320\260\321\202\320\260 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217:", 0));
        lblCurBase->setText(QApplication::translate("form_BookBaseUpdater", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\261\320\260\320\267\320\260:", 0));
    } // retranslateUi

};

namespace Ui {
    class form_BookBaseUpdater: public Ui_form_BookBaseUpdater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_BOOKBASEUPDATER_H
