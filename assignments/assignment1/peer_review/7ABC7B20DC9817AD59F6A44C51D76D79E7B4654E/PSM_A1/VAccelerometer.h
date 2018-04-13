//
//  rand_func.h
//  PSM_A1
//
//  Created by Simon Tan on 29/3/18.
//  Copyright © 2018 Simon Tan. All rights reserved.
//

#ifndef VAccelerometer_h
#define VAccelerometer_h

class virtualAccelerometer {
    
public:
    virtualAccelerometer();

    void populateWithRandomNumbers(int num_array[], size_t array_size);
    void setNumArray(int num_array[]);
    void getRandomNumbers();
    void getAccelerationData(double &x, double &y, double &z);
    

protected:
    double xAxis_;
    double yAxis_;
    double zAxis_;


};

#endif /* VAccelerometer_h */
