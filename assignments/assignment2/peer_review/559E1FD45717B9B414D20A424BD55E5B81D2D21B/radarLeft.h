#ifndef RADAR_H
#define RADAR_H

#include "ranger.h"
#define RADARFOV_1 20
#define RADARFOV_2 60
#define MAXDISTANCE 16.00
#define MINDISTANCE 0.20

class RadarLeft : public Ranger {
public:
    Radar();

    bool setFOV(int FOfV);

    void radarLeftReading();

    double* getData();
};

#endif /* RADAR_H */
