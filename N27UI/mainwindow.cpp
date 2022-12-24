#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//navigation entre pages
void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
     ui->stackedWidget->setCurrentIndex(arg1);
}



//utilisateur connecté - virement/déconnexion
void MainWindow::on_Deconnecter_Btn_clicked()
{
    // retour acceuil
    on_stackedWidget_currentChanged(0);
}


//page virement
void MainWindow::on_Virement_Btn_clicked()
{
    //go page virement
    on_stackedWidget_currentChanged(2);

}



//connexion
void MainWindow::on_Connexion_Btn_clicked()
{
    on_stackedWidget_currentChanged(3);
}




//inscription finnalisée - go connected
void MainWindow::on_pushButton_2_clicked()
{
    on_stackedWidget_currentChanged(3);
}


//inscription
void MainWindow::on_Creer_Btn_clicked()
{
    on_stackedWidget_currentChanged(1);
}


void MainWindow::on_pushButton_clicked()
{

}

