/**
 * @file team.h Defines the contents of a Team object.
 * @class team Holds the team name, stadium name, location, capacity, division, etc.
 * @brief Definition of the team class, holding all information regarding a single NFL team.
 * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#ifndef TEAM_H_
#define TEAM_H_

#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/** @brief A team object is the basic object that is dealt with in this program. */
class team
{
private:
    /** @param teamName Holds the name of the Team. */
    string teamName;

    /** @param stadiumName Holds the name of a Stadium. */
    string stadiumName;

    /** @param seatingCapacity Holds the maximum seating of a Stadium. */
    string seatingCapacity;

    /** @param location Holds the location of a Stadium. */
    string location;

    /** @param conference Holds the conference that the Team competes in. */
    string conference;

    /** @param division Holds the regional division of the Team. */
    string division;

    /** @param surfaceType Holds the material used for the turf of a Stadium. */
    string surfaceType;

    /** @param roofType Holds the type of roof of a Stadium. */
    string roofType;

    /** @param dateOpened Holds the date that a Staium was opened. */
    string dateOpened;

public:
    /** @brief Set the Team Name data member. */
    void setTeamName(string teamName);

    /** @brief Set the Stadium Name data member. */
    void setStadiumName(string stadiumName);

    /** @brief Set the Seating Capacity data member. */
    void setSeatingCapacity(string seatingCapacity);

    /** @brief Set the Stadium Location data member. */
    void setLocation(string location);

    /** @brief Set the Conference data member. */
    void setConference(string conference);

    /** @brief Set the Division data member. */
    void setDivision(string division);

    /** @brief Set the Surface Type data member. */
    void setSurfaceType(string surfaceType);

    /** @brief Set the Roof Type data member. */
    void setRoofType(string roofType);

    /** @brief Set the Date Opened data member. */
    void setDateOpened(string dateOpened);


    /**
     * @brief Get the Team Name data member.
     * @return Team name.
     */
    string getTeamName() const;

    /**
      * @brief Get the Stadium Name data member.
      * @return Team's stadium name.
      */
    string getStadiumName() const;

    /**
     * @brief Get the Seating Capacity data member.
     * @return Team's stadium seating capacity.
     */
    string getSeatingCapacity() const;

    /**
     * @brief Get the Location data member.
     * @return Team's location.
     */
    string getLocation() const;

    /**
     * @brief Get the Conference data member.
     * @return Team conference.
     */
    string getConference() const;

    /**
     * @brief Get the Division data member.
     * @return Team division.
     */
    string getDivision() const;

    /**
      * @brief Get the Surface Type data member.
      * @return Team stadium surface type.
      */
    string getSurfaceType() const;

    /**
     * @brief Get the Roof Type data member.
     * @return Team stadium roof type.
     */
    string getRoofType() const;

    /**
    * @brief Get the Date Opened data member.
    * @return Team's stadium date opened.
    */
    string getDateOpened() const;

    /**
     * @brief Member function to read in all Team information.
     * Input file specified in main and info stored into a Team object.
     * @param inFile File name to retreive Team information provided in main.
     */
    void read(fstream &inFile);
};

#endif // TEAM_H_
