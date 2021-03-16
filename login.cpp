#include "login.h"

Login::Login(QWidget *parent) : QInputDialog(parent)
{
    setWindowTitle(tr("Admin Login"));

    /**
     * @brief setLabelText Set the
     */
    setLabelText(tr("Password:"));

    // make sure it is in textinput mode
    setTextEchoMode(QLineEdit::Password);
}
