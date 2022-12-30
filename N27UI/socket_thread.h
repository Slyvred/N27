#ifndef SOCKET_THREAD_H
#define SOCKET_THREAD_H
#pragma once
#include <QThread>
#include "../classes/agency.hpp"
#include "../classes/socket.hpp"
#include <QObject>

class UpdateThread : public QObject
{
    Q_OBJECT

public:
    UpdateThread(agency& agence, QObject* parent = nullptr) : QObject(parent), agence(agence) {}

public slots:
    void update()
    {
        while (true)
        {
            auto str_id = to_string(agence.getId());
            agence.update();

            Client client("localhost", "8080");
            client.Connect();

            auto usr_obj = agence.exportUsers();
            client.SendJSON("U" + str_id, usr_obj); // Envoi user

            auto tra_obj = agence.exportTransactions();
            client.SendJSON("T" + str_id, tra_obj); // Envoi transactions

            auto acc_obj = agence.exportAccounts();
            client.SendJSON("A" + str_id, acc_obj); // Envoi accounts
            auto response = client.GetResponse();

            client.Close();
            QThread::sleep(60);
        }
    }

private:
    agency& agence;
};
#endif // SOCKET_THREAD_H
