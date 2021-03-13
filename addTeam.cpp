#include "header.h"

void addTeam(QAbstractItemModel *model, const QString &name,
             const QString &stadiumName, const QString &seatingCapacity,
             const QString &location, const QString &conference,
             const QString &division, const QString &surfaceType,
             const QString &roofType, const QString &dateOpened)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), name);
    model->setData(model->index(0, 1), stadiumName);
    model->setData(model->index(0, 2), seatingCapacity);
    model->setData(model->index(0, 3), location);
    model->setData(model->index(0, 4), conference);
    model->setData(model->index(0, 5), division);
    model->setData(model->index(0, 6), surfaceType);
    model->setData(model->index(0, 7), roofType);
    model->setData(model->index(0, 8), dateOpened);
}
