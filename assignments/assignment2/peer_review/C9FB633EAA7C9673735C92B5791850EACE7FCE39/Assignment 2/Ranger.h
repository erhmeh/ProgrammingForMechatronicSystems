#ifndef RANGER_H
#define RANGER_H

#include <string>
#include <vector>

using namespace std;

class Ranger
{

protected:

    // Fixed Ranger Parameters
    string _model;
    int _fieldOfView;
    double _maxRange;
    double _minRange;

    // Configurable Ranger Parameters
    int _port;
    int _baudRate;
    int _angularRes;          // angular spacing of measurements

    double _angularOffset;    // angular offset in degrees from the chosen reference x axis

    // Dependent parameters
    int _numSamples;          // number of measurements taken in one complete scan
                              // Depends on fov and angular resolution

    // Default values for configurable parameters
    int _dfPort;
    int _dfBaudRate;
    int _dfAngularRes;
    double _dfAngularOffset;


    // Input authentication for configurable parameters. If invalid values are used, default values
    // will be used. These default values are to be defined in the derived class

    // Input authentication methods that will vary with different Rangers
    virtual bool validatePort(int port) = 0;
    virtual bool validateBaudRate(int baudRate) = 0;
    virtual bool validateAngularRes(int angularRes) = 0;
    virtual bool validateAngularOffset(double angularOffset) = 0;
    virtual void updateNumSamples() = 0;


public:

    Ranger(int dfPort, int dfBaudRate, int dfAngularRes, double dfAngularOffset,
           string model, int fieldOfView, double maxRange, double minRange);

    // Getter methods for obtaining the fixed and configurable parameters of the sensor
    string getModel();
    int getFieldOfView();
    double getMaxRange();
    double getMinRange();
    int getBaudRate();
    int getPort(); //###### might need to change return type ###############################
    int getAngularRes();
    double getAngularOffset();
    int getNumSamples();

    // Setters methods for changing configurable parameters
    bool setPort(int port);       //############ /dev/ttyACMX or /dev/ttyUSBX ???? #########
    bool setBaudRate(int baudRate);
    bool setAngularRes(int angularRes);
    bool setAngularOffset(double angularOffset);


    // Generates random (normally distributed) sensor output based on the numSamples data member and
    // is capped by the minRange and maxRange data members. Output is returned in a vector of doubles.
    vector<double> getRandOutput();

};

#endif // RANGER_H
