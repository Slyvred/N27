//
// Created by Thomas Merlaud on 27/12/2022.
//

#include "../classes/agency.hpp"

//log out
void MainWindow::on_Deconnecter_Btn_clicked()
{
    // go home page
    on_stackedWidget_currentChanged(0);
}

//bank transfer
void MainWindow::on_Virement_Btn_clicked()
{
    //go bank transfer page
    on_stackedWidget_currentChanged(2);
}




