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



