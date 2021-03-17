/**
  * @file createTeamModel.cpp
  * @brief createTeamModel.cpp Contains definition of the createTeamModel function.
  * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
  */

#include "extraFunctions.h"

/**
 * @brief createTeamModel creates a model to store the information from the vector containing all Teams.
 * @param parent A pointer to the base class of a widget.
 * @param teamVec A vector containing all information regarding the NFL, stored in strings.
 * @return A QAbstractItemModel, containing all the information regarding the NFL, stored in QStrings.
 */
QAbstractItemModel *createTeamModel(QObject *parent, vector<team> &teamVec)
{
    /** @brief model Creates a new QStandardItemModel object.
     *  Defines the data passed to the QTreeView in Window, that sorts and displays the information.
     */
    QStandardItemModel *model = new QStandardItemModel(0, 9, parent);

    /**
      * @brief Creating an object for every header and labelling them appropriately.
      */
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Stadium Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Seating Capacity"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Location"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Conference"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Division"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Surface Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Stadium Roof Type"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Date Opened"));

    /**
      * @brief For loop iterates through the vector converting every string field to a QString.
      * After being converted to QStrings, the data from a team is passed to the addteam function.
      */
    for(unsigned int i = 0; i < teamVec.size(); i++)
    {
        QString qTeamName = QString::fromStdString(teamVec[i].getTeamName());
        QString qStadiumName = QString::fromStdString(teamVec[i].getStadiumName());
        QString qSeatingCapacity = QString::fromStdString(teamVec[i].getSeatingCapacity());
        QString qLocation = QString::fromStdString(teamVec[i].getLocation());
        QString qConference = QString::fromStdString(teamVec[i].getConference());
        QString qDivision = QString::fromStdString(teamVec[i].getDivision());
        QString qSurfaceType = QString::fromStdString(teamVec[i].getSurfaceType());
        QString qStadiumRoofType = QString::fromStdString(teamVec[i].getRoofType());
        QString qDateOpened = QString::fromStdString(teamVec[i].getDateOpened());
        addTeam(model, qTeamName, qStadiumName, qSeatingCapacity, qLocation,
                qConference, qDivision, qSurfaceType, qStadiumRoofType, qDateOpened);
    }

    return model;
}
