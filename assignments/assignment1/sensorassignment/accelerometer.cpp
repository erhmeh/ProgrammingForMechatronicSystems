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
        return false;
    }
}

int Accelerometer::getBaud(){
    return baud_;
}

bool Accelerometer::setUSB(int i){
    if (i == 0 || i == 1 || i == 2){
        ttyl_ = i;
        return true;
    }
    else {
        return false;
    }
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
        return false;
    }
}

int Accelerometer::getMaxAcceleration(){
    return maxAcceleration_;
}

void Accelerometer::takeSample(){
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

int Accelerometer::getSampleTime(){
    return 10;
}

int Accelerometer::getResolution(){
    return 1024;
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
