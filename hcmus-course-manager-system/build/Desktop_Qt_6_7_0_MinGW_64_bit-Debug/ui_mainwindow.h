/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageSignIn;
    QFrame *leftFrame;
    QPushButton *btnRegister;
    QLabel *labelSchoolLogo;
    QLabel *lableNoAccount;
    QLabel *lableAppName;
    QLabel *lableAppScript;
    QFrame *rightFrame;
    QPushButton *btnSignIn;
    QFrame *passwordFrame;
    QLineEdit *txtUsername;
    QCheckBox *checkBoxRemember;
    QFrame *passwordFrame_2;
    QLineEdit *txtPassword;
    QLabel *lableSignInScript;
    QLabel *lableSignIn;
    QPushButton *btnForgotPassword;
    QWidget *pageProfileInfo;
    QFrame *frameProfileInfo;
    QPushButton *btnEdit_ProfileInfo;
    QPushButton *btnSignOut_ProfileInfo;
    QLabel *labelUserPfp_ProfileInfo;
    QLabel *lableNoAccount_2;
    QLabel *lableAppScript_2;
    QLabel *lableAppScript_3;
    QLabel *lableAppScript_4;
    QLabel *lableAppScript_5;
    QLabel *lableAppScript_6;
    QLabel *lableAppScript_7;
    QLabel *lableAppScript_8;
    QLabel *lableAppScript_9;
    QLabel *lableAppScript_10;
    QLabel *lableAppScript_11;
    QLabel *lableAppScript_12;
    QLabel *lableAppScript_13;
    QLabel *lableAppScript_14;
    QLabel *lableAppScript_15;
    QLabel *lableAppScript_16;
    QLabel *lableAppScript_17;
    QLabel *lableAppScript_18;
    QPushButton *btnNext_ProfileInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        MainWindow->setMinimumSize(QSize(900, 600));
        MainWindow->setMaximumSize(QSize(900, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/app-logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 900, 600));
        pageSignIn = new QWidget();
        pageSignIn->setObjectName("pageSignIn");
        leftFrame = new QFrame(pageSignIn);
        leftFrame->setObjectName("leftFrame");
        leftFrame->setGeometry(QRect(0, 0, 310, 600));
        leftFrame->setStyleSheet(QString::fromUtf8("QFrame#leftFrame {\n"
"	border-image: url(:/assets/blue-gradient-yswap.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
""));
        btnRegister = new QPushButton(leftFrame);
        btnRegister->setObjectName("btnRegister");
        btnRegister->setGeometry(QRect(85, 430, 140, 45));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setKerning(true);
        btnRegister->setFont(font1);
        btnRegister->setCursor(QCursor(Qt::PointingHandCursor));
        btnRegister->setStyleSheet(QString::fromUtf8("QPushButton#btnRegister {\n"
"background-color: rgb(255, 196, 54);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#btnRegister:hover {\n"
"background-color: rgb(229, 176, 48);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
"}"));
        btnRegister->setAutoDefault(false);
        btnRegister->setFlat(false);
        labelSchoolLogo = new QLabel(leftFrame);
        labelSchoolLogo->setObjectName("labelSchoolLogo");
        labelSchoolLogo->setGeometry(QRect(15, 60, 280, 120));
        labelSchoolLogo->setStyleSheet(QString::fromUtf8("image: url(:/assets/hcmus-logo.png);"));
        lableNoAccount = new QLabel(leftFrame);
        lableNoAccount->setObjectName("lableNoAccount");
        lableNoAccount->setGeometry(QRect(110, 397, 101, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font2.setPointSize(12);
        font2.setBold(true);
        lableNoAccount->setFont(font2);
        lableNoAccount->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        lableAppName = new QLabel(leftFrame);
        lableAppName->setObjectName("lableAppName");
        lableAppName->setGeometry(QRect(15, 180, 280, 80));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Calibri")});
        font3.setPointSize(22);
        font3.setBold(true);
        font3.setItalic(false);
        lableAppName->setFont(font3);
        lableAppName->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);\n"
"font: 700 22pt \"Calibri\";"));
        lableAppName->setScaledContents(false);
        lableAppName->setAlignment(Qt::AlignCenter);
        lableAppName->setWordWrap(true);
        lableAppScript = new QLabel(leftFrame);
        lableAppScript->setObjectName("lableAppScript");
        lableAppScript->setGeometry(QRect(15, 260, 280, 25));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(10);
        font4.setBold(false);
        lableAppScript->setFont(font4);
        lableAppScript->setStyleSheet(QString::fromUtf8("color: rgb(182, 182, 182);"));
        lableAppScript->setAlignment(Qt::AlignCenter);
        lableAppScript->setWordWrap(true);
        rightFrame = new QFrame(pageSignIn);
        rightFrame->setObjectName("rightFrame");
        rightFrame->setGeometry(QRect(310, 0, 590, 600));
        rightFrame->setCursor(QCursor(Qt::ArrowCursor));
        rightFrame->setStyleSheet(QString::fromUtf8("QFrame#rightFrame {\n"
"	border-image: url(:/assets/blue-gradient-xswap.png) 0 0 0 0 stretch stretch;\n"
"}\n"
""));
        btnSignIn = new QPushButton(rightFrame);
        btnSignIn->setObjectName("btnSignIn");
        btnSignIn->setGeometry(QRect(120, 400, 350, 50));
        btnSignIn->setFont(font1);
        btnSignIn->setCursor(QCursor(Qt::PointingHandCursor));
        btnSignIn->setStyleSheet(QString::fromUtf8("QPushButton#btnSignIn {\n"
"background-color: rgb(12, 53, 106);\n"
"color: rgb(223, 223, 223);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#btnSignIn:hover {\n"
"background-color: rgb(14, 63, 127);\n"
"color: rgb(223, 223, 223);\n"
"border: none;\n"
"}"));
        btnSignIn->setAutoDefault(false);
        btnSignIn->setFlat(false);
        passwordFrame = new QFrame(rightFrame);
        passwordFrame->setObjectName("passwordFrame");
        passwordFrame->setGeometry(QRect(120, 290, 350, 50));
        passwordFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 141, 218);"));
        passwordFrame->setFrameShape(QFrame::StyledPanel);
        passwordFrame->setFrameShadow(QFrame::Raised);
        txtUsername = new QLineEdit(passwordFrame);
        txtUsername->setObjectName("txtUsername");
        txtUsername->setGeometry(QRect(20, 10, 311, 31));
        QFont font5;
        font5.setPointSize(12);
        txtUsername->setFont(font5);
        txtUsername->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: none;\n"
