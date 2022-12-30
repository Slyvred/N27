//
//  Created by Hippolyte, updated 12/30/22
//

#include "mainapp.h"
#include "ui_mainapp.h"

MainApp::MainApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainApp)
{
    ui->setupUi(this);
}

MainApp::~MainApp()
{
    delete ui;
}

void MainApp::on_connection_clicked()
{
    int numacc = ui->usernum->text().toInt();
    auto passwd = ui->passwd->text();

    unordered_map<int, user> liste = ag.getUsers();

    std::unordered_map<int, user>::iterator it = liste.find(numacc);

    if(it != liste.end() && it->second.getInfos().passwd == passwd.toStdString()) {
     userID = numacc;

     QString name = QString::fromStdString(ag.getUser(userID).getInfos().nom);
     QString firstname = QString::fromStdString(ag.getUser(userID).getInfos().prenom);

     ui->nom_tofill->setText(name);
     ui->prenom_tofill->setText(firstname);

     ui->IBAN->setText(QString::number(userID));

     const vector<int> UserAcc = ag.getUser(userID).getAccounts();

        float soldetotal = 0.0;

        for(int value : UserAcc) {
            soldetotal += ag.getAccount(value).getSolde();
        }

     ui->sold_tofill->setText(QString::number(soldetotal));

     ui->stackedWidget->setCurrentIndex(2);
    }
    else {
        ui->error_msg->setText("Numéro de client ou mot de passe invalide !");
    }
}


void MainApp::on_inscription_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}


void MainApp::on_register_2_clicked()
{
    std::string name = ui->nameinput->text().toStdString();
    std::string firstname = ui->firstnameinput->text().toStdString();
    std::string adresse = ui->adress->text().toStdString();

    std::string genre;

    if(ui->radioMan->isChecked())
        genre = "Homme";
    else if (ui->radioFemale->isChecked())
        genre = "Femme";
    else
        genre = "Non précisé";

    std::string password = ui->password->text().toStdString();

    QDate naissance = ui->birthDate->date();

    std::string birth = naissance.toString("dd-MM-yyyy").toStdString();


    infos inf = {name , firstname, adresse, birth, genre, password};

    ag.createUser(inf, 1);

    ag.exportAll();

    userID = ag.idOfNewUser;

    QString Nom = QString::fromStdString(ag.getUser(userID).getInfos().nom);
    QString Prenom = QString::fromStdString(ag.getUser(userID).getInfos().prenom);

    ui->IBAN->setText(QString::number(userID));

    ui->nom_tofill->setText(Nom);
    ui->prenom_tofill->setText(Prenom);

    const vector<int> UserAcc = ag.getUser(userID).getAccounts();

       float soldetotal = 0.0;

       for(int value : UserAcc) {
           soldetotal += ag.getAccount(value).getSolde();
       }

    ui->sold_tofill->setText(QString::number(soldetotal));

    ui->stackedWidget->setCurrentIndex(2);
}


void MainApp::on_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainApp::on_virement_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainApp::on_deconnexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainApp::on_toHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainApp::on_baktohome_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainApp::on_transfer_clicked()
{
    auto to_acc = ui->RIB->text();
    auto from_acc = ui->listAccount->currentText();
    auto amount = ui->lineEdit->text();
    auto solde = ag.getAccount(from_acc.toInt()).getSolde();

    if (to_acc.isEmpty() || amount.toFloat() > solde)
    {
       // Erreur
        std::cerr << "Erreur lors du virement externe de " << from_acc.toInt() << " vers " << to_acc.toInt() << " de " << amount.toFloat() << "$" << std::endl;
        return;
    }
    else
    {
        // Sinon on effectue le virement et on change de page
        std::cout << "Virement externe de " << from_acc.toInt() << " vers " << to_acc.toInt() << " de " << amount.toFloat() << "$" << std::endl;
        ag.send(from_acc.toInt(), to_acc.toInt(), amount.toFloat());
        ag.exportAll();
        ui->stackedWidget->setCurrentIndex(4);

        auto solde_tot = ui->sold_tofill->text().toFloat() - amount.toFloat();
        ui->sold_tofill->setText(QString::number(solde_tot));
    }
}


