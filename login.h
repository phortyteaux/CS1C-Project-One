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

private:

};

#endif // LOGIN_H
