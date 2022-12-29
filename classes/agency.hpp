//
// Created by remi on 30/11/22.
//
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <fstream>
#include <string>
#include <filesystem>
#include "json.hpp"
#include "user.hpp"

using namespace std;
using json = nlohmann::json;

#ifndef N27_AGENCY_H
#define N27_AGENCY_H

typedef struct Transaction {
    int from_acc, to_acc;
    float amount;
    long timestamp;
}transaction;


class agency {
private:
    unordered_map<int, user> users;
    unordered_map<int, account> accounts;
    vector<transaction> transactions;
    int id;
    int n_users;
public:

    agency();

    void createUser(infos& infos, int n_accounts);
    void addAccount(int uid, float solde, float interets);
    void deleteUser(int id);
    user& getUser(int id);
    void send(int from_acc, int to_acc, float amount);
    void deposit(int to_acc, float amount);

    json exportUsers() const;
    json exportAccounts() const;
    json exportTransactions() const;
    vector<json> exportAll() const;
    int getId() const;

    void importUsers();
    void importAcounts();
    void importTransactions();
    void importAll();

    const unordered_map<int, user>& getUsers() const;
    const unordered_map<int, account>& getAccounts() const;
    const vector<transaction>& getTransactions() const;

    void update();
};


#endif //N27_AGENCY_H