void MainApp::on_toInfo_clicked()
{
    QString Infoname = QString::fromStdString(ag.getUser(userID).getInfos().nom) + " " + QString::fromStdString(ag.getUser(userID).getInfos().prenom);
    ui->nameInfo->setText(Infoname);

    QString Infonaissance = QString::fromStdString(ag.getUser(userID).getInfos().date_naiss);
    ui->birthInfo->setText(Infonaissance);

    QString Infoadress = QString::fromStdString(ag.getUser(userID).getInfos().addr);
    ui->adressInfo->setText(Infoadress);


    QString Infogenre = QString::fromStdString(ag.getUser(userID).getInfos().genre);
    ui->genreInfo->setText(Infogenre);


    ui->idUserInfo->setText("Numéro d'utilisateur : " + QString::number(userID));

    const vector<int> UserAcc = ag.getUser(userID).getAccounts();

    QStringList labels;
    QList<QVariant>  dataList;
    ui->accountbox->clear();

    for(int value : UserAcc) {
        auto displayAcc = ag.getAccount(value).getInterets();
        QVariant data(ag.getAccount(value).getId());
        QString label;

        if (displayAcc == 1.02f)
            label = "Livret A";
        else if (displayAcc == 1.03f)
            label = "Livret Jeune";
        else
            label = "Compte Courant";

        ui->accountbox->addItem(label, data);
    }
    ui->stackedWidget->setCurrentIndex(5);
}


void MainApp::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainApp::on_createAccount_clicked()
{
    size_t solde = ui->montant->text().toFloat();
    std::string typeAcc = ui->interest->currentText().toStdString();
    float interet;

    if(typeAcc == "Livret A")
        interet = 1.02f; // 2%
    else if(typeAcc == "Livret Jeune")
        interet = 1.03f; // 3%
    else
        interet = 1.0f; // 0%

    ag.addAccount(userID, interet, solde);

    ag.getUser(userID).addAccount(ag.idOfNewAcc);

    ag.exportAll();

    const vector<int> UserAcc = ag.getUser(userID).getAccounts();

       float soldetotal = 0.0;

       for(int value : UserAcc) {
           soldetotal += ag.getAccount(value).getSolde();
       }

       ui->sold_tofill->setText(QString::number(soldetotal));

    ui->stackedWidget->setCurrentIndex(2);
}


void MainApp::on_tolivret_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainApp::on_tohomefrominfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainApp::on_accountbox_currentIndexChanged(int index)
{
    QVariant data = ui->accountbox->itemData(index);
    int idata = data.toInt();

    ui->sumAcc->setText(QString::number(ag.getAccount(idata).getSolde()));

}


void MainApp::on_virExtern_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    auto UserAcc = ag.getUser(userID).getAccounts();

    ui->listAccount->clear();

    for(int id : UserAcc) {
        ui->listAccount->addItem(QString::number(id));
    }
}


void MainApp::on_listAccount_currentIndexChanged(int index)
{
    auto selected_acc_solde = ag.getAccount(ui->listAccount->currentText().toInt()).getSolde();
    ui->sold_tofill_2->setText(QString::number(selected_acc_solde));
}


void MainApp::on_virIntern_clicked()
{
    auto UserAcc = ag.getUser(userID).getAccounts();

    ui->compteemet->clear();
    // On ajoute nos comptes dans les combobox
    for(int id : UserAcc) {
        ui->compteemet->addItem(QString::number(id));
    }

    ui->stackedWidget->setCurrentIndex(8);
}


void MainApp::on_compteemet_currentIndexChanged(int index)
{
    auto UserAcc = ag.getUser(userID).getAccounts();

    ui->compterecept->clear();
    // On ajoute les mêmes comptes à l'exception du compte emméteur
    for(int id : UserAcc) {
        auto acc = QString::number(id);
        if (acc == ui->compteemet->currentText()) continue;
        ui->compterecept->addItem(acc);
    }
    auto compte_emet_solde = ag.getAccount(ui->compteemet->currentText().toInt()).getSolde();
    ui->soldeCompteemetteur->setText(QString::number(compte_emet_solde));
}


void MainApp::on_tovirementemis_clicked()
{
    auto to_acc = ui->compterecept->currentText();
    auto from_acc = ui->compteemet->currentText();
    auto amount = ui->lineEdit_2->text();
    auto solde = ag.getAccount(from_acc.toInt()).getSolde();

    if (amount.isEmpty() || amount.toFloat() > solde)
    {
       // Erreur
        std::cerr << "Erreur lors du virement interne de " << from_acc.toInt() << " vers " << to_acc.toInt() << " de " << amount.toFloat() << "$" << std::endl;
        //std::cerr << "Car: amount.isEmpty() est " <<  amount.isEmpty() << "ou amount.toFloat() > solde est " << amount.toFloat() > solde << std::endl;
        return;
    }
    else
    {
        // Sinon on effectue le virement et on change de page
        ag.send(from_acc.toInt(), to_acc.toInt(), amount.toFloat());
        std::cout << "Virement interne de " << from_acc.toInt() << " vers " << to_acc.toInt() << " de " << amount.toFloat() << "$" << std::endl;
        ag.exportAll();
        ui->stackedWidget->setCurrentIndex(4);
    }
}


void MainApp::on_tovir_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

