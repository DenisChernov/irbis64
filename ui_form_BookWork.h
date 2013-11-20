/********************************************************************************
** Form generated from reading UI file 'form_BookWork.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_BOOKWORK_H
#define UI_FORM_BOOKWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_form_BookWork
{
public:
    QGroupBox *gbISBN;
    QLineEdit *leISBN;
    QPushButton *pbSearchByISBN;
    QGroupBox *gbSearchInProgress;
    QProgressBar *pbCurrentStage;
    QLabel *lblCurrentStage;

    void setupUi(QDialog *form_BookWork)
    {
        if (form_BookWork->objectName().isEmpty())
            form_BookWork->setObjectName(QStringLiteral("form_BookWork"));
        form_BookWork->resize(393, 187);
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
        form_BookWork->setPalette(palette);
        gbISBN = new QGroupBox(form_BookWork);
        gbISBN->setObjectName(QStringLiteral("gbISBN"));
        gbISBN->setGeometry(QRect(10, 10, 371, 51));
        leISBN = new QLineEdit(gbISBN);
        leISBN->setObjectName(QStringLiteral("leISBN"));
        leISBN->setGeometry(QRect(10, 20, 221, 20));
        pbSearchByISBN = new QPushButton(gbISBN);
        pbSearchByISBN->setObjectName(QStringLiteral("pbSearchByISBN"));
        pbSearchByISBN->setGeometry(QRect(240, 19, 121, 23));
        gbSearchInProgress = new QGroupBox(form_BookWork);
        gbSearchInProgress->setObjectName(QStringLiteral("gbSearchInProgress"));
        gbSearchInProgress->setGeometry(QRect(10, 70, 371, 101));
        pbCurrentStage = new QProgressBar(gbSearchInProgress);
        pbCurrentStage->setObjectName(QStringLiteral("pbCurrentStage"));
        pbCurrentStage->setEnabled(true);
        pbCurrentStage->setGeometry(QRect(20, 60, 331, 23));
        pbCurrentStage->setValue(0);
        pbCurrentStage->setTextVisible(false);
        lblCurrentStage = new QLabel(gbSearchInProgress);
        lblCurrentStage->setObjectName(QStringLiteral("lblCurrentStage"));
        lblCurrentStage->setGeometry(QRect(40, 20, 291, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lblCurrentStage->setFont(font);
        lblCurrentStage->setFrameShape(QFrame::WinPanel);
        lblCurrentStage->setFrameShadow(QFrame::Plain);
        lblCurrentStage->setTextFormat(Qt::PlainText);
        lblCurrentStage->setScaledContents(true);
        lblCurrentStage->setWordWrap(false);
        lblCurrentStage->setMargin(0);

        retranslateUi(form_BookWork);

        QMetaObject::connectSlotsByName(form_BookWork);
    } // setupUi

    void retranslateUi(QDialog *form_BookWork)
    {
        form_BookWork->setWindowTitle(QApplication::translate("form_BookWork", "form_BookWork", 0));
        gbISBN->setTitle(QApplication::translate("form_BookWork", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 ISBN", 0));
        pbSearchByISBN->setText(QApplication::translate("form_BookWork", "\320\230\321\201\320\272\320\260\321\202\321\214", 0));
        gbSearchInProgress->setTitle(QString());
        lblCurrentStage->setText(QApplication::translate("form_BookWork", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\215\321\202\320\260\320\277", 0));
    } // retranslateUi

};

namespace Ui {
    class form_BookWork: public Ui_form_BookWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_BOOKWORK_H
