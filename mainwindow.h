#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_SS_pushButton_clicked();

    void on_NFLbtn_clicked();

    void on_contactBtn_clicked();

    void on_helpBtn_clicked();

    void on_backBtn_clicked();

    void on_backBtn_2_clicked();

    void on_backBtn_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
