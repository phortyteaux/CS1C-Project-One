#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

class teamInfo
{
private:
	string teamName;
	string stadiumName;
	string seatingCapacity;
	string stadiumLocation;
	string conference;
	string division;
	string typeOfSurface;
	string typeOfRoof;
	string dateOpened;
public:
	// setters 
	void setTeamName(string);
	void setStadiumName(string);
	void setSeatingCapacity(string);
	void setStadiumLocation(string);
	void setConference(string);
	void setDivision(string);
	void setTypeOfSurface(string);
	void setTypeOfRoof(string);
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
};

