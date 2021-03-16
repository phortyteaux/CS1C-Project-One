/**
 * @file window.cpp
 * @brief window.cpp
 *
 * @authors
 */

#include <QtWidgets>
#include <QVector>
#include <QtAlgorithms>
#include <QInputDialog>
#include <iostream>
#include <string>
#include "window.h"
#include "login.h"
// #include "inputTeam.h"

/**
 * @brief NUM_COLUMNS
 */
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
 * @brief Window::Window
 */
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

    passwordValid = false;
}

/**
 * @brief Window::createActions
 */
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

/**
 * @brief Window::createMenus
 */
void Window::createMenus()
{
    menuBar = new QMenuBar(this);
    adminMenu = menuBar->addMenu(tr("Admin"));
    adminMenu->addAction(loginAct);
    adminMenu->addAction(addTeamAct);

    helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(contactAct);
    helpMenu->addAction(helpMeAct);
}

/**
 * @brief Window::contactUs
 */
void Window::contactUs()
{
    //
}

/**
 * @brief Window::helpMe
 */
void Window::helpMe()
{
    //
}

/**
 * @brief Window::adminLogin
 */
void Window::adminLogin()
{
    QInputDialog *login = new Login(this);

    login->show();

    QString password = "Password";

    if (login->textValue() == password)
    {
        // set a bool to true that allows the add team window, when clicked to open to another qinputdialog
        this->passwordValid = true;
    }
    else
    {
        // reset the login window
        this->passwordValid = false;
    }
}

/**
 * @brief Window::addTeamRunTime
 */
void Window::addTeamRunTime()
{
    // check bool if able to add team or not
    if (passwordValid)
    {
        // QInputDialog *inputTeam = new InputTeam(this);

        // inputTeam->show();
    }
}

/**
 * @brief Window::setSourceModel
 * @param model
 */
void Window::setSourceModel(QAbstractItemModel *model) /**/
{
    proxyModel->setSourceModel(model);
    sourceView->setModel(model);
    for(int i = 0; i < NUM_COLUMNS; i++)
    {
        proxyView->resizeColumnToContents(i);
    }
}

/**
 * @brief Window::filterRegularExpressionChanged
 */
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

/**
 * @brief Window::filterColumnChanged
 */
void Window::filterColumnChanged()
{
    proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
    sourceView->sortByColumn(filterColumnComboBox->currentIndex(), Qt::AscendingOrder);
}

/**
 * @brief Window::sortChanged
 */
void Window::sortChanged()
{
    proxyModel->setSortCaseSensitivity(
            sortCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                     : Qt::CaseInsensitive);
}

/**
 * @brief Window::calculateCapacity
 */
void Window::calculateCapacity()
{
    const int STADIUM_NAMES = 1;       /** @brief STADIUM_NAMES Column number with stadium names. */
    const int SEATING_CAPACITY = 2; /** @brief SEATING_CAPACITY Column number with seating capacity. */

    /**
     * @brief countedStadiums Contains the stadiums already counted in the total capacity.
     * Used in order to avoid repeats in the count of total seating capacity.
     */
    QVector<QVariant> countedStadiums;

    /** @brief result Holds the total calculated seats. */
    int result = 0;

    for(int row = 0; row < proxyModel->rowCount(); row++)
    {
        if(std::count(countedStadiums.begin(), countedStadiums.end(),
                      proxyModel->data(proxyModel->index(row, STADIUM_NAMES))))
        {
            QString temp;
            temp = proxyModel->data(proxyModel->index(row, STADIUM_NAMES)).toString();
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
    calculatedCapacityLabel->setText(QString::number(result));
}
