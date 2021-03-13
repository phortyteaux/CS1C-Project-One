#ifndef HEADER_H
#define HEADER_H

#include "team.h"
//#include "interactivepamphlet.h"
#include <QApplication>
#include <QStandardItemModel>
//#include <QTime>
//#include <QFile>
#include <cstdio>
//#include <QtCore>

vector<team> createDataSubset(vector<team>, string);

// this function adds a team to an abstract item model
void addTeam(QAbstractItemModel *model, const QString &name,
             const QString &stadiumName, const QString &seatingCapacity,
             const QString &location, const QString &conference,
             const QString &division, const QString &surfaceType,
             const QString &roofType, const QString &dateOpened);

// this function creates a team model from a vector of team objects and
// returns the model once all teams are input into it
QAbstractItemModel *createTeamModel(QObject *parent, vector<team> &teamVec);

#endif // HEADER_H
