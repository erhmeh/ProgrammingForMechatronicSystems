//main.cpp by Mitchell Galea (97115051) Date: 27/03/2018
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>


#include "axis_accelerometer_sensor.h"

using namespace std;


int main( int argc, char ** argv ){

cout << fixed;
cout << setprecision(2);

//new object assignment1 is constructed
//all values initialised and defaults set
axis_acc_sensor assignment1;

//queries the fixed sensor parameters
cout << "Sensor - assignment1 fixed parameters are:" << endl;
cout << "Sensor Model: " << assignment1.get_fixed_model() << endl;
cout << "Sampling Time: " << assignment1.get_fixed_sampling_time() << "Hz" << endl;
cout << "Sampling Resolution: " << assignment1.get_fixed_sampling_resolution() << endl;

//user inputs for variables Port, Baud Rate and Max Acceleration
cout << endl << "user inputs: ";
cout << assignment1.set_values(/*Port(0,1 or 2)*/ 0, /*Baud Rate(19200 or 38400)*/19600, /*Max Acceleration(10m/s^2, 20m/s^2 or 50m/s^2)*/10) << endl;

cout << "Port: " << assignment1.get_port() << endl;
cout << "Baud Rate: " << assignment1.get_baud() << endl;
cout << "Max Acceleration: " << assignment1.get_max_acceleration() << "m/s^2" << endl;

//program queries for data until user terminates program
while(1){
    while(assignment1.request_data() != true);
    for(double* c = assignment1.recieve_data(); c != assignment1.recieve_data() + 3; c++){
        if(c == assignment1.recieve_data()) cout << "x = " << *c << "\t";
        if(c == assignment1.recieve_data() + 1) cout << "y = " << *c << "\t";
        if(c == assignment1.recieve_data() + 2) cout << "z = " << *c << "\t";
    }
    cout << endl;
}
    return 0;
}

