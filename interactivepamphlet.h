#ifndef INTERACTIVEPAMPHLET_H
#define INTERACTIVEPAMPHLET_H

#include <QWidget>
#include <QtCore>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QSortFilterProxyModel;
class QTreeView;
class QPushButton;
QT_END_NAMESPACE

class InteractivePamphlet : public QWidget
{
    Q_OBJECT

public:
    InteractivePamphlet();

    void setSourceModel(QAbstractItemModel *model);

private slots:
    void filterRegularExpressionChanged();
    void filterColumnChanged();
    void sortChanged();
    void calculateCapacity();

private:
    QSortFilterProxyModel *proxyModel;

    QGroupBox *sourceGroupBox;
    QGroupBox *proxyGroupBox;
    QTreeView *sourceView;
    QTreeView *proxyView;
    QCheckBox *filterCaseSensitivityCheckBox;
    QCheckBox *sortCaseSensitivityCheckBox;
    QLabel *filterPatternLabel;
    QLabel *filterSyntaxLabel;
    QLabel *filterColumnLabel;
    QLabel *stadiumCapacityLabel;
    QLineEdit *filterPatternLineEdit;
    QPushButton *calculateTotalButton;
    enum Syntax {
        RegularExpression,
        Wildcard,
        FixedString
    };

    QComboBox *filterSyntaxComboBox;
    QComboBox *filterColumnComboBox;
};

#endif // INTERACTIVEPAMPHLET_H
