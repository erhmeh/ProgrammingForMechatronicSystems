#ifndef RADAR_H
#define RADAR_H

#include "Ranger.h"

using namespace std;

class Radar : public Ranger
{
private:

    // Methods for validating user input to Setters
    bool validatePort(int port);
    bool validateBaudRate(int baudRate);
    bool validateAngularRes(int angularRes);
    bool validateAngularOffset(double angularOffset);
    void updateNumSamples();


public:
    Radar();
    Radar(int port, int baudRate, int angularRes, double angularOffset);

};

#endif // RADAR_H
