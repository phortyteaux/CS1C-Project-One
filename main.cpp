/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "window.h"
#include "teamInfo.h"
#include "extra_functions.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTime>
#include <QFile>
#include <cstdio>
#include <QtCore>

void addTeam(QAbstractItemModel *model, const QString &teamName,
             const QString &stadiumName, const QString &seatingCapacity,
             const QString &location, const QString &conference,
             const QString &division, const QString &surfaceType,
             const QString &stadiumRoofType, const QString &dateOpened)
{
    model->insertRow(0);
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

    // works for first 30 teams in .csv
    for(int i = 0; i < teamInfoVec.size() && i <= 30; i++)
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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    //QAbstractItemModel *subsetModel;
    vector<teamInfo> mainInfoVec(35); //originally (35)
    vector<teamInfo> AFCInfoVec;
    fstream inFile;
    inFile.open("C:/Qt/Examples/Qt-6.0.0/widgets/itemviews/basicsortfiltermodel/nfl.csv");
    string temp="";
    getline(inFile, temp); //removes line containing column titles
    for(auto &elem : mainInfoVec)
    {
        elem.read(inFile);
    }
    inFile.close();
    AFCInfoVec = createDataSubset(mainInfoVec,"AFC");
    //cout << "size of AFCInfoVec: " << AFCInfoVec.size() << endl;
    window.setSourceModel(createTeamModel(&window, mainInfoVec), createTeamModel(&window, AFCInfoVec)/**/);
    window.show();
    return app.exec();
}
