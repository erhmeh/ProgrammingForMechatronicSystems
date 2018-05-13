#include <chrono>
#include <random>
#include "Ranger.h"

const double kMean = 6.0;
const double kStdDev = 5.0;


Ranger::Ranger(int dfPort, int dfBaudRate, int dfAngularRes, double dfAngularOffset,
               string model, int fieldOfView, double maxRange, double minRange) :
    _dfPort(dfPort), _dfBaudRate(dfBaudRate), _dfAngularRes(dfAngularRes), _dfAngularOffset(dfAngularOffset),
    _model(model), _fieldOfView(fieldOfView), _maxRange(maxRange), _minRange(minRange)
{

}

bool Ranger::setPort(int port)
{
    if (validatePort(port) == true) _port = port;
    else _port = _dfPort;

    return validatePort(port);
}

bool Ranger::setBaudRate(int baudRate)
{
    if (validateBaudRate(baudRate) == true) _baudRate = baudRate;
    else _baudRate = _dfBaudRate;

    return validateBaudRate(baudRate);
}

bool Ranger::setAngularRes(int angularRes)
{
    if (validateAngularRes(angularRes) == true) _angularRes = angularRes;
    else _angularRes = _dfAngularRes;
    updateNumSamples();

    return validateAngularRes(angularRes);
}

bool Ranger::setAngularOffset(double angularOffset)
{
    if (validateAngularOffset(angularOffset) == true) _angularOffset = angularOffset;
    else _angularOffset = _dfAngularOffset;

    return validateAngularOffset(angularOffset);
}



string Ranger::getModel()
{
    return _model;
}

int Ranger::getFieldOfView()
{
    return _fieldOfView;
}

double Ranger::getMaxRange()
{
    return _maxRange;
}

double Ranger::getMinRange()
{
    return _minRange;
}

double Ranger::getAngularOffset()
{
    return _angularOffset;
}

int Ranger::getBaudRate()
{
    return _baudRate;
}

int Ranger::getPort()
{
    return _port;
}

int Ranger::getAngularRes()
{
    return _angularRes;
}

int Ranger::getNumSamples()
{
    return _numSamples;
}


// Generates random (normally distributed) Ranger output and returns the output in a vector
// of dobles. The sample generation is based on the numSamples data member and
// is capped by the minRange and maxRange data members.
vector<double> Ranger::getRandOutput()
{
    vector<double> output; //container that will hold the 'fake' Ranger output

    // Create a random number generator and seed it with the system clock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    // Create a normal distribution of doubles using specified mean and standard deviation
    normal_distribution<double> distribution (kMean, kStdDev);

    // Push the specified number of values, sampled from the distrubution,
    // into our samples container
    for (int i = 0; i<_numSamples; i++){

        // Generate a random sample
        double sample = distribution(generator);

        // Cap samples at the Rangers maximum and minimum range
        if (sample > _maxRange) sample = _maxRange;
        if (sample < _minRange) sample = _minRange;

        // add this sample to the output container
        output.push_back(sample);
    }
    return output;
}

