//
// Created by remi on 30/11/22.
//

#include "agency.hpp"
#include "socket.hpp"
using json = nlohmann::json;

int importId()
{
    filesystem::path dir_path("./data/");
    if (!filesystem::exists(dir_path))
    {
        std::cerr << "Cannot find db" << std::endl;
        return 0;
    }

    string id;
    for (auto &entry : filesystem::directory_iterator(dir_path))
    {
        id = entry.path().filename().string();

        id = id.substr(1);
        id = id.substr(0, id.length() - 5); // -5 car .json
        break;
    }
    return stoi(id);
}

agency::agency()
{
    // auto tmp = importId();
    // id = (tmp) ? tmp :  rand(); // On essaie de récupérer l'ancien id
    id = rand();
    n_users = 0;
}

void agency::createUser(infos &infos, int n_accounts)
{
    user tmp(infos, n_accounts);
    n_users++;

    // On vérifie que l'id est unique
    while (users.find(tmp.getId()) != users.end())
        tmp.setId(rand());

    // On ajoute les comptes
    for (int i = 0; i < n_accounts; ++i)
    {
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

user &agency::getUser(int id)
{
    auto index = users.find(id);

    infos inf = {"none", "none", "none"};
    user tmp(inf, 0);

    // On renvoie un user nul si il n'existe pas
    return (index == users.end()) ? tmp : users.at(id);
}

void agency::deleteUser(int id)
{
    if (users.find(id) == users.end())
        return;
    users.erase(id);
    n_users--;
}

void agency::send(int from_acc, int to_acc, float amount)
{

    // On vérifie que les comptes sont valides
    if (accounts.find(from_acc) == accounts.end())
        return;

    // On vérifie que le solde permet le virement
    auto solde = accounts.at(from_acc).getSolde();
    if (solde < amount)
        return;


    // Si on ne trouve pas le compte, on fait la requête à l'agence centrale
    if (accounts.find(to_acc) == accounts.end())
    {
        cout << "Fetching remote account..." << endl;
        Client client("localhost", "8080");
        client.Connect();
        client.SendString("get " + to_string(to_acc));
        auto response = client.GetResponse();

        if (response.dump() == "{\"key\":\"value\"}" || response.dump() == "null") // Si on n'a pas le compte
        {
            cerr << "Account not found" << endl;
            client.Close();
            return;
        }

        cout << "Remote account found" << endl;

        auto to_solde = response["acc"]["id"][to_string(to_acc)]["solde"];
        response["acc"]["id"][to_string(to_acc)]["solde"] = (float)to_solde + amount;
        accounts.at(from_acc).setSolde(solde - amount);

        auto acc_obj = exportAccounts();
        client.SendJSON("A" + to_string(getId()), acc_obj); // Envoi accounts local

        // Envoi accouts distant
        client.SendJSON(response["file"], response["acc"]);

        client.Close();

        cout << "Sent " << amount << "$ to " << to_acc << " from " << from_acc << endl;
    }
    else
    {
        // On effectue le virement local
        accounts.at(from_acc).setSolde(solde - amount);
        accounts.at(to_acc).setSolde(accounts.at(to_acc).getSolde() + amount);
    }

    // On ajoute le virement dans l'historique de transactions
    transaction transac;
    transac.amount = amount;
    transac.from_acc = from_acc;
    transac.to_acc = to_acc;

    // Ici, on calcule le timestamp de la transaction pour savoir à quel moment elle a eu lieu
    const auto timestamp = chrono::system_clock::now();
    transac.timestamp = chrono::duration_cast<chrono::seconds>(timestamp.time_since_epoch()).count();

    transactions.push_back(transac);
}

void agency::deposit(int to_acc, float amount)
{
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
    transac.timestamp = chrono::duration_cast<chrono::seconds>(timestamp.time_since_epoch()).count();

    transactions.push_back(transac);
}

const unordered_map<int, user> &agency::getUsers() const
{
    return users;
}

const unordered_map<int, account> &agency::getAccounts() const
{
    return accounts;
}

const vector<transaction> &agency::getTransactions() const
{
    return transactions;
}

json agency::exportUsers() const
{
    json user;

    if (!filesystem::exists("./data/"))
        filesystem::create_directories("./data/");

    string filename = "data/U" + to_string(id) + ".json";
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "Couldn't open file ! " << endl;
        return user;
    }
    // cout << clients.size();

    for (auto &[id, usr] : users)
    {
        auto infos = usr.getInfos();
        auto num = id;
        auto str_num = to_string(num);
        auto nb_acc = usr.getAccounts().size();

        user["id"][str_num]["infos"]["nom"] = infos.nom;
        user["id"][str_num]["infos"]["prenom"] = infos.prenom;
        user["id"][str_num]["infos"]["adresse"] = infos.addr;
        user["id"][str_num]["numero"] = num;

        // Nous donne le nombre d'itérations à faire dans importJson
        user["id"][str_num]["nbAccounts"] = nb_acc;

        int i = 0;
        for (auto it2 : usr.getAccounts())
        {
            user["id"][str_num]["accounts"][i] = it2;
            i++;
        }
    }

    file << setw(2) << user << endl;
    file.close();
    cout << "Exported " << filename << endl;

    return user;
}

json agency::exportAccounts() const
{

    if (!filesystem::exists("./data/"))
        filesystem::create_directories("./data/");

    string filename = "data/A" + to_string(id) + ".json";
    ofstream file(filename);
    json account;

    if (!file.is_open())
    {
        cerr << "Couldn't open file ! " << endl;
        return account;
    }

    for (auto &[id, acc] : accounts)
    {

        auto str_num = to_string(id);

        // cout << num << endl;
        // cout << acc << endl;

        account["id"][str_num]["interests"] = acc.getInterets();
        account["id"][str_num]["solde"] = acc.getSolde();
        account["id"][str_num]["id"] = acc.getId();
    }

    file << setw(2) << account << endl;
    file.close();
    cout << "Exported " << filename << endl;

    return account;
}

json agency::exportTransactions() const
{

    if (!filesystem::exists("./data/"))
        filesystem::create_directories("./data/");

    string filename = "data/T" + to_string(id) + ".json";
    ofstream file(filename);
    json transac;

    if (!file.is_open())
    {
        cerr << "Couldn't open file ! " << endl;
        return transac;
    }

    for (auto &it : transactions)
    {
        auto str_num = to_string(it.from_acc);
        int i = 0;
        for (auto &it2 : transactions)
        {
            if (it2.from_acc != it.from_acc)
                continue;

            transac["id"][str_num][i]["fromAcc"] = it2.from_acc;
            transac["id"][str_num][i]["toAcc"] = it2.to_acc;
            transac["id"][str_num][i]["amount"] = it2.amount;
            transac["id"][str_num][i]["timestamp"] = it2.timestamp;
            i++;
        }
    }

    file << setw(2) << transac << endl;
    file.close();
    cout << "Exported " << filename << endl;
    return transac;
}

vector<json> agency::exportAll() const
{
    vector<json> vect;
    vect.push_back(exportAccounts());
    vect.push_back(exportTransactions());
    vect.push_back(exportUsers());

    return vect;
}

void agency::importAcounts()
{
    if (!filesystem::exists("./data/"))
        filesystem::create_directories("./data/");

    string filename = "data/A" + to_string(id) + ".json";
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Couldn't open file ! " << endl;
        return;
    }

    json obj = json::parse(file);
    file.close();

    for (auto &it : obj["id"])
    {
        //cout << it << endl;
        auto id = it["id"];
        auto interets = it["interests"];
        auto solde = it["solde"];

        account tmp(interets, solde);
        tmp.setId(id);

        accounts.insert({id, tmp});
    }
    cout << "Imported " << filename << endl;
}

