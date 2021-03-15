/**
 * @file
 * @brief
 *
 * @authors
 */

#include <QtWidgets>
#include <QVector>
#include <QtAlgorithms>
#include <iostream>
#include <string>
#include "window.h"

const int NUM_COLUMNS = 9;

static inline QColor textColor(const QPalette &palette)
{
    return palette.color(QPalette::Active, QPalette::Text);
}


static void setTextColor(QWidget *w, const QColor &c)
{
    auto palette = w->palette();
    if (textColor(palette) != c) {
        palette.setColor(QPalette::Active, QPalette::Text, c);
        w->setPalette(palette);
    }
}


Window::Window()
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
    filterSyntaxLabel = new QLabel(tr("Filter &syntax:"));
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

    stadiumCapacityLabel = new QLabel(tr("Total capacity:"));
    calculatedCapacityLabel = new QLabel(tr(""));

    calculateTotalButton = new QPushButton();
    calculateTotalButton->setText("Calculate total");

    connect(filterPatternLineEdit, &QLineEdit::textChanged,
            this, &Window::filterRegularExpressionChanged);
    connect(filterSyntaxComboBox, &QComboBox::currentIndexChanged,
            this, &Window::filterRegularExpressionChanged);
    connect(filterColumnComboBox, &QComboBox::currentIndexChanged,
            this, &Window::filterColumnChanged);
    connect(filterCaseSensitivityCheckBox, &QAbstractButton::toggled,
            this, &Window::filterRegularExpressionChanged);
    connect(sortCaseSensitivityCheckBox, &QAbstractButton::toggled,
            this, &Window::sortChanged);
    connect(calculateTotalButton, &QPushButton::released,
            this, &Window::calculateCapacity);

    sourceGroupBox = new QGroupBox(tr(""));
    sourceGroupBox->setFlat(true);
    proxyGroupBox = new QGroupBox(tr("Teams in the League"));
    proxyGroupBox->setFlat(true);

    topFiller = new QSpacerItem(5, 5);


    QHBoxLayout *sourceLayout = new QHBoxLayout;
    sourceLayout->addItem(topFiller);
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
    proxyLayout->addWidget(calculatedCapacityLabel, 3, 1);
    //proxyLayout->addWidget(filterCaseSensitivityCheckBox, 4, 0, 1, 2);
    //proxyLayout->addWidget(sortCaseSensitivityCheckBox, 4, 2); // to me
    proxyLayout->addWidget(calculateTotalButton, 3, 2);
    proxyGroupBox->setLayout(proxyLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(sourceGroupBox);
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

    createActions();
    createMenus();
}



void Window::createActions()
{
    contactAct = new QAction(tr("Contact Us"), this);
    contactAct->setStatusTip(tr("Email the devs"));
    connect(contactAct, &QAction::triggered, this, &Window::contactUs);

    helpMeAct = new QAction(tr("Help"), this);
    helpMeAct->setStatusTip(tr("Displays help info"));
    connect(helpMeAct, &QAction::triggered, this, &Window::helpMe);

    loginAct = new QAction(tr("Login"), this);
    loginAct->setStatusTip(tr("Login as admin"));
    connect(loginAct, &QAction::triggered, this, &Window::adminLogin);

    addTeamAct = new QAction(tr("New team"), this);
    addTeamAct->setStatusTip(tr("Add a new team"));
    connect(addTeamAct, &QAction::triggered, this, &Window::addTeamRunTime);
}


void Window::createMenus()
{
    //kek $
    menuBar = new QMenuBar(this);
    adminMenu = menuBar->addMenu(tr("Admin"));
    adminMenu->addAction(loginAct);
    adminMenu->addAction(addTeamAct);

    helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(contactAct);
    helpMenu->addAction(helpMeAct);
}


void Window::contactUs()
{
    //
}


void Window::helpMe()
{
    //
}


void Window::adminLogin()
{
    //
}


void Window::addTeamRunTime()
{
    //
}


void Window::setSourceModel(QAbstractItemModel *model) /**/
{
    proxyModel->setSourceModel(model);
    sourceView->setModel(model);
    for(int i = 0; i < NUM_COLUMNS; i++)
    {
        proxyView->resizeColumnToContents(i);
    }
}


void Window::filterRegularExpressionChanged()
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

void Window::filterColumnChanged()
{
    proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
    sourceView->sortByColumn(filterColumnComboBox->currentIndex(), Qt::AscendingOrder);
}

void Window::sortChanged()
{
    proxyModel->setSortCaseSensitivity(
            sortCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                     : Qt::CaseInsensitive);
}

void Window::calculateCapacity()
{
    const int STADIUM_NAMES = 1;       // column with stadium names
    const int SEATING_CAPACITY = 2;    // column with seating capacity
    QVector<QVariant> countedStadiums;
    int result = 0;
    for(int row = 0; row < proxyModel->rowCount(); row++)
    {
        if(std::count(countedStadiums.begin(), countedStadiums.end(),
                      proxyModel->data(proxyModel->index(row, STADIUM_NAMES))))
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
            // std::cout << "tempInt: " << tempInt << ", ";
            // std::cout << "result: " << result << std::endl;
        }
    }
    calculatedCapacityLabel->setText(QString::number(result));
}
