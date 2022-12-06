//
// Created by remi on 30/11/22.
//

#include "agency.h"
#include <fstream>
#include <string>
using json = nlohmann::json;

agency::agency() {
    id = rand();

    n_users = 0;
}

void agency::createUser(infos &infos, int n_accounts) {
    user tmp(infos, n_accounts);
    n_users++;

    // On vérifie que l'id est unique
    while (users.find(tmp.getId()) != users.end())
        tmp.setId(rand());

    // On ajoute les comptes
    for (int i = 0; i < n_accounts; ++i) {
        auto acc = account(1, 0);

        // On vérifie que l'id est unique
        while (accounts.find(acc.getId()) != accounts.end())
            acc.setId(rand());

        // On ajoute le compte dans agency
        accounts.insert({acc.getId(), acc});

        // On ajoute le numéro de compte dans user
        tmp.addAccount(acc.getId());
    }
    // On ajoute l'utilisateur dans la base de données
    users.insert({tmp.getId(), tmp});
}

user &agency::getuser(int id) {
    auto index = users.find(id);

    return users.at(id);
}

void agency::deleteUser(int id) {
    if (users.find(id) != users.end()) users.erase(id);
    n_users--;
}

void agency::send(int from_acc, int to_acc, float amount) {

    // ONn vérifie que les comptes sont valides
    if (accounts.find(from_acc) == accounts.end() || accounts.find(to_acc) == accounts.end())
        return;

    // On vérifie que le solde permet le virement
    auto solde = accounts.at(from_acc).getSolde();
    if (solde < amount) return;

    // On effectue le virement
    accounts.at(from_acc).setSolde(solde - amount);
    accounts.at(to_acc).setSolde(accounts.at(to_acc).getSolde() + amount);

    // On ajoute le virement dans l'historique de transactions
    transactions.push_back({from_acc, to_acc, amount});
}

const unordered_map<int, user> &agency::getUsers() const {
    return users;
}

const unordered_map<int, account> &agency::getAccounts() const {
    return accounts;
}

void agency::exportUsers() const {
    ofstream file("U" + to_string(id) + ".json");
    if (file.is_open())
    {
        //cout << clients.size();
        json user;
        for (auto &it : users)
        {
            //cout <<it.first <<endl;
            auto cInfos = it.second.getInfos();
            auto num = it.first;
            auto str_num = to_string(num);
            auto nbAcc = it.second.getAccounts().size();

            user["id"][str_num]["infos"]["nom"] = cInfos.nom;
            user["id"][str_num]["infos"]["prenom"] = cInfos.prenom;
            user["id"][str_num]["infos"]["adresse"] = cInfos.addr;
            user["id"][str_num]["numero"] = num;

            // Nous donne le nombre d'itérations à faire dans importJson
            user["id"][str_num]["nbAccounts"] = nbAcc;

            int i = 0;
            for (auto it2 : it.second.getAccounts())
            {
                user["id"][str_num]["accounts"][i] = it2;
                i++;
            }
        }
        file << setw(4) << user << endl;
        file.close();
    }
    else
    {
        cerr << "Couldn't open file ! " << endl;
    }
}

void agency::exportAcounts() const {

    ofstream file("A" + to_string(id) + ".json");

    if (file.is_open())
    {
        json account;

        for (auto& it: accounts)
        {
            auto num = it.first;
            auto acc = it.second;

            auto str_num = to_string(num);

            //cout << num << endl;
            //cout << acc << endl;

            account["id"][str_num]["interests"] = acc.getInterets();
            account["id"][str_num]["solde"] = acc.getSolde();
            account["id"][str_num]["id"] = acc.getId();
        }

        file << setw(4) << account << endl;
        file.close();
    }
    else
    {
        cerr << "Couldn't open file ! " << endl;
    }
}

void agency::importAcounts() {
    string filename = "A" + to_string(id) + ".json";
    ifstream file(filename);
    json obj = json::parse(file);

    for (auto &it : obj["id"]) {
        auto id = it["id"];
        auto interets = it["interests"];
        auto solde = it["solde"];

        account tmp(interets, solde);
        tmp.setId(id);

        accounts.insert({id, tmp});
    }
}

void agency::importUsers() {
    string filename = "U" + to_string(id) + ".json";
    ifstream file(filename);
    json obj = json::parse(file);
    infos inf;

    for (auto &it : obj["id"]) {
        cout << it << endl;

        inf.addr = it["infos"]["adresse"];
        inf.nom = it["infos"]["nom"];
        inf.prenom = it["infos"]["prenom"];

        int nb_acc = it["nbAccounts"];
        int num = it["numero"];

        user tmp(inf, nb_acc);
        for (auto &acc : it["accounts"])
            tmp.addAccount(acc);

        tmp.setId(num);
        n_users++;
        users.insert({num, tmp});
    }
}