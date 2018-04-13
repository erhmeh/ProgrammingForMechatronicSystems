//  Created by Simon Tan on 29/3/18.
//  Copyright © 2018 Simon Tan. All rights reserved.
//

#ifndef Accelerometer_h
#define Accelerometer_h

#include <string>
using namespace std;

class Sensor
{
    public:
    //Constructors (Special type of member functions)
    Sensor();
    
    //Member functions
    int setBaudRate(int bdr);
    int setMaxAcceleration(const int mxacl);
    int setUSBPort(int usbPort);
    
    void getModel();
    void getfrequency();
    void getresolution();
    


    
    bool getStatus();

    double getXAxis();
    double getYAxis();
    double getZaxis();

    
    void getRawAccelerationData(double &xUP, double &yUP, double &zUP); //obtains the raw acceleration data from the virtual sensor
    void getProcessedAcclerationData(double &xP, double &yP, double &zP); //processes the raw acceleration data so it's ready to be output to serial monitor
    
    private:
    
    //User Defined
    int baudRate_;
    int maxAccel_;
    int usbPortNo_;
    
    //Fixed Parameters
    string modelNo_ = "HWE-XXL";
    int operatingFreq_ = 10;
    int samplingResolution_ = 10;
    

    //Parameters for Virtual Accelerometer
    double xAxis_ = 0;
    double yAxis_ = 0;
    double zAxis_ = 0;


    double RAWx_ = 0;
    double RAWy_ = 0;
    double RAWz_ = 0;
    

};


#endif /* Accelerometer_h */
