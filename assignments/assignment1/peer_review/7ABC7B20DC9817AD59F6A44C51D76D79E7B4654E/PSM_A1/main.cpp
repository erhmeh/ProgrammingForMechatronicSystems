#include <iostream>
#include "Accelerometer.h"
#include <math.h>
using namespace std;

int main()
{
    Sensor Accelerometer;
    
    Accelerometer.getModel();
    Accelerometer.getresolution();
    Accelerometer.getfrequency();
    
    Accelerometer.setUSBPort(2);
    Accelerometer.setBaudRate(19200);
    Accelerometer.setMaxAcceleration(51);
    

    
    double x_AxisP = 0;
    double y_AxisP = 0;
    double z_AxisP = 0;

    
    
    while(1){
        for(int i = 0; i < 50; i++){
            Accelerometer.getProcessedAcclerationData(x_AxisP,y_AxisP,z_AxisP);
            cout << "x_Axis =" << x_AxisP << "m/s^-2" << endl;
            cout << "y_Axis =" << y_AxisP << "m/s^-2" << endl;
            cout << "z_Axis =" << z_AxisP << "m/s^-2" << endl;
            cout << endl;
    }


    }
    
  return 0;
    
}


