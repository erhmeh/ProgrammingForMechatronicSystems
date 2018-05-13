#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include "ranger.h"
#include <vector>

using std::vector;

class RangerFusion {
private:
    double fusedData[ARRAYSIZE]; //data array holds the fused data of rangers
    Ranger* laserSensor; //ranger in the first element of the ranger array, from getRangers(Ranger *rangers[])
    Ranger* radarLeft; //ranger in the second element of the ranger array, from getRangers(Ranger *rangers[])
    Ranger* radarRight; //ranger in the third element of the ranger array, from getRangers(Ranger *rangers[])

    double* laserSensorData; //data array of first ranger
    double* radarLeftData; //data array of second ranger
    double* radarRightData; //data array of third ranger

public:
    RangerFusion(); //RangerFusion class constructor

    void getRangers(Ranger *rangers[]); //obtains an array of rangers to fuse data

    void minFusion();

    void maxFusion();

    void averageFusion();

    double* getData();
};

#endif /* RANGERFUSION_H */
