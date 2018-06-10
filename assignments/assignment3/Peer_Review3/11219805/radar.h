#ifndef RADAR_H
#define RADAR_H

#include "ranger.h"

///Declare Radar as subclass of ranger
class Radar : public Ranger{

public:
    Radar();
    Radar(double baud, int port, int view);
    bool setFeildView(int view);
};

#endif // RADAR_H
