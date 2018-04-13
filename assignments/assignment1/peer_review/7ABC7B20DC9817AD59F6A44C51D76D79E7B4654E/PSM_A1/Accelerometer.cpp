//  PSM_A1
//  Created by Simon Tan on 29/3/18.
//  Copyright © 2018 Simon Tan. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "VAccelerometer.h"
#include "Accelerometer.h"

using namespace std;
using namespace std::chrono;
using namespace::this_thread;



#define DEFAULT_ACCELERATION 10
#define DEFAULT_BAUD 19200
#define DEFAULT_PORT 0

virtualAccelerometer VIRTACCL;

Sensor::Sensor() //this is our constructor
{
}


int Sensor::setUSBPort(int usbPort)
{
    usbPortNo_ = usbPort;
    
    if(usbPort == 0 || usbPort == 1 || usbPort == 2)
    {
        
        usbPortNo_ = usbPort;
        cout << "USER-DEFINED PARAMETERS:" << endl << "ParametersRequested USB Port set - Port "<< usbPortNo_ << " selected!" << endl;
        return usbPortNo_;
    }
    else
    {
        
        cout << "USER-DEFINED PARAMETERS:" << endl << "Requested USB Port invalid! Default Port (Port 0) selected" << endl;
        return DEFAULT_PORT;
        
    }
}


int Sensor::setBaudRate(int bdr)
{
    baudRate_ = bdr;
    
    if(baudRate_ == 19200 || baudRate_ == 38400)
    {
        
        cout << "Requested baud rate set to " << baudRate_ << endl;
        return baudRate_;
    }
    else
    {
       
        cout << "Requested baud rate invalid! Default Selected (19200)" << endl;
        return DEFAULT_BAUD;
    }
    
    
}

int Sensor::setMaxAcceleration(int mxacl)
{
    maxAccel_ = mxacl;
    if(maxAccel_ == 10 || maxAccel_ == 20 || maxAccel_ == 50)
    {
     
        
        cout << "Requested Max Acceleration Set to " << maxAccel_ << "m/s^2!" << endl << endl;
    }
    else
    {
        
        cout << "Requested Max Acceleration invalid! Default Acceleration (10m/s^2) Selected " << endl;
        maxAccel_ = DEFAULT_ACCELERATION;
    }
    return maxAccel_;
}




void Sensor::getRawAccelerationData(double &xUP, double &yUP, double &zUP)
{
    VIRTACCL.getAccelerationData(xAxis_,yAxis_,zAxis_);
    xUP = xAxis_;
    yUP = yAxis_;
    zUP = zAxis_;
    

}


void Sensor::getProcessedAcclerationData(double &xP, double &yP, double &zP)
{
    getRawAccelerationData(RAWx_, RAWy_, RAWz_);
    if (maxAccel_ == 10)
    {
      xP = (RAWx_*0.01955034)-maxAccel_; // = resx*(20/1023) - max accel
      yP = (RAWy_*0.01955034)-maxAccel_;
      zP = (RAWz_*0.01955034)-maxAccel_;

    }
    
    else if (maxAccel_ == 20)
        
    {
        xP = (RAWx_*0.038910068)-maxAccel_;
        yP = (RAWy_*0.038910068)-maxAccel_;
        zP = (RAWz_*0.038910068)-maxAccel_;
    }
    else{
        
        xP = (RAWx_*0.09775171)-maxAccel_;
        yP = (RAWy_*0.09775171)-maxAccel_;
        zP = (RAWz_*0.09775171)-maxAccel_;
    }
    
   
}



void Sensor::getfrequency()
{
    cout <<"Frequecy:" << operatingFreq_ << " bit" << endl << endl;
}

void Sensor::getModel()
{
    cout << "FIXED PARAMETERS:" << endl << "Model:" << modelNo_ << endl;
    
}

void Sensor:: getresolution()
{
    cout << "Sampling Resolution is" << samplingResolution_ << "bit" << endl;
    
}


