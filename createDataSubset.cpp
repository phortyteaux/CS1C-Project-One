#include "extra_functions.h"
// this is currently un-used

vector<team> createDataSubset(vector<team> fullSetVec, string searchTerm)
{
    vector<team> subsetVec;
    int result;
    for (int i = 0; i < fullSetVec.size(); i++)
    {
        result = strcmp(searchTerm.c_str(), fullSetVec[i].getDivision().substr(0,3).c_str());
        cout << fullSetVec[i].getDivision().substr(0, 3).c_str() << endl;
        if (result == 0)
        {
            cout << "adding AFC team to second vector at iteration: " << i << endl;
            subsetVec.push_back(fullSetVec[i]);
        }
    }
    return subsetVec;
}
