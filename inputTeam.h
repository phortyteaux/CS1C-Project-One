/**
  * @file inputTeam.h
  * @class InputTeam
  * @brief inputTeam.h Contains the definition of the InputTeam class.
  * A window responsible for recieving the input from the administrator to add a team to the list.
  * @authors Max Kwatcher, Johnny Wannamaker, Aileen Phoung, and Joy Haddad
  */

#ifndef INPUTTEAM_H
#define INPUTTEAM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QWidget;
class QLineEdit;
class QPushButton;
class QLabel;
class QComboBox;
class QtCore;
QT_END_NAMESPACE

/**
 * @brief The InputTeam class is a dialog that will allow the user to enter info for a new NFL team.
 */
class InputTeam : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief InputTeam Constructor for the InputTeam object, sets up the window for user input.
     */
    InputTeam(QWidget *parent = nullptr);

private:
    /**
     * @brief teamNameLineEdit
     * Pointer to a QLineEdit object accepting the input for a new team name.
     */
    QLineEdit *teamNameLineEdit;
    QLabel *teamNameLabel;

    /**
     * @brief stadiumNameLineEdit
     * Pointer to a QLineEdit object accepting the input for a new stadium name.
     */
    QLineEdit *stadiumNameLineEdit;
    QLabel *stadiumNameLabel;

    /**
     * @brief seatingCapacityLineEdit
     * Pointer to a QLineEdit object accepting the input for a new seating capacity.
     */
    QLineEdit *seatingCapacityLineEdit;
    QLabel *seatingCapacityLabel;

    /**
     * @brief cityLineEdit
     * Pointer to a QLineEdit object accepting the city in which the new team resides.
     */
    QLineEdit *cityLineEdit;
    QLabel *cityLabel;

    /**
     * @brief stateComboBox
     * Pointer to a QComboBox object accepting the state for the new team.
     * A drop down choice of the states.
     */
    QComboBox *stateComboBox;
    QLabel *stateLabel;

    /**
     * @brief conferenceComboBox
     * Pointer to a QComboBox object accepting either AFC or NFC.
     */
    QComboBox *conferenceComboBox;
    QLabel *conferenceLabel;

    /**
     * @brief divisionComboBox
     * Pointer to a QComboBox object accepts either North, South, East, or West.
     */
    QComboBox *divisionComboBox;
    QLabel *divisionLabel;

    /**
     * @brief surfaceTypeLineEdit
     * Pointer to a QLineEdit object accepting the type of surface found in the new stadium.
     */
    QLineEdit *surfaceTypeLineEdit;
    QLabel *surfaceTypeLabel;

    /**
     * @brief rooftypeCombo
     * Pointer to a QComboBox object that accepts either Fixed, Open, or Retractable.
     */
    QComboBox *roofTypeComboBox;
    QLabel *roofTypeLabel;

    /**
     * @brief yearLineEdit
     * Pointer to a QLineEdit object that accepts the year that the stadium opened.
     * Range of integers must be between 1924 and 2050.
     */
    QLineEdit *yearLineEdit;
    QLabel *dateOpenedLabel;
};

#endif // INPUTTEAM_H
