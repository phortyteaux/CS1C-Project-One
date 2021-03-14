#ifndef TEAMS_H
#define TEAMS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * \class Teams
 *
 * \brief team names
 *
 * This class is meant to be used display all the
 * NFL team components.
 *
 * \note The members will be sorted
 *
 * \author $Author: Aileen Phuong
 *
 * \date $Date: 2021/02/17 $
 *
 *
 */




class Teams {

public:
    string teamName;
    string stadiumName;
    int seatingCapacity;
    string location;
    string conference;
    string division;
    string surfaceType;
    string roofType;
    int dateOpened;

public:
    Teams();
    Teams(string teamName, string stadiumName, int seatingCapacity, string location, string
        conference, string division, string surfaceType, string roofType, int dateOpened);

    void setTeamName(string teamName);
    void setStadiumName(string stadiumName);
    void setSeatingCapacity(int seatingCapacity);
    void setLocation(string location);
    void setConference(string conference);
    void setDivision(string division);
    void setSurfaceType(string surfaceType);
    void setRoofType(string roofType);
    void setDateOpened(int dateOpened);

    void print() const;

};

class TempClass {

public:
    string seatingCapacityTemp;
    string dateOpenedTemp;

public:
    TempClass();
    TempClass(string seatingCapacityTemp, string dateOpenedTemp);

    void setSeatingCapacityTemp(string seatingCapacityTemp);
    void setDateOpenedTemp(string dateOpenedTemp);

    void printTemp() const;

};



#endif // TEAMS_H
