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
 * @brief addTeam
 * @param model
 * @param teamName
 * @param stadiumName
 * @param seatingCapacity
 * @param location
 * @param conference
 * @param division
 * @param surfaceType
 * @param stadiumRoofType
 * @param dateOpened
 */
void addTeam(QAbstractItemModel *model, const QString &teamName,
             const QString &stadiumName, const QString &seatingCapacity,
             const QString &location, const QString &conference,
             const QString &division, const QString &surfaceType,
             const QString &stadiumRoofType, const QString &dateOpened);

/**
 * @brief createTeamModel
 * @param parent
 * @param teamVec
 * @return
 */
QAbstractItemModel *createTeamModel(QObject *parent, vector<team> &teamVec);
#endif // EXTRA_FUNCTIONS_H
