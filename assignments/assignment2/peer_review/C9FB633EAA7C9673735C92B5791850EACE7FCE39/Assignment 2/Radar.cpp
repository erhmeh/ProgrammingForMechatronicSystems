#include "Radar.h"

namespace defaults{
    const int kPort = 0;
    const int kBaudRate = 38400;
    const int kAngularRes = 20;           // default angular resolution
    const double kAngularOffset = 70.0;
}

const string kModel = "RAD-001";
const int kFieldOfView = 60;
const double kMinRange = 0.2;
const double kMaxRange = 16.0;

// 1) Initialise all the required variables to enable connecting to the sensor
Radar::Radar() : Radar(defaults::kPort, defaults::kBaudRate, defaults::kAngularRes, defaults::kAngularOffset)
{

}

Radar::Radar(int port, int baudRate, int angularRes, double angularOffset) :
    Ranger(defaults::kPort, defaults::kBaudRate, defaults::kAngularRes, defaults::kAngularOffset,
           kModel, kFieldOfView, kMaxRange, kMinRange)

{
    // Values passed to the construtor on creation of a Radar object must be authenticated.
    // Calling the respective setter methods will authenticate these values and set the private
    // data member to either the passed value or a default value depending on the result of the authentication.
    setPort(port);
    setBaudRate(baudRate);
    setAngularRes(angularRes);          // Number of Samples will be updated when Angular Resolution is set
    setAngularOffset(angularOffset);
}


void Radar::updateNumSamples()
{
    // A radar scans an area of space, shaped like a cone, and returns the shortest distance to an object in inside this
    // cone (i.e. the radius of the sector). The object can be located anywhere on the arc of this sector. Therefore, the
    // number of samples in a scan can be determind by dividing the field of view by the angular resolution.
    _numSamples = (kFieldOfView/_angularRes);
}


bool Radar::validatePort(int port)
{
    if(port >= 0 && port <= 2)return true;
    else return false;
}

bool Radar::validateBaudRate(int baudRate)
{
    if(baudRate == 38400 || baudRate == 115200)return true;
    else return false;
}

bool Radar::validateAngularRes(int angularRes)
{
    if(angularRes == 20)return true;
    else return false;
}

bool Radar::validateAngularOffset(double angularOffset)
{
    if(angularOffset >= 0.0 && angularOffset < 360.0)return true;
    else return false;

    // Setting the angular offset to 0 degrees will make this Ranger the reference for fusion, with
    // all other Ranger angular offsets being relative to this reference.

    // If none of the Rangers have an offset of 0 degrees then the Ranger with the smallest
    // offset value will become the reference during fusion.
}

