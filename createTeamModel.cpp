/**
  * @file createTeamModel.cpp
  * @brief createTeamModel.cpp
  * Contains definition of the createTeamModel function.
  * @authors
  */

#include "extra_functions.h"

/**
 * @brief createTeamModel
 * @param parent A pointer to the base class of a
 * @param teamVec A vector containing all information regarding the NFL, stored in strings.
 * @return A QAbstractItemModel, containing all the information regarding the NFL, stored in QStrings.
 */
QAbstractItemModel *createTeamModel(QObject *parent, vector<team> &teamVec)
{
    /** @brief model
     *  Defines the data passed to the QTreeView, that sorts and displays the information.
     */
    QStandardItemModel *model = new QStandardItemModel(0, 9, parent);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Stadium Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Seating Capacity"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Location"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Conference"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Division"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Surface Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Stadium Roof Type"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Date Opened"));

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
