#ifndef RADARRIGHT_H
#define RADARRIGHT_H

#include "ranger.h"
#define RADARFOV_1 20
#define RADARFOV_2 60
#define MAXDISTANCE 16.00
#define MINDISTANCE 0.20

class RadarRight : public Ranger {
public:
    Radar();

    bool setFOV(int FOfV);

    void radarRightReading(); //

    double* getData(); //calls on radarRightReading() to populate data array
};
#endif /* RADARRIGHT_H */
