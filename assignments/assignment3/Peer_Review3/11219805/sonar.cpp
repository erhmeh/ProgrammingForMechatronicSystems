#include "ranger.h"
#include "sonar.h"

///Constructor that initialises every sonar specific parameter to default
Sonar::Sonar(){
    model_ = "SON-001";
    feildView_ = 90;
    maxDist_ = 6.0;
    minDist_ = 0.2;
    dataRate_ = 3;
}
///Constructor to accept configurable parameters
Sonar::Sonar(double baud, int port){
    Sonar();
    setBaud(baud);
    setPort(port);
}
