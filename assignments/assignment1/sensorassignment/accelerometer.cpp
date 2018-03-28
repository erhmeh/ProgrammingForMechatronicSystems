/* accelerometer.cpp
 * Programming for Mechatronic systems
 * Assignment 1
 *
 * @author: Jamin Early 99133391
 * @date: Week 3 Autumn Semester 2018
 */

#include "accelerometer.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// accelerometer object
Accelerometer::Accelerometer(){}

// sets baud rate, returns true if you parse a valid value or otherwise false. Defaults to 19200.
bool Accelerometer::setBaud(int i){
    if (i == 19200 || i == 38400){
        baud_ = i;
        return true;
    }
    else{
        baud_ = 19200;
        return false;
    }
}

// getter method for baud rate
int Accelerometer::getBaud(){
    return baud_;
}

/* randomly selects ttylX. To simulate a real life device, I have randomised this
 * value (0, 1 or 2) as it is rare that the user chooses where on the device tree the device
 * is attached without going out of your way to create a udev rule for the specific
 * uuid or other device property.
 */
void Accelerometer::setUSB(){
    srand(time(NULL));
    tty_ = rand()%2;
}

// getter method that returns the USB port that the sensor is attached to
int Accelerometer::getUSB(){
    return tty_;
}

// sets max acceleration. Returns true if valid and false otherwise. Defaults to 50.
bool Accelerometer::setMaxAcceleration(int i){
    if (i == 10 || i == 20 || i == 50){
        maxAcceleration_ = i;
        return true;
    }
    else{
        maxAcceleration_ = 50;
        return false;
    }
}

// getter method that returns the maxAcceleration
int Accelerometer::getMaxAcceleration(){
    return maxAcceleration_;
}

// takes a 'sample' by randomly selecting a value for X, Y and Z between 0 - 1024.
void Accelerometer::takeSample(){
    // in order to simulate the sampling time, a delay is added so the takeSample() method takes as long as specified by the
    long long int start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    srand(start);

    xRaw_ = rand()%1024;
    yRaw_ = rand()%1024;
    zRaw_ = rand()%1024;
    while (!(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() >= (start + (1000)/sampleTime_))) {
      // do nothing
    }
}

void Accelerometer::convSample(){
    if (xRaw_ >= 512){
        xConv_ = ((xRaw_-512)*maxAcceleration_)/512;
    }
    else{
        xConv_ = (-xRaw_*maxAcceleration_)/512;;
    }
    if (yRaw_ >= 512){
        yConv_ = ((yRaw_-512)*maxAcceleration_)/512;
    }
    else{
        yConv_ = (-yRaw_*maxAcceleration_)/512;
    }
    if (zRaw_ >= 512){
        zConv_ = ((zRaw_-512)*maxAcceleration_)/512;
    }
    else{
        zConv_ = (-zRaw_*maxAcceleration_)/512;
    }
}

void Accelerometer::setSampleTime(){
  sampleTime_ = 10;
}

int Accelerometer::getSampleTime(){
    return sampleTime_;
}

void Accelerometer::setResolution(){
  resolution_ = 1024;
}

int Accelerometer::getResolution(){
    return resolution_;
}

void Accelerometer::setupFixed(){
  setUSB();
  setSampleTime();
  setResolution();
}

double Accelerometer::getX(){
    return xConv_;
}

double Accelerometer::getY(){
    return yConv_;
}

double Accelerometer::getZ(){
    return zConv_;
}
