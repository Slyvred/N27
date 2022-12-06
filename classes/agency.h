//
// Created by remi on 30/11/22.
//
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "json.hpp"
#include "user.h"

using namespace std;

#ifndef N27_AGENCY_H
#define N27_AGENCY_H

typedef struct Transaction {
    int from_acc, to_acc;
    float amount;
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
    void deleteUser(int id);
    user& getuser(int id);
    void send(int from_acc, int to_acc, float amount);

    void exportUsers() const;
    void exportAcounts() const;

    void importUsers();
    void importAcounts();

    const unordered_map<int, user>& getUsers() const;
    const unordered_map<int, account>& getAccounts() const;

};


#endif //N27_AGENCY_H
