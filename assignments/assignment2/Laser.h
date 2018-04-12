#ifndef LASER_H
#define LASER_H

#include "Ranger.h"

class Laser : public Ranger
{
public:
    Laser();
    bool setXOffset(double i);
protected:
};

#endif // LASER_H
