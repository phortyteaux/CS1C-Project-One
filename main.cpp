#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teams.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtAlgorithms>

int convertSeating(string&, int&);
int convertDate(string&, int&);


int main(int argc, char *argv[])
{

        string name;
        string stadium;
        string seating;
        string local;
        string confer;
        string div;
        string surface;
        string roof;
        string date;

        int seatingC;
        int dateO;
        int i = 0;

        const int NUM = 33;
        Teams teamInfo[NUM];
        TempClass classTemp[NUM];

        ifstream myfile;
        myfile.open("C:/Users/joy4h/Documents/proj1/data.txt");
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                getline(myfile, name);
                teamInfo[i].setTeamName(name);

                getline(myfile, stadium);
                teamInfo[i].setStadiumName(stadium);

                getline(myfile, seating);
                classTemp[i].setSeatingCapacityTemp(seating);
                convertSeating(seating, seatingC);
                teamInfo[i].setSeatingCapacity(seatingC);

                getline(myfile, local);
                teamInfo[i].setLocation(local);

                getline(myfile, confer);
                teamInfo[i].setConference(confer);

                getline(myfile, div);
                teamInfo[i].setDivision(div);

                getline(myfile, surface);
                teamInfo[i].setSurfaceType(surface);

                getline(myfile, roof);
                teamInfo[i].setRoofType(roof);

                getline(myfile, date);
                classTemp[i].setDateOpenedTemp(date);
                convertDate(date, dateO);
                teamInfo[i].setDateOpened(dateO);

                i++;
            }
            myfile.close();

        }
        else
        {
            cout << "Could not access file." << endl;
           }


            string stads[33];
           for (int i = 0; i < 33; i++) {

              stads[i]= teamInfo[i].stadiumName;
           }
           int SIZE = sizeof(stads) / sizeof(stads[0]);

           sort(stads, stads + SIZE);
           for (int i = 0; i < 33; i++) {

              cout << stads[i] << endl;
           }


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


int convertSeating(string& seating, int& seatingC)
{
    stringstream ss;

    ss << seating;
    ss >> seatingC;

    return seatingC;
}

int convertDate(string& date, int& dateO)
{
    stringstream ss;

    ss << date;
    ss >> dateO;

    return dateO;

}

