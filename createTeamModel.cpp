#include "extra_functions.h"

QAbstractItemModel *createTeamModel(QObject *parent, vector<teamInfo> &teamInfoVec)
{
    // first two args define number of headers/columns
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

    for(int i = 0; i < teamInfoVec.size(); i++)
    {
        QString qTeamName = QString::fromStdString(teamInfoVec[i].getTeamName());
        QString qStadiumName = QString::fromStdString(teamInfoVec[i].getStadiumName());
        QString qSeatingCapacity = QString::fromStdString(teamInfoVec[i].getSeatingCapacity());
        QString qLocation = QString::fromStdString(teamInfoVec[i].getStadiumLocation());
        QString qConference = QString::fromStdString(teamInfoVec[i].getConference());
        QString qDivision = QString::fromStdString(teamInfoVec[i].getDivision());
        QString qSurfaceType = QString::fromStdString(teamInfoVec[i].getTypeOfSurface());
        QString qStadiumRoofType = QString::fromStdString(teamInfoVec[i].getTypeOfRoof());
        QString qDateOpened = QString::fromStdString(teamInfoVec[i].getDateOpened());
        addTeam(model, qTeamName, qStadiumName, qSeatingCapacity, qLocation,
                qConference, qDivision, qSurfaceType, qStadiumRoofType, qDateOpened);
    }

    return model;
}
