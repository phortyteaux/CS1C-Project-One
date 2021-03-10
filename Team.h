/** 
 * @file Team.h holds the definition of the Team class
 * @class Team Holds all of the information associated with a single NFL team
 * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#pragma once
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Team
{
private:
	/// @param name Holds the name of the Team.
	string name;

	/// @param name Holds the name of a Stadium.
	string stadiumName;

	/// @param seatingCapacity Holds the maximum seating of a Stadium.
	string seatingCapacity;

	/// @param location Holds the location of a Stadium.
	string location;

	/// @param conference Holds the conference that the Team competes in.
	string conference;

	/// @param division Holds the regional division of the Team.
	string division;

	/// @param surfaceType Holds the material used for the turf of a Stadium.
	string surfaceType;

	/// @param roofType Holds the type of roof of a Stadium.
	string roofType;

	/// @param dateOpened Holds the date that a Staium was opened.
	string dateOpened;

public:
	/**
	 * @brief Set the Team Name data member
	 * 
	 */
	void setTeamName(string name);

	/**
	 * @brief Set the Stadium Name data member
	 *
	 */
	void setStadiumName(string stadiumName);

	/**
	 * @brief Set the Seating Capacity data member
	 *
	 */
	void setSeatingCapacity(string seatingCapacity);

	/**
	 * @brief Set the Stadium Location data member
	 *
	 */
	void setLocation(string location);

	/**
	 * @brief Set the Conference data member
	 * 
	 */
	void setConference(string conference);

	/**
	 * @brief Set the Division data member
	 * 
	 */
	void setDivision(string division);

	/**
	 * @brief Set the Surface Type data member
	 *
	 */
	void setSurfaceType(string surfaceType);

	/**
	 * @brief Set the Roof Type data member
	 *
	 */
	void setRoofType(string roofType);

	/**
	 * @brief Set the Date Opened data member
	 *
	 */
	void setDateOpened(string dateOpened);


	/**
	 * @brief Get the Team Name data member
	 * 
	 * @return string 
	 */
	string getTeamName() const;

	/**
	  * @brief Get the Stadium Name data member
	  *
	  * @return string
	  */
	string getStadiumName() const;

	/**
	 * @brief Get the Seating Capacity data member
	 *
	 * @return integer
	 */
	string getSeatingCapacity() const;

	/**
	 * @brief Get the Location data member
	 *
	 * @return string
	 */
	string getLocation() const;

	/**
	 * @brief Get the Conference data member
	 * 
	 * @return string 
	 */
	string getConference() const;

	/**
	 * @brief Get the Division data member
	 * 
	 * @return string 
	 */
	string getDivision() const;

	/**
	  * @brief Get the Surface Type data member
	  *
	  * @return string
	  */
	string getSurfaceType() const;

	/**
	 * @brief Get the Roof Type data member
	 *
	 * @return string
	 */
	string getRoofType() const;

	/**
	* @brief Get the Date Opened data member
	*
	* @return integer
	*/
	int getDateOpened() const;

	/**
	 * @brief Member function to read in all Team information from an input 
	 * file specified in client and store in a Team object
      * 
	 * @param inFile file name to retreive Team information provided in client
	 */
	void read(fstream &inFile);


