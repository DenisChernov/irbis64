/********************************************************************************
** Form generated from reading UI file 'formLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLOGIN_H
#define UI_FORMLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_formLogin
{
public:
    QGroupBox *gbUserAccount;
    QCheckBox *cbSaveAccount;
    QLineEdit *leLogin;
    QLabel *lblLogin;
    QLineEdit *lePassword;
    QLabel *lblPass;
    QLabel *label;
    QPushButton *pbLogin;

    void setupUi(QDialog *formLogin)
    {
        if (formLogin->objectName().isEmpty())
            formLogin->setObjectName(QStringLiteral("formLogin"));
        formLogin->resize(250, 128);
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
        formLogin->setPalette(palette);
        gbUserAccount = new QGroupBox(formLogin);
        gbUserAccount->setObjectName(QStringLiteral("gbUserAccount"));
        gbUserAccount->setGeometry(QRect(10, 10, 231, 81));
        cbSaveAccount = new QCheckBox(gbUserAccount);
        cbSaveAccount->setObjectName(QStringLiteral("cbSaveAccount"));
        cbSaveAccount->setGeometry(QRect(150, 60, 81, 17));
        leLogin = new QLineEdit(gbUserAccount);
        leLogin->setObjectName(QStringLiteral("leLogin"));
        leLogin->setGeometry(QRect(70, 20, 141, 18));
        lblLogin = new QLabel(gbUserAccount);
        lblLogin->setObjectName(QStringLiteral("lblLogin"));
        lblLogin->setGeometry(QRect(20, 22, 46, 13));
        lePassword = new QLineEdit(gbUserAccount);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setGeometry(QRect(70, 40, 141, 18));
        lblPass = new QLabel(gbUserAccount);
        lblPass->setObjectName(QStringLiteral("lblPass"));
        lblPass->setGeometry(QRect(20, 42, 46, 13));
        label = new QLabel(gbUserAccount);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 101, 16));
        QPalette palette1;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette1);
        pbLogin = new QPushButton(formLogin);
        pbLogin->setObjectName(QStringLiteral("pbLogin"));
        pbLogin->setEnabled(true);
        pbLogin->setGeometry(QRect(160, 96, 75, 23));

        retranslateUi(formLogin);

        QMetaObject::connectSlotsByName(formLogin);
    } // setupUi

    void retranslateUi(QDialog *formLogin)
    {
        formLogin->setWindowTitle(QApplication::translate("formLogin", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0));
        gbUserAccount->setTitle(QApplication::translate("formLogin", "\320\243\321\207\320\265\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        cbSaveAccount->setText(QApplication::translate("formLogin", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        lblLogin->setText(QApplication::translate("formLogin", "\320\233\320\276\320\263\320\270\320\275:", 0));
        lblPass->setText(QApplication::translate("formLogin", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0));
        label->setText(QApplication::translate("formLogin", "\320\237\320\276\320\272\320\260 \320\261\320\265\320\267 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270", 0));
        pbLogin->setText(QApplication::translate("formLogin", "\320\222\320\276\320\271\321\202\320\270?", 0));
    } // retranslateUi

};

namespace Ui {
    class formLogin: public Ui_formLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLOGIN_H
