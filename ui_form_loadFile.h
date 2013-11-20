/********************************************************************************
** Form generated from reading UI file 'form_loadFile.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_LOADFILE_H
#define UI_FORM_LOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_form_loadfile
{
public:
    QProgressBar *pbLoadInfos;
    QLabel *lblAmountInfos;

    void setupUi(QDialog *form_loadfile)
    {
        if (form_loadfile->objectName().isEmpty())
            form_loadfile->setObjectName(QStringLiteral("form_loadfile"));
        form_loadfile->setWindowModality(Qt::ApplicationModal);
        form_loadfile->resize(402, 43);
        form_loadfile->setMinimumSize(QSize(402, 43));
        form_loadfile->setMaximumSize(QSize(402, 43));
        form_loadfile->setSizeGripEnabled(false);
        pbLoadInfos = new QProgressBar(form_loadfile);
        pbLoadInfos->setObjectName(QStringLiteral("pbLoadInfos"));
        pbLoadInfos->setEnabled(true);
        pbLoadInfos->setGeometry(QRect(10, 10, 381, 23));
        pbLoadInfos->setValue(0);
        pbLoadInfos->setTextVisible(false);
        lblAmountInfos = new QLabel(form_loadfile);
        lblAmountInfos->setObjectName(QStringLiteral("lblAmountInfos"));
        lblAmountInfos->setGeometry(QRect(170, 15, 46, 13));
        lblAmountInfos->setFrameShape(QFrame::NoFrame);
        lblAmountInfos->setAlignment(Qt::AlignCenter);

        retranslateUi(form_loadfile);

        QMetaObject::connectSlotsByName(form_loadfile);
    } // setupUi

    void retranslateUi(QDialog *form_loadfile)
    {
        form_loadfile->setWindowTitle(QApplication::translate("form_loadfile", "form_loadfile", 0));
        pbLoadInfos->setFormat(QString());
        lblAmountInfos->setText(QApplication::translate("form_loadfile", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class form_loadfile: public Ui_form_loadfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_LOADFILE_H
