//
// Created by remi on 30/11/22.
//

#ifndef N27_ACCOUNT_H
#define N27_ACCOUNT_H

#pragma once
#include <iostream>
using namespace std;

class account {
private:
    float interets;
    float solde;
    int id;
public:
    account(float interets, float solde);
    float getInterets() const;
    float getSolde() const;
    int getId() const;

    void setSolde(float solde);
    void setInterets(float interets);
    void setId(int id);
    friend ostream& operator<<(ostream& os, const account& acc);
};


#endif //N27_ACCOUNT_H
