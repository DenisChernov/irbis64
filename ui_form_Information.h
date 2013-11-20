/********************************************************************************
** Form generated from reading UI file 'form_Information.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_INFORMATION_H
#define UI_FORM_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_form_Information
{
public:
    QGroupBox *gbParametrs;
    QGroupBox *gbChose;
    QComboBox *cbType_6;
    QLabel *lblTarget_4;
    QComboBox *cbTarget_4;
    QLabel *lblType_6;
    QGroupBox *gbParametrsReg;
    QGroupBox *gbSource;
    QCheckBox *cbAK;
    QCheckBox *cbCK;
    QCheckBox *cbCKC;
    QCheckBox *cbKnF;
    QCheckBox *cbAC2Krai;
    QCheckBox *cbCF;
    QCheckBox *cbIRBIS_CKC;
    QCheckBox *cbIRBIS_EK;
    QCheckBox *cbConsultant;
    QCheckBox *cbCodecs;
    QCheckBox *cbInternet;
    QCheckBox *cbAC2CKC;
    QCheckBox *cbFSO;
    QCheckBox *cbGarant;
    QGroupBox *gbStat;
    QGroupBox *gbStatByTarget;
    QLabel *lblStudy_4;
    QLineEdit *leStudy_4;
    QLineEdit *leSpecial_4;
    QLabel *lblSpecial_4;
    QLabel *lblDosug_4;
    QLineEdit *leDosug_4;
    QLineEdit *leSelfStudy_4;
    QLabel *lblSelfStudy_4;
    QGroupBox *gbStatByType;
    QLineEdit *leAddresBiblio_6;
    QLineEdit *leYtochn_6;
    QLineEdit *leTemat_6;
    QLabel *lblFactograf_6;
    QLabel *lblYtochn_6;
    QLabel *lblAdressBiblio_6;
    QLabel *lblTemat_6;
    QLineEdit *leFactograf_6;
    QLabel *lblSocio_6;
    QLineEdit *leSocio_6;
    QPushButton *pbSearch;
    QTableWidget *twInfosInIrbis64;
    QFrame *line;
    QTableWidget *twInfosChosed;
    QPushButton *pbAdd;
    QFrame *line_2;
    QPushButton *pbRemove;
    QPushButton *pbSendInfosToIrbis64;
    QGroupBox *gbCreateBDMsg;
    QProgressBar *pbProgress;
    QLabel *label;
    QLabel *lblAmountInfo;
    QLabel *lblFilial;
    QComboBox *cbFilial;
    QGroupBox *gbInSearching;
    QTextBrowser *textBrowser;
    QLabel *lblInSearching;
    QLabel *lblInfoStatus;

    void setupUi(QDialog *form_Information)
    {
        if (form_Information->objectName().isEmpty())
            form_Information->setObjectName(QStringLiteral("form_Information"));
        form_Information->setEnabled(true);
        form_Information->resize(500, 656);
        form_Information->setMaximumSize(QSize(500, 656));
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
        form_Information->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral("images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        form_Information->setWindowIcon(icon);
        gbParametrs = new QGroupBox(form_Information);
        gbParametrs->setObjectName(QStringLiteral("gbParametrs"));
        gbParametrs->setGeometry(QRect(10, 26, 481, 211));
        gbChose = new QGroupBox(gbParametrs);
        gbChose->setObjectName(QStringLiteral("gbChose"));
        gbChose->setGeometry(QRect(10, 20, 461, 51));
        cbType_6 = new QComboBox(gbChose);
        cbType_6->setObjectName(QStringLiteral("cbType_6"));
        cbType_6->setGeometry(QRect(290, 20, 161, 18));
        lblTarget_4 = new QLabel(gbChose);
        lblTarget_4->setObjectName(QStringLiteral("lblTarget_4"));
        lblTarget_4->setGeometry(QRect(7, 21, 81, 16));
        cbTarget_4 = new QComboBox(gbChose);
        cbTarget_4->setObjectName(QStringLiteral("cbTarget_4"));
        cbTarget_4->setGeometry(QRect(87, 20, 121, 18));
        lblType_6 = new QLabel(gbChose);
        lblType_6->setObjectName(QStringLiteral("lblType_6"));
        lblType_6->setGeometry(QRect(217, 21, 81, 16));
        gbParametrsReg = new QGroupBox(gbParametrs);
        gbParametrsReg->setObjectName(QStringLiteral("gbParametrsReg"));
        gbParametrsReg->setGeometry(QRect(10, 80, 461, 121));
        gbSource = new QGroupBox(gbParametrsReg);
        gbSource->setObjectName(QStringLiteral("gbSource"));
        gbSource->setGeometry(QRect(10, 20, 441, 91));
        cbAK = new QCheckBox(gbSource);
        cbAK->setObjectName(QStringLiteral("cbAK"));
        cbAK->setGeometry(QRect(10, 20, 41, 17));
        cbCK = new QCheckBox(gbSource);
        cbCK->setObjectName(QStringLiteral("cbCK"));
        cbCK->setGeometry(QRect(10, 40, 41, 17));
        cbCKC = new QCheckBox(gbSource);
        cbCKC->setObjectName(QStringLiteral("cbCKC"));
        cbCKC->setGeometry(QRect(10, 60, 41, 17));
        cbKnF = new QCheckBox(gbSource);
        cbKnF->setObjectName(QStringLiteral("cbKnF"));
        cbKnF->setGeometry(QRect(53, 40, 51, 17));
        cbAC2Krai = new QCheckBox(gbSource);
        cbAC2Krai->setObjectName(QStringLiteral("cbAC2Krai"));
        cbAC2Krai->setGeometry(QRect(53, 60, 71, 17));
        cbCF = new QCheckBox(gbSource);
        cbCF->setObjectName(QStringLiteral("cbCF"));
        cbCF->setGeometry(QRect(53, 20, 41, 17));
        cbIRBIS_CKC = new QCheckBox(gbSource);
        cbIRBIS_CKC->setObjectName(QStringLiteral("cbIRBIS_CKC"));
        cbIRBIS_CKC->setGeometry(QRect(130, 60, 91, 17));
        cbIRBIS_EK = new QCheckBox(gbSource);
        cbIRBIS_EK->setObjectName(QStringLiteral("cbIRBIS_EK"));
        cbIRBIS_EK->setGeometry(QRect(130, 40, 81, 17));
        cbConsultant = new QCheckBox(gbSource);
        cbConsultant->setObjectName(QStringLiteral("cbConsultant"));
        cbConsultant->setGeometry(QRect(220, 40, 91, 17));
        cbCodecs = new QCheckBox(gbSource);
        cbCodecs->setObjectName(QStringLiteral("cbCodecs"));
        cbCodecs->setGeometry(QRect(220, 60, 71, 17));
        cbInternet = new QCheckBox(gbSource);
        cbInternet->setObjectName(QStringLiteral("cbInternet"));
        cbInternet->setGeometry(QRect(220, 20, 71, 17));
        cbAC2CKC = new QCheckBox(gbSource);
        cbAC2CKC->setObjectName(QStringLiteral("cbAC2CKC"));
        cbAC2CKC->setGeometry(QRect(130, 20, 71, 17));
        cbFSO = new QCheckBox(gbSource);
        cbFSO->setObjectName(QStringLiteral("cbFSO"));
        cbFSO->setGeometry(QRect(310, 40, 91, 17));
        cbGarant = new QCheckBox(gbSource);
        cbGarant->setObjectName(QStringLiteral("cbGarant"));
        cbGarant->setGeometry(QRect(310, 20, 71, 17));
        gbStat = new QGroupBox(form_Information);
        gbStat->setObjectName(QStringLiteral("gbStat"));
        gbStat->setGeometry(QRect(510, 190, 481, 141));
        gbStatByTarget = new QGroupBox(gbStat);
        gbStatByTarget->setObjectName(QStringLiteral("gbStatByTarget"));
        gbStatByTarget->setGeometry(QRect(10, 20, 201, 111));
        lblStudy_4 = new QLabel(gbStatByTarget);
        lblStudy_4->setObjectName(QStringLiteral("lblStudy_4"));
        lblStudy_4->setGeometry(QRect(10, 19, 46, 13));
        leStudy_4 = new QLineEdit(gbStatByTarget);
        leStudy_4->setObjectName(QStringLiteral("leStudy_4"));
        leStudy_4->setGeometry(QRect(110, 18, 61, 18));
        leSpecial_4 = new QLineEdit(gbStatByTarget);
        leSpecial_4->setObjectName(QStringLiteral("leSpecial_4"));
        leSpecial_4->setGeometry(QRect(110, 36, 61, 18));
        lblSpecial_4 = new QLabel(gbStatByTarget);
        lblSpecial_4->setObjectName(QStringLiteral("lblSpecial_4"));
        lblSpecial_4->setGeometry(QRect(10, 36, 81, 16));
        lblDosug_4 = new QLabel(gbStatByTarget);
        lblDosug_4->setObjectName(QStringLiteral("lblDosug_4"));
        lblDosug_4->setGeometry(QRect(10, 54, 81, 16));
        leDosug_4 = new QLineEdit(gbStatByTarget);
        leDosug_4->setObjectName(QStringLiteral("leDosug_4"));
        leDosug_4->setGeometry(QRect(110, 53, 61, 18));
        leSelfStudy_4 = new QLineEdit(gbStatByTarget);
        leSelfStudy_4->setObjectName(QStringLiteral("leSelfStudy_4"));
        leSelfStudy_4->setGeometry(QRect(110, 70, 61, 18));
        lblSelfStudy_4 = new QLabel(gbStatByTarget);
        lblSelfStudy_4->setObjectName(QStringLiteral("lblSelfStudy_4"));
        lblSelfStudy_4->setGeometry(QRect(10, 71, 101, 16));
        gbStatByType = new QGroupBox(gbStat);
        gbStatByType->setObjectName(QStringLiteral("gbStatByType"));
        gbStatByType->setGeometry(QRect(220, 20, 251, 111));
        leAddresBiblio_6 = new QLineEdit(gbStatByType);
        leAddresBiblio_6->setObjectName(QStringLiteral("leAddresBiblio_6"));
        leAddresBiblio_6->setGeometry(QRect(170, 70, 61, 18));
        leYtochn_6 = new QLineEdit(gbStatByType);
        leYtochn_6->setObjectName(QStringLiteral("leYtochn_6"));
        leYtochn_6->setGeometry(QRect(170, 36, 61, 18));
        leTemat_6 = new QLineEdit(gbStatByType);
        leTemat_6->setObjectName(QStringLiteral("leTemat_6"));
        leTemat_6->setGeometry(QRect(170, 18, 61, 18));
        lblFactograf_6 = new QLabel(gbStatByType);
        lblFactograf_6->setObjectName(QStringLiteral("lblFactograf_6"));
        lblFactograf_6->setGeometry(QRect(10, 54, 101, 16));
        lblYtochn_6 = new QLabel(gbStatByType);
        lblYtochn_6->setObjectName(QStringLiteral("lblYtochn_6"));
        lblYtochn_6->setGeometry(QRect(10, 36, 81, 16));
        lblAdressBiblio_6 = new QLabel(gbStatByType);
        lblAdressBiblio_6->setObjectName(QStringLiteral("lblAdressBiblio_6"));
        lblAdressBiblio_6->setGeometry(QRect(10, 71, 151, 16));
        lblTemat_6 = new QLabel(gbStatByType);
        lblTemat_6->setObjectName(QStringLiteral("lblTemat_6"));
        lblTemat_6->setGeometry(QRect(10, 19, 81, 16));
        leFactograf_6 = new QLineEdit(gbStatByType);
        leFactograf_6->setObjectName(QStringLiteral("leFactograf_6"));
        leFactograf_6->setGeometry(QRect(170, 53, 61, 18));
        lblSocio_6 = new QLabel(gbStatByType);
        lblSocio_6->setObjectName(QStringLiteral("lblSocio_6"));
        lblSocio_6->setGeometry(QRect(10, 90, 71, 16));
        leSocio_6 = new QLineEdit(gbStatByType);
        leSocio_6->setObjectName(QStringLiteral("leSocio_6"));
        leSocio_6->setGeometry(QRect(170, 88, 61, 18));
        pbSearch = new QPushButton(form_Information);
        pbSearch->setObjectName(QStringLiteral("pbSearch"));
        pbSearch->setGeometry(QRect(10, 241, 481, 23));
        twInfosInIrbis64 = new QTableWidget(form_Information);
        twInfosInIrbis64->setObjectName(QStringLiteral("twInfosInIrbis64"));
        twInfosInIrbis64->setGeometry(QRect(10, 272, 481, 161));
        twInfosInIrbis64->setStyleSheet(QLatin1String("QTableWidget::item {\n"
"    border: 1px solid #d9d9d9;\n"
"    border-top-color: transparent;\n"
"    border-bottom-color: transparent;\n"
"}\n"
" \n"
"QTableWidget::item:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);\n"
"    border: 1px solid #bfcde4;\n"
"}\n"
" \n"
"QTableWidget::item:selected {\n"
"    border: 1px solid #567dbc;\n"
"}\n"
" \n"
"QTableWidget::item:selected:active{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);\n"
"}\n"
" \n"
"QTableWidget::item:selected:!active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6b9be8, stop: 1 #577fbf);\n"
"}"));
        line = new QFrame(form_Information);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 436, 481, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        twInfosChosed = new QTableWidget(form_Information);
        twInfosChosed->setObjectName(QStringLiteral("twInfosChosed"));
        twInfosChosed->setGeometry(QRect(10, 456, 481, 171));
        twInfosChosed->setStyleSheet(QLatin1String("QTableWidget::item {\n"
"    border: 1px solid #d9d9d9;\n"
"    border-top-color: transparent;\n"
"    border-bottom-color: transparent;\n"
"}\n"
" \n"
"QTableWidget::item:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);\n"
"    border: 1px solid #bfcde4;\n"
"}\n"
" \n"
"QTableWidget::item:selected {\n"
"    border: 1px solid #567dbc;\n"
"}\n"
" \n"
"QTableWidget::item:selected:active{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);\n"
"}\n"
" \n"
"QTableWidget::item:selected:!active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6b9be8, stop: 1 #577fbf);\n"
"}"));
        pbAdd = new QPushButton(form_Information);
        pbAdd->setObjectName(QStringLiteral("pbAdd"));
        pbAdd->setGeometry(QRect(370, 436, 75, 18));
        line_2 = new QFrame(form_Information);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 630, 481, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pbRemove = new QPushButton(form_Information);
        pbRemove->setObjectName(QStringLiteral("pbRemove"));
        pbRemove->setGeometry(QRect(370, 630, 75, 18));
        pbSendInfosToIrbis64 = new QPushButton(form_Information);
        pbSendInfosToIrbis64->setObjectName(QStringLiteral("pbSendInfosToIrbis64"));
        pbSendInfosToIrbis64->setGeometry(QRect(30, 630, 75, 18));
        gbCreateBDMsg = new QGroupBox(form_Information);
        gbCreateBDMsg->setObjectName(QStringLiteral("gbCreateBDMsg"));
        gbCreateBDMsg->setGeometry(QRect(510, 50, 281, 111));
        pbProgress = new QProgressBar(gbCreateBDMsg);
        pbProgress->setObjectName(QStringLiteral("pbProgress"));
        pbProgress->setGeometry(QRect(20, 77, 241, 23));
        pbProgress->setMaximum(100);
        pbProgress->setValue(24);
        pbProgress->setTextVisible(false);
        label = new QLabel(gbCreateBDMsg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 16, 221, 51));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(0);
        label->setAlignment(Qt::AlignCenter);
        lblAmountInfo = new QLabel(gbCreateBDMsg);
        lblAmountInfo->setObjectName(QStringLiteral("lblAmountInfo"));
        lblAmountInfo->setGeometry(QRect(120, 82, 46, 13));
        lblAmountInfo->setAlignment(Qt::AlignCenter);
        lblFilial = new QLabel(form_Information);
        lblFilial->setObjectName(QStringLiteral("lblFilial"));
        lblFilial->setGeometry(QRect(240, 6, 81, 16));
        cbFilial = new QComboBox(form_Information);
        cbFilial->setObjectName(QStringLiteral("cbFilial"));
        cbFilial->setGeometry(QRect(320, 4, 91, 18));
        gbInSearching = new QGroupBox(form_Information);
        gbInSearching->setObjectName(QStringLiteral("gbInSearching"));
        gbInSearching->setGeometry(QRect(130, 220, 251, 71));
        textBrowser = new QTextBrowser(gbInSearching);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 251, 71));
        textBrowser->setFrameShape(QFrame::StyledPanel);
        textBrowser->setFrameShadow(QFrame::Sunken);
        lblInSearching = new QLabel(gbInSearching);
        lblInSearching->setObjectName(QStringLiteral("lblInSearching"));
        lblInSearching->setGeometry(QRect(40, 20, 181, 31));
        QFont font;
        font.setFamily(QStringLiteral("Monotype Corsiva"));
        font.setPointSize(18);
        lblInSearching->setFont(font);
        lblInfoStatus = new QLabel(form_Information);
        lblInfoStatus->setObjectName(QStringLiteral("lblInfoStatus"));
        lblInfoStatus->setGeometry(QRect(18, 7, 171, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lblInfoStatus->setFont(font1);
        twInfosInIrbis64->raise();
        twInfosChosed->raise();
        gbParametrs->raise();
        gbStat->raise();
        pbSearch->raise();
        line->raise();
        pbAdd->raise();
        line_2->raise();
        pbRemove->raise();
        pbSendInfosToIrbis64->raise();
        gbCreateBDMsg->raise();
        lblFilial->raise();
        cbFilial->raise();
        gbInSearching->raise();
        lblInfoStatus->raise();

        retranslateUi(form_Information);

        cbType_6->setCurrentIndex(0);
        cbTarget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(form_Information);
    } // setupUi

    void retranslateUi(QDialog *form_Information)
    {
        form_Information->setWindowTitle(QApplication::translate("form_Information", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\320\267\320\260\321\202\320\276\321\200 \321\201\320\277\321\200\320\260\320\262\320\276\320\272 <Development> Follow The Blind", 0));
        gbParametrs->setTitle(QApplication::translate("form_Information", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\277\321\200\320\260\320\262\320\276\320\272", 0));
        gbChose->setTitle(QApplication::translate("form_Information", "\320\232\321\200\320\270\321\202\320\265\321\200\320\270\320\270 \320\262\321\213\320\261\320\276\321\200\320\260", 0));
        cbType_6->clear();
        cbType_6->insertItems(0, QStringList()
         << QApplication::translate("form_Information", "\320\242\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\320\243\321\202\320\276\321\207\320\275\321\217\321\216\321\211\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\320\244\320\260\320\272\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\320\220\320\264\321\200\320\265\321\201\320\275\320\276-\320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\320\241\320\276\321\206\320\270\320\260\320\273\321\214\320\275\320\260\321\217", 0)
        );
        lblTarget_4->setText(QApplication::translate("form_Information", "\320\246\320\265\320\273\321\214 \320\267\320\260\320\277\321\200\320\276\321\201\320\260:", 0));
        cbTarget_4->clear();
        cbTarget_4->insertItems(0, QStringList()
         << QApplication::translate("form_Information", "\321\203\321\207\320\265\320\261\320\275\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\320\264\320\276\321\201\321\203\320\263\320\276\320\262\320\260\321\217", 0)
         << QApplication::translate("form_Information", "\321\201\320\260\320\274\320\276\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265", 0)
        );
        lblType_6->setText(QApplication::translate("form_Information", "\320\242\320\270\320\277 \321\201\320\277\321\200\320\260\320\262\320\272\320\270:", 0));
        gbParametrsReg->setTitle(QApplication::translate("form_Information", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \321\201\320\277\321\200\320\260\320\262\320\276\320\272", 0));
        gbSource->setTitle(QApplication::translate("form_Information", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", 0));
        cbAK->setText(QApplication::translate("form_Information", "\320\220\320\232", 0));
        cbCK->setText(QApplication::translate("form_Information", "\320\241\320\232", 0));
        cbCKC->setText(QApplication::translate("form_Information", "\320\241\320\232\320\241", 0));
        cbKnF->setText(QApplication::translate("form_Information", "\320\232\320\275.\320\244.", 0));
        cbAC2Krai->setText(QApplication::translate("form_Information", "\320\220\320\241-2 \320\232\321\200\320\260\320\271", 0));
        cbCF->setText(QApplication::translate("form_Information", "\320\241\320\244", 0));
        cbIRBIS_CKC->setText(QApplication::translate("form_Information", "\320\230\320\240\320\221\320\230\320\241 - \320\241\320\232\320\241", 0));
        cbIRBIS_EK->setText(QApplication::translate("form_Information", "\320\230\320\240\320\221\320\230\320\241 - \320\255\320\232", 0));
        cbConsultant->setText(QApplication::translate("form_Information", "\320\232\320\276\320\275\321\201\321\203\320\273\321\214\321\202\320\260\320\275\321\202", 0));
        cbCodecs->setText(QApplication::translate("form_Information", "\320\232\320\276\320\264\320\265\320\272\321\201", 0));
        cbInternet->setText(QApplication::translate("form_Information", "\320\230\320\275\321\202\320\265\321\200\320\275\320\265\321\202", 0));
        cbAC2CKC->setText(QApplication::translate("form_Information", "\320\220\320\241-2 \320\241\320\232\320\241", 0));
        cbFSO->setText(QApplication::translate("form_Information", "\320\244\320\241\320\236", 0));
        cbGarant->setText(QApplication::translate("form_Information", "\320\223\320\260\321\200\320\260\320\275\321\202", 0));
        gbStat->setTitle(QApplication::translate("form_Information", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \321\201\320\277\321\200\320\260\320\262\320\276\320\272", 0));
        gbStatByTarget->setTitle(QApplication::translate("form_Information", "\320\237\320\276 \321\206\320\265\320\273\320\270", 0));
        lblStudy_4->setText(QApplication::translate("form_Information", "\321\203\321\207\320\265\320\261\320\275\320\260\321\217", 0));
        leStudy_4->setText(QApplication::translate("form_Information", "0", 0));
        leSpecial_4->setText(QApplication::translate("form_Information", "0", 0));
        lblSpecial_4->setText(QApplication::translate("form_Information", "\321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\260\321\217", 0));
        lblDosug_4->setText(QApplication::translate("form_Information", "\320\264\320\276\321\201\321\203\320\263\320\276\320\262\320\260\321\217", 0));
        leDosug_4->setText(QApplication::translate("form_Information", "0", 0));
        leSelfStudy_4->setText(QApplication::translate("form_Information", "0", 0));
        lblSelfStudy_4->setText(QApplication::translate("form_Information", "\321\201\320\260\320\274\320\276\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        gbStatByType->setTitle(QApplication::translate("form_Information", "\320\237\320\276 \321\202\320\270\320\277\321\203", 0));
        leAddresBiblio_6->setText(QApplication::translate("form_Information", "0", 0));
        leYtochn_6->setText(QApplication::translate("form_Information", "0", 0));
        leTemat_6->setText(QApplication::translate("form_Information", "0", 0));
        lblFactograf_6->setText(QApplication::translate("form_Information", "\320\244\320\260\320\272\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217", 0));
        lblYtochn_6->setText(QApplication::translate("form_Information", "\320\243\321\202\320\276\321\207\320\275\321\217\321\216\321\211\320\260\321\217", 0));
        lblAdressBiblio_6->setText(QApplication::translate("form_Information", "\320\220\320\264\321\200\320\265\321\201\320\275\320\276-\320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217", 0));
        lblTemat_6->setText(QApplication::translate("form_Information", "\320\242\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217", 0));
        leFactograf_6->setText(QApplication::translate("form_Information", "0", 0));
        lblSocio_6->setText(QApplication::translate("form_Information", "\320\241\320\276\321\206\320\270\320\260\320\273\321\214\320\275\320\260\321\217", 0));
        leSocio_6->setText(QApplication::translate("form_Information", "0", 0));
        pbSearch->setText(QApplication::translate("form_Information", "\320\230\321\201\320\272\320\260\321\202\321\214", 0));
        pbAdd->setText(QApplication::translate("form_Information", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pbRemove->setText(QApplication::translate("form_Information", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pbSendInfosToIrbis64->setText(QApplication::translate("form_Information", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0));
        gbCreateBDMsg->setTitle(QString());
        pbProgress->setFormat(QString());
        label->setText(QApplication::translate("form_Information", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265 \321\201\320\277\321\200\320\260\320\262\320\276\320\272 \320\270\320\267 IRBIS64.\n"
"\320\222 \320\277\320\265\321\200\320\262\321\213\320\271 \321\200\320\260\320\267 \321\215\321\202\320\276 \320\264\320\273\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\321\206\320\265\321\201\321\201.\n"
"\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260 \320\266\320\264\320\270\321\202\320\265.", 0));
        lblAmountInfo->setText(QApplication::translate("form_Information", "0", 0));
        lblFilial->setText(QApplication::translate("form_Information", "Maker:", 0));
        gbInSearching->setTitle(QString());
        lblInSearching->setText(QApplication::translate("form_Information", "\320\222\321\213\320\261\320\276\321\200\320\272\320\260... \320\266\320\264\320\270\321\202\320\265...", 0));
        lblInfoStatus->setText(QApplication::translate("form_Information", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\201\320\277\321\200\320\260\320\262\320\276\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class form_Information: public Ui_form_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_INFORMATION_H
