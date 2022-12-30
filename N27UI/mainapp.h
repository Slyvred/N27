#ifndef MAINAPP_H
#define MAINAPP_H

#include <QDialog>
#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QDateEdit>
#include <QDate>
#include <QComboBox>
#include <QIcon>
#include <QVariant>
#include <QList>

#include <iostream>
#include <string>
#include <thread>

#include "../classes/account.hpp"
#include "../classes/agency.hpp"
#include "../classes/json.hpp"
#include "../classes/socket.hpp"
#include "../classes/user.hpp"

namespace Ui {
class MainApp;
}

class MainApp : public QDialog
{
    Q_OBJECT

public:
    explicit MainApp(QWidget *parent = nullptr);
    virtual ~MainApp();
    agency ag;
    int userID;

private slots:

    void on_connection_clicked();

    void on_inscription_clicked();

    void on_register_2_clicked();

    void on_cancel_clicked();

    void on_virement_clicked();

    void on_deconnexion_clicked();

    void on_toHome_clicked();

    void on_baktohome_clicked();

    void on_transfer_clicked();

    void on_toInfo_clicked();

    void on_pushButton_3_clicked();

    void on_createAccount_clicked();

    void on_tolivret_clicked();

    void on_tohomefrominfo_clicked();

    void on_accountbox_currentIndexChanged(int index);

    void on_virExtern_clicked();

    void on_listAccount_currentIndexChanged(int index);

    void on_virIntern_clicked();

    void on_compteemet_currentIndexChanged(int index);

    void on_tovirementemis_clicked();

    void on_tovir_clicked();

private:
    Ui::MainApp *ui;
};

#endif // MAINAPP_H
