/**
 * @file Team.cpp Holds implementation of methods defined in Team.
 * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#include "team.h" /** @include team.h */

/**
 * @brief A setter for the team name of a team object.
 * @param name The team name to be stored in the team object.
 */
void team::setTeamName(string name)
{
    this->name = name;
}

/**
 * @brief Set the Stadium Name data member.
 * @param stadiumName Holds the stadium name.
 */
void team::setStadiumName(string stadiumName)
{
    this->stadiumName = stadiumName;
}

/**
 * @brief Set the Seating Capacity data member.
 * @param seatingCapacity Holds the max seating capacity of the stadium.
 */
void team::setSeatingCapacity(string seatingCapacity)
{
    this->seatingCapacity = seatingCapacity;
}

/**
 * @brief Set the Stadium Location data member.
 * @param location Holds the location of the stadium.
 */
void team::setLocation(string location)
{
    this->location = location;
}

/**
 * @brief A setter for the conference of a team object.
 * @param conference The conference that a team competes in (NFC, AFC, etc).
 */
void team::setConference(string conference)
{
    this->conference = conference;
}

/**
 * @brief A setter for the division of a team object.
 * @param division The division of a team (NFC West, AFC South, etc).
 */
void team::setDivision(string division)
{
    this->division = division;
}

/**
 * @brief Set the Surface Type data member.
 * @param surfaceType Holds the type of surface the stadium turf is.
 */
void team::setSurfaceType(string surfaceType)
{
    this->surfaceType = surfaceType;
}

/**
 * @brief Set the Roof Type data member.
 * @param roofType Holds the type of roof the stadium has.
 */
void team::setRoofType(string roofType)
{
    this->roofType = roofType;
}

/**
 * @brief Set the Date Opened data member.
 * @param dateOpened Holds the date that the stadium was opened.
 */
void team::setDateOpened(string dateOpened)
{
    this->dateOpened = dateOpened;
}

/**
 * @brief A getter for the name of the Team.
 * @return String of the team name.
 */
string team::getTeamName() const
{
    return name;
}

/**
 * @brief A getter for the stadium name of the team.
 * @return String of the stadium name.
 */
string team::getStadiumName() const
{
    return stadiumName;
}

/**
 * @brief A getter for the seating capacity of the team.
 * @return String of the seating capacity.
 */
string team::getSeatingCapacity() const
{
    return seatingCapacity;
}

/**
 * @brief A getter for the location of a team's home stadium.
 * @return String of the location.
 */
string team::getLocation() const
{
    return location;
}

/**
 * @brief A getter for the conference of the Team.
 * @return String of the conference.
 */
string team::getConference() const
{
    return conference;
}

/**
 * @brief A getter for the division of the Team.
 * @return String of the divison.
 */
string team::getDivision() const
{
    return division;
}

/**
 * @brief A getter for the type of turf used in the stadium.
 * @return String of the surface type.
 */
string team::getSurfaceType() const
{
    return surfaceType;
}

/**
 * @brief A getter for the type of roof of the stadium.
 * @return String of the roof type.
 */
string team::getRoofType() const
{
    return roofType;
}

/**
 * @brief A getter for the date the home stadium opened.
 * @return String of the date opened.
 */
string team::getDateOpened() const
{
    return dateOpened;
}

/**
 * @brief Member function that reads in the data of a Team from a file.
 * @param inFile An input file name specified in main.
 */
void team::read(fstream &inFile)
{
    string temp = "";
    getline(inFile, name, ',');
    getline(inFile, stadiumName, ',');
    getline(inFile, temp, '"');
    getline(inFile, seatingCapacity, '"');
    getline(inFile, temp, '"');
    getline(inFile, location, '"');
    getline(inFile, temp, ',');
    getline(inFile, conference, ',');
    getline(inFile, division, ',');
    getline(inFile, surfaceType, ',');
    getline(inFile, roofType, ',');
    getline(inFile, dateOpened);
}
