#ifndef SONAR
#define SONAR

#include "Ranger.h"

//values that are constants to the class Sonar

const std::string SONAR_MODEL = "SON-001";

const int SONAR_DEFAULT_BAUD = 38400;
const int SONAR_ADDITIONAL_BAUD = 115200;

const int SONAR_DEFAULT_PORT = 0;
const int SONAR_ADDITIONAL_PORT1 = 1;
const int SONAR_ADDITIONAL_PORT2 = 2;

const double SONAR_DEFAULT_FIELD_OF_VIEW = 90.0; // (90 degrees)

const double SONAR_DEFAULT_ANGULAR_RESOLUTION = 90.0; // (90 degrees)

const double SONAR_DEFAULT_MAX_DISTANCE = 6.0; //(6 meters)

const double SONAR_DEFAULT_MIN_DISTANCE = 0.2; //(0.2 meters)

const double SONAR_DEFAULT_DATA_RATE = 3.0; //(3 Hz)

/*!
 *  \ingroup   ac_shapre Sonar
 *  \brief     Sonar class derived from Ranger
 *  \details
 *  This class is a derived class for all Sonar sensors used in a range finder.\n
 *  \author    Jordan Henry
 *  \version   1.0
 *  \date      20/05/2018
 *  \pre       none
 *  \bug       none reported as of 20/05/2018
 *  \warning   none reported as of 20/05/2018
 */

class Sonar : public Ranger{
public:
    // Constructor initialies the class object //
    Sonar();
};

#endif // SONAR
