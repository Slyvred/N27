#ifndef WIDGETS_H
#define WIDGETS_H

#include <QWidget>

class QPushButton;
class Login : public QWidget {
public:
    explicit Login(QWidget *parent = 0);
private:
    QPushButton *signin;
    QPushButton *login;
};

#endif // WIDGETS_H
