/**
  * @file extra_functions.h
  * @brief A header file for the additonal functions not defined in Window or Team.
  * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
  */

#ifndef EXTRA_FUNCTIONS_H
#define EXTRA_FUNCTIONS_H

#include "team.h"
#include "window.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTime>
#include <QFile>
#include <cstdio>
#include <QtCore>

/**
 * @brief addTeam Adds the data for one team to a model.
 * @param model Stores the data passed to QTreeView.
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
             const QString &roofType, const QString &dateOpened);

/**
 * @brief createTeamModel Creates the model where all NFL information will reside.
 * @param parent The model that is being used for the output of the teams.
 * @param teamVec The vector containing all team information in strings.
 * @return Pointer to a QAbstractItemModel.
 */
QAbstractItemModel *createTeamModel(QObject *parent, vector<team> &teamVec);

#endif // EXTRA_FUNCTIONS_H
