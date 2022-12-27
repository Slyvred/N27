//
// Created by Thomas Merlaud on 27/12/2022.
// Main page, user can log into his DigIsen account or if he doesn't have one, he can create one.

#include "../classes/agency.hpp"

//connexion
void MainWindow::on_Connexion_Btn_clicked()
{
    on_stackedWidget_currentChanged(3);

}


// go inscription
void MainWindow::on_Creer_Btn_clicked()
{
    on_stackedWidget_currentChanged(1);
}

