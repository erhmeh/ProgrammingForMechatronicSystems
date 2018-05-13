#ifndef LASER_H
#define LASER_H

#include "ranger.h"


class Laser : public Ranger
{
public:
    Laser();
    bool setAngRes(int);
    std::map<int, vector<double>> poll(void);

};

#endif // LASER_H
