/**
 * @file Story3.cpp
 * @author Max Kwatcher and Johnny Wannamaker
 * @brief This file contains the 'main' function. Program execution begins and ends there.
 * @version 0.1
 * @date 2021-02-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "teamInfo.h"

/**
 * @brief A function call operator overload. Will be moved into a global definition
 * at a later date.
 */
struct sortByTeam
{
    inline bool operator() (const teamInfo& obj1, const teamInfo& obj2)
    {
        return (obj1.getTeamName() < obj2.getTeamName());
    }
};

/**
 * @brief A function call operator overload. Will be moved into a global definition
 * at a later date.
 */
struct sortByStadium
{
    inline bool operator() (const teamInfo& obj1, const teamInfo& obj2)
    {
        return (obj1.getStadiumName() < obj2.getStadiumName());
    }
};

int main()
{
    /**
     * @brief A file stream object initialized.
     * 
     */
    fstream file;
    teamInfo newTeam1, newTeam2, newTeam3;
    string temp = "";

    file.open("nfl.csv");

    /**
     * @brief Construct a new getline object that removes the column names from the input file.
     * 
     */
    getline(file, temp); 
    
    newTeam1.read(file);
    newTeam2.read(file);
    newTeam3.read(file);

    file.close();

    vector<teamInfo> teamInfoVec;
    teamInfoVec.push_back(newTeam1);
    teamInfoVec.push_back(newTeam2);
    teamInfoVec.push_back(newTeam3);
    swap(teamInfoVec[0], teamInfoVec[2]); // data is already organized by team name, so swap unorganizes it

    cout << "Before sorting:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        teamInfoVec[i].print();
    }

    sort(teamInfoVec.begin(), teamInfoVec.end(), sortByTeam());

    cout << "After sorting:" << endl;
    for (int i = 0; i < 3; i++)
    {
        teamInfoVec[i].print();
    }

    return 0;
}
