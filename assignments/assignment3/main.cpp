/* main.cpp
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "radar.h"
#include "sonar.h"
#include "data_fusion.h"

using namespace std;

// User configurable variables
#define SONAR_BAUD 38400
#define RADAR_BAUD 38400
#define RADAR_FOV  40.0

// Declare radar and sonar objects
Radar radar;
Sonar sonar;
condition_variable cond;


// Prototype Functons
void initRadar();
void initSonar();

// Initialises Radar with user defined variables and prints out the device specific configuration
void initRadar()
{
    cout << "Initialising Radar. Fixed Parameters are as follows." << endl;
    cout << "Model Number: RAD-001" << endl;
    cout << "Data Rate: " << radar.getDataRate() << "Hz" << endl;
    cout << "Min distance: " << radar.getMinDistance() << "m" << endl;
    cout << "Max distance: " << radar.getMaxDistance() << "m" << endl << endl;
    cout << "Configuring user defined variables:" << endl;
    if (radar.setBaudRate(RADAR_BAUD))
    {
        cout << "Baud Rate set: " << radar.getBaudRate() << endl;
    }
    else
    {
        cout << "Invalid baud rate. Default value used: " << radar.getBaudRate() << endl;
    }
    if (sonar.getTty() == 1)
    {
        radar.setTtyACM(2);
        cout << "Radar has been attached to ttyACM2" << endl;
    }
    else
    {
        radar.setTtyACM(1);
        cout << "Radar has been attached to ttyACM1" << endl;
    }
    if (radar.setFov(RADAR_FOV))
    {
        cout << "FOV: " << radar.getFov() << " degrees" << endl << endl;
    }
    else
    {
        cout << "Invalid value for FOV selected. Default value used." << endl << "FOV: " << radar.getFov() << " degrees" << endl << endl;
    }
}

void initSonar()
{
    cout << "Initialising Sonar. Fixed Parameters are as follows." << endl;
    cout << "Model Number: SON-001" << endl;
    cout << "FOV: " << sonar.getFov() << endl;
    cout << "Data Rate: " << sonar.getDataRate() << "Hz" << endl;
    cout << "Min distance: " << sonar.getMinDistance() << "m" << endl;
    cout << "Max distance: " << sonar.getMaxDistance() << "m" << endl << endl;
    cout << "Configuring user defined variables:" << endl;
    if (sonar.setBaudRate(SONAR_BAUD))
    {
        cout << "Baud Rate set: " << sonar.getBaudRate() << endl;
    }
    else
    {
        cout << "Invalid baud rate. Default value used: " << sonar.getBaudRate() << endl;
    }
    if (radar.getTty() == 1)
    {
        sonar.setTtyACM(2);
        cout << "Sonar has been attached to ttyACM2" << endl << endl;
    }
    else
    {
        sonar.setTtyACM(1);
        cout << "Sonar has been attached to ttyACM1" << endl << endl;
    }
}

int main()
{
    initRadar();
    initSonar();

    mutex mu;

    thread radarThread(radar.takeReading, ref(mu), ref(cond));
    radarThread.join();
    return 0;
}
