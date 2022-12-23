//
// Created by remi on 30/11/22.
//

#include "user.hpp"
#include <iostream>
#include <fstream>
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
    return accounts[index];
}

void user::addAccount(int id) {
    // Si le compte n'existe pas déjà
    if (find(accounts.begin(), accounts.end(), id) == accounts.end())
        accounts.push_back(id);
}

ostream& operator<<(ostream& os, const user& user)
{
    auto infos = user.getInfos();
    os << "Nom: " << infos.nom << endl;
    os << "Prénom: " << infos.prenom << endl;
    os << "Adresse: " << infos.addr << endl;

    os << "Numéro de client: " << user.getId() << endl;
    os << "Comptes: (" << user.getAccounts().size() << ")" << endl << endl;
    for (auto& it : user.getAccounts())
        os << it << endl;

    os << "--------------------" << endl;
    return os;
}