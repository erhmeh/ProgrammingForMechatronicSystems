//axis_accelerometer_sensor.cpp by Mitchell Galea (97115051) Date: 27/03/2018
#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <chrono>
#include <unistd.h>

#include "axis_accelerometer_sensor.h"

using namespace std;


//default constructor sets defaults
axis_acc_sensor::axis_acc_sensor(){
    port_ = DEFAULT_PORT;
    baud_ = DEFAULT_BAUD;
    max_acceleration_ = DEFAULT_MAX_ACCELERATION;
}

//set value function will set all sane inputs, any inputs that are not sane will
//be set to default, the function returns whether the inputs are sane
string axis_acc_sensor::set_values(int port, int baud, int max_acc){
    string sane = "sane";

    if(port == 0)port_ = "dev/ttyUSB0";
    else if(port == 1)port_ = "dev/ttyUSB1";
    else if(port == 2)port_ = "dev/ttyUSB2";
    else {
        port_ = DEFAULT_PORT;
        sane = "port not sane - default set";
    }

    if(baud == 19200)baud_ = 19200;
    else if(baud == 38400)baud_ = 38400;
    else {
        baud_ = DEFAULT_BAUD;
        if(sane == "sane")sane = "baud not sane - default set";
        else sane = "port and baud not sane - defaults set";
    }

    if(max_acc == 10)max_acceleration_ = 10;
    else if(max_acc == 20)max_acceleration_ = 20;
    else if(max_acc == 50)max_acceleration_ = 50;
    else {
        max_acceleration_ = DEFAULT_MAX_ACCELERATION;
        if(sane == "sane") sane = "max_acc not sane - default set";
        else if(sane == "port not sane - default set")sane = "port and max_acc not sane - defaults set";
        else if(sane == "baud not sane - default set")sane = "baud and max_acc not sane - defaults set";
        else sane = "port, baud and max_acc not sane - defaults set";
    }
    return sane;
}

//getter methods to access all private variables and parameters

string axis_acc_sensor::get_fixed_model() const{
    return model_;
}

int axis_acc_sensor::get_fixed_sampling_time() const{
    return sampling_time_;
}

int axis_acc_sensor::get_fixed_sampling_resolution() const{
    return sampling_resolution_;
}

string axis_acc_sensor::get_port() const {
    return port_;
}

int axis_acc_sensor::get_baud() const{
    return baud_;
}

int axis_acc_sensor::get_max_acceleration() const{
    return max_acceleration_;
}

// request data uses usleep function to poll every 100ms equating to a rate of 10Hz
// when data is requested random data is written to the acceleration array

bool axis_acc_sensor::request_data() {
    for(int i= 0; i<3; i++){
        acceleration[i] = generate_random_data();
    }
    usleep(100000); //100ms
    return true;
}

// returns pointer to the acceleration array
double* axis_acc_sensor::recieve_data() {
    return acceleration;
}

//uses uniform int distribution to generate random values for acceleration
//range of -500;500 is an appropriation of the 1024 sampling resolution with a cutoff at 1000 to allow for
//more useable acceleration results

double axis_acc_sensor::generate_random_data() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed*seed);
    uniform_int_distribution<int> distribution (-500, 500);

    return double(distribution(generator))/(500/max_acceleration_);
}

