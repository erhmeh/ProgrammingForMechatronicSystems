#ifndef ASSIGNMENT3_RADAR_H
#define ASSIGNMENT3_RADAR_H

#include "ranger.h"

#define MODEL_RADAR "RAD-001"
#define MAX_DISTANCE_RADAR (double) 10.0
#define MIN_DISTANCE_RADAR (double) 0.2
#define DATA_RATE_RADAR (double) 10

#define MEAN_RADAR 0
#define STANDARD_DEVIATION_RADAR (double) 0.1

/*! \class Radar inherits from class ranger
    \brief Class representing a ranger of type radar
 *  \date      20.05.2018
    Class implementing a ranger type radar which produces measurements at specified data rate an runs in a separate thread
*/
class Radar: public Ranger
{
private:

public:
    //!Constructor of the radar
    /*! Initializes all parameters which have then to be set
    */
    Radar();

    //! Returns the valid options for the field of view of the ranger.
    /*!
      \return String listing all valid options of the field of view of the ranger
    */
    std::string getValidFOV();

    //*
     /*! Function to set the field of view of the radar and checks for validity
     * \param field_of_view Value of field_of_view to be set
     * \return bool indicator whether the value was accepted
     */
    bool setFOV(double field_of_view);

    //! Returns valid ports as a string
    /*!
      \return String listing all valid ports
    */
    std::string getValidPort();

    //! Returns valid baud numbers as a string
    /*!
      \return String listing all valid baud numbers
    */
    std::string getValidBaud();

    //! Sets the baud number of the radar
    /*! Function checks whether the baud number is accepted and uses a default value otherwise.
     * Acceptance is returned as a bool
     * \param baud baud number to be set
      \return bool indicator whether the value was accepted
    */
    bool setBaud(int baud);

    //! Sets the port of the radar
    /*! Function checks whether the port is accepted and uses a default value otherwise.
     * Acceptance is returned as a bool
     * \param port Port to be set
      \return bool indicator whether the value was accepted
    */
    bool setPort(int port);


    //! Function passed to a thread to run the radar and simulate data
    /*! Values are generated based on the desired data rate and stored in a cMeasurement struct which is passed to
     * the ranger buffer
     * This function contains an endless loop to run the radar until the thread is terminated
     *
      \param buffer The buffer into which the ranger stores its generated data
    */
    void run(RangerBuffer &buffer);
};

#endif //ASSIGNMENT3_RADAR_H
