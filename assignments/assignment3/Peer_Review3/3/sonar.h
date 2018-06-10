#ifndef ASSIGNMENT3_SONAR_H
#define ASSIGNMENT3_SONAR_H

#include "ranger.h"

#define MODEL_SONAR "SON-001"
#define FIELD_OF_VIEW_SONAR (double) 90
#define MAX_DISTANCE_SONAR (double) 6.0
#define MIN_DISTANCE_SONAR (double) 0.2
#define DATA_RATE_SONAR (double) 3


#define MEAN_SONAR 0
#define STANDARD_DEVIATION_SONAR (double) 0.1


/*! \class Sonar inherits from class ranger
    \brief Class representing a ranger of type sonar
 *  \date      20.05.2018
    Class implementing a ranger type sonar which produces measurements at specified data rate an runs in a separate thread
*/
class Sonar: public Ranger
{
private:

public:
    //!Constructor of the sonar
    /*! Initializes all parameters which have then to be set
    */
    Sonar();

    //! Returns valid ports as a string
    /*!
      \return String listing all valid ports
    */
    std::string getValidPort();

    //! Returns valid baud rates as a string
    /*!
      \return String listing all valid baud rates
    */
    std::string getValidBaud();

    //! Sets the baud number of the sonar
    /*! Function checks whether the baud rate is accepted and uses a default value otherwise.
     * Acceptance is returned as a bool
     * \param baud baud number to be set
      \return bool indicator whether the value was accepted
    */
    bool setBaud(int baud);

    //! Sets the port of the sonar
    /*! Function checks whether the port is accepted and uses a default value otherwise.
     * Acceptance is returned as a bool
     * \param port Port to be set
      \return bool indicator whether the value was accepted
    */
    bool setPort(int port);


    //! Function passed to a thread to run the sonar and simulate data
    /*! Values are generated based on the desired data rate and stored in a cMeasurement struct which is passed to
     * the ranger buffer
     * This function contains an endless loop to run the sonar until the thread is terminated
     *
      \param buffer The buffer into which the ranger stores its generated data
    */
    void run(RangerBuffer &buffer);
};

#endif //ASSIGNMENT3_SONAR_H
