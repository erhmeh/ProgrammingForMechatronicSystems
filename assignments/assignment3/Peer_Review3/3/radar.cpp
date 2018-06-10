#include "radar.h"

#include <random>

enum FOV{
    c20 = 20,
    c40 = 40,
};


Radar::Radar(): Ranger(MODEL_RADAR,eRADAR)
{
    baud_ = 0;
    port_ = 0;
    field_of_view_ = 0;
    max_distance_ = MAX_DISTANCE_RADAR;
    min_distance_ = MIN_DISTANCE_RADAR;
    data_rate_ = DATA_RATE_RADAR;
}


void Radar::run(RangerBuffer &buffer) {
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
        std::normal_distribution<double> distribution(MEAN_RADAR,STANDARD_DEVIATION_RADAR);

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
bool Radar::setBaud(int baud) {
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


bool Radar::setPort(int port)
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

bool Radar::setFOV(double field_of_view) {
    //check if input parameter is valid
    if (field_of_view == c20 || field_of_view == c40) {
        field_of_view_ = field_of_view;
        return true;
    }else {
        field_of_view_ = c20;
        return false;
    }
}


std::string Radar::getValidFOV() {
    return "(20/40)";
}

std::string Radar::getValidPort(){
    return "(0/1/2)";
}

std::string Radar::getValidBaud(){
    return "(38400/115200)";
}



