#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Deconnecter_Btn_clicked();

    void on_Virement_Btn_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_Connexion_Btn_clicked();

    void on_pushButton_2_clicked();

    void on_Creer_Btn_clicked();

    void on_pushButton_clicked();

    void on_SelectionCpt_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
};

agency agence;
#endif // MAINWINDOW_H
