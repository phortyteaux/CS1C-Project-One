#ifndef LOGIN_H
#define LOGIN_H

#include <QInputDialog>

namespace Ui {
class Login;
class QInputDialog;
}

class Login : public QInputDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
