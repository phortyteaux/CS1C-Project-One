#include "window.h"
#include "team.h"
#include "extra_functions.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;

    /**
     * @brief mainInfoVec
     * A vector holding all of the team objects in the input file.
     */
    vector<team> mainInfoVec;

    /**
     * @brief inFile.
     * An fstream object representing the input data.
     */
    fstream inFile;

    /**
      * @brief Opens the input file containing all information regarding NFL.
      */
    // inFile.open("C:/Users/johnn/OneDrive/Desktop/CS1C-Project-One-QtFiles/nfl.csv");
    inFile.open("/Users/johnny/Desktop/CS1C-Project-One-Documented/nfl.csv");

    team tempElement;

    /**
      * @brief This loop iterates through the file until end of file flag.
      */
    while(!inFile.eof())
    {
        tempElement.read(inFile);
        mainInfoVec.push_back(tempElement);
    }

    /**
      * @brief Closes the input file.
      */
    inFile.close();

    window.setSourceModel(createTeamModel(&window, mainInfoVec));
    window.show();
    return app.exec();
}