"	color: rgb(230, 230, 230);\n"
"}"));
        txtUsername->setEchoMode(QLineEdit::Password);
        checkBoxRemember = new QCheckBox(rightFrame);
        checkBoxRemember->setObjectName("checkBoxRemember");
        checkBoxRemember->setGeometry(QRect(120, 355, 111, 22));
        checkBoxRemember->setCursor(QCursor(Qt::PointingHandCursor));
        checkBoxRemember->setStyleSheet(QString::fromUtf8("color: rgb(226, 226, 226);"));
        checkBoxRemember->setChecked(true);
        passwordFrame_2 = new QFrame(rightFrame);
        passwordFrame_2->setObjectName("passwordFrame_2");
        passwordFrame_2->setGeometry(QRect(120, 235, 350, 50));
        passwordFrame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 141, 218);"));
        passwordFrame_2->setFrameShape(QFrame::StyledPanel);
        passwordFrame_2->setFrameShadow(QFrame::Raised);
        txtPassword = new QLineEdit(passwordFrame_2);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(20, 10, 311, 31));
        txtPassword->setFont(font5);
        txtPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: none;\n"
"	color: rgb(230, 230, 230);\n"
"}"));
        lableSignInScript = new QLabel(rightFrame);
        lableSignInScript->setObjectName("lableSignInScript");
        lableSignInScript->setGeometry(QRect(120, 170, 351, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Segoe UI")});
        font6.setPointSize(8);
        font6.setBold(false);
        lableSignInScript->setFont(font6);
        lableSignInScript->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        lableSignInScript->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lableSignInScript->setWordWrap(true);
        lableSignIn = new QLabel(rightFrame);
        lableSignIn->setObjectName("lableSignIn");
        lableSignIn->setGeometry(QRect(120, 109, 351, 61));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Calibri")});
        font7.setPointSize(30);
        font7.setBold(true);
        font7.setItalic(false);
        lableSignIn->setFont(font7);
        lableSignIn->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);\n"
"font: 700 30pt \"Calibri\";"));
        lableSignIn->setScaledContents(false);
        lableSignIn->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lableSignIn->setWordWrap(true);
        btnForgotPassword = new QPushButton(rightFrame);
        btnForgotPassword->setObjectName("btnForgotPassword");
        btnForgotPassword->setGeometry(QRect(210, 453, 171, 31));
        QFont font8;
        font8.setUnderline(true);
        btnForgotPassword->setFont(font8);
        btnForgotPassword->setCursor(QCursor(Qt::PointingHandCursor));
        btnForgotPassword->setStyleSheet(QString::fromUtf8("color: rgb(135, 206, 250);"));
        btnForgotPassword->setFlat(true);
        stackedWidget->addWidget(pageSignIn);
        pageProfileInfo = new QWidget();
        pageProfileInfo->setObjectName("pageProfileInfo");
        pageProfileInfo->setStyleSheet(QString::fromUtf8("QWidget#pageProfileInfo {\n"
"	border-image: url(:/assets/blue-gradient.png) 0 0 0 0 stretch stretch;\n"
"}\n"
""));
        frameProfileInfo = new QFrame(pageProfileInfo);
        frameProfileInfo->setObjectName("frameProfileInfo");
        frameProfileInfo->setGeometry(QRect(0, 0, 290, 600));
        frameProfileInfo->setStyleSheet(QString::fromUtf8("QFrame#frameProfileInfo {\n"
"	background-color: WhiteSmoke\n"
"}\n"
""));
        frameProfileInfo->setFrameShape(QFrame::StyledPanel);
        frameProfileInfo->setFrameShadow(QFrame::Raised);
        btnEdit_ProfileInfo = new QPushButton(frameProfileInfo);
        btnEdit_ProfileInfo->setObjectName("btnEdit_ProfileInfo");
        btnEdit_ProfileInfo->setGeometry(QRect(150, 540, 125, 45));
        btnEdit_ProfileInfo->setFont(font1);
        btnEdit_ProfileInfo->setCursor(QCursor(Qt::PointingHandCursor));
        btnEdit_ProfileInfo->setStyleSheet(QString::fromUtf8("QPushButton#btnEdit_ProfileInfo {\n"
"background-color: rgb(255, 196, 54);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#btnEdit_ProfileInfo:hover {\n"
"background-color: rgb(229, 176, 48);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
"}"));
        btnEdit_ProfileInfo->setAutoDefault(false);
        btnEdit_ProfileInfo->setFlat(false);
        btnSignOut_ProfileInfo = new QPushButton(frameProfileInfo);
        btnSignOut_ProfileInfo->setObjectName("btnSignOut_ProfileInfo");
        btnSignOut_ProfileInfo->setGeometry(QRect(10, 540, 125, 45));
        btnSignOut_ProfileInfo->setFont(font1);
        btnSignOut_ProfileInfo->setCursor(QCursor(Qt::PointingHandCursor));
        btnSignOut_ProfileInfo->setStyleSheet(QString::fromUtf8("QPushButton#btnSignOut_ProfileInfo {\n"
"background-color: rgb(12, 53, 106);\n"
"color: rgb(223, 223, 223);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#btnSignOut_ProfileInfo:hover {\n"
"background-color: rgb(14, 63, 127);\n"
"color: rgb(223, 223, 223);\n"
"border: none;\n"
"}"));
        btnSignOut_ProfileInfo->setAutoDefault(false);
        btnSignOut_ProfileInfo->setFlat(false);
        labelUserPfp_ProfileInfo = new QLabel(frameProfileInfo);
        labelUserPfp_ProfileInfo->setObjectName("labelUserPfp_ProfileInfo");
        labelUserPfp_ProfileInfo->setGeometry(QRect(80, 50, 130, 130));
        labelUserPfp_ProfileInfo->setStyleSheet(QString::fromUtf8("image: url(:/assets/app-logo.ico);\n"
"background-color: rgb(46, 47, 48);"));
        lableNoAccount_2 = new QLabel(frameProfileInfo);
        lableNoAccount_2->setObjectName("lableNoAccount_2");
        lableNoAccount_2->setGeometry(QRect(50, 190, 191, 31));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font9.setPointSize(14);
        font9.setBold(true);
        lableNoAccount_2->setFont(font9);
        lableNoAccount_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lableNoAccount_2->setAlignment(Qt::AlignCenter);
        lableAppScript_2 = new QLabel(frameProfileInfo);
        lableAppScript_2->setObjectName("lableAppScript_2");
        lableAppScript_2->setGeometry(QRect(50, 220, 191, 20));
        lableAppScript_2->setFont(font4);
        lableAppScript_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lableAppScript_2->setAlignment(Qt::AlignCenter);
        lableAppScript_2->setWordWrap(true);
        lableAppScript_3 = new QLabel(frameProfileInfo);
        lableAppScript_3->setObjectName("lableAppScript_3");
        lableAppScript_3->setGeometry(QRect(20, 260, 121, 20));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Segoe UI")});
        font10.setPointSize(11);
        font10.setBold(false);
        lableAppScript_3->setFont(font10);
        lableAppScript_3->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_3->setWordWrap(true);
        lableAppScript_4 = new QLabel(frameProfileInfo);
        lableAppScript_4->setObjectName("lableAppScript_4");
        lableAppScript_4->setGeometry(QRect(170, 260, 121, 20));
        lableAppScript_4->setFont(font10);
        lableAppScript_4->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_4->setWordWrap(true);
        lableAppScript_5 = new QLabel(frameProfileInfo);
        lableAppScript_5->setObjectName("lableAppScript_5");
        lableAppScript_5->setGeometry(QRect(20, 280, 131, 31));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font11.setPointSize(12);
        font11.setBold(false);
        lableAppScript_5->setFont(font11);
        lableAppScript_5->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_5->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_5->setWordWrap(true);
        lableAppScript_6 = new QLabel(frameProfileInfo);
        lableAppScript_6->setObjectName("lableAppScript_6");
        lableAppScript_6->setGeometry(QRect(170, 280, 121, 31));
        lableAppScript_6->setFont(font11);
        lableAppScript_6->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_6->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_6->setWordWrap(true);
        lableAppScript_7 = new QLabel(frameProfileInfo);
        lableAppScript_7->setObjectName("lableAppScript_7");
        lableAppScript_7->setGeometry(QRect(170, 340, 121, 31));
        lableAppScript_7->setFont(font11);
        lableAppScript_7->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_7->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_7->setWordWrap(true);
        lableAppScript_8 = new QLabel(frameProfileInfo);
        lableAppScript_8->setObjectName("lableAppScript_8");
        lableAppScript_8->setGeometry(QRect(20, 340, 131, 31));
        lableAppScript_8->setFont(font11);
        lableAppScript_8->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_8->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_8->setWordWrap(true);
        lableAppScript_9 = new QLabel(frameProfileInfo);
        lableAppScript_9->setObjectName("lableAppScript_9");
        lableAppScript_9->setGeometry(QRect(170, 320, 121, 20));
        lableAppScript_9->setFont(font10);
        lableAppScript_9->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_9->setWordWrap(true);
        lableAppScript_10 = new QLabel(frameProfileInfo);
        lableAppScript_10->setObjectName("lableAppScript_10");
        lableAppScript_10->setGeometry(QRect(20, 320, 121, 20));
        lableAppScript_10->setFont(font10);
        lableAppScript_10->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_10->setWordWrap(true);
        lableAppScript_11 = new QLabel(frameProfileInfo);
        lableAppScript_11->setObjectName("lableAppScript_11");
        lableAppScript_11->setGeometry(QRect(170, 400, 121, 31));
        lableAppScript_11->setFont(font11);
        lableAppScript_11->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_11->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_11->setWordWrap(true);
        lableAppScript_12 = new QLabel(frameProfileInfo);
        lableAppScript_12->setObjectName("lableAppScript_12");
        lableAppScript_12->setGeometry(QRect(20, 400, 131, 31));
        lableAppScript_12->setFont(font11);
        lableAppScript_12->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_12->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_12->setWordWrap(true);
        lableAppScript_13 = new QLabel(frameProfileInfo);
        lableAppScript_13->setObjectName("lableAppScript_13");
        lableAppScript_13->setGeometry(QRect(170, 380, 121, 20));
        lableAppScript_13->setFont(font10);
        lableAppScript_13->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_13->setWordWrap(true);
        lableAppScript_14 = new QLabel(frameProfileInfo);
        lableAppScript_14->setObjectName("lableAppScript_14");
        lableAppScript_14->setGeometry(QRect(20, 380, 121, 20));
        lableAppScript_14->setFont(font10);
        lableAppScript_14->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_14->setWordWrap(true);
        lableAppScript_15 = new QLabel(frameProfileInfo);
        lableAppScript_15->setObjectName("lableAppScript_15");
        lableAppScript_15->setGeometry(QRect(170, 460, 121, 61));
        lableAppScript_15->setFont(font11);
        lableAppScript_15->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_15->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_15->setWordWrap(true);
        lableAppScript_16 = new QLabel(frameProfileInfo);
        lableAppScript_16->setObjectName("lableAppScript_16");
        lableAppScript_16->setGeometry(QRect(20, 460, 131, 61));
        lableAppScript_16->setFont(font11);
        lableAppScript_16->setContextMenuPolicy(Qt::NoContextMenu);
        lableAppScript_16->setStyleSheet(QString::fromUtf8("color: Black;"));
        lableAppScript_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_16->setWordWrap(true);
        lableAppScript_17 = new QLabel(frameProfileInfo);
        lableAppScript_17->setObjectName("lableAppScript_17");
        lableAppScript_17->setGeometry(QRect(170, 440, 121, 20));
        lableAppScript_17->setFont(font10);
        lableAppScript_17->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_17->setWordWrap(true);
        lableAppScript_18 = new QLabel(frameProfileInfo);
        lableAppScript_18->setObjectName("lableAppScript_18");
        lableAppScript_18->setGeometry(QRect(20, 440, 121, 20));
        lableAppScript_18->setFont(font10);
        lableAppScript_18->setStyleSheet(QString::fromUtf8("color: DimGray;"));
        lableAppScript_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lableAppScript_18->setWordWrap(true);
        btnNext_ProfileInfo = new QPushButton(pageProfileInfo);
        btnNext_ProfileInfo->setObjectName("btnNext_ProfileInfo");
        btnNext_ProfileInfo->setGeometry(QRect(760, 540, 125, 45));
        btnNext_ProfileInfo->setFont(font1);
        btnNext_ProfileInfo->setCursor(QCursor(Qt::PointingHandCursor));
        btnNext_ProfileInfo->setStyleSheet(QString::fromUtf8("QPushButton#btnNext_ProfileInfo {\n"
"background-color: rgb(255, 196, 54);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#btnNext_ProfileInfo:hover {\n"
"background-color: rgb(229, 176, 48);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
"}"));
        btnNext_ProfileInfo->setAutoDefault(false);
        btnNext_ProfileInfo->setFlat(false);
        stackedWidget->addWidget(pageProfileInfo);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        btnRegister->setDefault(false);
        btnSignIn->setDefault(false);
        btnEdit_ProfileInfo->setDefault(false);
        btnSignOut_ProfileInfo->setDefault(false);
        btnNext_ProfileInfo->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        labelSchoolLogo->setText(QString());
        lableNoAccount->setText(QCoreApplication::translate("MainWindow", "No Account?", nullptr));
        lableAppName->setText(QCoreApplication::translate("MainWindow", "US Course Management System", nullptr));
        lableAppScript->setText(QCoreApplication::translate("MainWindow", "Efficiency, enthusiastic, excellence.", nullptr));
        btnSignIn->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        txtUsername->setText(QString());
        txtUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        checkBoxRemember->setText(QCoreApplication::translate("MainWindow", "Remember me", nullptr));
        txtPassword->setText(QString());
        txtPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        lableSignInScript->setText(QCoreApplication::translate("MainWindow", "Sign in to your account to enroll courses, manage your grades, tasks and more.", nullptr));
        lableSignIn->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        btnForgotPassword->setText(QCoreApplication::translate("MainWindow", "Forgot password?", nullptr));
        btnEdit_ProfileInfo->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btnSignOut_ProfileInfo->setText(QCoreApplication::translate("MainWindow", "Sign Out", nullptr));
        labelUserPfp_ProfileInfo->setText(QString());
        lableNoAccount_2->setText(QCoreApplication::translate("MainWindow", "User Name Here", nullptr));
        lableAppScript_2->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
        lableAppScript_3->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lableAppScript_4->setText(QCoreApplication::translate("MainWindow", "Birth", nullptr));
        lableAppScript_5->setText(QCoreApplication::translate("MainWindow", "21120082", nullptr));
        lableAppScript_6->setText(QCoreApplication::translate("MainWindow", "15/02/2003", nullptr));
        lableAppScript_7->setText(QCoreApplication::translate("MainWindow", "Male", nullptr));
        lableAppScript_8->setText(QCoreApplication::translate("MainWindow", "Ba Ria - Vung Tau", nullptr));
        lableAppScript_9->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        lableAppScript_10->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        lableAppScript_11->setText(QCoreApplication::translate("MainWindow", "Bachelor", nullptr));
        lableAppScript_12->setText(QCoreApplication::translate("MainWindow", "2021", nullptr));
        lableAppScript_13->setText(QCoreApplication::translate("MainWindow", "Education Level", nullptr));
        lableAppScript_14->setText(QCoreApplication::translate("MainWindow", "Recruited", nullptr));
        lableAppScript_15->setText(QCoreApplication::translate("MainWindow", "Information Technology", nullptr));
        lableAppScript_16->setText(QCoreApplication::translate("MainWindow", "System Information", nullptr));
        lableAppScript_17->setText(QCoreApplication::translate("MainWindow", "Program", nullptr));
        lableAppScript_18->setText(QCoreApplication::translate("MainWindow", "Major", nullptr));
        btnNext_ProfileInfo->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
