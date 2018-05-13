#ifndef RADAR_H
#define RADAR_H

#include "ranger.h"

class Radar : public Ranger
{
public:
    Radar();
    std::map<int, vector<double>> poll(void);
};

#endif // RADAR_H
