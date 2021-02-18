/**
 * @file teamInfo.h
 * @class teamInfo
 * @brief This class holds all of the information associated with a single NFL team.
 * @author Max Kwatcher and Johnny Wannamaker
 * @date 2021-02-17
 */

#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


class teamInfo
{
private:
	/// @param teamName Holds the name of the team
	string teamName;

	/// @param stadiumName Holds the name of the home stadium
	string stadiumName;

	/// @param seatingCapaciy Holds the seating capacity of the stadium
	string seatingCapacity;

	/// @param stadiumLocation Holds the city and state of the stadium
	string stadiumLocation;

	/// @param conference Holds the conference that the team competes in
	string conference;

	/// @param division Holds the regional division of the team
	string division;

	/// @param typeOfSurface Holds the material of the stadium turf
	string typeOfSurface;

	/// @param typeOfRoof Holds the type of roof of the stadium
	string typeOfRoof;

	/// @param dateOpened Holds the date that the stadium was opened
	string dateOpened;
public:
	/**
	 * @brief Set the Team Name object
	 * 
	 */
	void setTeamName(string);

	/**
	 * @brief Set the Stadium Name object
	 * 
	 */
	void setStadiumName(string);

	/**
	 * @brief Set the Seating Capacity object
	 * 
	 */
	void setSeatingCapacity(string);

	/**
	 * @brief Set the Stadium Location object
	 * 
	 */
	void setStadiumLocation(string);

	/**
	 * @brief Set the Conference object
	 * 
	 */
	void setConference(string);

	/**
	 * @brief Set the Division object
	 * 
	 */
	void setDivision(string);

	/**
	 * @brief Set the Type Of Surface object
	 * 
	 */
	void setTypeOfSurface(string);

	/**
	 * @brief Set the Type Of Roof object
	 * 
	 */
	void setTypeOfRoof(string);

	/**
	 * @brief Set the Date Opened object
	 * 
	 */
	void setDateOpened(string);

	// getters 
	string getTeamName() const;
	string getStadiumName() const;
	string getSeatingCapacity() const;
	string getStadiumLocation() const;
	string getConference() const;
	string getDivision() const;
	string getTypeOfSurface() const;
	string getTypeOfRoof() const;
	string getDateOpened() const;

	// misc functions
	void read(fstream&);
	void print();
	void alphabetize(vector<string>&);
	void addToVector(vector<string>&, string);
};


