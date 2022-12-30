//Client Application

#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "mainapp.h"

#include <iostream>
//#include <thread>
#include <boost/asio.hpp>
#include "socket_thread.h"
#include "../classes/account.hpp"
#include "../classes/agency.hpp"
#include "../classes/json.hpp"
#include "../classes/socket.hpp"
#include "../classes/user.hpp"

int main(int argc, char *argv[])
{
    // On définit l'application
    QApplication app(argc, argv);

    //On récupère les informations depuis la base de donnée
    agency agence;
    agence.importAll();

    MainApp page;

    page.ag = agence;

    QThread* thread = new QThread;
    UpdateThread* updateThread = new UpdateThread(page.ag);
    updateThread->moveToThread(thread);
    QObject::connect(thread, &QThread::started, updateThread, &UpdateThread::update);
    thread->start();

    page.show();

    return app.exec();
}
