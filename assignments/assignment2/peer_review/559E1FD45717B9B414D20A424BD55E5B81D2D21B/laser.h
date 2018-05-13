#ifndef LASER_H
#define LASER_H

#include "ranger.h"
#define LASERFOV 180
#define ANGLERES_1 10
#define ANGLERES_2 30
#define MAXLASER 8.0
#define MINLASER 0.2

class Laser : public Ranger {
private:
    int angleRes; //angular resolution of the laser

    double generateData; //uses genDist and filters out results related to the max and min values of the laser

public:
    Laser();

    //setters
    bool setAngleRes(int resolutionInput);

    //getters
    int getAngleRes(); //angular resolution of the laser

    void laserScan(); //takes readings depending on FOV and resolution, data stored in array

    double* getData(); //calls upon laserScan function to populate the laser data array

};

#endif /* LASER_H */

