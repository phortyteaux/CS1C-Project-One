/**
 * @file window.h
 *
 *  @class Window
 *  Defines the content of the main window of the interactive pamphlet app.
 *  @authors
 */

#ifndef WINDOW_H
#define WINDOW_H

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
class QInputDialog;
class QTreeView;
class QPushButton;
class QMenuBar;
class QMenu;
class QAction;
class QSpacerItem;
QT_END_NAMESPACE

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
    void setSourceModel(QAbstractItemModel *model); /**/
    //void setProxyView(QAbstractItemModel *model);

private slots:
    void filterRegularExpressionChanged();
    void filterColumnChanged();
    void sortChanged();
    void calculateCapacity();

    void contactUs();
    void helpMe();
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
     * @brief The Syntax enum.
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

    QInputDialog *login;

    QAction *helpMeAct;

    QAction *contactAct;

    QAction *loginAct;

    QAction *addTeamAct;

    QMenuBar *menuBar;

    QMenu *adminMenu;

    QMenu *helpMenu;

    void createActions();

    void createMenus();

    bool passwordValid;
};

#endif // WINDOW_H
