#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teams.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
        //change file location on github
        myfile.open("I:/Pictures/CompSciCS1C/QTProjects/Project1Part6AileenPhuong/data.txt");
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
            cout << "Could not access file." << endl;

        int total = 0;

        for (int j = 0; j < 33; j++)
        {
            total = total + teamInfo[j].seatingCapacity;
        }

        ofstream outfile;
        outfile.open("I:/Pictures/CompSciCS1C/QTProjects/Project1Part6AileenPhuong/totalCapacity.txt");
        outfile << total;
        outfile.close();

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
