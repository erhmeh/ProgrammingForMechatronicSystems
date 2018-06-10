#include "ranger.h"
#include "radar.h"

///Constructor that initialises every radar specific parameter to default
Radar::Radar(){
    model_ = "RAD-001";
    feildView_ = 20;
    maxDist_ = 10.0;
    minDist_ = 0.2;
    dataRate_ = 10;
}
///Constructor to accept configurable parameters
Radar::Radar(double baud, int port, int view){
    Radar();
    setBaud(baud);
    setPort(port);
    setFeildView(view);
}
///Function to configure feild of view
bool Radar::setFeildView(int view){
    if (view == 20 || view == 40) {
        feildView_ = view;
        return 1;
    }
    ///Default feild of view when input is invalid
    else{
        feildView_ = 20;
        return 0;
    }
}
