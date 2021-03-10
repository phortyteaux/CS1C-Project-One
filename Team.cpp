/**
 * @file Team.cpp Holds implementation of methods defined in Team
 * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#include "Team.h"

/**
 * @brief A setter for the team name of a team object.
 * @param Name The team name to be stored in the team info object.
 */
void Team::setTeamName(string name) 
{
	this->name = name;
}

/**
 * @brief Set the Stadium Name data member.
 * @param stadiumName Holds the stadium name.
 */
void Team::setStadiumName(string stadiumName)
{
	this->stadiumName = stadiumName;
}

/**
 * @brief Set the Seating Capacity data member.
 * @param seatingCapacity Holds the max seating capacity of the stadium.
 */
void Team::setSeatingCapacity(string seatingCapacity)
{
	this->seatingCapacity = seatingCapacity;
}

/**
 * @brief Set the Stadium Location data member.
 * @param location Holds the location of the stadium.
 */
void Team::setLocation(string location)
{
	this->location = location;
}

/**
 * @brief A setter for the conference of a team object.
 * @param conference The conference that a team competes in (NFC, AFC, etc).
 */
void Team::setConference(string conference) 
{
	this->conference = conference;
}

/**
 * @brief A setter for the division of a team object.
 * @param division The division of a team (NFC West, AFC South, etc).
 */
void Team::setDivision(string division) 
{
	this->division = division;
}

/**
 * @brief Set the Surface Type data member.
 * @param surfaceType Holds the type of surface the stadium turf is.
 */
void Team::setSurfaceType(string surfaceType)
{
	this->surfaceType = surfaceType;
}

/**
 * @brief Set the Roof Type data member.
 * @param roofType Holds the type of roof the stadium has.
 */
void Team::setRoofType(string roofType)
{
	this->roofType = roofType;
}

/**
 * @brief Set the Date Opened data member.
 * @param dateOpened Holds the date that the stadium was opened.
 */
void Team::setDateOpened(string dateOpened)
{
	this->dateOpened = dateOpened;
}

/**
 * @brief A getter for the name of the Team.
 * @return String of the team name.
 */
string Team::getTeamName() const 
{
	return name;
}

/**
 * @brief A getter for the stadium name of the team.
 * @return String of the stadium name.
 */
string Team::getStadiumName() const
{
	return stadiumName;
}

/**
 * @brief A getter for the seating capacity of the team.
 * @return String of the seating capacity.
 */
string Team::getSeatingCapacity() const
{
	return seatingCapacity;
}

/**
 * @brief A getter for the location of a team's home stadium.
 * @return String of the location.
 */
string Team::getLocation() const
{
	return location;
}

/**
 * @brief A getter for the conference of the Team.
 * @return String of the conference.
 */
string Team::getConference() const 
{
	return conference;
}

/**
 * @brief A getter for the division of the Team.
 * @return String of the divison. 
 */
string Team::getDivision() const 
{
	return division;
}

/**
 * @brief A getter for the type of turf used in the stadium.
 * @return String of the surface type.
 */
string Team::getSurfaceType() const
{
	return surfaceType;
}

/**
 * @brief A getter for the type of roof of the stadium.
 * @return String of the roof type.
 */
string Team::getRoofType() const
{
	return roofType;
}

/**
 * @brief A getter for the date the home stadium opened.
 * @return String of the date opened.
 */
string Team::getDateOpened() const
{
	return dateOpened;
}

/**
 * @brief Member function that reads in the data of a Team from a file.
 * 
 * @param inFile An input file name specified in main.
 */
void Team::read(fstream &inFile) 
{
	string temp = ""; 
	getline(inFile, name, ',');
	getline(inFile, stadium.name, ',');
	getline(inFile, temp, '"');
	getline(inFile, stadium.seatingCapacity, '"');
	getline(inFile, temp, '"');
	getline(inFile, stadium.location, '"');
	getline(inFile, temp, ',');
	getline(inFile, conference, ',');
	getline(inFile, division, ',');
	getline(inFile, stadium.surfaceType, ',');
	getline(inFile, stadium.roofType, ',');
	getline(inFile, stadium.dateOpened);
}