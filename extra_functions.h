#ifndef EXTRA_FUNCTIONS_H
#define EXTRA_FUNCTIONS_H
#include "teamInfo.h"
#include "window.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTime>
#include <QFile>
#include <cstdio>
#include <QtCore>

vector<teamInfo> createDataSubset(vector<teamInfo>, string);

void addTeam(QAbstractItemModel *model, const QString &teamName,
             const QString &stadiumName, const QString &seatingCapacity,
             const QString &location, const QString &conference,
             const QString &division, const QString &surfaceType,
             const QString &stadiumRoofType, const QString &dateOpened);

QAbstractItemModel *createTeamModel(QObject *parent, vector<teamInfo> &teamInfoVec);
#endif // EXTRA_FUNCTIONS_H
