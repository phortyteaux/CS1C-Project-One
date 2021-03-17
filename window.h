/**
 *  @file window.h
 *  @class Window
 *  @brief Defines the content of the main window of the interactive pamphlet app.
 *  @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtCore>
#include "team.h"

QT_BEGIN_NAMESPACE
class QtCore;
class QAbstractItemModel;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QSortFilterProxyModel;
class QInputDialog;
class QTreeView;
class QPushButton;
class QMenuBar;
class QMenu;
class QAction;
class QSpacerItem;
class QMessageBox;
QT_END_NAMESPACE

/**
 * @brief The Window class is the central widget of the application.
 * It supports the functionality a viewing a spread of NFL teams, being able to sort by their column
 * headers (Team Name, Stadium Name, Location, Conference, Division, etc.), calculating the maximum
 * capacity of seats across all stadiums, and support for an administator login to add a team.
 */
class Window : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Window
     * Constructor for the Window class.
     */
    Window();

    /**
     * @brief setSourceModel Sets the source model to be displayed in the widget.
     * @param model A pointer to the QAbstractItem containing the source model.
     */
    void setSourceModel(QAbstractItemModel *model);

    /**
     * @brief mainInfoVec A vector.
     * A vector holding all of the team objects in the input file.
     */
    static vector<team> mainInfoVec;

private slots:
    /** @brief Indicates the text filter has been changed. */
    void filterRegularExpressionChanged();

    /** @brief Indicates the column to filter the view by when text is entered has been changed. */
    void filterColumnChanged();

    /** @brief Indicates that the sort of the view has been changed by column header. */
    void sortChanged();

    /** @brief Indicator to calculate the total capacity across all stadiums in the view. */
    void calculateCapacity();

    /** @brief Indicates the Contact Us menu option has been activated. */
    void contactUs();

    /** @brief Indicates that the Help menu option has been activated. */
    void helpMe();

    /** @brief Indicator for the . */
    void adminLogin();
    void addTeamRunTime();

private:
    /**
     * @param proxyModel
     * Pointer to a QSortFilterProxyModel object.
     */
    QSortFilterProxyModel *proxyModel;

    /**
     * @brief topFiller
     * Pointer to a QSpacerItem object.
     */
    QSpacerItem *topFiller;

    /**
     * @brief sourceGroupBox
     * Pointer to a QGroupBox object.
     */
    QGroupBox *sourceGroupBox;

    /**
     * @brief proxyGroupBox
     * Pointer to a QGroupBox object.
     */
    QGroupBox *proxyGroupBox;

    /**
     * @brief sourceView
     * Pointer to a QTreeView object.
     */
    QTreeView *sourceView;

    /**
     * @brief proxyView
     * Pointer to a QTreeView object.
     */
    QTreeView *proxyView;

    /**
     * @brief filterCaseSensitivityCheckBox
     * Pointer to a QCheckBox object.
     */
    QCheckBox *filterCaseSensitivityCheckBox;

    /**
     * @brief sortCaseSensitivityCheckBox
     * Pointer to a QCheckBox object.
     */
    QCheckBox *sortCaseSensitivityCheckBox;

    /**
     * @brief filterPatternLabel
     * Pointer to a QLabel object.
     */
    QLabel *filterPatternLabel;

    /**
     * @brief filterSyntaxLabel
     * Pointer to a QLabel object.
     */
    QLabel *filterSyntaxLabel;

    /**
     * @brief filterColumnLabel
     * Pointer to a QLabel object.
     */
    QLabel *filterColumnLabel;

    /**
     * @brief stadiumCapacityLabel
     * Pointer to a QLabel object.
     */
    QLabel *stadiumCapacityLabel;

    /**
     * @brief calculatedCapacityLabel
     * Pointer to a QLabel object.
     */
    QLabel *calculatedCapacityLabel;

    /**
     * @brief filterPatternLineEdit
     * Pointer to a QLineEdit object.
     */
    QLineEdit *filterPatternLineEdit;

    /**
     * @brief calculateTotalButton
     * Pointer to a QPushButton object.
     */
    QPushButton *calculateTotalButton;

    /**
     * @brief The Syntax enum to indicate  .
     */
    enum Syntax {
        RegularExpression,
        Wildcard,
        FixedString
    };

    /**
     * @brief filterSyntaxComboBox
     * Pointer to a QComboBox object.
     */
    QComboBox *filterSyntaxComboBox;

    /**
     * @brief filterColumnComboBox
     * Pointer to a QComboBox object.
     */
    QComboBox *filterColumnComboBox;

    /**
     * @brief helpMeAct
     * Pointer to a QAction object.
     */
    QAction *helpMeAct;

    /**
     * @brief contactAct
     * Pointer to a QAction object.
     */
    QAction *contactAct;

    /**
     * @brief loginAct
     * Pointer to a QAction object.
     */
    QAction *loginAct;

    /**
     * @brief addTeamAct
     * Pointer to a QAction object.
     */
    QAction *addTeamAct;

    /**
     * @brief menuBar
     * Pointer to a QMenuBar object.
     */
    QMenuBar *menuBar;

    /**
     * @brief adminMenu
     * Pointer to a QMenu object.
     */
    QMenu *adminMenu;

    /**
     * @brief helpMenu
     * Pointer to a QMenu object.
     */
    QMenu *helpMenu;

    /**
     * @brief createActions
     */
    void createActions();

    /**
     * @brief createMenus
     */
    void createMenus();

    /**
     * @brief passwordValid
     * A bool indicating if the entered password by the user is correct or not.
     */
    bool passwordValid;
};

#endif // WINDOW_H
