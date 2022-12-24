#include <iostream>
#include <ctime>
// #include <thread>
#include "../classes/account.hpp"
#include "../classes/agency.hpp"
#include "../classes/user.hpp"
#include "../classes/socket.hpp"


// Fonction update
void update(agency& agence)
{
    time_t currentTime;
    struct tm *localTime;

    while (true)
    {
        time(&currentTime);                   // Get the current time
        localTime = localtime(&currentTime);  // Convert the current time to the local time
        // bool sent = false;

        //if (localTime->tm_hour != 18 || localTime->tm_min != 4 || localTime->tm_sec != 0) continue;

        agence.update();

        Client client("localhost", "8080");
        client.Connect();

        auto usr_obj = agence.exportUsers();
        client.SendJSON("U" + to_string(agence.getId()), usr_obj); // Envoi user

        auto tra_obj = agence.exportTransactions();
        client.SendJSON("T" + to_string(agence.getId()), tra_obj); // Envoi transactions

        auto acc_obj = agence.exportAccounts();
        client.SendJSON("A" + to_string(agence.getId()), acc_obj); // Envoi accounts

        client.SendString("get 1372962516");
        // Obtenez la réponse envoyée par le serveur en appelant la fonction GetResponse de l'instance du client.
        json response = client.GetResponse();
        //std::cout << "Received response: " << response.dump() << std::endl;

        client.Close();
        // sent = true;
        sleep(10);
    }
}


// Vu que nous n'avons pas d'interface on passe en CLI en attendant
void doWork(agency& agence)
{
    string input;
    while (input != "END")
    {
        cout << ">>> ";
        cin >> input;

        if (input == "send")
        {
            float amount = 100;


            // Implémentation de test absolument atroce
            for (auto& [id, usr] : agence.getUsers())
            {
                for (auto& [id2, usr2] : agence.getUsers())
                {
                    if (id2 == id) continue;

                    agence.send(agence.getUser(id).getAccount(0), agence.getUser(id2).getAccount(0), amount);
                    break;
                }
                break;
            }

            //agence.send(agence.getUser(1025202362).getAccount(0), agence.getUser(1681692777).getAccount(0), amount);
            cout << "Sent " << amount << "$" << endl;
        }
        else if (input == "deposit")
        {
            float amount = 1000;

            // Implémentation de test absolument atroce
            for (auto& [id, usr] : agence.getUsers())
            {
                agence.deposit(agence.getUser(id).getAccount(0), amount);
                break;
            }
            //agence.deposit(agence.getUser(1025202362).getAccount(0), amount);
            cout << "Deposited " << amount << "$" << endl;
        }
    }
}

int main()
{

    // Désactivé pour la version dev
    srand(time(NULL));

    // ZONE DE TESTS
    agency agence;

    infos inf = {"Doe", "John", "Zaza street"};

    // On crée 4 utilisateurs aléatoires ayant entre 1 et 2 comptes
    for (int i = 0; i < 4; ++i)
        agence.createUser(inf, rand() % 3 + 1);


    // Chaque compte dispose de 1000 euros
    for (auto &[num, acc] : agence.getAccounts())
        agence.deposit(num, 1000);


    // On simule des transactions entre deux utilisateurs
    // agence.send(agence.getUser(1681692777).getAccount(0), agence.getUser(2044897763).getAccount(0), 300);
    // agence.send(agence.getUser(1681692777).getAccount(0), agence.getUser(2044897763).getAccount(0), 50);
    // agence.send(agence.getUser(2044897763).getAccount(0), agence.getUser(1681692777).getAccount(0), 300);
    // agence.send(agence.getUser(2044897763).getAccount(0), agence.getUser(2044897763).getAccount(0), 50);

    // On exporte tout
    auto usr_obj = agence.exportUsers();
    auto acc_obj = agence.exportAccounts();
    auto tra_obj = agence.exportTransactions();

    // On importe tout
    /*agence.importUsers();
    agence.importAcounts();
    agence.importTransactions();*/

    // On print pour vérifier que l'import s'est déroulé correctement
    /*for (auto &[id, usr] : agence.getUsers())
    {
        cout << usr << endl;
    }
    for (auto &[num, acc] : agence.getAccounts())
    {
        cout << acc << endl;
    }
    for (auto &it : agence.getTransactions())
    {
        cout << "from_acc: " << it.from_acc << endl;
        cout << "to_acc: " << it.to_acc << endl;
        cout << "amount: " << it.amount << endl;
        cout << "timestamp: " << it.timestamp << endl;
        cout << "---------------------" << endl;
    }*/
    //

    thread th(update, std::ref(agence));
    thread th_work(doWork, std::ref(agence));

    th.join();
    th_work.join();

    return EXIT_SUCCESS;
}
