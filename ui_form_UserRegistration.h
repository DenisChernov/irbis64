/********************************************************************************
** Form generated from reading UI file 'form_UserRegistration.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_USERREGISTRATION_H
#define UI_FORM_USERREGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_form_UserRegistration
{
public:
    QGroupBox *gbNewUserReg;
    QLabel *lblFam;
    QLineEdit *leFam_10;
    QLineEdit *leName_11;
    QLabel *lblName;
    QLineEdit *leSurname_12;
    QLabel *lblSurname;
    QLabel *lblBirthYear;
    QLineEdit *leBirthYear_21;
    QComboBox *cbAdditionalCategory_67;
    QGroupBox *gbuserFoto;
    QPushButton *pbBrowseFoto;
    QPushButton *pbScanFoto;
    QLabel *lblUserFoto;
    QPushButton *pbRequest;
    QComboBox *cbCategory_50;
    QLineEdit *leTelNumber_Home_17;
    QLabel *lblTelNumber;
    QLineEdit *leTelNumber_Work_18;
    QGroupBox *gbPassport_14;
    QGroupBox *gbPassport_SerialNumber_14;
    QLineEdit *leSerial_14;
    QLineEdit *leNumber_14;
    QGroupBox *gbDataOfIssue_14;
    QDateEdit *deDateOfIssue_14;
    QGroupBox *gbPlaceOfIssue_14;
    QComboBox *cbPlaceOfIssue_14;
    QGroupBox *gbRegistrationAddress_14;
    QGroupBox *gbCity_14;
    QComboBox *cbCity_14;
    QGroupBox *gbStreet_14;
    QComboBox *cbStreet_14;
    QGroupBox *gbHomeNumber_14;
    QLineEdit *leHouseNumber_14;
    QGroupBox *gbAppNumber_14;
    QLineEdit *leAppNumber_14;
    QGroupBox *gbHomeAddress_13;
    QGroupBox *gbCity_13;
    QComboBox *cbCity_13;
    QGroupBox *gbStreet_13;
    QComboBox *cbStreet_13;
    QGroupBox *gbHouseNumber_13;
    QLineEdit *leHouseNumber_13;
    QGroupBox *gbAppNumber_13;
    QLineEdit *leAppNumber_13;
    QGroupBox *gbOptions;
    QCheckBox *cbAddressRegistration;
    QPushButton *pbSendToServer;
    QPushButton *pbClearForm;
    QCheckBox *cbDontHavePassport;
    QCheckBox *cbContract;
    QCheckBox *cbEF_691;
    QCheckBox *cbSPS_691;
    QCheckBox *cbMBA_691;
    QComboBox *cbEducation_20;
    QLabel *lblEducation;
    QLabel *lblAdditionalCategory;
    QGroupBox *gbTeachPlace_19;
    QGroupBox *gbTeachPlaceName_19;
    QComboBox *cbTeachPlaceName_19;
    QGroupBox *gbStudy_19;
    QComboBox *cbStudy_19;
    QGroupBox *gbClass_19;
    QLineEdit *leClass_19;
    QGroupBox *gbWorkPlace_15;
    QGroupBox *gbWorkPlaceName_15;
    QLineEdit *leWorkPlaceName_15;
    QGroupBox *gbJob_16;
    QLineEdit *leJob_16;
    QGroupBox *gbFilial;
    QComboBox *cbFilial;
    QLabel *lblTelNumber_work;
    QLabel *lblTelNumber_home;

    void setupUi(QDialog *form_UserRegistration)
    {
        if (form_UserRegistration->objectName().isEmpty())
            form_UserRegistration->setObjectName(QStringLiteral("form_UserRegistration"));
        form_UserRegistration->setEnabled(true);
        form_UserRegistration->resize(631, 718);
        form_UserRegistration->setMinimumSize(QSize(0, 498));
        form_UserRegistration->setMaximumSize(QSize(631, 718));
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
        form_UserRegistration->setPalette(palette);
        form_UserRegistration->setSizeGripEnabled(false);
        form_UserRegistration->setModal(false);
        gbNewUserReg = new QGroupBox(form_UserRegistration);
        gbNewUserReg->setObjectName(QStringLiteral("gbNewUserReg"));
        gbNewUserReg->setGeometry(QRect(4, 0, 621, 711));
        lblFam = new QLabel(gbNewUserReg);
        lblFam->setObjectName(QStringLiteral("lblFam"));
        lblFam->setGeometry(QRect(20, 22, 51, 16));
        lblFam->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leFam_10 = new QLineEdit(gbNewUserReg);
        leFam_10->setObjectName(QStringLiteral("leFam_10"));
        leFam_10->setGeometry(QRect(80, 22, 301, 18));
        leFam_10->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leFam_10->setMaxLength(20);
        leFam_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        leName_11 = new QLineEdit(gbNewUserReg);
        leName_11->setObjectName(QStringLiteral("leName_11"));
        leName_11->setGeometry(QRect(80, 41, 301, 18));
        leName_11->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leName_11->setMaxLength(20);
        leName_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblName = new QLabel(gbNewUserReg);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(40, 40, 31, 20));
        lblName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leSurname_12 = new QLineEdit(gbNewUserReg);
        leSurname_12->setObjectName(QStringLiteral("leSurname_12"));
        leSurname_12->setGeometry(QRect(80, 60, 301, 18));
        leSurname_12->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leSurname_12->setMaxLength(20);
        lblSurname = new QLabel(gbNewUserReg);
        lblSurname->setObjectName(QStringLiteral("lblSurname"));
        lblSurname->setGeometry(QRect(10, 60, 61, 16));
        lblSurname->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblBirthYear = new QLabel(gbNewUserReg);
        lblBirthYear->setObjectName(QStringLiteral("lblBirthYear"));
        lblBirthYear->setGeometry(QRect(10, 80, 61, 16));
        lblBirthYear->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leBirthYear_21 = new QLineEdit(gbNewUserReg);
        leBirthYear_21->setObjectName(QStringLiteral("leBirthYear_21"));
        leBirthYear_21->setGeometry(QRect(80, 79, 41, 18));
        leBirthYear_21->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leBirthYear_21->setInputMask(QStringLiteral(""));
        leBirthYear_21->setMaxLength(4);
        leBirthYear_21->setFrame(true);
        leBirthYear_21->setCursorPosition(0);
        cbAdditionalCategory_67 = new QComboBox(gbNewUserReg);
        cbAdditionalCategory_67->setObjectName(QStringLiteral("cbAdditionalCategory_67"));
        cbAdditionalCategory_67->setGeometry(QRect(130, 79, 251, 18));
        cbAdditionalCategory_67->setMaxVisibleItems(9);
        gbuserFoto = new QGroupBox(gbNewUserReg);
        gbuserFoto->setObjectName(QStringLiteral("gbuserFoto"));
        gbuserFoto->setGeometry(QRect(420, 40, 201, 251));
        pbBrowseFoto = new QPushButton(gbuserFoto);
        pbBrowseFoto->setObjectName(QStringLiteral("pbBrowseFoto"));
        pbBrowseFoto->setEnabled(false);
        pbBrowseFoto->setGeometry(QRect(18, 214, 75, 23));
        pbScanFoto = new QPushButton(gbuserFoto);
        pbScanFoto->setObjectName(QStringLiteral("pbScanFoto"));
        pbScanFoto->setEnabled(false);
        pbScanFoto->setGeometry(QRect(100, 214, 81, 23));
        lblUserFoto = new QLabel(gbuserFoto);
        lblUserFoto->setObjectName(QStringLiteral("lblUserFoto"));
        lblUserFoto->setGeometry(QRect(10, 20, 181, 181));
        lblUserFoto->setPixmap(QPixmap(QString::fromUtf8("images/nofoto.png")));
        lblUserFoto->setScaledContents(true);
        pbRequest = new QPushButton(gbuserFoto);
        pbRequest->setObjectName(QStringLiteral("pbRequest"));
        pbRequest->setEnabled(false);
        pbRequest->setGeometry(QRect(40, 190, 121, 23));
        cbCategory_50 = new QComboBox(gbNewUserReg);
        cbCategory_50->setObjectName(QStringLiteral("cbCategory_50"));
        cbCategory_50->setGeometry(QRect(130, 100, 251, 18));
        cbCategory_50->setStyleSheet(QStringLiteral(""));
        cbCategory_50->setMaxVisibleItems(14);
        leTelNumber_Home_17 = new QLineEdit(gbNewUserReg);
        leTelNumber_Home_17->setObjectName(QStringLiteral("leTelNumber_Home_17"));
        leTelNumber_Home_17->setGeometry(QRect(120, 140, 121, 18));
        leTelNumber_Home_17->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leTelNumber_Home_17->setInputMask(QStringLiteral(""));
        leTelNumber_Home_17->setMaxLength(11);
        leTelNumber_Home_17->setFrame(true);
        leTelNumber_Home_17->setCursorPosition(0);
        leTelNumber_Home_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblTelNumber = new QLabel(gbNewUserReg);
        lblTelNumber->setObjectName(QStringLiteral("lblTelNumber"));
        lblTelNumber->setGeometry(QRect(10, 141, 61, 16));
        lblTelNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leTelNumber_Work_18 = new QLineEdit(gbNewUserReg);
        leTelNumber_Work_18->setObjectName(QStringLiteral("leTelNumber_Work_18"));
        leTelNumber_Work_18->setGeometry(QRect(280, 140, 101, 18));
        leTelNumber_Work_18->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leTelNumber_Work_18->setInputMask(QStringLiteral(""));
        leTelNumber_Work_18->setMaxLength(11);
        leTelNumber_Work_18->setFrame(true);
        leTelNumber_Work_18->setCursorPosition(0);
        gbPassport_14 = new QGroupBox(gbNewUserReg);
        gbPassport_14->setObjectName(QStringLiteral("gbPassport_14"));
        gbPassport_14->setGeometry(QRect(0, 490, 411, 221));
        gbPassport_SerialNumber_14 = new QGroupBox(gbPassport_14);
        gbPassport_SerialNumber_14->setObjectName(QStringLiteral("gbPassport_SerialNumber_14"));
        gbPassport_SerialNumber_14->setGeometry(QRect(40, 20, 211, 41));
        leSerial_14 = new QLineEdit(gbPassport_SerialNumber_14);
        leSerial_14->setObjectName(QStringLiteral("leSerial_14"));
        leSerial_14->setGeometry(QRect(10, 16, 71, 18));
        leSerial_14->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leSerial_14->setMaxLength(4);
        leNumber_14 = new QLineEdit(gbPassport_SerialNumber_14);
        leNumber_14->setObjectName(QStringLiteral("leNumber_14"));
        leNumber_14->setGeometry(QRect(90, 16, 111, 18));
        leNumber_14->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbDataOfIssue_14 = new QGroupBox(gbPassport_14);
        gbDataOfIssue_14->setObjectName(QStringLiteral("gbDataOfIssue_14"));
        gbDataOfIssue_14->setGeometry(QRect(260, 20, 111, 41));
        deDateOfIssue_14 = new QDateEdit(gbDataOfIssue_14);
        deDateOfIssue_14->setObjectName(QStringLiteral("deDateOfIssue_14"));
        deDateOfIssue_14->setGeometry(QRect(10, 16, 91, 18));
        deDateOfIssue_14->setStyleSheet(QLatin1String("QDateEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        deDateOfIssue_14->setAlignment(Qt::AlignCenter);
        deDateOfIssue_14->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        deDateOfIssue_14->setCurrentSection(QDateTimeEdit::YearSection);
        deDateOfIssue_14->setCalendarPopup(true);
        gbPlaceOfIssue_14 = new QGroupBox(gbPassport_14);
        gbPlaceOfIssue_14->setObjectName(QStringLiteral("gbPlaceOfIssue_14"));
        gbPlaceOfIssue_14->setGeometry(QRect(10, 60, 391, 51));
        cbPlaceOfIssue_14 = new QComboBox(gbPlaceOfIssue_14);
        cbPlaceOfIssue_14->setObjectName(QStringLiteral("cbPlaceOfIssue_14"));
        cbPlaceOfIssue_14->setGeometry(QRect(10, 20, 371, 18));
        cbPlaceOfIssue_14->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbPlaceOfIssue_14->setEditable(true);
        gbRegistrationAddress_14 = new QGroupBox(gbPassport_14);
        gbRegistrationAddress_14->setObjectName(QStringLiteral("gbRegistrationAddress_14"));
        gbRegistrationAddress_14->setGeometry(QRect(0, 110, 401, 111));
        gbCity_14 = new QGroupBox(gbRegistrationAddress_14);
        gbCity_14->setObjectName(QStringLiteral("gbCity_14"));
        gbCity_14->setGeometry(QRect(9, 20, 381, 41));
        cbCity_14 = new QComboBox(gbCity_14);
        cbCity_14->setObjectName(QStringLiteral("cbCity_14"));
        cbCity_14->setGeometry(QRect(10, 16, 361, 18));
        cbCity_14->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbCity_14->setEditable(true);
        gbStreet_14 = new QGroupBox(gbRegistrationAddress_14);
        gbStreet_14->setObjectName(QStringLiteral("gbStreet_14"));
        gbStreet_14->setGeometry(QRect(10, 60, 281, 41));
        cbStreet_14 = new QComboBox(gbStreet_14);
        cbStreet_14->setObjectName(QStringLiteral("cbStreet_14"));
        cbStreet_14->setGeometry(QRect(10, 16, 241, 18));
        cbStreet_14->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbStreet_14->setEditable(true);
        gbHomeNumber_14 = new QGroupBox(gbRegistrationAddress_14);
        gbHomeNumber_14->setObjectName(QStringLiteral("gbHomeNumber_14"));
        gbHomeNumber_14->setGeometry(QRect(300, 60, 41, 41));
        leHouseNumber_14 = new QLineEdit(gbHomeNumber_14);
        leHouseNumber_14->setObjectName(QStringLiteral("leHouseNumber_14"));
        leHouseNumber_14->setGeometry(QRect(6, 16, 30, 18));
        leHouseNumber_14->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbAppNumber_14 = new QGroupBox(gbRegistrationAddress_14);
        gbAppNumber_14->setObjectName(QStringLiteral("gbAppNumber_14"));
        gbAppNumber_14->setGeometry(QRect(350, 60, 41, 41));
        leAppNumber_14 = new QLineEdit(gbAppNumber_14);
        leAppNumber_14->setObjectName(QStringLiteral("leAppNumber_14"));
        leAppNumber_14->setGeometry(QRect(6, 16, 30, 18));
        leAppNumber_14->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbHomeAddress_13 = new QGroupBox(gbNewUserReg);
        gbHomeAddress_13->setObjectName(QStringLiteral("gbHomeAddress_13"));
        gbHomeAddress_13->setGeometry(QRect(0, 160, 411, 111));
        gbCity_13 = new QGroupBox(gbHomeAddress_13);
        gbCity_13->setObjectName(QStringLiteral("gbCity_13"));
        gbCity_13->setGeometry(QRect(20, 20, 361, 41));
        cbCity_13 = new QComboBox(gbCity_13);
        cbCity_13->setObjectName(QStringLiteral("cbCity_13"));
        cbCity_13->setGeometry(QRect(10, 16, 341, 18));
        cbCity_13->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbCity_13->setEditable(true);
        gbStreet_13 = new QGroupBox(gbHomeAddress_13);
        gbStreet_13->setObjectName(QStringLiteral("gbStreet_13"));
        gbStreet_13->setGeometry(QRect(10, 60, 281, 41));
        cbStreet_13 = new QComboBox(gbStreet_13);
        cbStreet_13->setObjectName(QStringLiteral("cbStreet_13"));
        cbStreet_13->setGeometry(QRect(10, 16, 261, 18));
        QFont font;
        font.setPointSize(8);
        cbStreet_13->setFont(font);
        cbStreet_13->setStyleSheet(QLatin1String("QComboBox {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        cbStreet_13->setEditable(true);
        gbHouseNumber_13 = new QGroupBox(gbHomeAddress_13);
        gbHouseNumber_13->setObjectName(QStringLiteral("gbHouseNumber_13"));
        gbHouseNumber_13->setGeometry(QRect(310, 60, 41, 41));
        leHouseNumber_13 = new QLineEdit(gbHouseNumber_13);
        leHouseNumber_13->setObjectName(QStringLiteral("leHouseNumber_13"));
        leHouseNumber_13->setGeometry(QRect(6, 16, 30, 18));
        leHouseNumber_13->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbAppNumber_13 = new QGroupBox(gbHomeAddress_13);
        gbAppNumber_13->setObjectName(QStringLiteral("gbAppNumber_13"));
        gbAppNumber_13->setGeometry(QRect(360, 60, 41, 41));
        leAppNumber_13 = new QLineEdit(gbAppNumber_13);
        leAppNumber_13->setObjectName(QStringLiteral("leAppNumber_13"));
        leAppNumber_13->setGeometry(QRect(6, 16, 30, 18));
        leAppNumber_13->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        leAppNumber_13->setMaxLength(3);
        gbOptions = new QGroupBox(gbNewUserReg);
        gbOptions->setObjectName(QStringLiteral("gbOptions"));
        gbOptions->setGeometry(QRect(420, 290, 181, 202));
        cbAddressRegistration = new QCheckBox(gbOptions);
        cbAddressRegistration->setObjectName(QStringLiteral("cbAddressRegistration"));
        cbAddressRegistration->setGeometry(QRect(40, 20, 101, 17));
        pbSendToServer = new QPushButton(gbOptions);
        pbSendToServer->setObjectName(QStringLiteral("pbSendToServer"));
        pbSendToServer->setEnabled(false);
        pbSendToServer->setGeometry(QRect(20, 140, 141, 23));
        pbSendToServer->setChecked(false);
        pbSendToServer->setAutoDefault(false);
        pbClearForm = new QPushButton(gbOptions);
        pbClearForm->setObjectName(QStringLiteral("pbClearForm"));
        pbClearForm->setGeometry(QRect(20, 170, 141, 23));
        pbClearForm->setAutoDefault(false);
        cbDontHavePassport = new QCheckBox(gbOptions);
        cbDontHavePassport->setObjectName(QStringLiteral("cbDontHavePassport"));
        cbDontHavePassport->setGeometry(QRect(40, 80, 121, 17));
        cbContract = new QCheckBox(gbOptions);
        cbContract->setObjectName(QStringLiteral("cbContract"));
        cbContract->setGeometry(QRect(40, 50, 101, 17));
        cbEF_691 = new QCheckBox(gbOptions);
        cbEF_691->setObjectName(QStringLiteral("cbEF_691"));
        cbEF_691->setGeometry(QRect(25, 110, 41, 17));
        cbSPS_691 = new QCheckBox(gbOptions);
        cbSPS_691->setObjectName(QStringLiteral("cbSPS_691"));
        cbSPS_691->setGeometry(QRect(75, 110, 41, 17));
        cbMBA_691 = new QCheckBox(gbOptions);
        cbMBA_691->setObjectName(QStringLiteral("cbMBA_691"));
        cbMBA_691->setGeometry(QRect(125, 110, 41, 17));
        cbEducation_20 = new QComboBox(gbNewUserReg);
        cbEducation_20->setObjectName(QStringLiteral("cbEducation_20"));
        cbEducation_20->setGeometry(QRect(130, 120, 251, 18));
        cbEducation_20->setMaxVisibleItems(8);
        lblEducation = new QLabel(gbNewUserReg);
        lblEducation->setObjectName(QStringLiteral("lblEducation"));
        lblEducation->setGeometry(QRect(10, 121, 111, 16));
        lblEducation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAdditionalCategory = new QLabel(gbNewUserReg);
        lblAdditionalCategory->setObjectName(QStringLiteral("lblAdditionalCategory"));
        lblAdditionalCategory->setGeometry(QRect(10, 102, 111, 16));
        lblAdditionalCategory->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gbTeachPlace_19 = new QGroupBox(gbNewUserReg);
        gbTeachPlace_19->setObjectName(QStringLiteral("gbTeachPlace_19"));
        gbTeachPlace_19->setGeometry(QRect(0, 270, 411, 111));
        gbTeachPlaceName_19 = new QGroupBox(gbTeachPlace_19);
        gbTeachPlaceName_19->setObjectName(QStringLiteral("gbTeachPlaceName_19"));
        gbTeachPlaceName_19->setGeometry(QRect(10, 20, 391, 41));
        cbTeachPlaceName_19 = new QComboBox(gbTeachPlaceName_19);
        cbTeachPlaceName_19->setObjectName(QStringLiteral("cbTeachPlaceName_19"));
        cbTeachPlaceName_19->setGeometry(QRect(20, 16, 341, 18));
        cbTeachPlaceName_19->setFont(font);
        cbTeachPlaceName_19->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        gbStudy_19 = new QGroupBox(gbTeachPlace_19);
        gbStudy_19->setObjectName(QStringLiteral("gbStudy_19"));
        gbStudy_19->setGeometry(QRect(60, 60, 141, 41));
        cbStudy_19 = new QComboBox(gbStudy_19);
        cbStudy_19->setObjectName(QStringLiteral("cbStudy_19"));
        cbStudy_19->setGeometry(QRect(10, 16, 121, 18));
        gbClass_19 = new QGroupBox(gbTeachPlace_19);
        gbClass_19->setObjectName(QStringLiteral("gbClass_19"));
        gbClass_19->setGeometry(QRect(220, 60, 131, 41));
        leClass_19 = new QLineEdit(gbClass_19);
        leClass_19->setObjectName(QStringLiteral("leClass_19"));
        leClass_19->setGeometry(QRect(10, 16, 113, 18));
        leClass_19->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbWorkPlace_15 = new QGroupBox(gbNewUserReg);
        gbWorkPlace_15->setObjectName(QStringLiteral("gbWorkPlace_15"));
        gbWorkPlace_15->setGeometry(QRect(0, 380, 411, 111));
        gbWorkPlaceName_15 = new QGroupBox(gbWorkPlace_15);
        gbWorkPlaceName_15->setObjectName(QStringLiteral("gbWorkPlaceName_15"));
        gbWorkPlaceName_15->setGeometry(QRect(10, 20, 391, 41));
        leWorkPlaceName_15 = new QLineEdit(gbWorkPlaceName_15);
        leWorkPlaceName_15->setObjectName(QStringLiteral("leWorkPlaceName_15"));
        leWorkPlaceName_15->setGeometry(QRect(10, 16, 371, 18));
        leWorkPlaceName_15->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbJob_16 = new QGroupBox(gbWorkPlace_15);
        gbJob_16->setObjectName(QStringLiteral("gbJob_16"));
        gbJob_16->setGeometry(QRect(10, 60, 391, 41));
        leJob_16 = new QLineEdit(gbJob_16);
        leJob_16->setObjectName(QStringLiteral("leJob_16"));
        leJob_16->setGeometry(QRect(10, 16, 371, 18));
        leJob_16->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        gbFilial = new QGroupBox(gbNewUserReg);
        gbFilial->setObjectName(QStringLiteral("gbFilial"));
        gbFilial->setGeometry(QRect(420, 0, 201, 41));
        cbFilial = new QComboBox(gbFilial);
        cbFilial->setObjectName(QStringLiteral("cbFilial"));
        cbFilial->setGeometry(QRect(60, 16, 81, 18));
        lblTelNumber_work = new QLabel(gbNewUserReg);
        lblTelNumber_work->setObjectName(QStringLiteral("lblTelNumber_work"));
        lblTelNumber_work->setGeometry(QRect(55, 141, 61, 16));
        lblTelNumber_work->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblTelNumber_home = new QLabel(gbNewUserReg);
        lblTelNumber_home->setObjectName(QStringLiteral("lblTelNumber_home"));
        lblTelNumber_home->setGeometry(QRect(215, 141, 61, 16));
        lblTelNumber_home->setStyleSheet(QStringLiteral(""));
        lblTelNumber_home->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        QWidget::setTabOrder(leFam_10, leName_11);
        QWidget::setTabOrder(leName_11, leSurname_12);
        QWidget::setTabOrder(leSurname_12, leBirthYear_21);
        QWidget::setTabOrder(leBirthYear_21, cbAdditionalCategory_67);
        QWidget::setTabOrder(cbAdditionalCategory_67, cbCategory_50);
        QWidget::setTabOrder(cbCategory_50, cbEducation_20);
        QWidget::setTabOrder(cbEducation_20, leTelNumber_Home_17);
        QWidget::setTabOrder(leTelNumber_Home_17, leTelNumber_Work_18);
        QWidget::setTabOrder(leTelNumber_Work_18, cbCity_13);
        QWidget::setTabOrder(cbCity_13, cbStreet_13);
        QWidget::setTabOrder(cbStreet_13, leHouseNumber_13);
        QWidget::setTabOrder(leHouseNumber_13, leAppNumber_13);
        QWidget::setTabOrder(leAppNumber_13, cbTeachPlaceName_19);
        QWidget::setTabOrder(cbTeachPlaceName_19, cbStudy_19);
        QWidget::setTabOrder(cbStudy_19, leClass_19);
        QWidget::setTabOrder(leClass_19, leWorkPlaceName_15);
        QWidget::setTabOrder(leWorkPlaceName_15, leJob_16);
        QWidget::setTabOrder(leJob_16, leSerial_14);
        QWidget::setTabOrder(leSerial_14, leNumber_14);
        QWidget::setTabOrder(leNumber_14, deDateOfIssue_14);
        QWidget::setTabOrder(deDateOfIssue_14, cbPlaceOfIssue_14);
        QWidget::setTabOrder(cbPlaceOfIssue_14, cbCity_14);
        QWidget::setTabOrder(cbCity_14, cbStreet_14);
        QWidget::setTabOrder(cbStreet_14, leHouseNumber_14);
        QWidget::setTabOrder(leHouseNumber_14, leAppNumber_14);
        QWidget::setTabOrder(leAppNumber_14, cbContract);
        QWidget::setTabOrder(cbContract, pbSendToServer);
        QWidget::setTabOrder(pbSendToServer, pbClearForm);
        QWidget::setTabOrder(pbClearForm, pbBrowseFoto);
        QWidget::setTabOrder(pbBrowseFoto, pbScanFoto);
        QWidget::setTabOrder(pbScanFoto, cbAddressRegistration);
        QWidget::setTabOrder(cbAddressRegistration, cbDontHavePassport);

        retranslateUi(form_UserRegistration);

        cbAdditionalCategory_67->setCurrentIndex(0);
        cbCategory_50->setCurrentIndex(0);
        cbPlaceOfIssue_14->setCurrentIndex(4);
        cbEducation_20->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(form_UserRegistration);
    } // setupUi

    void retranslateUi(QDialog *form_UserRegistration)
    {
        form_UserRegistration->setWindowTitle(QApplication::translate("form_UserRegistration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        gbNewUserReg->setTitle(QApplication::translate("form_UserRegistration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        lblFam->setText(QApplication::translate("form_UserRegistration", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", 0));
        leFam_10->setInputMask(QString());
        leName_11->setInputMask(QString());
        lblName->setText(QApplication::translate("form_UserRegistration", "\320\230\320\274\321\217:", 0));
        leSurname_12->setInputMask(QString());
        lblSurname->setText(QApplication::translate("form_UserRegistration", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276:", 0));
        lblBirthYear->setText(QApplication::translate("form_UserRegistration", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264.:", 0));
        leBirthYear_21->setText(QString());
        cbAdditionalCategory_67->clear();
        cbAdditionalCategory_67->insertItems(0, QStringList()
         << QApplication::translate("form_UserRegistration", "\320\222\320\267\321\200\320\276\321\201\320\273\321\213\320\265 \320\270\320\275\320\262\320\260\320\273\320\270\320\264\321\213", 0)
         << QApplication::translate("form_UserRegistration", "\320\224\320\265\321\202\320\270 \320\264\320\276 14 \320\273\320\265\321\202 \320\262\320\272\320\273", 0)
         << QApplication::translate("form_UserRegistration", "\320\230\320\275\320\262\320\260\320\273\320\270\320\264\321\213 15-24 \320\262\320\272\320\273.", 0)
         << QApplication::translate("form_UserRegistration", "\320\230\320\275\320\262\320\260\320\273\320\270\320\264\321\213 \320\264\320\265\321\202\320\270 \320\264\320\276 14 \320\273.", 0)
         << QApplication::translate("form_UserRegistration", "\320\236\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\320\265 \320\275\320\260 \320\264\320\276\320\274\321\203", 0)
         << QApplication::translate("form_UserRegistration", "\320\237\320\265\320\275\321\201\320\270\320\276\320\275\320\265\321\200\321\213", 0)
         << QApplication::translate("form_UserRegistration", "\320\241\320\270\321\200\320\276\321\202\321\213 \320\264\320\265\321\202\320\270 \320\264\320\276 14 \320\273\320\265\321\202", 0)
         << QApplication::translate("form_UserRegistration", "\320\256\320\275\320\276\321\210\320\265\321\201\321\202\320\262\320\276 15-24 \320\273\320\265\321\202 \320\262\320\272\320\273", 0)
         << QString()
        );
        gbuserFoto->setTitle(QApplication::translate("form_UserRegistration", "\320\244\320\276\321\202\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        pbBrowseFoto->setText(QApplication::translate("form_UserRegistration", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", 0));
        pbScanFoto->setText(QApplication::translate("form_UserRegistration", "\320\241\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        lblUserFoto->setText(QString());
        pbRequest->setText(QApplication::translate("form_UserRegistration", "\320\242\320\265\321\201\321\202 \320\267\320\260\320\277\321\200\320\276\321\201\320\276\320\262", 0));
        cbCategory_50->clear();
        cbCategory_50->insertItems(0, QStringList()
         << QApplication::translate("form_UserRegistration", "\320\222\321\200\320\260\321\207\320\270, \321\201\321\200. \320\274\320\265\320\264. \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\273", 0)
         << QApplication::translate("form_UserRegistration", "\320\224\320\276\321\210\320\272\320\276\320\273\321\214\320\275\320\270\320\272\320\270", 0)
         << QApplication::translate("form_UserRegistration", "\320\230\320\242\320\240", 0)
         << QApplication::translate("form_UserRegistration", "\320\237\320\273\320\260\320\275\320\276\320\262\320\276-\321\204\320\270\320\275\320\260\320\275\321\201\320\276\320\262\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\270, \321\215\320\272\320\276\320\275\320\276\320\274\320\270\321\201\321\202\321\213", 0)
         << QApplication::translate("form_UserRegistration", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\270, \320\262\320\276\321\201\320\277\320\270\321\202\320\260\321\202\320\265\320\273\320\270", 0)
         << QApplication::translate("form_UserRegistration", "\320\237\321\200\320\276\321\207\320\270\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\240\320\260\320\261\320\276\321\207\320\270\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\241\320\273\321\203\320\266\320\260\321\211\320\270\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\241\320\277\320\265\321\206. \320\264\321\200. \320\277\321\200\320\276\321\204\320\265\321\201\321\201\320\270\320\271", 0)
         << QApplication::translate("form_UserRegistration", "\320\243\321\207\320\260\321\211\320\270\320\265\321\201\321\217 \320\262\321\213\321\201\321\210\320\270\321\205 \320\277\321\200\320\276\321\204.", 0)
         << QApplication::translate("form_UserRegistration", "\320\243\321\207\320\260\321\211\320\270\320\265\321\201\321\217 \320\275\320\260\321\207. \320\277\321\200\320\276\321\204.", 0)
         << QApplication::translate("form_UserRegistration", "\320\243\321\207\320\260\321\211\320\270\320\265\321\201\321\217 \320\276\320\261\321\211\320\265\320\276\320\261\321\200\320\260\320\267.", 0)
         << QApplication::translate("form_UserRegistration", "\320\243\321\207\320\260\321\211\320\270\320\265\321\201\321\217 \321\201\321\200\320\265\320\264\320\275\320\270\321\205 \320\277\321\200\320\276\321\204.", 0)
         << QApplication::translate("form_UserRegistration", "\320\256\321\200\320\270\321\201\321\202\321\213", 0)
        );
        leTelNumber_Home_17->setText(QString());
        lblTelNumber->setText(QApplication::translate("form_UserRegistration", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275\321\213", 0));
        leTelNumber_Work_18->setText(QString());
        gbPassport_14->setTitle(QApplication::translate("form_UserRegistration", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        gbPassport_SerialNumber_14->setTitle(QApplication::translate("form_UserRegistration", "\320\241\320\265\321\200\320\270\321\217, \320\275\320\276\320\274\320\265\321\200", 0));
        gbDataOfIssue_14->setTitle(QApplication::translate("form_UserRegistration", "\320\222\321\213\320\264\320\260\320\275", 0));
        gbPlaceOfIssue_14->setTitle(QApplication::translate("form_UserRegistration", "\320\234\320\265\321\201\321\202\320\276 \320\262\321\213\320\264\320\260\321\207\320\270", 0));
        cbPlaceOfIssue_14->clear();
        cbPlaceOfIssue_14->insertItems(0, QStringList()
         << QApplication::translate("form_UserRegistration", "\320\236\320\222\320\224 \320\233\320\225\320\235\320\230\320\235\320\241\320\232\320\236\320\223\320\236 \320\236\320\232\320\240\320\243\320\223\320\220 \320\223\320\236\320\240\320\236\320\224\320\220 \320\234\320\243\320\240\320\234\320\220\320\235\320\241\320\232\320\220", 0)
         << QApplication::translate("form_UserRegistration", "\320\236\320\222\320\224 \320\236\320\232\320\242\320\257\320\221\320\240\320\254\320\241\320\232\320\236\320\223\320\236 \320\236\320\232\320\240\320\243\320\223\320\220 \320\223\320\236\320\240\320\236\320\224\320\220 \320\234\320\243\320\240\320\234\320\220\320\235\320\241\320\232\320\220", 0)
         << QApplication::translate("form_UserRegistration", "\320\236\320\222\320\224 \320\237\320\225\320\240\320\222\320\236\320\234\320\220\320\231\320\241\320\232\320\236\320\223\320\236 \320\236\320\232\320\240\320\243\320\223\320\220 \320\223\320\236\320\240\320\236\320\224\320\220 \320\234\320\243\320\240\320\234\320\220\320\235\320\241\320\232\320\220", 0)
         << QApplication::translate("form_UserRegistration", "\320\236\320\243\320\244\320\234\320\241 \320\240\320\236\320\241\320\241\320\230\320\230 \320\237\320\236 \320\234\320\236 \320\222 \320\233\320\225\320\235\320\230\320\235\320\241\320\232\320\236\320\234 \320\220\320\236 \320\223\320\236\320\240\320\236\320\224\320\220 \320\234\320\243\320\240\320\234\320\220\320\235\320\241\320\232\320\220", 0)
         << QApplication::translate("form_UserRegistration", "\320\236\320\243\320\244\320\234\320\241 \320\240\320\236\320\241\320\241\320\230\320\230 \320\237\320\236 \320\234\320\236 \320\222 \320\236\320\232\320\242\320\257\320\221\320\240\320\254\320\241\320\232\320\236\320\234 \320\220\320\236 \320\223\320\236\320\240\320\236\320\224\320\220 \320\234\320\243\320\240\320\234\320\220\320\235\320\241\320\232\320\220", 0)
         << QApplication::translate("form_UserRegistration", "\320\236\320\243\320\244\320\234\320\241 \320\240\320\236\320\241\320\241\320\230\320\230 \320\237\320\236 \320\234\320\236 \320\222 \320\237\320\225\320\240\320\222\320\236\320\234\320\220\320\231\320\241\320\232\320\236\320\234 \320\220\320\236 \320\223\320\236\320\240\320\236\320\224\320\220 \320\234\320\243\320\240\320\234\320\220\320\235\320\241\320\232\320\220", 0)
        );
        gbRegistrationAddress_14->setTitle(QApplication::translate("form_UserRegistration", "\320\220\320\264\321\200\320\265\321\201 \320\277\321\200\320\276\320\277\320\270\321\201\320\272\320\270", 0));
        gbCity_14->setTitle(QApplication::translate("form_UserRegistration", "\320\223\320\276\321\200\320\276\320\264", 0));
        gbStreet_14->setTitle(QApplication::translate("form_UserRegistration", "\320\243\320\273\320\270\321\206\320\260", 0));
        gbHomeNumber_14->setTitle(QApplication::translate("form_UserRegistration", "\320\224\320\276\320\274", 0));
        gbAppNumber_14->setTitle(QApplication::translate("form_UserRegistration", "\320\232\320\262.", 0));
        gbHomeAddress_13->setTitle(QApplication::translate("form_UserRegistration", "\320\224\320\276\320\274\320\260\321\210\320\275\320\270\320\271 \320\260\320\264\321\200\320\265\321\201", 0));
        gbCity_13->setTitle(QApplication::translate("form_UserRegistration", "\320\223\320\276\321\200\320\276\320\264", 0));
        gbStreet_13->setTitle(QApplication::translate("form_UserRegistration", "\320\243\320\273\320\270\321\206\320\260", 0));
        gbHouseNumber_13->setTitle(QApplication::translate("form_UserRegistration", "\320\224\320\276\320\274", 0));
        gbAppNumber_13->setTitle(QApplication::translate("form_UserRegistration", "\320\232\320\262.", 0));
        gbOptions->setTitle(QApplication::translate("form_UserRegistration", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276", 0));
        cbAddressRegistration->setText(QApplication::translate("form_UserRegistration", "\320\220\320\264\321\200\320\265\321\201 \320\277\321\200\320\276\320\277\320\270\321\201\320\272\320\270", 0));
        pbSendToServer->setText(QApplication::translate("form_UserRegistration", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        pbClearForm->setText(QApplication::translate("form_UserRegistration", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        cbDontHavePassport->setText(QApplication::translate("form_UserRegistration", "\320\235\320\265\321\202 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", 0));
        cbContract->setText(QApplication::translate("form_UserRegistration", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200", 0));
        cbEF_691->setText(QApplication::translate("form_UserRegistration", "\320\225\320\244", 0));
        cbSPS_691->setText(QApplication::translate("form_UserRegistration", "\320\241\320\237\320\241", 0));
        cbMBA_691->setText(QApplication::translate("form_UserRegistration", "\320\234\320\221\320\220", 0));
        cbEducation_20->clear();
        cbEducation_20->insertItems(0, QStringList()
         << QApplication::translate("form_UserRegistration", "\320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\276\321\201\320\275. \320\276\320\261\321\211\320\265\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\267\320\260\320\276\321\207\320\275\320\276\320\265 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\264\320\276\321\210\320\272\320\276\320\273\321\214\320\275\320\276\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\321\201\321\200\320\265\320\264\320\275\320\265\320\265 \320\277\321\200\320\276\321\204.", 0)
         << QApplication::translate("form_UserRegistration", "\320\262\321\213\321\201\321\210\320\265\320\265 \320\277\321\200\320\276\321\204.", 0)
         << QApplication::translate("form_UserRegistration", "\321\201\321\200\320\265\320\264\320\275\320\265\320\265 (\320\277\320\276\320\273\320\275\320\276\320\265) \320\276\320\261\321\211\320\265\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\275\320\260\321\207. \320\277\321\200\320\276\321\204.", 0)
        );
        lblEducation->setText(QApplication::translate("form_UserRegistration", "\320\236\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        lblAdditionalCategory->setText(QApplication::translate("form_UserRegistration", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", 0));
        gbTeachPlace_19->setTitle(QApplication::translate("form_UserRegistration", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \320\274\320\265\321\201\321\202\320\265 \321\203\321\207\320\265\320\261\321\213", 0));
        gbTeachPlaceName_19->setTitle(QApplication::translate("form_UserRegistration", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\203\321\207\320\265\320\261\320\275\320\276\320\263\320\276 \320\267\320\260\320\262\320\265\320\264\320\265\320\275\320\270\321\217", 0));
        cbTeachPlaceName_19->clear();
        cbTeachPlaceName_19->insertItems(0, QStringList()
         << QString()
        );
        gbStudy_19->setTitle(QApplication::translate("form_UserRegistration", "\320\244\320\276\321\200\320\274\320\260 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\321\217", 0));
        cbStudy_19->clear();
        cbStudy_19->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("form_UserRegistration", "\320\224\320\275\320\265\320\262\320\275\320\276\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\222\320\265\321\207\320\265\321\200\320\275\320\265\320\265", 0)
         << QApplication::translate("form_UserRegistration", "\320\227\320\260\320\276\321\207\320\275\320\276\320\265", 0)
        );
        gbClass_19->setTitle(QApplication::translate("form_UserRegistration", "\320\232\320\273\320\260\321\201\321\201 / \320\272\321\203\321\200\321\201", 0));
        gbWorkPlace_15->setTitle(QApplication::translate("form_UserRegistration", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \320\274\320\265\321\201\321\202\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", 0));
        gbWorkPlaceName_15->setTitle(QApplication::translate("form_UserRegistration", "\320\234\320\265\321\201\321\202\320\276 \321\200\320\260\320\261\320\276\321\202\321\213", 0));
        gbJob_16->setTitle(QApplication::translate("form_UserRegistration", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", 0));
        gbFilial->setTitle(QApplication::translate("form_UserRegistration", "\320\244\320\270\320\273\320\270\320\260\320\273", 0));
        lblTelNumber_work->setText(QApplication::translate("form_UserRegistration", "\321\201\320\273\321\203\320\266.:", 0));
        lblTelNumber_home->setText(QApplication::translate("form_UserRegistration", "\320\264\320\276\320\274.:", 0));
    } // retranslateUi

};

namespace Ui {
    class form_UserRegistration: public Ui_form_UserRegistration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_USERREGISTRATION_H
