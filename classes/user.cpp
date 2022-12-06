//
// Created by remi on 30/11/22.
//

#include "user.h"
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
    os << "--------------------" << endl;
    os << "Nom: " << infos.nom << endl;
    os << "Prénom: " << infos.prenom << endl;
    os << "Adresse: " << infos.addr << endl;

    os << "Numéro de client: " << user.getId() << endl;
    os << "Comptes: (" << user.getAccounts().size() << ")" << endl << endl;
    for (auto& it : user.getAccounts())
        os << it << endl;

    return os;
}

void user::exportJson() const
{
    ofstream file(to_string(id) + ".json");

    if (file.is_open())
    {
        json client;
        client["infos"]["nom"] = m_infos.nom;
        client["infos"]["prenom"] = m_infos.prenom;
        client["infos"]["adresse"] = m_infos.addr;
        client["numero"] = id;

        // Nous donne le nombre d'itérations à faire dans importJson
        client["nbAccounts"] = n_accounts;

        int i = 0;
        for (auto& it : accounts)
        {
            client["accounts"][i] = it;
            i++;
        }

        file << setw(4) << client << endl;
        file.close();
    }
    else
    {
        cerr << "Couldn't open file ! " << endl;
    }
}

void user::importJson(int id)
{
    string filename = to_string(id) + ".json";
    ifstream file(filename);
    json obj = json::parse(file);

    id = obj["numero"];
    m_infos.addr = obj["infos"]["adresse"];
    m_infos.nom = obj["infos"]["nom"];
    m_infos.prenom = obj["infos"]["prenom"];

    for (int i = 0; i < obj["nbAccounts"]; i++)
    {
        accounts.push_back(obj["accounts"][i]);
    }
}