/**
 *  @file main.cpp
 *  @brief Defines the main function of the program.
 *  @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#include "window.h"
#include "team.h"
#include "extraFunctions.h"


/**
 * @brief The main function, handles the execution of the application as well as input from file.
 * @param argc Number of arguments passed as command line parameters.
 * @param argv Arguments passed as command line parameters.
 * @return The execution of the application.
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /**
     * @brief window Declaring a main window, calls the default constructor.
     */
    Window window;

    /**
     * @brief inFile
     * An fstream object representing the input data.
     */
    fstream inFile;

    /**
      * @brief Opens the input file containing all information regarding NFL.
      */
    inFile.open("C:/Users/johnn/OneDrive/Desktop/CS1C-Project-One-main/nfl.csv");

    team tempElement;

    /**
      * @brief This loop iterates through the file until end of file flag.
      * Reads in the data of the NFL into a vector of Team objects.
      */
    while(!inFile.eof())
    {
        tempElement.read(inFile);
        Window::mainInfoVec.push_back(tempElement);
    }

    /**
      * @brief Closes the input file.
      */
    inFile.close();

    /**
      * @brief setSourceModel Sets the source model of the main window to the created by createTeamModel.
      * A model is created for the NFL Information and passed to the main window from the mainInfoVec.
      */
    window.setSourceModel(createTeamModel(&window, Window::mainInfoVec));


    window.show();
    return app.exec();
}
