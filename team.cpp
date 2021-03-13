#include "team.h"


// setters
void team::setTeamName(string n)
{
    teamName = n;
}
void team::setStadiumName(string n)
{
    stadiumName = n;
}
void team::setSeatingCapacity(string n)
{
    seatingCapacity = n;
}
void team::setStadiumLocation(string n)
{
    stadiumLocation = n;
}
void team::setConference(string n)
{
    conference = n;
}
void team::setDivision(string n)
{
    division = n;
}
void team::setTypeOfSurface(string n)
{
    typeOfSurface = n;
}
void team::setTypeOfRoof(string n)
{
    typeOfRoof = n;
}
void team::setDateOpened(string n)
{
    dateOpened = n;
}

// getters
string team::getTeamName() const
{
    return teamName;
}
string team::getStadiumName() const
{
    return stadiumName;
}
string team::getSeatingCapacity() const
{
    return seatingCapacity;
}
string team::getStadiumLocation() const
{
    return stadiumLocation;
}
string team::getConference() const
{
    return conference;
}
string team::getDivision() const
{
    return division;
}
string team::getTypeOfSurface() const
{
    return typeOfSurface;
}
string team::getTypeOfRoof() const
{
    return typeOfRoof;
}
string team::getDateOpened() const
{
    return dateOpened;
}

// misc functions
void team::read(fstream &inFile)
{
    string temp = ""; //used to remove quotes from the .csv

    getline(inFile, teamName, ',');
    getline(inFile, stadiumName, ',');
    getline(inFile, temp, '"');
    getline(inFile, seatingCapacity, '"');
    getline(inFile, temp, '"');
    getline(inFile, stadiumLocation, '"');
    getline(inFile, temp, ',');
    getline(inFile, conference, ',');
    getline(inFile, division, ',');
    getline(inFile, typeOfSurface, ',');
    getline(inFile, typeOfRoof, ',');
    getline(inFile, dateOpened);
}
void team::print()
{
    //temporary implementation of of print()
    cout << "Printing: " << endl;
    cout << teamName << endl;
    /*cout << stadiumName << endl;
    cout << seatingCapacity << endl;
    cout << stadiumLocation << endl;
    cout << conference << endl;
    cout << division << endl;
    cout << typeOfSurface << endl;
    cout << typeOfRoof << endl;
    cout << dateOpened << endl;*/
}
void team::alphabetize(vector<string>& sortingVector)
{
    sort(sortingVector.begin(), sortingVector.end());
}
void team::addToVector(vector<string>& sortingVector, string dataMember)
{
    sortingVector.push_back(dataMember);
}
