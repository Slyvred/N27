//
// Created by remi on 30/11/22.
//
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "account.h"

using namespace std;

#ifndef N27_USER_H
#define N27_USER_H

typedef struct Infos {
    string nom, prenom, addr;
}infos;


class user {
private:
    infos m_infos;
    int n_accounts;
    int id;
    vector<int> accounts;
public:
    user(infos& infos, int n_accounts);
    int getId() const;
    void setId(int id);
    const infos& getInfos() const;
    const vector<int>& getAccounts() const;
    const int& getAccount(int index) const;
    void addAccount(int id);
    friend ostream& operator<<(ostream& os, const user& user);
};


#endif //N27_USER_H
