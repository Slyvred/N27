//
// Created by remi on 30/11/22.
//

#include "user.hpp"
#include <iostream>
#include <fstream>
#include <exception>
#include "json.hpp"
using json = nlohmann::json;


// Constructeur réduit, la plus grande partie se fait dans agency::createUser
user::user(infos& infos, int n_accounts) : m_infos(infos), n_accounts(n_accounts){
    id = rand();
}

int user::getId() const {
    return id;
}

void user::setId(int id) {
    this->id = id;
}

const infos &user::getInfos() const {
    return m_infos;
}

const vector<int> &user::getAccounts() const {
    return accounts;
}

const int &user::getAccount(int index) const {

    // if (this->m_infos == (infos){"none", "none", "none"})
    // {
    //     return accounts[0];
    // }

    return (index < accounts.size()) ? accounts[index] : accounts[0];
}

void user::addAccount(int id) {
    // Si le compte n'existe pas déjà
    if (find(accounts.begin(), accounts.end(), id) == accounts.end()) {
        accounts.push_back(id);
        n_accounts++;
    }
}

ostream& operator<<(ostream& os, const user& user)
{
    auto infos = user.getInfos();
    os << "Nom: " << infos.nom << endl;
    os << "Prénom: " << infos.prenom << endl;
    os << "Adresse: " << infos.addr << endl;
    os << "Date de naissance: " << infos.date_naiss << endl;
    os << "Genre: " << infos.genre << endl;
    os << "Mot de passe: " << infos.passwd << endl;



    os << "Numéro de client: " << user.getId() << endl;
    os << "Comptes: (" << user.getAccounts().size() << ")" << endl << endl;
    for (auto& it : user.getAccounts())
        os << it << endl;

    os << "--------------------" << endl;
    return os;
}