#ifndef SONAR_H
#define SONAR_H

#include "ranger.h"

///Declare sonar as subclass of ranger
class Sonar : public Ranger{

public:
    Sonar();
    Sonar(double baud, int port);
};

#endif // SONAR_H
