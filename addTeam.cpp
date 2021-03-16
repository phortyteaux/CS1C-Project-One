#include "extra_functions.h"

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
