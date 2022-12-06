#include <iostream>
#include "classes/account.h"
#include "classes/agency.h"
#include "classes/user.h"

int main() {

    // Désactivé pour la version dev
    //srand(time(NULL));

    // ZONE DE TESTS
    agency agenceCentrale;

    infos inf = {"Doe", "John", "Zaza street"};

    for (int i = 0; i < 4; ++i)
        agenceCentrale.createUser(inf, rand() % 3 + 1);

    /*
    for (auto& [num, usr] : agenceCentrale.getUsers()) {
        cout << usr << endl;
        //value.exportJson();
    }*/
    for (auto& [num, acc] : agenceCentrale.getAccounts()) {
        agenceCentrale.deposit(num, rand() % 1000 + 300);
        //cout << acc << endl;
    }

    agenceCentrale.send(agenceCentrale.getUser(1681692777).getAccount(0), agenceCentrale.getUser(2044897763).getAccount(0), 300);

    agenceCentrale.exportUsers();
    agenceCentrale.exportAcounts();
    agenceCentrale.exportTransactions();
    //agenceCentrale.importUsers();
    //agenceCentrale.importAcounts();

    for (auto& [id, urs] : agenceCentrale.getUsers()) {
        cout << urs << endl;
    }
    for (auto& [num, acc] : agenceCentrale.getAccounts()) {
        cout << acc << endl;
    }
    //
    return EXIT_SUCCESS;
}
