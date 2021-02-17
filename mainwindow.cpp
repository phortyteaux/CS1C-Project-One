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

    ui->SS_textBrowser->setText(in.readAll());
}