void agency::importUsers()
{
    if (!filesystem::exists("./data/"))
        filesystem::create_directories("./data/");

    string filename = "data/U" + to_string(id) + ".json";
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Couldn't open file ! " << endl;
        return;
    }

    json obj = json::parse(file);
    file.close();
    infos inf;

    for (auto &it : obj["id"])
    {
        //cout << it << endl;

        // On récupère les infos
        inf.addr = it["infos"]["adresse"];
        inf.nom = it["infos"]["nom"];
        inf.prenom = it["infos"]["prenom"];

        // On récupère l'id
        int nb_acc = it["nbAccounts"];
        int num = it["numero"];

        // On ajoute chaque compte de l'user à l'objet
        user tmp(inf, nb_acc);
        for (auto &acc : it["accounts"])
            tmp.addAccount(acc);

        // On récupère son id
        tmp.setId(num);

        // On l'ajoute à l'agence et à la map
        n_users++;
        users.insert({num, tmp});
    }
    cout << "Imported " << filename << endl;
}

void agency::importTransactions()
{
    if (!filesystem::exists("./data/"))
        filesystem::create_directories("./data/");

    string filename = "data/T" + to_string(id) + ".json";
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Couldn't open file ! " << endl;
        return;
    }

    json obj = json::parse(file);
    file.close();
    transaction transac;

    // On ajoute chaque transaction de chaque utilisateur
    for (auto &it : obj["id"])
    {
        for (auto &it2 : it)
        {
            transac.amount = it2["amount"];
            transac.from_acc = it2["fromAcc"];
            transac.timestamp = it2["timestamp"];
            transac.to_acc = it2["toAcc"];

            transactions.push_back(transac);
        }
    }
    cout << "Imported " << filename << endl;
}

void agency::importAll()
{
    id = importId();
    importAcounts();
    importTransactions();
    importUsers();
}

// Nous dit si la transaction a plus de 48h
bool isTooOld(transaction &tr)
{
    const long threshold = 172800; // 48h en secs
    const auto timestamp = chrono::system_clock::now();
    auto timestamp_sec = chrono::duration_cast<chrono::seconds>(timestamp.time_since_epoch()).count();

    return (tr.timestamp - timestamp_sec) >= threshold;
}

void agency::update()
{
    // Si la transaction a 48 heures ou plus on la supprime
    transactions.erase(remove_if(transactions.begin(), transactions.end(), isTooOld), transactions.end());
}

int agency::getId() const
{
    return this->id;
}