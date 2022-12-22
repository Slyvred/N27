#include <iostream>
#include "classes/account.h"
#include "classes/agency.h"
#include "classes/user.h"
#include "classes/socket.h"

int main()
{

    // Désactivé pour la version dev
    // srand(time(NULL));

    // ZONE DE TESTS
    agency agenceCentrale;

    infos inf = {"Doe", "John", "Zaza street"};

    for (int i = 0; i < 4; ++i)
        agenceCentrale.createUser(inf, rand() % 3 + 1);

    // for (auto& [num, usr] : agenceCentrale.getUsers()) {
    // cout << usr << endl;
    // value.exportJson();
    //}
    for (auto &[num, acc] : agenceCentrale.getAccounts())
    {
        agenceCentrale.deposit(num, 1000);
        // cout << acc << endl;
    }

    agenceCentrale.send(agenceCentrale.getUser(1681692777).getAccount(0), agenceCentrale.getUser(2044897763).getAccount(0), 300);
    agenceCentrale.send(agenceCentrale.getUser(1681692777).getAccount(0), agenceCentrale.getUser(2044897763).getAccount(0), 50);
    agenceCentrale.send(agenceCentrale.getUser(2044897763).getAccount(0), agenceCentrale.getUser(1681692777).getAccount(0), 300);
    agenceCentrale.send(agenceCentrale.getUser(2044897763).getAccount(0), agenceCentrale.getUser(2044897763).getAccount(0), 50);

    auto usr_obj = agenceCentrale.exportUsers();
    auto acc_obj = agenceCentrale.exportAcounts();
    auto tra_obj = agenceCentrale.exportTransactions();

    /*agenceCentrale.importUsers();
    agenceCentrale.importAcounts();
    agenceCentrale.importTransactions();*/

    /*for (auto &[id, usr] : agenceCentrale.getUsers())
    {
        cout << usr << endl;
    }
    for (auto &[num, acc] : agenceCentrale.getAccounts())
    {
        cout << acc << endl;
    }
    for (auto &it : agenceCentrale.getTransactions())
    {
        cout << "from_acc: " << it.from_acc << endl;
        cout << "to_acc: " << it.to_acc << endl;
        cout << "amount: " << it.amount << endl;
        cout << "timestamp: " << it.timestamp << endl;
        cout << "---------------------" << endl;
    }*/
    //

    Client client("localhost", "1234");
    client.Connect();

    string filename = "U" + to_string(agenceCentrale.getId());
    client.SendString(filename);
    client.SendRequest(usr_obj);

    filename = "T" + to_string(agenceCentrale.getId());
    client.SendString(filename);
    client.SendRequest(tra_obj);

    filename = "A" + to_string(agenceCentrale.getId());
    client.SendString(filename);
    client.SendRequest(acc_obj);

    // Obtenez la réponse envoyée par le serveur en appelant la fonction GetResponse de l'instance du client.
    json response = client.GetResponse();
    std::cout << "Received response: " << response.dump() << std::endl;

    client.Close();
    return EXIT_SUCCESS;
}
