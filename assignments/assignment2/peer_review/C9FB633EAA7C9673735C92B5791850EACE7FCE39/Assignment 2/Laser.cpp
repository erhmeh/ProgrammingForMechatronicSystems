#include "Laser.h"

namespace defaults{
    const int kPort = 0;
    const int kBaudRate = 38400;
    const int kAngularRes = 30;           // default angular resolution
    const double kAngularOffset = 0.0;
}

const string kModel = "UTM-XXL";
const int kFieldOfView = 180;
const double kMinRange = 0.2;
const double kMaxRange = 8.0;



// 1) Initialise all the required variables to enable connecting to the sensor
Laser::Laser() : Laser(defaults::kPort, defaults::kBaudRate, defaults::kAngularRes, defaults::kAngularOffset)
{

}

Laser::Laser(int port, int baudRate, int angularRes, double angularOffset) :
    Ranger(defaults::kPort, defaults::kBaudRate, defaults::kAngularRes, defaults::kAngularOffset,
           kModel, kFieldOfView, kMaxRange, kMinRange)

{
    // Values passed to the construtor on creation of a Laser object must be authenticated.
    // Calling the respective setter methods will authenticate these values and set the private
    // data member to either the passed value or a default value depending on the result of the authentication.
    setPort(port);
    setBaudRate(baudRate);
    setAngularRes(angularRes);          // Number of samples will be updated when Angular Resolution is set
    setAngularOffset(angularOffset);
}


void Laser::updateNumSamples()
{
    // A laser returns the distance to a point in space, therefore, the number of smaples in a
    // scan must be determined by adding 1 to the division of the field of view by the angular resolution.
    _numSamples = (kFieldOfView/_angularRes) + 1;
}


bool Laser::validatePort(int port)
{
    if(port >= 0 && port <= 2)return true;
    else return false;
}

bool Laser::validateBaudRate(int baudRate)
{
    if(baudRate == 38400 || baudRate == 115200)return true;
    else return false;
}


bool Laser::validateAngularRes(int angularRes)
{
    if(angularRes == 10 || angularRes == 30)return true;
    else return false;
}

bool Laser::validateAngularOffset(double angularOffset)
{
    if(angularOffset >= 0.0 && angularOffset < 360.0)return true;
    else return false;

    // Setting the angular offset to 0 degrees will make this Ranger the reference for fusion, with
    // all other Ranger angular offsets being relative to this reference.

    // If none of the Rangers have an offset of 0 degrees then the Ranger with the smallest
    // offset value will become the reference during fusion.
}

