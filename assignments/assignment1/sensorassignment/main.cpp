/* main.cpp
 * Programming for Mechatronic systems
 * Assignment 1
 *
 * @author: Jamin Early 99133391
 * @date: Week 3 Autumn Semester 2018
 */

#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
#include "accelerometer.h"

using namespace std;

// This main is a demonstration of the accelerometer.cpp class that simulates the behaviour of HWE-XXL

// User configurable values.
int baudRate = 19200;
int maxAcceleration = 50;

int main()
{
        // sensor object
        Accelerometer sensor;
        // sets up USB, resolution and sampling time as these are not user configurable
        sensor.setupFixed();
        // if the user specified valid config values, use these
        if(sensor.setBaud(baudRate) && sensor.setMaxAcceleration(maxAcceleration)) {
                cout << "Successfully configured sensor" << endl;
        }
        else {
                cout << "Incorrect sensor settings. Configuring with default values." << endl;
        }
        // print configuration values to serial monitor
        cout << "Baud Rate: " << sensor.getBaud() << endl;
        cout << "Device attached at /dev/ttyUSB" << sensor.getUSB() << endl;
        cout << "Sampling time set to " << sensor.getSampleTime() << "Hz" << endl;
        cout << "Max acceleration is set to " << sensor.getMaxAcceleration() << endl;
        cout << "Sensor Resolution is " << sensor.getResolution() << " m/s^2" << endl;
        // Infinite loop printing the sensor output
        while(true) {
                // take a reading of the sensor
                if(sensor.takeSample()){
                // convert sensor value to m/s^2
                sensor.convSample();
                // print converted values
                cout << "X = " << sensor.getX() << endl;
                cout << "Y = " << sensor.getY() << endl;
                cout << "Z = " << sensor.getZ() << endl;
                // blank line for readabiity
                cout << "" << endl;
              }
        }
        return 0;
}
