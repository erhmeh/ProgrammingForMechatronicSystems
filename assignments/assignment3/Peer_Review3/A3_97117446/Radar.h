#ifndef RADAR
#define RADAR

#include "Ranger.h"

// values that are constants to the class Radar
const std::string RADAR_MODEL = "RAD-001";

const int RADAR_DEFAULT_BAUD = 38400;
const int RADAR_ADDITIONAL_BAUD = 115200;

const int RADAR_DEFAULT_PORT = 0;
const int RADAR_ADDITIONAL_PORT1 = 1;
const int RADAR_ADDITIONAL_PORT2 = 2;

const double RADAR_DEFAULT_FIELD_OF_VIEW = 20.0; // (20 degrees)
const double RADAR_ADDITIONAL_FIELD_OF_VIEW = 40.0; // (40 degrees)

const double RADAR_DEFAULT_ANGULAR_RESOLUTION = 20.0; // (20 degrees)
const double RADAR_ADDITIONAL_ANGULAR_RESOLUTION = 40.0; // (40 degrees)

const double RADAR_DEFAULT_MAX_DISTANCE = 10.0; //(10 meters)

const double RADAR_DEFAULT_MIN_DISTANCE = 0.2; //(0.2 meters)

const double RADAR_DEFAULT_DATA_RATE = 10.0; //(10 Hz)

const std::string RADAR_TYPE = "Radar";

/*!
 *  \ingroup   ac_shapre Radar
 *  \brief     Radar class derived from Ranger
 *  \details
 *  This class is a derived class for all Radar sensors used in a range finder.\n
 *  \author    Jordan Henry
 *  \version   1.0
 *  \date      20/05/2018
 *  \pre       none
 *  \bug       none reported as of 20/05/2018
 *  \warning   none reported as of 20/05/2018
 */

class Radar : public Ranger{
public:
    // Constructor initialies the class object //
    Radar();
};

#endif // RADAR
