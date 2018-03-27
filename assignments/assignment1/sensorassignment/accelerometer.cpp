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

Accelerometer::Accelerometer(){}

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

int Accelerometer::getBaud(){
    return baud_;
}

void Accelerometer::setUSB(){
    srand(time(NULL));
    ttyl_ = rand%3;
}

int Accelerometer::getUSB(){
    return ttyl_;
}

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

int Accelerometer::getMaxAcceleration(){
    return maxAcceleration_;
}

void Accelerometer::takeSample(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    srand(time(NULL));
    xRaw_ = rand()%1024;
    yRaw_ = rand()%1024;
    zRaw_ = rand()%1024;
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

int Accelerometer::setResolution(){
  resolution_ = 1024;
}

int Accelerometer::getResolution(){
    return resolution_;
}

void Accelerometer::setupFixed(){
  this.setUSB();
  this.setSampleTime();
  this.setResolution();
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
