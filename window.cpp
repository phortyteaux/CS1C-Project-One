/**
 * @file window.cpp
 * @brief window.cpp Defines the behavior of the behavior of a Window object.
 * Window serves as the central widget in the application, and handles the GUI.
 * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#include <QtWidgets>
#include <QVector>
#include <QtAlgorithms>
#include <QtCore>
#include <QInputDialog>
#include <fstream>
#include <iostream>
#include <string>

#include "window.h"

/**
 * @brief NUM_COLUMNS Constant representing the number of columns in the QTreeView.
 */
const int NUM_COLUMNS = 9;

/**
 * @brief textColor Defines the coloring of the application based on the OS of the user.
 * @param palette The variable that referes to the coloring of the application.
 * @return A QColor at every point that it is referenced.
 */
static inline QColor textColor(const QPalette &palette)
{
    return palette.color(QPalette::Active, QPalette::Text);
}

/**
 * @brief setTextColor Sets the color of the text for the application based on the system default of user OS.
 * @param widget The central widget of the program.
 * @param color The color of the text used in the widget.
 */
static void setTextColor(QWidget *widget, const QColor &color)
{
    auto palette = widget->palette();
    if (textColor(palette) != color) {
        palette.setColor(QPalette::Active, QPalette::Text, color);
        widget->setPalette(palette);
    }
}

/**
 * @brief Window::Window The default constructor for the Window class.
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

    filterColumnLabel = new QLabel(tr("Filter &Column:"));
    filterColumnLabel->setBuddy(filterColumnComboBox);

    stadiumCapacityLabel = new QLabel(tr("Total Capacity:"));
    calculatedCapacityLabel = new QLabel(tr(""));
    calculatedCapacityLabel->setAlignment( Qt::AlignHCenter | Qt::AlignVCenter);

    calculateTotalButton = new QPushButton();
    calculateTotalButton->setText("Calculate Total");

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

    /** @brief Sets the passwordValid value initially to false, assuming the user has not logged in yet. */
    passwordValid = false;
}

/** @brief Window::createActions Connects menu items with the actions required to open their windows. */
void Window::createActions()
{
    /** @brief Allocates a new Action for contactAct, sets status, and maps connection. */
    contactAct = new QAction(tr("Contact Us"), this);
    contactAct->setStatusTip(tr("Email the devs"));
    connect(contactAct, &QAction::triggered, this, &Window::contactUs);

    /** @brief Allocates a new Action for helpMeAct, sets status, and maps connection. */
    helpMeAct = new QAction(tr("Help"), this);
    helpMeAct->setStatusTip(tr("Displays help info"));
    connect(helpMeAct, &QAction::triggered, this, &Window::helpMe);

    /** @brief Allocates a new Action for loginAct, sets status, and maps connection. */
    loginAct = new QAction(tr("Login"), this);
    loginAct->setStatusTip(tr("Login as admin"));
    connect(loginAct, &QAction::triggered, this, &Window::adminLogin);

    /** @brief Allocates a new Action for addTeamAct, sets status, and maps connection. */
    addTeamAct = new QAction(tr("New team"), this);
    addTeamAct->setStatusTip(tr("Add a new team"));
    connect(addTeamAct, &QAction::triggered, this, &Window::addTeamRunTime);
}

/**
 * @brief Window::createMenus Creates the menu bar at the top of the Window object.
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
 * @brief Window::contactUs This function displays a message window with the developer contact info.
 */
void Window::contactUs()
{
   QMessageBox::StandardButton reply = QMessageBox::question(this, "Developer Emails",
       "phortyteaux@gmail.com\nj.wannamaker19@gmail.com\nImTechy48@gmail.com\njoy4haddad@gmail.com\n\n"
       "Would you like to copy the emails to your clipboard?", QMessageBox::Yes | QMessageBox::No);

   if (reply == QMessageBox::Yes)
    {
        QApplication::clipboard();
    }
}

/**
 * @brief Window::helpMe This function displays all the relevant information to navigate the GUI.
 */
void Window::helpMe()
{
    QMessageBox::about(this, "Help Menu", "• In the drop down menu next to 'filter column,' choose\n "
        "an NFL category in order to sort by.\n • By choosing one of the categories, you can filter search\n"
        " for a specific team using the category you chose.\n • Pusing the 'Calculate Total' button will "
        "display the\n total seating capacity accross all the stadiums. ");
}

/**
 * @brief Window::adminLogin provides a window for the Admin to enter their password.
 * Validates or invalidates the Admin attempt to login, when logged in they can add a new team to the dataset.
 */
