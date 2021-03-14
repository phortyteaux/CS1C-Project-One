#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teams.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SS_pushButton_clicked()
{

    QFile thefile("C:/Users/joy4h/Documents/proj1/ss.txt");

    if(! thefile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",thefile.errorString());
    }

    QTextStream in(&thefile);

    //ui->SS_textBrowser->setText(in.readAll());
}




void MainWindow::on_NFLbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_contactBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_helpBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_backBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_backBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_backBtn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
