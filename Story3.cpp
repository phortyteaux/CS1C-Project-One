// Story3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "teamInfo.h"

// function call operator overloads
// will move these to a file for global definitions later
struct sortByTeam
{
    inline bool operator() (const teamInfo& obj1, const teamInfo& obj2)
    {
        return (obj1.getTeamName() < obj2.getTeamName());
    }
};
struct sortByStadium
{
    inline bool operator() (const teamInfo& obj1, const teamInfo& obj2)
    {
        return (obj1.getStadiumName() < obj2.getStadiumName());
    }
};

int main()
{
    fstream file;
    teamInfo newTeam1, newTeam2, newTeam3;
    string temp = "";

    file.open("nfl.csv");

    getline(file, temp); //removes line containing column titles
    
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