void Window::adminLogin()
{
    QInputDialog *login = new QInputDialog;

    /**
     * @brief setWindowTitle Sets the title of the window to Admin Login.
     */
    login->setWindowTitle(tr("Admin Login"));

    /** @brief Sets the text for the labels to Enter Password. */
    login->setLabelText(tr("Password"));

    /**
     * @brief setTextEchoMode Sets the input line to Password mode so the text is hidden when typed.
     */
    login->setTextEchoMode(QLineEdit::Password);

    QString password = "Password";

    if (passwordValid)
    {
        QMessageBox *alreadyLoggedIn = new QMessageBox;
        alreadyLoggedIn->setWindowTitle(tr("Error"));
        alreadyLoggedIn->setText(tr("You have already logged in"));
        alreadyLoggedIn->show();
    }
    else
    {
        login->show();

        if (login->exec() == QDialog::Accepted)
        {
            if (login->textValue() == password)
            {
                QMessageBox *validInput = new QMessageBox;
                validInput->setWindowTitle(tr("Welcome"));
                validInput->setText(tr("Successful login.\nYou may now Add Team."));
                validInput->show();
                this->passwordValid = true;
            }
            else
            {
                /**
                 * @brief invalidInput
                 * Pointer to a QMessageBox object indicating that the login failed.
                 */
                QMessageBox *invalidInput = new QMessageBox;

                invalidInput->setWindowTitle(tr("Error"));
                invalidInput->setText(tr("Failed login.\nPassword is invalid, please try again"));
                invalidInput->show();
                this->passwordValid = false;
            }
        }
    }
}

/**
 * @brief Window::addTeamRunTime Allows the user to enter a file path where data for the new team is located.
 * Opens the file specified by the user, checks if it has the necessary data, and updates the list with the
 * new team.
 */
void Window::addTeamRunTime()
{
    /**
      * @brief inputTeam The QInputDialog window that will provide the line between the user input and data
      * management in the program.
      */
     QInputDialog *inputTeam = new QInputDialog;

     /**
      * @brief inFile An instance of an fstream object that can read in from the file specified by the user.
      */
     std::fstream inFile;

     /** @brief setlabelText sets the text for the label. */
     inputTeam->setLabelText(tr("Specify a file path"));

     inputTeam->setWindowTitle(tr("Add a New Team"));

     QMessageBox *fileError = new QMessageBox;
     fileError->setWindowTitle(tr("Error"));
     fileError->setText(tr("Failed to open the file.\nPlease try again."));

     QMessageBox *fileSuccess = new QMessageBox;
     fileSuccess->setWindowTitle(tr("Success"));
     fileSuccess->setText(tr("The file was found and opened successfully."));
     ;

     if (passwordValid)
     {
        inputTeam->show();
        inFile.open(inputTeam->textValue().QString::toStdString());

        if (inputTeam->exec() == QDialog::Accepted)
        {
            if (!inFile.fail() || inFile.is_open())
            {
                fileSuccess->show();

                // read in from the file

                // pass to addTeam
            }
            else
            {
                fileError->show();
            }
        }

     }
     else
     {

         QMessageBox *invalidAttempt = new QMessageBox;
         invalidAttempt->setWindowTitle(tr("Error"));
         invalidAttempt->setText("Must login first before adding a team!");
         invalidAttempt->show();
     }
}

/**
 * @brief Window::setSourceModel Passes the "source" data to the model and view that are used for the Widget.
 * @param model A pointer to a QAbstractItemModel.
 */
void Window::setSourceModel(QAbstractItemModel *model) /**/
{
    proxyModel->setSourceModel(model);
    sourceView->setModel(model);

    for(int i = 0; i < NUM_COLUMNS; i++)
    {
        /** @brief Makes it so that the column sizes are determined by the longest member in that column. */
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
 * @brief Window::sortChanged Indicates that the 
 */
void Window::sortChanged()
{
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
}

/**
 * @brief Window::calculateCapacity Calculates the sum of all stadiums' seating capacity.
 * Accounts for all repeats in the list by adding stadium names to a string vector and checking the current
 * stadium against previously summed stadiums.
 */
void Window::calculateCapacity()
{
    const int STADIUM_NAMES = 1;    /** @brief STADIUM_NAMES Column number with stadium names. */
    const int SEATING_CAPACITY = 2; /** @brief SEATING_CAPACITY Column number with seating capacity. */

    /**
     * @brief countedStadiums Contains the stadiums already counted in the total capacity.
     * Used in order to avoid repeats in the count of total seating capacity.
     */
    QVector<QVariant> countedStadiums;

    /** @brief result Holds the total calculated seats. */
    int result = 0;

    /** @brief Loop iterates through */
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
