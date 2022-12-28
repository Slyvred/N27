#include "mainwindow.h"
#include "includes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    agence.importAll();
    return a.exec();
}

