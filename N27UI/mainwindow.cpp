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


//switch stack widget indexes
void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
     ui->stackedWidget->setCurrentIndex(arg1);
}


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

