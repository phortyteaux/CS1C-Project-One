/**
 *  @file login.h
 *  @class Login
 *  @brief Defines the content of the main window of the interactive pamphlet app.
 *  @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#ifndef LOGIN_H
#define LOGIN_H

#include <QInputDialog>

QT_BEGIN_NAMESPACE
class Login;
class QInputDialog;
QT_END_NAMESPACE

class Login : public QInputDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
};

#endif // LOGIN_H
