#include "widgets.h"

#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

Login::Login(QWidget *parent) :
 QWidget(parent)
 {
 QVBoxLayout *layoutvert = new QVBoxLayout;


 // Create and position the button
 signin = new QPushButton("Sign in", this);
 login = new QPushButton("Log in", this);
}
