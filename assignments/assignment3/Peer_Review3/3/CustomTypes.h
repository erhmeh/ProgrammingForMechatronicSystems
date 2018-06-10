//
// Created by lw on 15.05.18.
//

#ifndef ASSIGNMENT3_CUSTOMTYPES_H
#define ASSIGNMENT3_CUSTOMTYPES_H

#include <chrono>
#include <vector>

/** Enum specifying the different ranger types
 *  Different ranger types can be specified by setting the member variable accordingly
 */
enum eRangerType {
    eRANGER_UNKNOWN =0,
    eSONAR = 1,
    eRADAR = 2

};

/** Struct to hold all necessary information about a measurement of a ranger type sensor
 * \date      20.05.2018
 */
struct cMeasurement
{
    /**
    *  Vector containing all measured distance values as doubles
    */
    std::vector<double> measurement;
    /**
    *  Enum ranger type defining the type of ranger which produced this measurement
    */
    eRangerType rangerType;
    /**
    *  Time point at which the measurement was produced
    */
    std::chrono::system_clock::time_point time;
    /**Maximal distance of the ranger to allow correct fusion
    */
    double ranger_max_distance;
    /**
    *  Miniamal distance of the ranger to allow correct fusion
    */
    double ranger_min_distance;
    /**
    *  field of view of the ranger
    */
    double ranger_FOV;
};



#endif //ASSIGNMENT3_CUSTOMTYPES_H
