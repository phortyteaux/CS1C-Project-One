/**
 *  @file login.cpp
 *  @class Login
 *  @brief Defines the content of the login window of the interactive pamphlet app.
 *  @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#include "login.h"

/**
 * @brief Login::Login Constructor of the Login class.
 * @param parent The parent QWidget that creates an instance of the Login object.
 */
Login::Login(QWidget *parent) : QInputDialog(parent)
{
    /**
     * @brief setWindowTitle Sets the title of the window to Admin Login.
     */
    setWindowTitle(tr("Admin Login"));

    /** @brief setlabelText sets the text for the label to Enter Password. */
    setLabelText(tr("Password:"));

    /**
     * @brief setTextEchoMode Sets the input line to Password mode so the text is hidden when typed.
     */
    setTextEchoMode(QLineEdit::Password);
}
