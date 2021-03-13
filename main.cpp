#include "interactivepamphlet.h"
#include "team.h"
#include "header.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    InteractivePamphlet window;
    vector<team> teamVec;

    /**
     * @brief An fstream object declared for the input file.
     * Contains all information regarding the NFL teams.
     */
    fstream inFile;

    /**
     * @brief The input file is opened to the correct path.
     */
    // inFile.open("/Users/johnny/Desktop/IJLAProject1/nfl.csv");
    inFile.open("C:/Users/johnn/OneDrive/Desktop/CS1C-Project-One-main/nfl.csv");

    // this loops through the input file and every loop reads in the data into a new team object
    // in the team vector. terminates at the end of file flag
    team tempElement;
    while (!inFile.eof())
    {
        tempElement.read(inFile);
        teamVec.push_back(tempElement);
    }

    // the input file is closed after all data from the input file has been read in
    inFile.close();

    // sets the source widget of the window to the widget
    window.setSourceModel(createTeamModel(&window, teamVec));

    window.show();
    return app.exec();
}
