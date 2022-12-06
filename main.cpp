#include <iostream>
#include "classes/account.h"
#include "classes/agency.h"
#include "classes/user.h"

int main() {

    // Désactivé pour la version dev
    //srand(time(NULL));

    agency agenceCentrale;

    infos inf = {"Doe", "John", "Zaza street"};

    for (int i = 0; i < 4; ++i)
        agenceCentrale.createUser(inf, rand() % 3);

    for (auto& [key, value] : agenceCentrale.getUsers()) {
        cout << value << endl;
        //value.exportJson();
    }
    for (auto& [num, acc] : agenceCentrale.getAccounts()) {
        cout << acc << endl;
    }

    agenceCentrale.exportUsers();
    agenceCentrale.exportAcounts();
    //agenceCentrale.importUsers();
    //agenceCentrale.importAcounts();

    for (auto& [id, urs] : agenceCentrale.getUsers()) {
        cout << urs << endl;
    }
    for (auto& [num, acc] : agenceCentrale.getAccounts()) {
        cout << acc << endl;
    }
    return EXIT_SUCCESS;
}
