#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QInputDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    setWindowTitle(tr("Admin Login"));

    // set the text for the label to Enter Password
    setLabelText(tr("Password:"));

    // make sure it is in textinput mode
    setTextEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}
