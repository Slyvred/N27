/********************************************************************************
** Form generated from reading UI file 'mainapp.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINAPP_H
#define UI_MAINAPP_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainApp
{
public:
    QVBoxLayout *verticalLayout_14;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *usernum;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *passwd;
    QLabel *error_msg;
    QHBoxLayout *horizontalLayout;
    QPushButton *connection;
    QPushButton *inscription;
    QLabel *TitleLogin;
    QWidget *page_2;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *verticalLayout_23;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameinput;
    QLineEdit *firstnameinput;
    QLineEdit *adress;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_2;
    QLabel *birth;
    QRadioButton *radioMan;
    QRadioButton *radioFemale;
    QRadioButton *radioNP;
    QDateEdit *birthDate;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancel;
    QPushButton *register_2;
    QWidget *page_3;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QPushButton *toInfo;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *sold_tofill;
    QSpacerItem *verticalSpacer_4;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *tolivret;
    QPushButton *virement;
    QPushButton *deconnexion;
    QWidget *verticalLayoutWidget_12;
    QVBoxLayout *verticalLayout_17;
    QLabel *IBAN;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_12;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *nom_tofill;
    QLabel *prenom_tofill;
    QWidget *page_4;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_22;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLabel *sold_tofill_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QComboBox *listAccount;
    QLineEdit *RIB;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *toHome;
    QPushButton *transfer;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *baktohome;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_13;
    QLabel *idUserInfo;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_12;
    QLabel *nameInfo;
    QLabel *adressInfo;
    QLabel *birthInfo;
    QLabel *genreInfo;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *verticalSpacer_2;
    QComboBox *accountbox;
    QLabel *sumAcc;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *tohomefrominfo;
    QWidget *page_7;
    QLabel *label_7;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_9;
    QComboBox *interest;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_10;
    QLineEdit *montant;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_3;
    QPushButton *createAccount;
    QWidget *page_8;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_11;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *virIntern;
    QPushButton *virExtern;
    QWidget *page_9;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_13;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_14;
    QComboBox *compteemet;
    QLabel *soldeCompteemetteur;
    QLabel *label_15;
    QComboBox *compterecept;
    QLabel *label_16;
    QLineEdit *lineEdit_2;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *tovir;
    QPushButton *tovirementemis;

    void setupUi(QDialog *MainApp)
    {
        if (MainApp->objectName().isEmpty())
            MainApp->setObjectName("MainApp");
        MainApp->resize(431, 400);
        verticalLayout_14 = new QVBoxLayout(MainApp);
        verticalLayout_14->setObjectName("verticalLayout_14");
        stackedWidget = new QStackedWidget(MainApp);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 90, 301, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        usernum = new QLineEdit(verticalLayoutWidget);
        usernum->setObjectName("usernum");

        verticalLayout->addWidget(usernum);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        passwd = new QLineEdit(verticalLayoutWidget);
        passwd->setObjectName("passwd");

        verticalLayout_8->addWidget(passwd);


        verticalLayout->addLayout(verticalLayout_8);

        error_msg = new QLabel(verticalLayoutWidget);
        error_msg->setObjectName("error_msg");

        verticalLayout->addWidget(error_msg, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        connection = new QPushButton(verticalLayoutWidget);
        connection->setObjectName("connection");

        horizontalLayout->addWidget(connection);

        inscription = new QPushButton(verticalLayoutWidget);
        inscription->setObjectName("inscription");

        horizontalLayout->addWidget(inscription);


        verticalLayout->addLayout(horizontalLayout);

        TitleLogin = new QLabel(page);
        TitleLogin->setObjectName("TitleLogin");
        TitleLogin->setGeometry(QRect(90, 40, 211, 31));
        TitleLogin->setStyleSheet(QString::fromUtf8("* {\n"
"font-size: 20px;\n"
"}"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayoutWidget_10 = new QWidget(page_2);
        verticalLayoutWidget_10->setObjectName("verticalLayoutWidget_10");
        verticalLayoutWidget_10->setGeometry(QRect(0, 0, 411, 381));
        verticalLayout_23 = new QVBoxLayout(verticalLayoutWidget_10);
        verticalLayout_23->setObjectName("verticalLayout_23");
        verticalLayout_23->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        nameinput = new QLineEdit(verticalLayoutWidget_10);
        nameinput->setObjectName("nameinput");

        verticalLayout_2->addWidget(nameinput);

        firstnameinput = new QLineEdit(verticalLayoutWidget_10);
        firstnameinput->setObjectName("firstnameinput");

        verticalLayout_2->addWidget(firstnameinput);

        adress = new QLineEdit(verticalLayoutWidget_10);
        adress->setObjectName("adress");

        verticalLayout_2->addWidget(adress);

        password = new QLineEdit(verticalLayoutWidget_10);
        password->setObjectName("password");
        password->setEnabled(true);

        verticalLayout_2->addWidget(password);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        birth = new QLabel(verticalLayoutWidget_10);
        birth->setObjectName("birth");

        horizontalLayout_2->addWidget(birth);

        radioMan = new QRadioButton(verticalLayoutWidget_10);
        radioMan->setObjectName("radioMan");

        horizontalLayout_2->addWidget(radioMan);

        radioFemale = new QRadioButton(verticalLayoutWidget_10);
        radioFemale->setObjectName("radioFemale");

        horizontalLayout_2->addWidget(radioFemale);

        radioNP = new QRadioButton(verticalLayoutWidget_10);
        radioNP->setObjectName("radioNP");

        horizontalLayout_2->addWidget(radioNP);


        verticalLayout_2->addLayout(horizontalLayout_2);

        birthDate = new QDateEdit(verticalLayoutWidget_10);
        birthDate->setObjectName("birthDate");
        birthDate->setLocale(QLocale(QLocale::French, QLocale::France));
        birthDate->setTimeSpec(Qt::UTC);
        birthDate->setDate(QDate(2022, 12, 29));

        verticalLayout_2->addWidget(birthDate);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cancel = new QPushButton(verticalLayoutWidget_10);
        cancel->setObjectName("cancel");

        horizontalLayout_3->addWidget(cancel);

        register_2 = new QPushButton(verticalLayoutWidget_10);
        register_2->setObjectName("register_2");

        horizontalLayout_3->addWidget(register_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_23->addLayout(verticalLayout_2);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        horizontalLayoutWidget_4 = new QWidget(page_3);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(0, 150, 381, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_8 = new QLabel(horizontalLayoutWidget_4);
        label_8->setObjectName("label_8");

        verticalLayout_3->addWidget(label_8, 0, Qt::AlignHCenter);

        toInfo = new QPushButton(horizontalLayoutWidget_4);
        toInfo->setObjectName("toInfo");

        verticalLayout_3->addWidget(toInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("* {\n"
"font-size: 15px;\n"
"}"));

        verticalLayout_4->addWidget(label, 0, Qt::AlignHCenter);

        sold_tofill = new QLabel(horizontalLayoutWidget_4);
        sold_tofill->setObjectName("sold_tofill");

        verticalLayout_4->addWidget(sold_tofill, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalLayoutWidget_5 = new QWidget(page_3);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(0, 270, 383, 71));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        tolivret = new QPushButton(horizontalLayoutWidget_5);
        tolivret->setObjectName("tolivret");

        horizontalLayout_5->addWidget(tolivret);

        virement = new QPushButton(horizontalLayoutWidget_5);
        virement->setObjectName("virement");

        horizontalLayout_5->addWidget(virement);

        deconnexion = new QPushButton(horizontalLayoutWidget_5);
        deconnexion->setObjectName("deconnexion");

        horizontalLayout_5->addWidget(deconnexion);

        verticalLayoutWidget_12 = new QWidget(page_3);
        verticalLayoutWidget_12->setObjectName("verticalLayoutWidget_12");
        verticalLayoutWidget_12->setGeometry(QRect(-10, 70, 401, 52));
        verticalLayout_17 = new QVBoxLayout(verticalLayoutWidget_12);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        IBAN = new QLabel(verticalLayoutWidget_12);
        IBAN->setObjectName("IBAN");

        verticalLayout_17->addWidget(IBAN, 0, Qt::AlignHCenter);

        verticalLayoutWidget_4 = new QWidget(page_3);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 401, 41));
        verticalLayout_18 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_4);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:20px;\n"
"}"));

        verticalLayout_18->addWidget(label_12, 0, Qt::AlignHCenter);

        horizontalLayoutWidget_6 = new QWidget(page_3);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(0, 40, 381, 31));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        nom_tofill = new QLabel(horizontalLayoutWidget_6);
        nom_tofill->setObjectName("nom_tofill");

        horizontalLayout_15->addWidget(nom_tofill, 0, Qt::AlignHCenter);

        prenom_tofill = new QLabel(horizontalLayoutWidget_6);
        prenom_tofill->setObjectName("prenom_tofill");

        horizontalLayout_15->addWidget(prenom_tofill, 0, Qt::AlignHCenter);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayoutWidget_8 = new QWidget(page_4);
        verticalLayoutWidget_8->setObjectName("verticalLayoutWidget_8");
        verticalLayoutWidget_8->setGeometry(QRect(0, 0, 381, 61));
        verticalLayout_21 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_21->setObjectName("verticalLayout_21");
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_8);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:20px;\n"
"}"));

        verticalLayout_21->addWidget(label_2, 0, Qt::AlignHCenter);

        verticalLayoutWidget_9 = new QWidget(page_4);
        verticalLayoutWidget_9->setObjectName("verticalLayoutWidget_9");
        verticalLayoutWidget_9->setGeometry(QRect(0, 70, 371, 311));
        verticalLayout_22 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_22->setObjectName("verticalLayout_22");
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_5 = new QLabel(verticalLayoutWidget_9);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("* {\n"
"font-size: 15px;\n"
"}"));

        verticalLayout_6->addWidget(label_5, 0, Qt::AlignHCenter);

        sold_tofill_2 = new QLabel(verticalLayoutWidget_9);
        sold_tofill_2->setObjectName("sold_tofill_2");

        verticalLayout_6->addWidget(sold_tofill_2, 0, Qt::AlignHCenter);


        verticalLayout_5->addLayout(verticalLayout_6);

        lineEdit = new QLineEdit(verticalLayoutWidget_9);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_5->addWidget(lineEdit);

        label_4 = new QLabel(verticalLayoutWidget_9);
        label_4->setObjectName("label_4");

        verticalLayout_5->addWidget(label_4);

        listAccount = new QComboBox(verticalLayoutWidget_9);
        listAccount->setObjectName("listAccount");

        verticalLayout_5->addWidget(listAccount);

        RIB = new QLineEdit(verticalLayoutWidget_9);
        RIB->setObjectName("RIB");

        verticalLayout_5->addWidget(RIB);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        toHome = new QPushButton(verticalLayoutWidget_9);
        toHome->setObjectName("toHome");

        horizontalLayout_6->addWidget(toHome);

        transfer = new QPushButton(verticalLayoutWidget_9);
        transfer->setObjectName("transfer");

        horizontalLayout_6->addWidget(transfer);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_22->addLayout(verticalLayout_5);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        verticalLayout_7 = new QVBoxLayout(page_5);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_6 = new QLabel(page_5);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:23px;}"));

        verticalLayout_7->addWidget(label_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        baktohome = new QPushButton(page_5);
        baktohome->setObjectName("baktohome");

        horizontalLayout_11->addWidget(baktohome);


        verticalLayout_7->addLayout(horizontalLayout_11);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        verticalLayout_10 = new QVBoxLayout(page_6);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_3 = new QLabel(page_6);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:20px;\n"
"}"));

        verticalLayout_9->addWidget(label_3, 0, Qt::AlignHCenter);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        idUserInfo = new QLabel(page_6);
        idUserInfo->setObjectName("idUserInfo");
        idUserInfo->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard);

        verticalLayout_13->addWidget(idUserInfo, 0, Qt::AlignHCenter);


        verticalLayout_9->addLayout(verticalLayout_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        nameInfo = new QLabel(page_6);
        nameInfo->setObjectName("nameInfo");

        verticalLayout_12->addWidget(nameInfo);

        adressInfo = new QLabel(page_6);
        adressInfo->setObjectName("adressInfo");

        verticalLayout_12->addWidget(adressInfo);

        birthInfo = new QLabel(page_6);
        birthInfo->setObjectName("birthInfo");

        verticalLayout_12->addWidget(birthInfo);

        genreInfo = new QLabel(page_6);
        genreInfo->setObjectName("genreInfo");

        verticalLayout_12->addWidget(genreInfo);


        horizontalLayout_8->addLayout(verticalLayout_12);


        horizontalLayout_12->addLayout(horizontalLayout_8);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_2);

        accountbox = new QComboBox(page_6);
        accountbox->setObjectName("accountbox");

        verticalLayout_15->addWidget(accountbox);

        sumAcc = new QLabel(page_6);
        sumAcc->setObjectName("sumAcc");

        verticalLayout_15->addWidget(sumAcc, 0, Qt::AlignHCenter);


        horizontalLayout_12->addLayout(verticalLayout_15);


        horizontalLayout_7->addLayout(horizontalLayout_12);


        verticalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        tohomefrominfo = new QPushButton(page_6);
        tohomefrominfo->setObjectName("tohomefrominfo");

        horizontalLayout_10->addWidget(tohomefrominfo);


        verticalLayout_9->addLayout(horizontalLayout_10);


        verticalLayout_10->addLayout(verticalLayout_9);

        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_7 = new QLabel(page_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 10, 171, 41));
        label_7->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:20px;\n"
"}"));
        verticalLayoutWidget_11 = new QWidget(page_7);
        verticalLayoutWidget_11->setObjectName("verticalLayoutWidget_11");
        verticalLayoutWidget_11->setGeometry(QRect(0, 60, 381, 321));
        verticalLayout_16 = new QVBoxLayout(verticalLayoutWidget_11);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_11);
        label_9->setObjectName("label_9");

        verticalLayout_16->addWidget(label_9);

        interest = new QComboBox(verticalLayoutWidget_11);
        interest->addItem(QString());
        interest->addItem(QString());
        interest->setObjectName("interest");

        verticalLayout_16->addWidget(interest);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_16->addItem(verticalSpacer_3);

        label_10 = new QLabel(verticalLayoutWidget_11);
        label_10->setObjectName("label_10");

        verticalLayout_16->addWidget(label_10);

        montant = new QLineEdit(verticalLayoutWidget_11);
        montant->setObjectName("montant");

        verticalLayout_16->addWidget(montant);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        pushButton_3 = new QPushButton(verticalLayoutWidget_11);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_9->addWidget(pushButton_3);

        createAccount = new QPushButton(verticalLayoutWidget_11);
        createAccount->setObjectName("createAccount");

        horizontalLayout_9->addWidget(createAccount);


        verticalLayout_16->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        verticalLayoutWidget_3 = new QWidget(page_8);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 381, 51));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:20px;\n"
"}"));

        verticalLayout_11->addWidget(label_11, 0, Qt::AlignHCenter);

        horizontalLayoutWidget = new QWidget(page_8);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 60, 381, 321));
        horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        virIntern = new QPushButton(horizontalLayoutWidget);
        virIntern->setObjectName("virIntern");

        horizontalLayout_14->addWidget(virIntern);

        virExtern = new QPushButton(horizontalLayoutWidget);
        virExtern->setObjectName("virExtern");

        horizontalLayout_14->addWidget(virExtern);


        horizontalLayout_13->addLayout(horizontalLayout_14);

        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        verticalLayoutWidget_6 = new QWidget(page_9);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(0, 0, 381, 80));
        verticalLayout_19 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_19->setObjectName("verticalLayout_19");
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget_6);
        label_13->setObjectName("label_13");
        label_13->setStyleSheet(QString::fromUtf8("* {\n"
"font-size:20px;\n"
"}"));

        verticalLayout_19->addWidget(label_13, 0, Qt::AlignHCenter);

        verticalLayoutWidget_7 = new QWidget(page_9);
        verticalLayoutWidget_7->setObjectName("verticalLayoutWidget_7");
        verticalLayoutWidget_7->setGeometry(QRect(0, 90, 381, 241));
        verticalLayout_20 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_20->setObjectName("verticalLayout_20");
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(verticalLayoutWidget_7);
        label_14->setObjectName("label_14");

        verticalLayout_20->addWidget(label_14);

        compteemet = new QComboBox(verticalLayoutWidget_7);
        compteemet->setObjectName("compteemet");

        verticalLayout_20->addWidget(compteemet);

        soldeCompteemetteur = new QLabel(verticalLayoutWidget_7);
        soldeCompteemetteur->setObjectName("soldeCompteemetteur");

        verticalLayout_20->addWidget(soldeCompteemetteur);

        label_15 = new QLabel(verticalLayoutWidget_7);
        label_15->setObjectName("label_15");

        verticalLayout_20->addWidget(label_15);

        compterecept = new QComboBox(verticalLayoutWidget_7);
        compterecept->setObjectName("compterecept");

        verticalLayout_20->addWidget(compterecept);

        label_16 = new QLabel(verticalLayoutWidget_7);
        label_16->setObjectName("label_16");

        verticalLayout_20->addWidget(label_16);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_7);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_20->addWidget(lineEdit_2);

        horizontalLayoutWidget_7 = new QWidget(page_9);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(0, 340, 381, 41));
        horizontalLayout_16 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        tovir = new QPushButton(horizontalLayoutWidget_7);
        tovir->setObjectName("tovir");

        horizontalLayout_16->addWidget(tovir);

        tovirementemis = new QPushButton(horizontalLayoutWidget_7);
        tovirementemis->setObjectName("tovirementemis");

        horizontalLayout_16->addWidget(tovirementemis);

        stackedWidget->addWidget(page_9);

        verticalLayout_14->addWidget(stackedWidget);


        retranslateUi(MainApp);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainApp);
    } // setupUi

    void retranslateUi(QDialog *MainApp)
    {
        MainApp->setWindowTitle(QCoreApplication::translate("MainApp", "Dialog", nullptr));
        usernum->setPlaceholderText(QCoreApplication::translate("MainApp", "Num\303\251ro de compte", nullptr));
        passwd->setPlaceholderText(QCoreApplication::translate("MainApp", "Mot de passe", nullptr));
        error_msg->setText(QString());
        connection->setText(QCoreApplication::translate("MainApp", "Connexion", nullptr));
        inscription->setText(QCoreApplication::translate("MainApp", "Inscription", nullptr));
        TitleLogin->setText(QCoreApplication::translate("MainApp", "Veuillez vous connecter", nullptr));
        nameinput->setPlaceholderText(QCoreApplication::translate("MainApp", "Nom", nullptr));
        firstnameinput->setPlaceholderText(QCoreApplication::translate("MainApp", "Pr\303\251nom", nullptr));
        adress->setText(QString());
        adress->setPlaceholderText(QCoreApplication::translate("MainApp", "Adresse", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("MainApp", "Mot de passe", nullptr));
        birth->setText(QCoreApplication::translate("MainApp", "Date de naissance :", nullptr));
        radioMan->setText(QCoreApplication::translate("MainApp", "Homme", nullptr));
        radioFemale->setText(QCoreApplication::translate("MainApp", "Femme", nullptr));
        radioNP->setText(QCoreApplication::translate("MainApp", "Non pr\303\251cis\303\251", nullptr));
        cancel->setText(QCoreApplication::translate("MainApp", "Retour", nullptr));
        register_2->setText(QCoreApplication::translate("MainApp", "S'inscrire", nullptr));
        label_8->setText(QCoreApplication::translate("MainApp", "Vos informations", nullptr));
        toInfo->setText(QCoreApplication::translate("MainApp", "Profil", nullptr));
        label->setText(QCoreApplication::translate("MainApp", "Solde total :", nullptr));
        sold_tofill->setText(QCoreApplication::translate("MainApp", "TextLabel", nullptr));
        tolivret->setText(QCoreApplication::translate("MainApp", "Cr\303\251er un livret", nullptr));
        virement->setText(QCoreApplication::translate("MainApp", "Effectuer un virement", nullptr));
        deconnexion->setText(QCoreApplication::translate("MainApp", "Se d\303\251connecter", nullptr));
        IBAN->setText(QCoreApplication::translate("MainApp", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainApp", "Bienvenue dans votre espace N27 ! ", nullptr));
        nom_tofill->setText(QCoreApplication::translate("MainApp", "Nom_tofill", nullptr));
        prenom_tofill->setText(QCoreApplication::translate("MainApp", "Prenom_tofill", nullptr));
        label_2->setText(QCoreApplication::translate("MainApp", "Virement externe", nullptr));
        label_5->setText(QCoreApplication::translate("MainApp", "Votre solde :", nullptr));
        sold_tofill_2->setText(QCoreApplication::translate("MainApp", "sold_tofill", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainApp", "Montant du virement", nullptr));
        label_4->setText(QCoreApplication::translate("MainApp", "Compte \303\251metteur :", nullptr));
        RIB->setPlaceholderText(QCoreApplication::translate("MainApp", "RIB destinataire", nullptr));
        toHome->setText(QCoreApplication::translate("MainApp", "Retour", nullptr));
        transfer->setText(QCoreApplication::translate("MainApp", "Effectuer le virement", nullptr));
        label_6->setText(QCoreApplication::translate("MainApp", "Votre virement a bien \303\251t\303\251 effectu\303\251 !", nullptr));
        baktohome->setText(QCoreApplication::translate("MainApp", "Retour", nullptr));
        label_3->setText(QCoreApplication::translate("MainApp", "Vos informations", nullptr));
        idUserInfo->setText(QCoreApplication::translate("MainApp", "TextLabel", nullptr));
        nameInfo->setText(QCoreApplication::translate("MainApp", "Nom Pr\303\251nom", nullptr));
        adressInfo->setText(QCoreApplication::translate("MainApp", "TextLabel", nullptr));
        birthInfo->setText(QCoreApplication::translate("MainApp", "N\303\251 le :", nullptr));
        genreInfo->setText(QCoreApplication::translate("MainApp", "TextLabel", nullptr));
        sumAcc->setText(QCoreApplication::translate("MainApp", "TextLabel", nullptr));
        tohomefrominfo->setText(QCoreApplication::translate("MainApp", "Retour", nullptr));
        label_7->setText(QCoreApplication::translate("MainApp", "Cr\303\251ation d'un livret", nullptr));
        label_9->setText(QCoreApplication::translate("MainApp", "Type de livret : ", nullptr));
        interest->setItemText(0, QCoreApplication::translate("MainApp", "Livret A", nullptr));
        interest->setItemText(1, QCoreApplication::translate("MainApp", "Livret Jeune", nullptr));

        label_10->setText(QCoreApplication::translate("MainApp", "Montant disponible sur ce livret : ", nullptr));
        montant->setPlaceholderText(QCoreApplication::translate("MainApp", "Entrer un montant (afin de tester les transactions)", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainApp", "Retour", nullptr));
        createAccount->setText(QCoreApplication::translate("MainApp", "Cr\303\251er", nullptr));
        label_11->setText(QCoreApplication::translate("MainApp", "S\303\251lectionnez un type de virement", nullptr));
        virIntern->setText(QCoreApplication::translate("MainApp", "Virement Interne", nullptr));
        virExtern->setText(QCoreApplication::translate("MainApp", "Virement externe", nullptr));
        label_13->setText(QCoreApplication::translate("MainApp", "Virement Interne", nullptr));
        label_14->setText(QCoreApplication::translate("MainApp", "Compte \303\251metteur :", nullptr));
        soldeCompteemetteur->setText(QCoreApplication::translate("MainApp", "SoldeCompteEmet", nullptr));
        label_15->setText(QCoreApplication::translate("MainApp", "Compte r\303\251cepteur :", nullptr));
        label_16->setText(QCoreApplication::translate("MainApp", "Montant : ", nullptr));
        tovir->setText(QCoreApplication::translate("MainApp", "Retour", nullptr));
        tovirementemis->setText(QCoreApplication::translate("MainApp", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainApp: public Ui_MainApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINAPP_H
