//
// Created by remi on 30/11/22.
//

#include "agency.h"
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

user &agency::getUser(int id) {
    auto index = users.find(id);

    return users.at(id);
}

void agency::deleteUser(int id) {
    if (users.find(id) != users.end()) users.erase(id);
    n_users--;
}

void agency::send(int from_acc, int to_acc, float amount) {

    // On vérifie que les comptes sont valides
    if (accounts.find(from_acc) == accounts.end() || accounts.find(to_acc) == accounts.end())
        return;

    // On vérifie que le solde permet le virement
    auto solde = accounts.at(from_acc).getSolde();
    if (solde < amount) return;

    // On effectue le virement
    accounts.at(from_acc).setSolde(solde - amount);
    accounts.at(to_acc).setSolde(accounts.at(to_acc).getSolde() + amount);

    // On ajoute le virement dans l'historique de transactions
    transaction transac;
    transac.amount = amount;
    transac.from_acc = from_acc;
    transac.to_acc = to_acc;

    // Ici, on calcule le timestamp de la transaction pour savoir à quel moment elle a eu lieu
    const auto timestamp = chrono::system_clock::now();
    transac.timestamp = chrono::duration_cast<chrono::microseconds>(timestamp.time_since_epoch()).count();

    transactions.push_back(transac);
}

void agency::deposit(int to_acc, float amount) {
    // On vérifie que les comptes sont valides
    if (accounts.find(to_acc) == accounts.end())
        return;


    auto solde = accounts.at(to_acc).getSolde();
    accounts.at(to_acc).setSolde(solde + amount);

    // On ajoute le virement dans l'historique de transactions
    transaction transac;
    transac.amount = amount;
    transac.from_acc = to_acc;
    transac.to_acc = to_acc;

    // Ici, on calcule le timestamp de la transaction pour savoir à quel moment elle a eu lieu
    const auto timestamp = chrono::system_clock::now();
    transac.timestamp = chrono::duration_cast<chrono::microseconds>(timestamp.time_since_epoch()).count();

    transactions.push_back(transac);
}

const unordered_map<int, user> &agency::getUsers() const {
    return users;
}

const unordered_map<int, account> &agency::getAccounts() const {
    return accounts;
}

const vector<transaction> &agency::getTransactions() const {
    return transactions;
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
        file << setw(2) << user << endl;
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

        file << setw(2) << account << endl;
        file.close();
    }
    else
    {
        cerr << "Couldn't open file ! " << endl;
    }
}

void agency::exportTransactions() const {
    ofstream file("T" + to_string(id) + ".json");

    if (file.is_open())
    {
        json transac;

        for (auto& it: transactions)
        {
            auto str_num = to_string(it.from_acc);
            //auto str_timestamp = to_string(it.timestamp);

            //auto n_transac = count(transactions.begin(), transactions.end(), [&it](transaction tmp){return tmp.from_acc == it.from_acc;});
            auto n_transac = std::count_if(transactions.begin(), transactions.end(),[&it](transaction tmp){return tmp.from_acc == it.from_acc;});
            cout << n_transac << endl;
            cout << "from_acc: " << it.from_acc << endl;
            cout << "to_acc: " << it.to_acc << endl;
            cout << "amount: " << it.amount << endl;
            cout << "timestamp: " << it.timestamp << endl;

            //cout << num << endl;
            //cout << acc << endl;

            /*
            transac["id"][str_num]["toAcc"] = it.to_acc;
            transac["id"][str_num]["amount"] = it.amount;
            transac["id"][str_num]["timestamp"] = it.timestamp;*/

            for (auto i = 0; i < n_transac; i++)
            {
                transac["id"][str_num][i]["amount"] = it.amount;
                transac["id"][str_num][i]["toAcc"] = it.to_acc;
                transac["id"][str_num][i]["timestamp"] = it.timestamp;
            }
            transac["id"][str_num]["n_transac"] = n_transac;
        }

        file << setw(2) << transac << endl;
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
        cout << it << endl;
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

void agency::importTransactions() {
    string filename = "T" + to_string(id) + ".json";
    ifstream file(filename);
    json obj = json::parse(file);
    transaction transac;

    for (auto &it : obj["id"]) {
        cout << it << endl;
    }
}

// Nous dit si la transaction a plus de 48h
bool isTooOld(transaction& tr)
{
    const long threshold = 172800000000; // 48h en microsecs
    const auto timestamp = chrono::system_clock::now();
    auto timestamp_sec = chrono::duration_cast<chrono::microseconds>(timestamp.time_since_epoch()).count();

    return (tr.timestamp - timestamp_sec) >= threshold;
}

void agency::update() {
    // Si la transaction a 48 heures ou plus on la supprime
    transactions.erase(remove_if(transactions.begin(), transactions.end(), isTooOld), transactions.end());

    // Ajouter communication avec les autres agences
}