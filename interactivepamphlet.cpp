#include <QtWidgets>
#include <QVector>
#include <QtAlgorithms>
#include <iostream>
#include <string>
#include "interactivepamphlet.h"

const int NUM_COLUMNS = 9;

/**
 * @brief textColor
 * @param palette
 * @return
 */
static inline QColor textColor(const QPalette &palette)
{
    return palette.color(QPalette::Active, QPalette::Text);
}

/**
 * @brief setTextColor
 * @param w
 * @param c
 */
static void setTextColor(QWidget *w, const QColor &c)
{
    auto palette = w->palette();
    if (textColor(palette) != c) {
        palette.setColor(QPalette::Active, QPalette::Text, c);
        w->setPalette(palette);
    }
}

/**
 * @brief InteractivePamphlet::InteractivePamphlet
 */
InteractivePamphlet::InteractivePamphlet()
{
    proxyModel = new QSortFilterProxyModel;

    sourceView = new QTreeView;
    sourceView->setRootIsDecorated(false);
    sourceView->setAlternatingRowColors(true);
    sourceView->setSortingEnabled(true);

    proxyView = new QTreeView;
    proxyView->setRootIsDecorated(false);
    proxyView->setAlternatingRowColors(true);
    proxyView->setModel(proxyModel);
    proxyView->setSortingEnabled(true);
    proxyView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    sortCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive sorting"));
    filterCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive filter"));

    filterPatternLineEdit = new QLineEdit;
    filterPatternLineEdit->setClearButtonEnabled(true);
    filterPatternLabel = new QLabel(tr("&Filter pattern:"));
    filterPatternLabel->setBuddy(filterPatternLineEdit);

    filterSyntaxComboBox = new QComboBox;
    filterSyntaxComboBox->addItem(tr("Regular expression"), RegularExpression);
    filterSyntaxComboBox->addItem(tr("Wildcard"), Wildcard);
    filterSyntaxComboBox->addItem(tr("Fixed string"), FixedString);

    filterSyntaxLabel = new QLabel(tr("Filter &Column:"));
    filterSyntaxLabel->setBuddy(filterSyntaxComboBox);

    filterColumnComboBox = new QComboBox;
    filterColumnComboBox->addItem(tr("Team Name"));
    filterColumnComboBox->addItem(tr("Stadium Name"));
    filterColumnComboBox->addItem(tr("Seating Capacity"));
    filterColumnComboBox->addItem(tr("Stadium Location"));
    filterColumnComboBox->addItem(tr("Conference"));
    filterColumnComboBox->addItem(tr("Division"));
    filterColumnComboBox->addItem(tr("Surface Type"));
    filterColumnComboBox->addItem(tr("Stadium Roof Type"));
    filterColumnComboBox->addItem(tr("Date Opened"));

    filterColumnLabel = new QLabel(tr("Filter &column:"));
    filterColumnLabel->setBuddy(filterColumnComboBox);

    stadiumCapacityLabel = new QLabel(tr("total capacity"));

    calculateTotalButton = new QPushButton();
    calculateTotalButton->setText("Calculate Total");

    connect(filterPatternLineEdit, &QLineEdit::textChanged,
            this, &InteractivePamphlet::filterRegularExpressionChanged);
    connect(filterSyntaxComboBox, &QComboBox::currentIndexChanged,
            this, &InteractivePamphlet::filterRegularExpressionChanged);
    connect(filterColumnComboBox, &QComboBox::currentIndexChanged,
            this, &InteractivePamphlet::filterColumnChanged);
    connect(filterCaseSensitivityCheckBox, &QAbstractButton::toggled,
            this, &InteractivePamphlet::filterRegularExpressionChanged);
    connect(sortCaseSensitivityCheckBox, &QAbstractButton::toggled,
            this, &InteractivePamphlet::sortChanged);
    connect(calculateTotalButton, &QPushButton::released,
            this, &InteractivePamphlet::calculateCapacity);

//    sourceGroupBox = new QGroupBox(tr("Original Model"));
    proxyGroupBox = new QGroupBox(tr("Teams in the National Football League")); // Sorted/Filtered Model

    QHBoxLayout *sourceLayout = new QHBoxLayout;
    //sourceLayout->addWidget(sourceView);
    sourceGroupBox->setLayout(sourceLayout);

    // had everything but the proxyView/prpoxyGroupBox commented out
    QGridLayout *proxyLayout = new QGridLayout;
    proxyLayout->addWidget(proxyView, 0, 0, 1, 3);
    proxyLayout->addWidget(filterPatternLabel, 1, 0); // from me
    proxyLayout->addWidget(filterPatternLineEdit, 1, 1, 1, 2);
    //proxyLayout->addWidget(filterSyntaxLabel, 2, 0);
    //proxyLayout->addWidget(filterSyntaxComboBox, 2, 1, 1, 2);
    proxyLayout->addWidget(filterColumnLabel, 2, 0);
    proxyLayout->addWidget(filterColumnComboBox, 2, 1, 1, 2);
    proxyLayout->addWidget(stadiumCapacityLabel, 3, 0);
    //proxyLayout->addWidget(filterCaseSensitivityCheckBox, 4, 0, 1, 2);
    //proxyLayout->addWidget(sortCaseSensitivityCheckBox, 4, 2); // to me
    proxyLayout->addWidget(calculateTotalButton, 3, 1);
    proxyGroupBox->setLayout(proxyLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    //mainLayout->addWidget(sourceGroupBox);
    mainLayout->addWidget(proxyGroupBox);

    setLayout(mainLayout);

    setWindowTitle(tr("NFL Information Pamphlet"));
    resize(500, 450);

    proxyView->sortByColumn(0, Qt::AscendingOrder);
    filterColumnComboBox->setCurrentIndex(5);
    filterSyntaxComboBox->setCurrentIndex(2);

    //may need to re-comment this out
    filterPatternLineEdit->setText("");
    filterCaseSensitivityCheckBox->setChecked(false); //both were true
    sortCaseSensitivityCheckBox->setChecked(false);
}

/**
 * @brief InteractivePamphlet::setSourceModel
 * @param model
 */
void InteractivePamphlet::setSourceModel(QAbstractItemModel *model) /**/
{
    proxyModel->setSourceModel(model);
    sourceView->setModel(model);
    for(int i = 0; i < NUM_COLUMNS; i++)
    {
        proxyView->resizeColumnToContents(i);
    }
}

/**
 * @brief InteractivePamphlet::filterRegularExpressionChanged
 */
void InteractivePamphlet::filterRegularExpressionChanged()
{
    Syntax s = Syntax(filterSyntaxComboBox->itemData(filterSyntaxComboBox->currentIndex()).toInt());
    QString pattern = filterPatternLineEdit->text();
    switch (s) {
    case Wildcard:
        pattern = QRegularExpression::wildcardToRegularExpression(pattern);
        break;
    case FixedString:
        pattern = QRegularExpression::escape(pattern);
        break;
    default:
        break;
    }

    QRegularExpression::PatternOptions options = QRegularExpression::NoPatternOption;
    if (!filterCaseSensitivityCheckBox->isChecked())
        options |= QRegularExpression::CaseInsensitiveOption;
    QRegularExpression regularExpression(pattern, options);

    if (regularExpression.isValid()) {
        filterPatternLineEdit->setToolTip(QString());
        proxyModel->setFilterRegularExpression(regularExpression);
        setTextColor(filterPatternLineEdit, textColor(style()->standardPalette()));
    } else {
        filterPatternLineEdit->setToolTip(regularExpression.errorString());
        proxyModel->setFilterRegularExpression(QRegularExpression());
        setTextColor(filterPatternLineEdit, Qt::red);
    }
}

/**
 * @brief InteractivePamphlet::filterColumnChanged
 */
void InteractivePamphlet::filterColumnChanged()
{
    proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
    sourceView->sortByColumn(filterColumnComboBox->currentIndex(), Qt::AscendingOrder);
}

/**
 * @brief InteractivePamphlet::sortChanged
 */
void InteractivePamphlet::sortChanged()
{
    proxyModel->setSortCaseSensitivity(
            sortCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                     : Qt::CaseInsensitive);
}

/**
 * @brief InteractivePamphlet::calculateCapacity
 */
void InteractivePamphlet::calculateCapacity()
{
    const int STADIUM_NAMES = 1;       // column with stadium names
    const int SEATING_CAPACITY = 2;    // column with seating capacity
    QVector<QVariant> countedStadiums;
    int result = 0;
    for(int row = 0; row < proxyModel->rowCount(); row++)
    {
        if(std::count(countedStadiums.begin(), countedStadiums.end(), proxyModel->data(proxyModel->index(row, STADIUM_NAMES))))
        {
            QString temp;
            temp = proxyModel->data(proxyModel->index(row, STADIUM_NAMES)).toString();
            std::cout << "already counted " << temp.toStdString() << std::endl;
        }
        else
        {
            int tempInt;
            QString tempQString;
            std::string tempString;
            countedStadiums.push_back(proxyModel->data(proxyModel->index(row, STADIUM_NAMES)));
            tempQString = proxyModel->data(proxyModel->index(row, SEATING_CAPACITY)).toString();
            tempString = tempQString.toStdString();
            tempString.erase(std::remove(tempString.begin(), tempString.end(), ','), tempString.end());
            tempInt = stoi(tempString);
            result += tempInt;
        }
    }
    stadiumCapacityLabel->setText(QString::number(result));
}

