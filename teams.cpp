#include "teams.h"

TempClass::TempClass() : seatingCapacityTemp("Unknown"), dateOpenedTemp("Unknown")
{

}
TempClass::TempClass(string seatingCapacityTemp, string dateOpenedTemp) : seatingCapacityTemp(seatingCapacityTemp), dateOpenedTemp(dateOpenedTemp)
{

}

void TempClass::setSeatingCapacityTemp(string seatingCapacityTemp)
{
    this->seatingCapacityTemp = seatingCapacityTemp;
}

void TempClass::setDateOpenedTemp(string dateOpenedTemp)
{
    this->dateOpenedTemp = dateOpenedTemp;
}

void TempClass::printTemp() const
{
    cout << seatingCapacityTemp << " " << dateOpenedTemp << endl;
}

Teams::Teams() : teamName("Unknown"), stadiumName("Unknown"), seatingCapacity(0), location("Unknown"), conference("unknown"),
division("Unknown"), surfaceType("Unknown"), roofType("Unknown"), dateOpened(0)
{

}

Teams::Teams(string teamName, string stadiumName, int seatingCapacity, string location, string
    conference, string division, string surfaceType, string roofType, int dateOpened) :
    teamName(teamName), stadiumName(stadiumName), seatingCapacity(seatingCapacity), location(location), conference(conference),
    division(division), surfaceType(surfaceType), roofType(roofType), dateOpened(dateOpened) {

}

void Teams::setTeamName(string teamName) {
    this->teamName = teamName;
}

void Teams::setStadiumName(string stadiumName)
{
    this->stadiumName = stadiumName;
}
void Teams::setSeatingCapacity(int seatingCapacity)
{
    this->seatingCapacity = seatingCapacity;
}
void Teams::setLocation(string location)
{
    this->location = location;
}
void Teams::setConference(string conference)
{
    this->conference = conference;
}
void Teams::setDivision(string division)
{
    this->division = division;
}
void Teams::setSurfaceType(string surfaceType)
{
    this->surfaceType = surfaceType;
}
void Teams::setRoofType(string roofType)
{
    this->roofType = roofType;
}
void Teams::setDateOpened(int dateOpened)
{
    this->dateOpened = dateOpened;
}

void Teams::print() const
{
    cout << teamName << "  " << stadiumName << "  " << seatingCapacity << "  " << location << "  " << conference << "  " <<
        division << "  " << surfaceType << "  " << roofType << "  " << dateOpened << endl;
}


