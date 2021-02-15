#include "teamInfo.h"


// setters
void teamInfo::setTeamName(string n) 
{
	teamName = n;
}
void teamInfo::setStadiumName(string n) 
{
	stadiumName = n;
}
void teamInfo::setSeatingCapacity(string n) 
{
	seatingCapacity = n;
}
void teamInfo::setStadiumLocation(string n) 
{
	stadiumLocation = n;
}
void teamInfo::setConference(string n) 
{
	conference = n;
}
void teamInfo::setDivision(string n) 
{
	division = n;
}
void teamInfo::setTypeOfSurface(string n) 
{
	typeOfSurface = n;
}
void teamInfo::setTypeOfRoof(string n) 
{
	typeOfRoof = n;
}
void teamInfo::setDateOpened(string n) 
{
	dateOpened = n;
}

// getters
string teamInfo::getTeamName() const 
{
	return teamName;
}
string teamInfo::getStadiumName() const 
{
	return stadiumName;
}
string teamInfo::getSeatingCapacity() const 
{
	return seatingCapacity;
}
string teamInfo::getStadiumLocation() const 
{
	return stadiumLocation;
}
string teamInfo::getConference() const 
{
	return conference;
}
string teamInfo::getDivision() const 
{
	return division;
}
string teamInfo::getTypeOfSurface() const 
{
	return typeOfSurface;
}
string teamInfo::getTypeOfRoof() const 
{
	return typeOfRoof;
}
string teamInfo::getDateOpened() const 
{
	return dateOpened;
}

// misc functions
void teamInfo::read(fstream &inFile) 
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
void teamInfo::print() 
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
void teamInfo::alphabetize(vector<string>& sortingVector) 
{
	sort(sortingVector.begin(), sortingVector.end());
}
void teamInfo::addToVector(vector<string>& sortingVector, string dataMember) 
{
	sortingVector.push_back(dataMember);
}