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

void MainWindow::on_TC_PushButton_clicked()
{
    //change file location on github
    QFile thefile("I:/Pictures/CompSciCS1C/QTProjects/Project1Part6AileenPhuong/totalCapacity.txt");

    if(! thefile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",thefile.errorString());
    }

    QTextStream in(&thefile);

    ui->TC_TextBrowser->setText(in.readAll());
}

