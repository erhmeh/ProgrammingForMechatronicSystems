#ifndef LASER_H
#define LASER_H

#include "Ranger.h"

using namespace std;

class Laser : public Ranger
{
private:

    // Methods for validating user input to Setters
    bool validatePort(int port);
    bool validateBaudRate(int baudRate);
    bool validateAngularRes(int angularRes);
    bool validateAngularOffset(double angularOffset);
    void updateNumSamples();

public:
    Laser();
    Laser(int port, int baudRate, int angularRes, double angularOffset);

};

#endif // LASER_H
