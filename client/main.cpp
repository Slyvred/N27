#include <iostream>
#include <thread>
#include "../classes/account.hpp"
#include "../classes/agency.hpp"
#include "../classes/user.hpp"
#include "../classes/socket.hpp"


// Fonction update
void update(agency& agence)
{
    while (true)
    {
        auto str_id = to_string(agence.getId());
        agence.update();

        Client client("localhost", "8080");
        client.Connect();


        /*for (const auto &entry : std::filesystem::directory_iterator("data/"))
        {
            if (!entry.is_regular_file())
                continue;
            
            auto last_time_write = abs(entry.last_write_time().time_since_epoch().count());

            auto request = "update " + str_id + " " + to_string(last_time_write);
            client.SendString(request);
            auto response = client.GetResponse();
            cout << "Received response: " << response.dump() << endl;
        }*/

        auto usr_obj = agence.exportUsers();
        client.SendJSON("U" + str_id, usr_obj); // Envoi user
        //auto response = client.GetResponse();
        // std::cout << "Received response: " << response.dump() << std::endl;

        auto tra_obj = agence.exportTransactions();
        client.SendJSON("T" + str_id, tra_obj); // Envoi transactions
        //response = client.GetResponse();
        // std::cout << "Received response: " << response.dump() << std::endl;


        auto acc_obj = agence.exportAccounts();
        client.SendJSON("A" + str_id, acc_obj); // Envoi accounts
        auto response = client.GetResponse();
        //std::cout << "Received response: " << response.dump() << std::endl;

        client.Close();
        this_thread::sleep_for(10s);
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
            /*for (auto& [id, usr] : agence.getUsers())
            {
                for (auto& [id2, usr2] : agence.getUsers())
                {
                    if (id2 == id) continue;

                    agence.send(agence.getUser(id).getAccount(0), agence.getUser(id2).getAccount(0), amount);
                    break;
                }
                break;
            }*/

            agence.send(1021266762, 118926120, 100);
            //cout << "Sent " << amount << "$" << endl;
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
            cout << "Deposited " << amount << "$" << endl;
        }
        else if (input == "add")
        {
            agence.addAccount(1620888699, 667, 1.02);
        }
        else cerr << "Unknown command" << endl;
    }
}

int main()
{
    srand(time(NULL));

    // ZONE DE TESTS
    agency agence;

    // string nom, prenom, addr, date_naiss, genre, passwd;
    /*infos inf = {"Doe", "John", "Zaza street", "12/04/2003", "Homme", "rockyou123"};

    // On crée 4 utilisateurs aléatoires ayant entre 1 et 2 comptes
    for (int i = 0; i < 4; ++i)
        agence.createUser(inf, rand() % 3 + 1);


    // Chaque compte dispose de 1000 euros
    for (auto &[num, acc] : agence.getAccounts())
        agence.deposit(num, 1000);

    // On exporte tout
    agence.exportAll();*/

    // On importe tout
    agence.importAll();

    // On print pour vérifier que l'import s'est déroulé correctement
    for (auto &[id, usr] : agence.getUsers())
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
    }
    //

    thread th(update, std::ref(agence));
    thread th_work(doWork, std::ref(agence));

    th.join();
    th_work.join();

    return EXIT_SUCCESS;
}
