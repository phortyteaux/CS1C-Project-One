/**
  * @file addTeam.cpp
  * @brief addTeam.cpp Contains definition of the addTeam function.
  * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
  */

#include "extra_functions.h"

/**
 * @brief addTeam Adds a team to the model passed by pointer.
 * @param model A data containment that makes it possible to interact with the team info from a widget.
 * @param teamName Name of the team.
 * @param stadiumName Name of the home stadium.
 * @param seatingCapacity How many seats the stadium has.
 * @param location Where the stadium is located.
 * @param conference Conference of the team.
 * @param division Division of the team.
 * @param surfaceType The surface type of the stadium turf.
 * @param roofType The type of roof of the stadium.
 * @param dateOpened The date the stadium opened.
 */
void addTeam(QAbstractItemModel *model, const QString &teamName,
             const QString &stadiumName, const QString &seatingCapacity,
             const QString &location, const QString &conference,
             const QString &division, const QString &surfaceType,
             const QString &stadiumRoofType, const QString &dateOpened)
{
    /**
      * @brief Adds a row to the model from the top.
      */
    model->insertRow(0);

    /** @brief Adds the QStrings into the . */
    model->setData(model->index(0, 0), teamName);
    model->setData(model->index(0, 1), stadiumName);
    model->setData(model->index(0, 2), seatingCapacity);
    model->setData(model->index(0, 3), location);
    model->setData(model->index(0, 4), conference);
    model->setData(model->index(0, 5), division);
    model->setData(model->index(0, 6), surfaceType);
    model->setData(model->index(0, 7), stadiumRoofType);
    model->setData(model->index(0, 8), dateOpened);
}
