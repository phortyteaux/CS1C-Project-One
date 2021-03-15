#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QInputDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    setWindowTitle(tr("Admin Login"));

    // set the text for the label to Enter Password

    // make sure it is in textinput mode

    // make sure the password text input is in echo mode
}

Login::~Login()
{
    delete ui;
}
