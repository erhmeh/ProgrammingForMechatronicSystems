#include "sonar.h"

#include <random>


//Constructor sets constant values and initializes all other parameters with default values
Sonar::Sonar(): Ranger(MODEL_SONAR,eSONAR)
{
    field_of_view_ = FIELD_OF_VIEW_SONAR;
    max_distance_ = MAX_DISTANCE_SONAR;
    min_distance_ = MIN_DISTANCE_SONAR;
    baud_ = c38400;                                      //Default initialization values
    port_ = USB0;
    data_rate_ = DATA_RATE_SONAR;
}


void Sonar::run(RangerBuffer &buffer) {
    while(true){
        // Get the current time
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

        // setup of measurement
        cMeasurement meas;
        meas.rangerType = getType();
        meas.ranger_FOV = getFieldOfView();
        meas.ranger_max_distance = getMaxDistance();
        meas.ranger_min_distance = getMinDistance();
        meas.time = now;

        // Create a random number generator (using the random library)
        std::default_random_engine generator(now.time_since_epoch().count());
        std::normal_distribution<double> distribution(MEAN_SONAR,STANDARD_DEVIATION_SONAR);

        double omega = 2*M_PI*0.05;
        double value = 6 +(4*sin(omega * now.time_since_epoch().count())) + distribution(generator);
        if (value > max_distance_)
        {
            value = max_distance_;
        }
        if (value < min_distance_)
        {
            value = min_distance_;
        }
        meas.measurement.push_back(value);

        buffer.addValue(meas);
        std::this_thread::sleep_until(now + std::chrono::milliseconds((int)(1000/data_rate_)));
    }
}


//Set functions
bool Sonar::setBaud(int baud) {
    //check if input parameter is valid
    if (baud == c38400 || baud == c115200){
        baud_ = baud;
        return true;
    }else
    {
        baud_ = c38400;
        return false;
    }
}


bool Sonar::setPort(int port)
{
    //check if input parameter is valid
    if (port == USB0 || port == USB1 || port == USB2) {
        port_ = port;
        return true;
    }else {
        port_ = USB0;
        return false;
    }
}

std::string Sonar::getValidPort(){
    return "(0/1/2)";
}

std::string Sonar::getValidBaud(){
    return "(38400/115200)";
}