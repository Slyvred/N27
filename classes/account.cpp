//
// Created by remi on 30/11/22.
//

#include "account.h"
#include <random>

account::account(float interets, float solde) : interets(interets), solde(solde) {
    id = rand();
}

int account::getId() const {
    return id;
}

float account::getInterets() const {
    return interets;
}

void account::setInterets(float interets) {
    this->interets = interets;
}

void account::setSolde(float solde) {
    this->solde = solde;
}

float account::getSolde() const {
    return solde;
}

void account::setId(int id) {
    this->id = id;
}

ostream& operator<<(ostream& os, const account& acc)
{
    os << "Numéro: " << acc.getId() << endl;
    os << "Solde: " << acc.getSolde() << endl;
    os << "Intérêts: " << acc.getInterets() << endl;
    return os;
}