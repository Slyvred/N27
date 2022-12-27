//
// Created by Thomas Merlaud on 27/12/2022.
//

#include "../classes/agency.hpp"

//bank transfer done, new  transfer -> go transfer page
void MainWindow::on_pushButton_3_clicked()
{
    on_stackedWidget_currentChanged(2);
}


//bank transfer done, go home page
void MainWindow::on_pushButton_4_clicked()
{
    on_stackedWidget_currentChanged(3);
}

